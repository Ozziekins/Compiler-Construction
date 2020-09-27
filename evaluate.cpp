int Evaluate::visit(NProgram *program){
    cout << "Program" << endl;
    return 0;
}

int Evaluate::visit(NBlock *block){
    cout << "NBlock" << endl;
    for(int i = 0; i < (int)block->instructions.size(); i++) {
        block->instructions[i]->accept(*this);
    }

    return 0;
}

int Evaluate::visit(NDeclaration *decl){
    cout << "NDeclaration" << endl;
    cout << *(decl->identifier) << endl;
    if (decl->assignmentExpr) {
        decl->assignmentExpr->accept(*this);
    }
    return 0;
}


int Evaluate::visit(NArray *){
    cout << "NArray" << endl;
    return 0;
}

int Evaluate::visit(NTuple *){
    cout << "NTuple" << endl;
    return 0;
}

int Evaluate::visit(NStatement *stmt){
    cout << "NStatement" << endl;
    return 0;
}

int Evaluate::visit(NAssignment *assignmnt){
    cout << "NAssignment" << endl;
    assignmnt->identifier->accept(*this);
    assignmnt->expression->accept(*this);
    return 0;
}

int Evaluate::visit(NPrint *print){
    cout << "NPrint" << endl;
    for(int i = 0; i < (int)print->expressions.size(); i++)
        print->expressions[i]->accept(*this);
    return 0;
}

int Evaluate::visit(NFunctionDefinition *funcdef){
    cout << "NFunctionDefinition" << endl;
    funcdef->arguments->accept(*this);
    if (funcdef->block)
        funcdef->block->accept(*this);
    if (funcdef->expression)
        funcdef->expression->accept(*this);
    return 0;
}

int Evaluate::visit(NParameters *params) {
    cout << "NParameter" << endl;
    for(int i = 0; i < (int)params->arguments.size(); i++)
        params->arguments[i]->accept(*this);
    return 0;
}

int Evaluate::visit(NIf *ifstmt){
    cout << "NIf" << endl;
    ifstmt->condition->accept(*this);
    ifstmt->ifblock->accept(*this);
    return 0;
}

int Evaluate::visit(NIfElse *ifstmt){
    cout << "NIfElse" << endl;
    ifstmt->condition->accept(*this);
    ifstmt->ifblock->accept(*this);
    ifstmt->elseblock->accept(*this);
    return 0;
}

int Evaluate::visit(NLoop *loop){
    cout << "NLoop" << endl;
    loop->condition->accept(*this);
    loop->block->accept(*this);
    return 0;
}

int Evaluate::visit(NReturn *retstmt){
    cout << "NReturn" << endl;
    retstmt->expression->accept(*this);
    return 0;
}

int Evaluate::visit(NExpression *){
    cout << "NExpression" << endl;
    return 0;
}

int Evaluate::visit(NIdentifier *id){
    cout << "NIdentifier" << endl;
    cout << *(id->name) << endl;
    return 0;
}


int Evaluate::visit(NIntegerLiteral *intlit){
    cout << "NIntegerLiteral" << endl;
    cout << intlit->value << endl;
    return 0;
}

int Evaluate::visit(NReal *){
    cout << "NReal" << endl;
    return 0;
}


int Evaluate::visit(NBool *){
    cout << "NBool" << endl;
    return 0;
}

int Evaluate::visit(NStringLiteral *){
    cout << "NStringLiteral" << endl;
    return 0;
}

int Evaluate::visit(NBinaryOperator *bin_op){
    cout << "NBinaryOperator" << endl;
    bin_op->lhs->accept(*this);
    bin_op->rhs->accept(*this);
    return 0;
}

int Evaluate::visit(NTypeCheck *){
    cout << "NTypeCheck" << endl;
    return 0;
}

int Evaluate::visit(NUnary *){
    cout << "NUnary" << endl;
    return 0;
}

int Evaluate::visit(NReadInput *){
    cout << "NReadInput" << endl;
    return 0;
}
