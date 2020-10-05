
// A very bad move from me to declare such a global variable
bool DEBUG = true;

void print_symbol_table(map<NIdentifier *, complex_t *> SymbolTable) {
    cout << "\n _____ SYMBOLTABLE ________\n";
    for (const auto& x : SymbolTable) {
        cout << "| " << type_name(*x.second) << "\n";

        if (!string(type_name(*x.second)).compare("STRING"))
            cout << "| " << *x.first->name << "= " << *(x.second->stringVAl) << endl << "| " << endl;
        else if (!string(type_name(*x.second)).compare("INTEGER"))
            cout << "| " << *x.first->name << "= " << x.second->intVal << endl << "| " << endl;
        else if (!string(type_name(*x.second)).compare("FLOAT"))
            cout << "| " << *x.first->name << "= " << x.second->floatVal << endl << "| " << endl;
        
        
        else if (!string(type_name(*x.second)).compare("EMPTY"))
            cout << "| " << *x.first->name << "= " << *(x.second->stringVAl) << endl << "| " << endl;
        else cout << "\n STRANGE TYPE ENCOUTERED !!!! \n";
        //TODO ADD OTHER ONES!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    cout << "|__________________________\n\n";
    
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
    NIdentifier* ident_name = decl->identifier;
    if (DEBUG) cout << "of variable [" << *ident_name->name << "] : ";

    //initialize symbol table with corresponding types
    complex_t *value = nullptr;
    if (decl->assignmentExpr){
        value = decl->assignmentExpr->accept(*this);
        ident_name->type = string(type_name(*value));
    }
    else { //TODO NOW EMPTY HAS VALUE eMpTy; IS IT OK?
        value = create_type();
        value->type = EMPTY;
        value->stringVAl = new string("eMpTy");
    }
    SymbolTable.insert({ident_name, value});
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
    cout << "NAssignment" << endl;
    assignmnt->identifier->accept(*this);
    assignmnt->expression->accept(*this);
    return nullptr;
}

complex_t *Evaluate::visit(NPrint *print){
    cout << "NPrint" << endl;
    for(int i = 0; i < (int)print->expressions.size(); i++)
        print->expressions[i]->accept(*this);
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
    cout << "NIdentifier" << endl;
    cout << *(id->name) << endl;
    return nullptr;
}


complex_t *Evaluate::visit(NIntegerLiteral *intlit){
    cout << "NIntegerLiteral {" << intlit->value << "}" << endl;
    complex_t * ival = create_type();
    ival->type = INTEGER;
    ival->intVal = intlit->value;
    return ival;
}

complex_t *Evaluate::visit(NReal *reallit){
    cout << "NReal" << endl;
    complex_t * fval = create_type();
    fval->type = FLOAT;
    fval->floatVal = reallit->value;
    return fval;
}


complex_t *Evaluate::visit(NBool *blit){
    cout << "NBool" << endl;
    complex_t * bval = create_type();
    bval->type = BOOL;
    bval->boolVAl = blit->value;
    return bval;
}

complex_t *Evaluate::visit(NStringLiteral *slit){
    cout << "NStringLiteral" << endl;
    complex_t * sval = create_type();
    sval->type = STRING;
    sval->stringVAl = slit->text;
    return sval;
}

complex_t *Evaluate::visit(NBinaryOperator *bin_op){
    cout << "NBinaryOperator" << endl;
    auto op = bin_op->op;
    auto left = bin_op->lhs->accept(*this);
    auto right = bin_op->rhs->accept(*this);

    // int result;
    // if(op == 1) result = left + right;
    // else if(op == 2) result = left - right;
    // else if(op == 3) result = left * right;
    // else if(op == 4) result = left / right;
    // else if(op == 5) result = left < right;
    // else if(op == 6) result = left > right;
    // else if(op == 7) result = left <= right;
    // else if(op == 8) result = left >= right;
    // else if(op == 9) result = left == right;
    // else if(op == 10) result = left != right;
    // else if(op == 11) result = left && right;
    // else if(op == 12) result = left || right;
    // else if(op == 13) result = left ^ right;
    return nullptr;
}

complex_t *Evaluate::visit(NTypeCheck *){
    cout << "NTypeCheck" << endl;
    return nullptr;
}

complex_t *Evaluate::visit(NUnary *){
    cout << "NUnary" << endl;
    return nullptr;
}

complex_t *Evaluate::visit(NReadInput *){
    cout << "NReadInput" << endl;
    return nullptr;
}
