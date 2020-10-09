#include "ast_nodes.h"

#define DO_THING(complex, THING) \
switch( complex->type ){ \
case INTEGER: THING(complex->intVal); break;\
case FLOAT:   THING(complex->floatVal); break;\
case STRING:  THING(*(complex->stringVAl)); break;\
case BOOL:    THING(complex->boolVal); break;\
case ARRAY: cout << "\nARRAYS :- not implemented??\n"; exit(228); break;\
case TUPLE: cout << "\nTUPLE :- not implemented??\n";  exit(228);break;\
case EMPTY: cout << "\nEMPTY :- not implemented??\n";  exit(228);break;\
default: cout << "\nEMPTY :- not implemented??\n";\
}\

#define DO_THING_NUM(complex, THING) \
switch( complex->type ){ \
case INTEGER: THING(complex->intVal); break;\
case FLOAT:   THING(complex->floatVal); break;\
case BOOL:    THING(complex->boolVal); break;\
default: cout << "\nEMPTY :- not implemented??\n";\
}\


string type_name(complex_t complex){
    switch( complex.type ){
        case INTEGER: 
            return "INTEGER"; 
        case FLOAT: 
            return "FLOAT";
        case STRING: 
            return "STRING"; 
        case BOOL: 
            return "BOOL";
        case ARRAY: 
            return "ARRAY";
        case TUPLE: 
            return "TUPLE"; 
        default:
            return "EMPTY";
    }
}

complex_t *create_type () {
    return (complex_t *)malloc(sizeof(complex_t));
}

//Program
complex_t * NProgram::accept(Visitor &v) {
    return v.visit(this);
}


//Block
void NBlock::push_back(NInstruction *instruction) {
    instructions.insert(instructions.begin(),instruction);
    // instructions.push_back(instruction);
}

complex_t * NBlock::accept(Visitor &v) {
    return v.visit(this);
}


//Assignment
NAssignment::NAssignment(NExpression *identifier, NExpression *expression) {
    this->identifier = identifier;
    this->expression = expression;
}

complex_t * NAssignment::accept(Visitor &v) {
    return v.visit(this);
}


//Print
complex_t * NPrint::accept(Visitor &v) {
    return v.visit(this);
}


//If - IfElse
NIf::NIf(NExpression *condition, NBlock *ifblock) {
    this->condition = condition;
    this->ifblock = ifblock;
}

complex_t * NIf::accept(Visitor &v) {
    return v.visit(this);
}

NIfElse::NIfElse(NExpression *condition, NBlock *ifblock, NBlock *elseblock) {
    this->condition = condition;
    this->ifblock = ifblock;
    this->elseblock = elseblock;
}

complex_t * NIfElse::accept(Visitor &v) {
    return v.visit(this);
}


//Loop
NLoop::NLoop(NExpression *condition, NBlock *block) {
    this->condition = condition;
    this->block = block;
}

complex_t * NLoop::accept(Visitor &v) {
    return v.visit(this);
}

NRangeLoop::NRangeLoop(NIdentifier *id, NExpression *from, NExpression *to, NBlock *block) {
    this->id = id;
    this->from = from;
    this->to = to;
    this->block = block;
}

complex_t * NRangeLoop::accept(Visitor &v) {
    return v.visit(this);
}

//Declaration
NDeclaration::NDeclaration(NIdentifier *id) {
    this->identifier = id;
}

NDeclaration::NDeclaration(NIdentifier *id, NExpression *assignmentExpr) {
    this->identifier = id;
    this->assignmentExpr = assignmentExpr;
}

complex_t * NDeclaration::accept(Visitor &v) {
    return v.visit(this);
}


//Return
NReturn::NReturn(NExpression *expression) {
    this->expression = expression;
}

complex_t * NReturn::accept(Visitor &v) {
    return v.visit(this);
}


//Expression
NExpression::NExpression() {
}

complex_t * NExpression::accept(Visitor &v) {
    return v.visit(this);
}



//Statement
NStatement::NStatement(){
}
complex_t * NStatement::accept(Visitor &v) {
    return v.visit(this);
}


//Identifier
NIdentifier::NIdentifier(string *name){
    // this->type = string("empty");
    this->name = name;
}
complex_t * NIdentifier::accept(Visitor &v) {
    return v.visit(this);
}



//IntegerLiteral
NIntegerLiteral::NIntegerLiteral(long long value) {
    this->value = value;
}
complex_t * NIntegerLiteral::accept(Visitor &v) {
    return v.visit(this);
}


//Real
complex_t * NReal::accept(Visitor &v) {
    return v.visit(this);
}



//Bool
 NBool::NBool(string *text){
    this->text = text;
    string str = *text;
    if (!str.compare("true"))
        this->value = true;
 }
complex_t * NBool::accept(Visitor &v) {
    return v.visit(this);
}



//StringLiteral
complex_t * NStringLiteral::accept(Visitor &v) {
    return v.visit(this);
}



//BinaryOperator
complex_t * NBinaryOperator::accept(Visitor &v) {
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
complex_t * NFunctionDefinition::accept(Visitor &v) {
    return v.visit(this);
}


//FunctionCall
complex_t * NFunctionCall::accept(Visitor &v) {
    return v.visit(this);
}

//Parameters
void NParameters::push_parameter(NIdentifier * argument) {
    this->arguments.push_back(argument);
}
complex_t * NParameters::accept(Visitor &v) {
    return v.visit(this);
}

//Expressions
void NExpressions::push_argument(NExpression * argument) {
    this->expressions.insert(this->expressions.begin(), argument);
}

complex_t * NExpressions::accept(Visitor &v) {
    return v.visit(this);
}



//TypeCheck
complex_t * NTypeCheck::accept(Visitor &v) {
    return v.visit(this);
}


//Array
complex_t * NArray::accept(Visitor &v) {
    return v.visit(this);
}


//Tuple
complex_t * NTuple::accept(Visitor &v) {
    return v.visit(this);
}


//Unary
complex_t * NUnary::accept(Visitor &v) {
    return v.visit(this);
}

//ReadInput
complex_t * NReadIntInput::accept(Visitor &v) {
    return v.visit(this);
}

//ReadInput
complex_t * NReadRealInput::accept(Visitor &v) {
    return v.visit(this);
}

//ReadInput
complex_t * NReadStringInput::accept(Visitor &v) {
    return v.visit(this);
}

#include "traverse.cpp"
#include "evaluate.cpp"