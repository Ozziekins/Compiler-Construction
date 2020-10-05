#pragma once
#include <iostream>
#include <vector>

using namespace std;

typedef enum types { INTEGER = 0, FLOAT, STRING, BOOL, ARRAY, TUPLE } type_t;
typedef struct complexTypes complex_t;

struct complexTypes{
    type_t type;
    union {
        int intVal;
        float floatVal;
        string *stringVAl;
        bool boolVAl;
        vector<complex_t> *arrayVal;
        vector<pair<string, complex_t>> *tupleVal;
    };
};

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
    virtual complex_t *visit(NProgram *) = 0;
    virtual complex_t *visit(NBlock *) = 0;
    virtual complex_t *visit(NDeclaration *) = 0;

    virtual complex_t *visit(NArray *) = 0;
    virtual complex_t *visit(NTuple *) = 0;
    virtual complex_t *visit(NStatement *) = 0;
    virtual complex_t *visit(NAssignment *) = 0;
    virtual complex_t *visit(NPrint *) = 0;
    virtual complex_t *visit(NFunctionDefinition *) = 0;
    virtual complex_t *visit(NParameters *) = 0;
    virtual complex_t *visit(NIf *) = 0;
    virtual complex_t *visit(NIfElse *) = 0;
    virtual complex_t *visit(NLoop *) = 0;
    virtual complex_t *visit(NRangeLoop *) = 0;
    virtual complex_t *visit(NReturn *) = 0;
    virtual complex_t *visit(NExpression *) = 0;
    virtual complex_t *visit(NIdentifier *) = 0;

    virtual complex_t *visit(NIntegerLiteral *) = 0;
    virtual complex_t *visit(NReal *) = 0;

    virtual complex_t *visit(NBool *) = 0;
    virtual complex_t *visit(NStringLiteral *) = 0;
    virtual complex_t *visit(NBinaryOperator *) = 0;
    virtual complex_t *visit(NTypeCheck *) = 0;
    virtual complex_t *visit(NUnary *) = 0;
    virtual complex_t *visit(NReadInput *) = 0;
};


class Node {
public:
    virtual complex_t *accept(Visitor &) = 0;
};

class NProgram : public Node {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    complex_t *accept(Visitor &);
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
    complex_t *accept(Visitor &);
};

class NExpression : public NInstruction {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NExpression();
    complex_t *accept(Visitor &);
};

class NStatement : public NInstruction {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NStatement();
    complex_t *accept(Visitor &);
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
    complex_t *accept(Visitor &);
};

class NIdentifier : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    string type = string("empty");
    string *name;
    NIdentifier(string *name);
    complex_t *accept(Visitor &);
};


class NIntegerLiteral : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    long long value;
    NIntegerLiteral(long long value);
    complex_t *accept(Visitor &);
};

class NReal : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    double value;
    NReal(double value) : value(value) { }
    complex_t *accept(Visitor &);
};

class NBool : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    string *text;
    NBool(string *text) : text(text) { }
    complex_t *accept(Visitor &);
};

class NStringLiteral : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    string *text;
    NStringLiteral(string *text){ }
    complex_t *accept(Visitor &);
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
    complex_t *accept(Visitor &);
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
    complex_t *accept(Visitor &);
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
    complex_t *accept(Visitor &);
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
    complex_t *accept(Visitor &);
};

class NParameters : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    vector<NIdentifier *> arguments;
    void push_parameter(NIdentifier * argument);
    complex_t *accept(Visitor &);
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
    complex_t *accept(Visitor &);
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
    complex_t *accept(Visitor &);
};


class NLoop : public NStatement {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NBlock *block;
    NExpression *condition;
    NLoop(NExpression *condition, NBlock *block);
    complex_t *accept(Visitor &);
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
    complex_t *accept(Visitor &);
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
    complex_t *accept(Visitor &);
};

class NArray : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NArray() {}
    complex_t *accept(Visitor &);
};

class NTuple : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NTuple(){}
    complex_t *accept(Visitor &);
};

class NReturn : public NStatement {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NExpression *expression = nullptr;
    NReturn(NExpression *expression);
    NReturn(){}
    complex_t *accept(Visitor &);
};

class NUnary : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    int op;
    NExpression *expression;
    NUnary(int op, NExpression *expression) : op(op), expression(expression) {}
    complex_t *accept(Visitor &);
};

class NReadInput : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NReadInput() {}
    complex_t *accept(Visitor &);
};


#include "traverse.h"
#include "evaluate.h"