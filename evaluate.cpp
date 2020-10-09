// A very bad move from me to declare such a global variable
bool DEBUG = false;

// OPERATIONS ON ARRAY _ COMPLEX_T
vector<complex_t> *add_arr_int(vector<complex_t> *lval, complex_t rval) {
    lval->push_back(rval);
    return lval;
}

// TUPLE ADDITION



void Evaluate::print_symbol_table() {
    int depth = 0;
    if (DEBUG){

        for ( auto scope = scopes.rbegin(); scope != scopes.rend(); ++scope  ){
            cout << "\n _____ SYMBOLTABLE_"<<depth<<"________\n";
            auto temp = **scope;
            for (const auto& x : temp) {

                cout << "| " << type_name(*x.second) << "\n";

                if (!string(type_name(*x.second)).compare("STRING"))
                    cout << "| " << x.first << "= " << *(x.second->stringVAl) << endl << "| " << endl;
                else if (!string(type_name(*x.second)).compare("INTEGER"))
                    cout << "| " << x.first << "= " << x.second->intVal << endl << "| " << endl;
                else if (!string(type_name(*x.second)).compare("FLOAT"))
                    cout << "| " << x.first << "= " << x.second->floatVal << endl << "| " << endl;
                else if (!string(type_name(*x.second)).compare("BOOL"))
                    cout << "| " << x.first << "= " << x.second->boolVal << endl << "| " << endl;
                else if (!string(type_name(*x.second)).compare("FUNCTION"))
                    cout << "| " << x.first << endl << "| " << endl;
                else if (!string(type_name(*x.second)).compare("EMPTY"))
                    cout << "| " << x.first << "= " << *(x.second->stringVAl) << endl << "| " << endl;
                else cout << "\n STRANGE TYPE ENCOUTERED !!!! \n";
                //TODO ADD OTHER ONES!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            }
            cout << "|__________________________\n\n";
            depth++;
        }
    }
}

complex_t *Evaluate::visit(NProgram *program){
    return nullptr;
}

complex_t *Evaluate::visit(NBlock *block){

    //TODO BREAK ON RETURN
    // try {
    for(int i = 0; i < (int)block->instructions.size(); i++) {
        block->instructions[i]->accept(*this);
    }
    // }
    // catch(complex_t* t){
    //    if (DEBUG) cout << "Encountered A return\n"; 
    //    throw(t);
    // }
    return nullptr;
}

complex_t *Evaluate::visit(NDeclaration *decl){
    
    if (DEBUG) cout << "Parsed NDeclaration "; 
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
    scopes.front()->insert( { ident_name, value} );
    print_symbol_table();

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
    #undef THING
    *var = *newvar;
    print_symbol_table();
    return nullptr;
}




complex_t *Evaluate::visit(NPrint *print){

    //TODO CHECK FOR EMPTY???
    // if ( x == EMPTY ){
    //     cout << "Semantic? Error:\n\tOPERATIONS ON EMPTY VALUES ARE NOT ALLOWED\n";
    //     exit(228);
    // }
    if (DEBUG) cout << "Parsed NPrint" << endl;

    if ((int)print->expressions->expressions.size() > 0){
        #define THING(x) cout << x;
        
        for(int i = 0; i < (int)print->expressions->expressions.size(); i++)
            DO_THING(print->expressions->expressions[i]->accept(*this),THING)

        cout << endl;
        #undef  THING
    }
    else{
        cout << "\nSEMANTIC? ERROR:\n\t PRINT WITH NO ARGUMENTS";
        exit(228);
    }
    return nullptr;
}

complex_t *Evaluate::visit(NFunctionDefinition *funcdef){
    if (DEBUG) cout << "NFunctionDefinition" << endl;

    auto res = create_type();
    res->type = FUNCTION;
    res->function = funcdef;

    // funcdef->arguments->accept(*this);
    // if (funcdef->block)
    //     funcdef->block->accept(*this);
    // if (funcdef->expression)
    //     funcdef->expression->accept(*this);
    return res;
}

complex_t *Evaluate::visit(NFunctionCall *funcall){

    if (DEBUG) cout << "NFunctionCall of {"<< *(funcall->id->name) <<"()}" << endl;
    auto func = funcall->id->accept(*this);


    if (func->type == FUNCTION){
        auto funcdef = func->function;

        if (funcdef->arguments){  
            if (funcdef->block){
                try{
                    scopes.push_front( new map<string, complex_t *>() );
                    funcdef->arguments->accept(*this, funcall->arguments);
                    funcdef->block->accept(*this);
                }
                catch(complex_t* res){
                    scopes.pop_front();
                    return res;
                }
            }
            else{
                
                scopes.push_front( new map<string, complex_t *>() );
                funcdef->arguments->accept(*this, funcall->arguments);
                auto res = funcdef->expression->accept(*this); //TODO CHECK FOR BUGS 
                scopes.pop_front();
                return res;
            }
        }
        else{
            if (funcdef->block){
                try{
                    scopes.push_front( new map<string, complex_t *>() );
                    funcdef->block->accept(*this);
                }
                catch(complex_t* res){
                    scopes.pop_front();
                    return res;
                }
            }
            else{
                // cout << "THE TYPE OF RES IS " << type_name(*funcdef->expression->accept(*this));
                return funcdef->expression->accept(*this);
            }
        }

    }
    else{
        cout << "\nSEMANTIC? ERROR:\n\t ATTEMPT TO CALL NON-FUNCTION " << *(funcall->id->name) << endl;
        exit(228);
    }

    
    
    auto res = create_type(); 
    res->type = EMPTY;
    res->stringVAl = new string("eMpTy");

    return res;
}

complex_t *Evaluate::visit(NParameters *params, NExpressions * values) {
    if (DEBUG) cout << "Parsed NParameter" << endl;
    
    if ( values->expressions.size() == params->arguments.size() )
    for(int i = 0; i < (int)params->arguments.size(); i++){
        
        // cout << "Argument var " << *params->arguments[i]->name << endl;//accept(*this);
        // cout << "OF TYPE: " << values->expressions[i]->accept(*this)->type << endl;
        scopes.front()->insert( { *params->arguments[i]->name, values->expressions[i]->accept(*this)} );
        // cout << "INSERTED" << endl;
        // print_symbol_table();
    }
    else{
        cout << "SEMANTIC ERROR:\n\tNUMBER OF PARAMETERS DOES NOT MATCH THE NUMBER OF ARGUMENTS";
        exit(228);
    }

    return nullptr;
}

complex_t *Evaluate::visit(NIf *ifstmt){
    if (DEBUG) cout << "Parsed NIf" << endl;
    

    #define THING(x) if ( x ){\
        scopes.push_front( new map<string, complex_t *>() );\
        ifstmt->ifblock->accept(*this);\
        scopes.pop_front();\
    }\

    DO_THING_NUM(ifstmt->condition->accept(*this), THING)
    
    #undef THING

    //TODO check whether this is okay
    // if (ifstmt->condition->accept(*this)->boolVAl){
    //     ifstmt->ifblock->accept(*this);
    //     scopes.pop_front();
    // }

    return nullptr;
}

