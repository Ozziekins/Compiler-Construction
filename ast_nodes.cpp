#include "ast_nodes.h"

//Program
int NProgram::accept(Visitor &v) {
    return v.visit(this);
}


//Block
void NBlock::push_back(NInstruction *instruction) {
    instructions.push_back(instruction);
}

int NBlock::accept(Visitor &v) {
    return v.visit(this);
}


//Assignment
NAssignment::NAssignment(NExpression *identifier, NExpression *expression) {
    this->identifier = identifier;
    this->expression = expression;
}

int NAssignment::accept(Visitor &v) {
    return v.visit(this);
}


//Print
void NPrint::push_back(NExpression *expression) {
    expressions.push_back(expression);
}

int NPrint::accept(Visitor &v) {
    return v.visit(this);
}


//If - IfElse
NIf::NIf(NExpression *condition, NBlock *ifblock) {
    this->condition = condition;
    this->ifblock = ifblock;
}

int NIf::accept(Visitor &v) {
    return v.visit(this);
}

NIfElse::NIfElse(NExpression *condition, NBlock *ifblock, NBlock *elseblock) {
    this->condition = condition;
    this->ifblock = ifblock;
    this->elseblock = elseblock;
}

int NIfElse::accept(Visitor &v) {
    return v.visit(this);
}


//Loop
NLoop::NLoop(NExpression *condition, NBlock *block) {
    this->condition = condition;
    this->block = block;
}

int NLoop::accept(Visitor &v) {
    return v.visit(this);
}

NRangeLoop::NRangeLoop(NIdentifier *id, NExpression *from, NExpression *to, NBlock *block) {
    this->id = id;
    this->from = from;
    this->to = to;
    this->block = block;
}

int NRangeLoop::accept(Visitor &v) {
    return v.visit(this);
}

//Declaration
NDeclaration::NDeclaration(string *id) {
    this->identifier = id;
}

NDeclaration::NDeclaration(string *id, NExpression *assignmentExpr) {
    this->identifier = id;
    this->assignmentExpr = assignmentExpr;
}

int NDeclaration::accept(Visitor &v) {
    return v.visit(this);
}


//Return
NReturn::NReturn(NExpression *expression) {
    this->expression = expression;
}

int NReturn::accept(Visitor &v) {
    return v.visit(this);
}


//Expression
NExpression::NExpression() {
}

int NExpression::accept(Visitor &v) {
    return v.visit(this);
}



//Statement
NStatement::NStatement(){
}
int NStatement::accept(Visitor &v) {
    return v.visit(this);
}


//Identifier
int NIdentifier::accept(Visitor &v) {
    return v.visit(this);
}



//IntegerLiteral
int NIntegerLiteral::accept(Visitor &v) {
    return v.visit(this);
}


//Real
int NReal::accept(Visitor &v) {
    return v.visit(this);
}



//Bool
int NBool::accept(Visitor &v) {
    return v.visit(this);
}



//StringLiteral
int NStringLiteral::accept(Visitor &v) {
    return v.visit(this);
}



//BinaryOperator
int NBinaryOperator::accept(Visitor &v) {
    return v.visit(this);
}



//FunctionDefinition
void NFunctionDefinition::setBody(NBlock *block) {
    this->block = block;
}
void NFunctionDefinition::setExpression(NExpression *expression) {
    this->expression = expression;
}
void NFunctionDefinition::setParameters(NParameters *arguments) {
    this->arguments = arguments;
}
int NFunctionDefinition::accept(Visitor &v) {
    return v.visit(this);
}



//Parameters
void NParameters::push_parameter(NIdentifier * argument) {
    this->arguments.push_back(argument);
}
int NParameters::accept(Visitor &v) {
    return v.visit(this);
}



//TypeCheck
int NTypeCheck::accept(Visitor &v) {
    return v.visit(this);
}


//Array
int NArray::accept(Visitor &v) {
    return v.visit(this);
}


//Tuple
int NTuple::accept(Visitor &v) {
    return v.visit(this);
}


//Unary
int NUnary::accept(Visitor &v) {
    return v.visit(this);
}

//ReadInput
int NReadInput::accept(Visitor &v) {
    return v.visit(this);
}


#include "traverse.cpp"
#include "evaluate.cpp"