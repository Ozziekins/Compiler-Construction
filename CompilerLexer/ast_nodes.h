#pragma once
#include <iostream>
#include <vector>

class Node {
public:
    virtual ~Node() {}
};

class NExpression : public Node {
public:
    NExpression() { }
};

class NStatement : public Node {
public:
    NStatement() {}
};
class NDeclaration : public Node {
public:
    std::string identifier;
    NExpression *assignmentExpr;
    NDeclaration(const std::string& id) : identifier(id) { }
    NDeclaration(const std::string& id, NExpression *assignmentExpr) :
        identifier(id), assignmentExpr(assignmentExpr) { }
};

class NIdentifier : public NExpression {
public:
    std::string name;
    NIdentifier(const std::string& name) : name(name) {}
};

typedef std::vector<NStatement*> StatementList;
typedef std::vector<NExpression*> ExpressionList;
typedef std::vector<NDeclaration*> DeclarationList;
typedef std::vector<NIdentifier*> ParameterList;



class NInteger : public NExpression {
public:
    long long value;
    NInteger(long long value) : value(value) { }
};

class NReal : public NExpression {
public:
    double value;
    NReal(double value) : value(value) { }
};

class NBool : public NExpression {
public:
    std::string text;
    NBool(const std::string& text) : text(text) { }
};

class NString : public NExpression {
public:
    std::string text;
    NString(const std::string& text) : text(text) { }
};

class NBlock : public NStatement {
public:
    StatementList statements;
    DeclarationList declarations;
    NBlock() { }
};

class NBinaryOperator : public NExpression {
public:
    int op;
    NExpression& lhs;
    NExpression& rhs;
    NBinaryOperator(NExpression& lhs, int op, NExpression& rhs) :
        lhs(lhs), rhs(rhs), op(op) { }
};

class NAssignment : public NStatement {
public:
    NExpression& lhs;
    NExpression& rhs;
    NAssignment(NExpression& lhs, NExpression& rhs) : 
        lhs(lhs), rhs(rhs) { }
};

class NPrint : public NStatement {
public:
    ExpressionList expressions;
    NPrint(ExpressionList& list_expression) : expressions(list_expression) {}
};

class NFunctionDefinition : public NExpression {
public:
    ParameterList arguments;
    NBlock block;
    NExpression expression;
    NFunctionDefinition(NBlock& block) :
        block(block) { }
    NFunctionDefinition(NExpression& expression) :
        expression(expression) { }
    NFunctionDefinition(const ParameterList& arguments, NBlock& block) :
        arguments(arguments), block(block) { }
    NFunctionDefinition(const ParameterList& arguments, NExpression& expression) :
        arguments(arguments), expression(expression) { }
};

class NIf : public NStatement {
public:
    NBlock iblock;
    NBlock eblock;
    NExpression condition;
    NIf(NExpression& condition, NBlock& iblock, NBlock& eblock) :
        condition(condition), iblock(iblock), eblock(eblock) { }
    NIf(NExpression& condition, NBlock& iblock) :
        condition(condition), iblock(iblock) { }
};

class NLoop : public NStatement {
public:
    NBlock& block;
    NExpression condition;
    NLoop(NExpression& condition, NBlock& block) :
        condition(condition), block(block) { }
};

class NTypeCheck : public NExpression {
public:
    int op;
    NExpression& primary;
    std::string type;
    NTypeCheck(int op, NExpression& expression, const std::string& type) : 
        op(op), primary(expression), type(type) {}
    NTypeCheck(NExpression& expression, const std::string& type) : 
        primary(expression), type(type) {}
};

class NArray : public NExpression {
public:
    NArray() {}
};

class NTuple : public NExpression {
public:
    NTuple(){}
};

class NReturn : public NStatement {
public:
    NExpression expression;
    NReturn(NExpression& expression) : expression(expression) {}
    NReturn(){}
};

class NUnary : public NExpression {
public:
    int op;
    NExpression expression;
    NUnary(int op, NExpression& expression) : op(op), expression(expression) {}
};

class NReadInput : public NExpression {
public:
    NReadInput() {}
};