complex_t *Evaluate::visit(NIfElse *ifstmt){
    if (DEBUG) cout << "Parsed NIfElse" << endl;

    #define THING(x) if ( x ){\
        scopes.push_front( new map<string, complex_t *>() );\
        ifstmt->ifblock->accept(*this);\
        scopes.pop_front();\
    }\
    else{\
        scopes.push_front( new map<string, complex_t *>() );\
        ifstmt->elseblock->accept(*this);\
        scopes.pop_front();\
    }\

    DO_THING_NUM(ifstmt->condition->accept(*this), THING)
    
    #undef THING

    // ifstmt->condition->accept(*this);
    // ifstmt->ifblock->accept(*this);


    return nullptr;
}

complex_t *Evaluate::visit(NLoop *loop){
    if (DEBUG) cout << "Parsed NLoop" << endl;


    #define THING(x) while ( x )\
    for(int i = 0; i < (int)loop->block->instructions.size(); i++)\
        loop->block->instructions[i]->accept(*this);\

    scopes.push_front( new map<string, complex_t *>() );
    DO_THING_NUM(loop->condition->accept(*this), THING)
    scopes.pop_front();
    #undef THING

    return nullptr;
}

complex_t *Evaluate::visit(NRangeLoop *loop){

    if (DEBUG) cout << "Parsed NRangeLoop" << endl;


    auto from = loop->from->accept(*this);
    auto to = loop->to->accept(*this);
    auto complex = loop->id->accept(*this);

    if ( from->type == INTEGER && to->type == INTEGER ){

        complex->type = INTEGER;

        scopes.push_front( new map<string, complex_t *>() );
        for( complex->intVal = from->intVal; complex->intVal <= to->intVal ; ++(complex->intVal) )
            for(int i = 0; i < (int)loop->block->instructions.size(); i++)
                loop->block->instructions[i]->accept(*this);
        scopes.pop_front();

    }
    else
        cout << "\n SEMANTIC ERROR:\n NON-INTEGER IN THE RANGE LOOP\n";

    return nullptr;
}

complex_t *Evaluate::visit(NReturn *retstmt){
    if (DEBUG) cout << "Parsed NReturn" << endl;

    throw retstmt->expression->accept(*this);
    return nullptr;
}

complex_t *Evaluate::visit(NExpression *){
    cout << "NExpression" << endl;
    return nullptr;
}

complex_t *Evaluate::visit(NExpressions *){
    cout << "NExpressions" << endl;
    return nullptr;
}


