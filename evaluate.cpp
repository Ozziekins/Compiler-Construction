
// A very bad move from me to declare such a global variable
bool DEBUG = false;

void print_symbol_table(map<string/*NIdentifier * */, complex_t *> SymbolTable) {
    if (DEBUG){
        cout << "\n _____ SYMBOLTABLE ________\n";
        for (const auto& x : SymbolTable) {
            cout << "| " << type_name(*x.second) << "\n";

            if (!string(type_name(*x.second)).compare("STRING"))
                cout << "| " << x.first << "= " << *(x.second->stringVAl) << endl << "| " << endl;
            else if (!string(type_name(*x.second)).compare("INTEGER"))
                cout << "| " << x.first << "= " << x.second->intVal << endl << "| " << endl;
            else if (!string(type_name(*x.second)).compare("FLOAT"))
                cout << "| " << x.first << "= " << x.second->floatVal << endl << "| " << endl;
                    else if (!string(type_name(*x.second)).compare("BOOL"))
                cout << "| " << x.first << "= " << x.second->boolVAl << endl << "| " << endl;
            
            else if (!string(type_name(*x.second)).compare("EMPTY"))
                cout << "| " << x.first << "= " << *(x.second->stringVAl) << endl << "| " << endl;
            else cout << "\n STRANGE TYPE ENCOUTERED !!!! \n";
            //TODO ADD OTHER ONES!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        }
        cout << "|__________________________\n\n";
    }
}

complex_t *Evaluate::visit(NProgram *program){
    return nullptr;
}

complex_t *Evaluate::visit(NBlock *block){

    for(int i = 0; i < (int)block->instructions.size(); i++) {
        block->instructions[i]->accept(*this);
    }
    return nullptr;
}

complex_t *Evaluate::visit(NDeclaration *decl){
    
    if (DEBUG) cout << "Parsed NDeclaration "; //<< endl;
    string ident_name = *(decl->identifier->name);
    if (DEBUG) cout << "of variable [" << ident_name << "] : ";

    //initialize symbol table with corresponding types
    complex_t *value = nullptr;
    if (decl->assignmentExpr){
        value = decl->assignmentExpr->accept(*this);
        // ident_name->type = string(type_name(*value)); //TODO OH NO, WHAT IS THE EXPRESSION TYPE AAAAAAAAAAA
    }
    else { //TODO NOW EMPTY HAS VALUE eMpTy; IS IT OK?
        value = create_type();
        value->type = EMPTY;
        value->stringVAl = new string("eMpTy");
    }
    SymbolTable.insert({ ident_name, value});
    print_symbol_table(SymbolTable);

    return nullptr;
}


complex_t *Evaluate::visit(NArray *){
    cout << "NArray" << endl;
    return nullptr;
}

complex_t *Evaluate::visit(NTuple *){
    cout << "NTuple" << endl;
    return nullptr;
}

complex_t *Evaluate::visit(NStatement *stmt){
    cout << "NStatement" << endl;
    return nullptr;
}

complex_t *Evaluate::visit(NAssignment *assignmnt){

    complex_t *var = assignmnt->identifier->accept(*this);
    complex_t *newvar = assignmnt->expression->accept(*this);

    #define THING(x) cout << x;
    if (DEBUG){
        cout << "Parsed NAssignment and changed newvar from {";
        DO_THING(var, THING);
        cout << "} to {";
        DO_THING(newvar, THING);
        cout<< "}" << endl;
    }
    
    *var = *newvar;

    return nullptr;
}




complex_t *Evaluate::visit(NPrint *print){

    //TODO CHECK FOR EMPTY???
    // if ( x == EMPTY ){
    //     cout << "Semantic? Error:\n\tOPERATIONS ON EMPTY VALUES ARE NOT ALLOWED\n";
    //     exit(228);
    // }

    #define THING(x) cout << x;

    if (DEBUG) cout << "Parsed NPrint" << endl;
    
    for(int i = 0; i < (int)print->expressions.size(); i++)
        DO_THING(print->expressions[i]->accept(*this),THING)

    cout << endl;
    #undef  THING

    return nullptr;
}

complex_t *Evaluate::visit(NFunctionDefinition *funcdef){
    cout << "NFunctionDefinition" << endl;
    funcdef->arguments->accept(*this);
    if (funcdef->block)
        funcdef->block->accept(*this);
    if (funcdef->expression)
        funcdef->expression->accept(*this);
    return nullptr;
}

complex_t *Evaluate::visit(NParameters *params) {
    cout << "NParameter" << endl;
    for(int i = 0; i < (int)params->arguments.size(); i++)
        params->arguments[i]->accept(*this);
    return nullptr;
}

complex_t *Evaluate::visit(NIf *ifstmt){
    cout << "NIf" << endl;
    ifstmt->condition->accept(*this);
    ifstmt->ifblock->accept(*this);
    return nullptr;
}

complex_t *Evaluate::visit(NIfElse *ifstmt){
    cout << "NIfElse" << endl;
    ifstmt->condition->accept(*this);
    ifstmt->ifblock->accept(*this);
    ifstmt->elseblock->accept(*this);
    return nullptr;
}

complex_t *Evaluate::visit(NLoop *loop){
    cout << "NLoop" << endl;
    loop->condition->accept(*this);
    loop->block->accept(*this);
    return nullptr;
}

complex_t *Evaluate::visit(NRangeLoop *loop){

    cout << "NRangeLoop" << endl;
    loop->id->accept(*this);
    loop->from->accept(*this);
    loop->to->accept(*this);
    loop->block->accept(*this);
    return nullptr;
}

complex_t *Evaluate::visit(NReturn *retstmt){
    cout << "NReturn" << endl;
    retstmt->expression->accept(*this);
    return nullptr;
}

complex_t *Evaluate::visit(NExpression *){
    cout << "NExpression" << endl;
    return nullptr;
}

complex_t *Evaluate::visit(NIdentifier *id){
    //TODO PROPER SYMBOLTABLES + SCOPE interactions

    string name = *(id->name);
    if (DEBUG) cout << "Parsed NIdentifier [" << name << "]" << endl;

    if ( SymbolTable.count(*(id->name)) != 0)
         return SymbolTable[name];
    else{
        cout << "\nSEMANTIC? ERROR:\n\tIDENTIFIER " << name << " IS NOT PRESENT IN THE SYMBOL TABLE!\n";
        exit(228);
    }
        
   
}


complex_t *Evaluate::visit(NIntegerLiteral *intlit){
    if (DEBUG) cout << "Parsed NIntegerLiteral {" << intlit->value << "}" << endl;
    complex_t * ival = create_type();
    ival->type = INTEGER;
    ival->intVal = intlit->value;
    return ival;
}

complex_t *Evaluate::visit(NReal *reallit){
    if (DEBUG) cout << "Parsed NReal {" << reallit->value << "}" << endl;
    complex_t * fval = create_type();
    fval->type = FLOAT;
    fval->floatVal = reallit->value;
    return fval;
}


complex_t *Evaluate::visit(NBool *blit){
    if (DEBUG) cout << "Parsed NBool {" << blit->value << "}" << endl;
    complex_t * bval = create_type();
    bval->type = BOOL;
    bval->boolVAl = blit->value;
    return bval;
}

complex_t *Evaluate::visit(NStringLiteral *slit){
    if (DEBUG) cout << "Parsed NStringLiteral {" << *(slit->text) << "}" << endl;
    complex_t * sval = create_type();
    sval->type = STRING;
    sval->stringVAl = slit->text;
    return sval;
}

#define THING(x)     switch(op){\
        case PLUS:\
            x = LVAL + RVAL; break;\
        case MINUS:\
            x = LVAL - RVAL; break;\
        case MULT:\
            x = LVAL * RVAL; break;\
        case DIV:\
            x = LVAL / RVAL; break;\
        case LESS:\
            x = LVAL < RVAL; break;\
        case GREAT:\
            x = LVAL > RVAL; break;\
        default:\
            cout << "ILLEGAL OPERATION for numbers; CODE: [" << op << "]"; break; \
        }\

