complex_t *Traverse::visit(NProgram *program){
    cout << "Program" << endl;
    return nullptr;
}

complex_t *Traverse::visit(NBlock *block){
    cout << "NBlock" << endl;
    for(int i = 0; i < (int)block->instructions.size(); i++) {
        block->instructions[i]->accept(*this);
    }

    return nullptr;
}

complex_t *Traverse::visit(NDeclaration *decl){
    cout << "NDeclaration" << endl;
    if (decl->assignmentExpr) {
        decl->assignmentExpr->accept(*this);
    }
    return nullptr;
}


complex_t *Traverse::visit(NArray *){
    cout << "NArray" << endl;
    return nullptr;
}

complex_t *Traverse::visit(NTuple *){
    cout << "NTuple" << endl;
    return nullptr;
}

complex_t *Traverse::visit(NStatement *stmt){
    cout << "NStatement" << endl;
    return nullptr;
}

complex_t *Traverse::visit(NAssignment *assignmnt){
    cout << "NAssignment" << endl;
    assignmnt->identifier->accept(*this);
    assignmnt->expression->accept(*this);
    return nullptr;
}

complex_t *Traverse::visit(NPrint *print){
    cout << "NPrint" << endl;
    for(int i = 0; i < (int)print->expressions.size(); i++)
        print->expressions[i]->accept(*this);
    return nullptr;
}

complex_t *Traverse::visit(NFunctionDefinition *funcdef){
    cout << "NFunctionDefinition" << endl;
    funcdef->arguments->accept(*this);
    if (funcdef->block)
        funcdef->block->accept(*this);
    if (funcdef->expression)
        funcdef->expression->accept(*this);
    return nullptr;
}

complex_t *Traverse::visit(NParameters *params) {
    cout << "NParameter" << endl;
    for(int i = 0; i < (int)params->arguments.size(); i++)
        params->arguments[i]->accept(*this);
    return nullptr;
}

complex_t *Traverse::visit(NIf *ifstmt){
    cout << "NIf" << endl;
    ifstmt->condition->accept(*this);
    ifstmt->ifblock->accept(*this);
    return nullptr;
}

complex_t *Traverse::visit(NIfElse *ifstmt){
    cout << "NIfElse" << endl;
    ifstmt->condition->accept(*this);
    ifstmt->ifblock->accept(*this);
    ifstmt->elseblock->accept(*this);
    return nullptr;
}

complex_t *Traverse::visit(NLoop *loop){
    cout << "NLoop" << endl;
    loop->condition->accept(*this);
    loop->block->accept(*this);
    return nullptr;
}

complex_t *Traverse::visit(NRangeLoop *loop){
    cout << "NRangeLoop" << endl;
    loop->id->accept(*this);
    loop->from->accept(*this);
    loop->to->accept(*this);
    loop->block->accept(*this);
    return nullptr;
}

complex_t *Traverse::visit(NReturn *retstmt){
    cout << "NReturn" << endl;
    retstmt->expression->accept(*this);
    return nullptr;
}

complex_t *Traverse::visit(NExpression *){
    cout << "NExpression" << endl;
    return nullptr;
}

complex_t *Traverse::visit(NIdentifier *id){
    cout << "NIdentifier" << endl;
    cout << *(id->name) << endl;
    return nullptr;
}


complex_t *Traverse::visit(NIntegerLiteral *intlit){
    cout << "NIntegerLiteral" << endl;
    cout << intlit->value << endl;
    return nullptr;
}

complex_t *Traverse::visit(NReal *){
    cout << "NReal" << endl;
    return nullptr;
}


complex_t *Traverse::visit(NBool *){
    cout << "NBool" << endl;
    return nullptr;
}

complex_t *Traverse::visit(NStringLiteral *){
    cout << "NStringLiteral" << endl;
    return nullptr;
}

complex_t *Traverse::visit(NBinaryOperator *bin_op){
    cout << "NBinaryOperator" << endl;
    bin_op->lhs->accept(*this);
    bin_op->rhs->accept(*this);
    return nullptr;
}

complex_t *Traverse::visit(NTypeCheck *){
    cout << "NTypeCheck" << endl;
    return nullptr;
}

complex_t *Traverse::visit(NUnary *){
    cout << "NUnary" << endl;
    return nullptr;
}

complex_t *Traverse::visit(NReadIntInput *){
    cout << "NReadInput" << endl;
    return nullptr;
}

complex_t *Traverse::visit(NReadRealInput *){
    cout << "NReadRealInput" << endl;
    return nullptr;
}

complex_t *Traverse::visit(NReadStringInput *){
    cout << "NReadStringInput" << endl;
    return nullptr;
}