complex_t *Evaluate::visit(NIdentifier *id){
    //TODO PROPER SYMBOLTABLES + SCOPE interactions

    string name = *(id->name);
    if (DEBUG) cout << "Parsed NIdentifier [" << name << "]" << endl;

    for (auto& x : scopes)
        if ( (*x).count(*(id->name)) != 0){
            // cout << "Found in this scope; " << x->size() << endl;
            return (*x)[name];
        }
        else{
            if (DEBUG) cout << "Not found in this scope; " << x->size() << " ;trying outer one...\n";
        }

    cout << "\nSEMANTIC? ERROR:\n\tIDENTIFIER " << name << " IS NOT PRESENT IN THE SYMBOL TABLE!\n";
    exit(228);
   
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
    bval->boolVal = blit->value;
    return bval;
}

complex_t *Evaluate::visit(NStringLiteral *slit){
    if (DEBUG) cout << "Parsed NStringLiteral {" << *(slit->text) << "}" << endl;
    complex_t * sval = create_type();
    sval->type = STRING;
    sval->stringVAl = slit->text;
    return sval;
}

complex_t *Evaluate::visit(NTypeCheck * check){
    if (DEBUG) cout << "Parsed NTypeCheck" << endl;

    auto value = check->primary->accept(*this);

    if ( check->op == NOT && value->type != BOOL  ){
        cout << "SEMANTIC? ERROR:\n\t USING NOT ON NON-BOOLEAN LITERALS";
    } 

    auto res = create_type();
    res->type = BOOL;
    res->boolVal = ( check->type == value->type ); 

    return res;
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
    else if (value->type == BOOL){
        if (op == NOT)
            value->boolVal = !exp->boolVal;
        else{
            cout << "Semantic? Error:\n\tILLEGAL UNARY OPERATION: " << op << endl;
            exit(228);
        }
    }
    else{
        cout << "Semantic? Error:\n\tILLEGAL TYPE FOUND IN UNARY OPERATION\n";
        exit(228);
    }

    if (DEBUG) cout << endl;
    return value;
}

complex_t *Evaluate::visit(NReadIntInput *){
    if (DEBUG) cout << "Parsed NReadIntInput of value {";

    auto value = create_type();
    value->type = INTEGER;
    cin >> value->intVal; 

    if (DEBUG) cout << value->intVal << "}" << endl;;

    return value;
}

complex_t *Evaluate::visit(NReadRealInput *){
    if (DEBUG) cout << "Parsed NReadRealInput {" << endl;
    
    auto value = create_type();
    value->type = FLOAT;
    cin >> value->floatVal; 

    if (DEBUG) cout << value->floatVal << "}" << endl;;

    return value;
}

complex_t *Evaluate::visit(NReadStringInput *){
    if (DEBUG) cout << "Parsed NReadStringInput" << endl;
    
    auto value = create_type();
    value->type = STRING;
    string* tmp = new string();
    cin >> *(tmp); 

    value->stringVAl = tmp;

    if (DEBUG) cout << value->stringVAl << "}" << endl;;

    return value;
}