complex_t *Evaluate::visit(NBinaryOperator *bin_op){

    if (DEBUG) cout << "Parsed NBinaryOperator CODE={" << bin_op->op << "}" << endl;
    auto op = bin_op->op;
    auto left = bin_op->lhs->accept(*this);
    auto right = bin_op->rhs->accept(*this);
    auto left_T  = left->type;
    auto right_T = right->type;
    complex_t * value = create_type();

    //CHECK FOR EMPTY
    if ( left_T == EMPTY || right_T == EMPTY  ){
        cout << "Semantic? Error:\n\tOPERATIONS ON EMPTY VALUES ARE NOT ALLOWED\n";
        exit(228);
    }

    //OPerations on numbers
    if ( ( left_T == INTEGER ||  left_T == FLOAT ) && (right_T == INTEGER || right_T == FLOAT ) ){
        
        // ETA HUYNA NE RABOTAET
        if (left_T == FLOAT || right_T == FLOAT){
            value->type = FLOAT; 
        }
        else{
            value->type = INTEGER;
        };


        if (left_T == FLOAT){
            auto LVAL = left->floatVal;

            if (right_T == FLOAT){
               auto RVAL = right->floatVal;
               DO_THING(value, THING)
            }
            else{
                auto RVAL = right->intVal;
                DO_THING(value, THING)
            }
        }
        else if (right_T == FLOAT){
            auto LVAL = left->intVal;
            auto RVAL = right->floatVal;
            DO_THING(value, THING)
        }
        else{
            auto LVAL = left->intVal;
            auto RVAL = right->intVal;
            DO_THING(value, THING)
        }

    }
    // if for RETARDED OPERATIONS

    switch(left_T) {
        case EMPTY:
            // No operation possible
            break;
        case INTEGER:
            switch(right_T) {
                case INTEGER:

                case FLOAT:

                default:
                    cout << "OPERATION NOT POSSIBLE"
            }
            break;
        case FLOAT:
            switch(right_T) {
                case INTEGER:
                case FLOAT:
                default:
                    cout << "OPERATION NOT POSSIBLE"
            }
            break;
        case BOOL:
            switch(right_T) {
                case BOOL:
                default:
                    cout << "OPERATION NOT POSSIBLE"
            }
            break;
        case ARRAY:
            switch(right_T) {
                case ARRAY:

                default:
                    cout << "OPERATION NOT POSSIBLE"
            }
            break;
        case TUPLE:
            switch(right_T) {
                case ARRAY:
                
                default:
                    cout << "OPERATION NOT POSSIBLE"
            }
            break;
    }
    return value;
}
#undef THING


