#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Node;
class NProgram;

class NInstruction;
class NBlock;


class NDeclaration;
class NArray;
class NTuple;


class NStatement;
class NAssignment;
class NPrint;
class NFunctionDefinition;
class NParameters;
class NIf;
class NIfElse;
class NLoop;
class NRangeLoop;
class NReturn;

class NExpression;
class NIdentifier;
class NIntegerLiteral;
class NReal;
class NBool;
class NStringLiteral;
class NBinaryOperator;
class NTypeCheck;
class NUnary;
class NReadInput;

class Visitor
{
public:
    virtual int visit(NProgram *) = 0;
    virtual int visit(NBlock *) = 0;
    virtual int visit(NDeclaration *) = 0;

    virtual int visit(NArray *) = 0;
    virtual int visit(NTuple *) = 0;
    virtual int visit(NStatement *) = 0;
    virtual int visit(NAssignment *) = 0;
    virtual int visit(NPrint *) = 0;
    virtual int visit(NFunctionDefinition *) = 0;
    virtual int visit(NParameters *) = 0;
    virtual int visit(NIf *) = 0;
    virtual int visit(NIfElse *) = 0;
    virtual int visit(NLoop *) = 0;
    virtual int visit(NRangeLoop *) = 0;
    virtual int visit(NReturn *) = 0;
    virtual int visit(NExpression *) = 0;
    virtual int visit(NIdentifier *) = 0;

    virtual int visit(NIntegerLiteral *) = 0;
    virtual int visit(NReal *) = 0;

    virtual int visit(NBool *) = 0;
    virtual int visit(NStringLiteral *) = 0;
    virtual int visit(NBinaryOperator *) = 0;
    virtual int visit(NTypeCheck *) = 0;
    virtual int visit(NUnary *) = 0;
    virtual int visit(NReadInput *) = 0;
};


class Node {
public:
    virtual int accept(Visitor &) = 0;
};

class NProgram : public Node {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    int accept(Visitor &);
};

class NInstruction : public Node {
};

class NBlock : public NInstruction {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    vector<NInstruction *> instructions;
    void push_back(NInstruction *instruction);
    int accept(Visitor &);
};

class NExpression : public NInstruction {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NExpression();
    int accept(Visitor &);
};

class NStatement : public NInstruction {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NStatement();
    int accept(Visitor &);
};

class NDeclaration : public NInstruction {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    string *identifier;
    NExpression *assignmentExpr = nullptr;
    NDeclaration(string *id);
    NDeclaration(string *id, NExpression *assignmentExpr);
    int accept(Visitor &);
};

class NIdentifier : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    string *name;
    NIdentifier(string *name) : name(name) {}
    int accept(Visitor &);
};


class NIntegerLiteral : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    long long value;
    NIntegerLiteral(long long value) : value(value) { }
    int accept(Visitor &);
};

class NReal : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    double value;
    NReal(double value) : value(value) { }
    int accept(Visitor &);
};

class NBool : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    string *text;
    NBool(string *text) : text(text) { }
    int accept(Visitor &);
};

class NStringLiteral : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    string *text;
    NStringLiteral(string *text){ }
    int accept(Visitor &);
};

class NBinaryOperator : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    int op;
    NExpression *lhs;
    NExpression *rhs;
    NBinaryOperator(NExpression *lhs, int op, NExpression *rhs) :
        lhs(lhs), rhs(rhs), op(op) { }
    int accept(Visitor &);
};

//Done
class NAssignment : public NStatement {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NExpression *identifier;
    NExpression *expression;
    NAssignment(NExpression *identifier, NExpression *expression);
    int accept(Visitor &);
};

// struct print_t
// {
//     NStringLiteral *string_literal;
//     NExpression *expression;
// };

//Done
class NPrint : public NStatement {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    vector<NExpression *> expressions;
    void push_back(NExpression *expression);
    int accept(Visitor &);
};

class NFunctionDefinition : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NParameters *arguments;
    NBlock *block = nullptr;
    NExpression *expression = nullptr;
    void setBody(NBlock *block);
    void setExpression(NExpression *expression);
    void setParameters(NParameters *arguments);
    int accept(Visitor &);
};

class NParameters : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    vector<NIdentifier *> arguments;
    void push_parameter(NIdentifier * argument);
    int accept(Visitor &);
};

//Done
class NIf : public NStatement {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NBlock *ifblock;
    NExpression *condition;
    NIf(NExpression *condition, NBlock *ifblock);
    int accept(Visitor &);
};

class NIfElse : public NStatement {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NBlock *ifblock;
    NBlock *elseblock;
    NExpression *condition;
    NIfElse(NExpression *condition, NBlock *ifblock, NBlock *elseblock);
    int accept(Visitor &);
};


class NLoop : public NStatement {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NBlock *block;
    NExpression *condition;
    NLoop(NExpression *condition, NBlock *block);
    int accept(Visitor &);
};

class NRangeLoop : public NStatement {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NBlock *block;
    NIdentifier *id;
    NExpression *from;
    NExpression *to;
    NRangeLoop(NIdentifier *id, NExpression *from, NExpression *to, NBlock *block);
    int accept(Visitor &);
};

class NTypeCheck : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    int op;
    NExpression *primary;
    string *type;
    NTypeCheck(int op, NExpression *expression, string *type) : 
        op(op), primary(expression), type(type) {}
    NTypeCheck(NExpression *expression, string *type) : 
        primary(expression), type(type) {}
    int accept(Visitor &);
};

class NArray : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NArray() {}
    int accept(Visitor &);
};

class NTuple : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NTuple(){}
    int accept(Visitor &);
};

class NReturn : public NStatement {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NExpression *expression = nullptr;
    NReturn(NExpression *expression);
    NReturn(){}
    int accept(Visitor &);
};

class NUnary : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    int op;
    NExpression *expression;
    NUnary(int op, NExpression *expression) : op(op), expression(expression) {}
    int accept(Visitor &);
};

class NReadInput : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NReadInput() {}
    int accept(Visitor &);
};


#include "traverse.h"
#include "evaluate.h"