complex_t *evaluate_expression(complex_t * left, Operators optor, complex_t *right){
    auto left_t = left->type;
    auto right_t = right->type;
    
    complex_t* result = create_type();
    switch(left_t) {
        case EMPTY:
            cout << "No possible operations with EMPTY types\n";
            break;
        case INTEGER:
            switch(right_t) {
                case INTEGER:
                    {int lval = left->intVal;
                    int rval = right->intVal;
                    switch(optor) {
                        case PLUS: result->type = INTEGER; result->intVal = lval + rval; break;
                        case MINUS: result->type = INTEGER; result->intVal = lval - rval; break;
                        case MULT: result->type = INTEGER; result->intVal = lval * rval; break;
                        case DIV: result->type = INTEGER; result->intVal = floor(lval / rval); break;
                        case LESS: result->type = BOOL; result->boolVal = lval < rval; break;
                        case GREAT: result->type = BOOL; result->boolVal = lval > rval; break;
                        case LEQ: result->type = BOOL; result->boolVal = lval <= rval; break;
                        case GEQ: result->type = BOOL; result->boolVal = lval >= rval; break;
                        case EQUAL: result->type = BOOL; result->boolVal = lval == rval; break;
                        case NEQ: result->type = BOOL; result->boolVal = lval != rval; break;
                        default: cout << "OPERATION NOT IMPLEMENTED";
                    }}
                    break;
                case FLOAT:
                    {int lval = left->intVal;
                    float rval = right->floatVal;
                    switch(optor) {
                        case PLUS: result->type = FLOAT; result->floatVal = lval + rval; break;
                        case MINUS: result->type = FLOAT; result->floatVal = lval - rval; break;
                        case MULT: result->type = FLOAT; result->floatVal = lval * rval; break;
                        case DIV: result->type = FLOAT; result->floatVal = lval / rval; break;
                        case LESS: result->type = BOOL; result->boolVal = lval < rval; break;
                        case GREAT: result->type = BOOL; result->boolVal = lval > rval; break;
                        case LEQ: result->type = BOOL; result->boolVal = lval <= rval; break;
                        case GEQ: result->type = BOOL; result->boolVal = lval >= rval; break;
                        case EQUAL: result->type = BOOL; result->boolVal = lval == rval; break;
                        case NEQ: result->type = BOOL; result->boolVal = lval != rval; break;
                        default: cout << "OPERATION NOT IMPLEMENTED";
                    }}
                    break;
                default:
                    cout << "OPERATION NOT POSSIBLE";
            }
            break;
        case FLOAT:
            switch(right_t) {
                case INTEGER:
                    {float lval = left->floatVal;
                    int rval = right->intVal;
                    switch(optor) {
                        case PLUS: result->type = FLOAT; result->floatVal = rval + lval; break;
                        case MINUS: result->type = FLOAT; result->floatVal = lval - rval; break;
                        case MULT: result->type = FLOAT; result->floatVal = rval * lval; break;
                        case DIV: result->type = FLOAT; result->floatVal = lval / rval; break;
                        case LESS: result->type = BOOL; result->boolVal = lval < rval; break;
                        case GREAT: result->type = BOOL; result->boolVal = rval > lval; break;
                        case LEQ: result->type = BOOL; result->boolVal = rval <= lval; break;
                        case GEQ: result->type = BOOL; result->boolVal = rval >= lval; break;
                        case EQUAL: result->type = BOOL; result->boolVal = rval == lval; break;
                        case NEQ: result->type = BOOL; result->boolVal = rval != lval; break;
                        default: cout << "OPERATION NOT IMPLEMENTED";
                    }}
                    break;
                case FLOAT:
                    {float lval = left->floatVal;
                    float rval = right->floatVal;
                    switch(optor) {
                        case PLUS: result->type = FLOAT; result->floatVal = rval + lval; break;
                        case MINUS: result->type = FLOAT; result->floatVal = lval - rval; break;
                        case MULT: result->type = FLOAT; result->floatVal = rval * lval; break;
                        case DIV: result->type = FLOAT; result->floatVal = lval / rval; break;
                        case LESS: result->type = BOOL; result->boolVal = lval < rval; break;
                        case GREAT: result->type = BOOL; result->boolVal = rval > lval; break;
                        case LEQ: result->type = BOOL; result->boolVal = rval <= lval; break;
                        case GEQ: result->type = BOOL; result->boolVal = rval >= lval; break;
                        case EQUAL: result->type = BOOL; result->boolVal = rval == lval; break;
                        case NEQ: result->type = BOOL; result->boolVal = rval != lval; break;
                        default: cout << "OPERATION NOT IMPLEMENTED";
                    }}
                    break;
                default:
                    cout << "OPERATION NOT POSSIBLE";
            }
            break;
        case BOOL:
            switch(right_t) {
                case BOOL:
                    {bool lval = left->intVal;
                    bool rval = right->intVal;
                    switch(optor) {
                        case AND: result->type = BOOL; result->boolVal = lval && rval; break;
                        case OR: result->type = BOOL; result->boolVal = lval || rval; break;
                        case XOR: result->type = BOOL; result->boolVal = (!lval != !rval); break;
                        case NEQ: result->type = BOOL; result->boolVal = (lval != rval); break;
                        case EQUAL: result->type = BOOL; result->boolVal = (lval == rval); break;
                        default: cout << "OPERATION NOT IMPLEMENTED";
                    }} break;
                default:
                    cout << "OPERATION NOT POSSIBLE";
            }
            break;
        case ARRAY:
            switch(right_t) {
                case ARRAY:
                    break;
                default:
                    cout << "OPERATION NOT POSSIBLE";
            }
            break;
        case TUPLE:
            switch(right_t) {
                case ARRAY:
                    break;
                default:
                    cout << "OPERATION NOT POSSIBLE";
            }
            break;
        case STRING:
            if (right_t == STRING ){
                string lval = *(left->stringVAl);
                string rval = *(right->stringVAl);
                switch(optor) {
                    case PLUS: 
                        result->type = STRING;
                        result->stringVAl = new string(lval + rval); 
                        break;
                    default: 
                        cout << "OPERATION NOT IMPLEMENTED";
                        break;
                }
            }
            else{
                cout << "\nILLEGEAL OPERATION ON STRING\n";
            }
            break;
        default: cout << "\nOPERATION ON THIS TYPE NOT IMPLEMENTED\n";
    }
    return result;
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
    // complex_t * value = create_type();


    return evaluate_expression(left, op, right);
}
#undef THING