complex_t *Evaluate::visit(NTypeCheck *){
     cout << "NTypeCheck" << endl;
    return nullptr;
}


complex_t *Evaluate::visit(NUnary *unary){
    if (DEBUG) cout << "Parsed NUnary {" ;
    
    complex_t *exp = unary->expression->accept(*this);
    complex_t *value = create_type();
    value->type = exp->type;

    int op = unary->op;

    //TODO ADD PROPER NOT SUPPORT
    if (value->type == INTEGER){
        if (op == PLUS)
            value->intVal = exp->intVal;
        else if (op == MINUS)
            value->intVal = -exp->intVal;
        else if (op == NOT)
            value->intVal = !exp->intVal; 
        else{
            cout << "Semantic? Error:\n\tILLEGAL UNARY OPERATION: " << op << endl;
            exit(228);
        }
    }
    else if (value->type == FLOAT){
        if (op == PLUS)
            value->floatVal = exp->floatVal;
        else if (op == MINUS)
            value->floatVal = -exp->floatVal;
        else if (op == NOT)
            value->floatVal = !exp->floatVal;
        else{
            cout << "Semantic? Error:\n\tILLEGAL UNARY OPERATION: " << op << endl;
            exit(228);
        }
    }
    else{
        cout << "Semantic? Error:\n\tILLEGAL TYPE FOUND IN UNARY OPERATION\n";
        exit(228);
    }

   

    cout << endl;
    return value;
}

complex_t *Evaluate::visit(NReadInput *){
    cout << "NReadInput" << endl;
    return nullptr;
}
