#pragma once
#include <iostream>
#include <vector>

using namespace std;

// ADDED EMPTY AS -1
typedef enum types { EMPTY = -1, INTEGER = 0, FLOAT, STRING, BOOL, ARRAY, TUPLE } type_t;
typedef enum Operators {PLUS = 1, MINUS, MULT, DIV, LESS, GREAT, LEQ, GEQ, EQUAL, NEQ, AND, OR, XOR, NOT } Operators;
typedef struct complexTypes complex_t;

struct complexTypes{
    type_t type;
    union {
        int intVal;
        float floatVal;
        string *stringVAl;
        bool boolVal;
        vector<pair<int, complex_t*>> *arrayVal;
        vector<pair<string, complex_t*>> *tupleVal;
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
class NTAssignments;
class NPrint;
class NFunctionDefinition;
class NFunctionCall;
class NExpressions;
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
class NReadIntInput;
class NReadRealInput;
class NReadStringInput;

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
    virtual complex_t *visit(NTAssignments *) = 0;
    virtual complex_t *visit(NPrint *) = 0;
    virtual complex_t *visit(NFunctionDefinition *) = 0;
    virtual complex_t *visit(NFunctionCall *) = 0;
    virtual complex_t *visit(NExpressions *) = 0;
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
    virtual complex_t *visit(NReadIntInput *) = 0;
    virtual complex_t *visit(NReadRealInput *) = 0;
    virtual complex_t *visit(NReadStringInput *) = 0;
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
    NIdentifier *identifier;
    NExpression *assignmentExpr = nullptr;
    NDeclaration(NIdentifier *id);
    NDeclaration(NIdentifier *id, NExpression *assignmentExpr);
    complex_t *accept(Visitor &);
};

class NIdentifier : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    // string type = string("EMPTY");
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
    bool value = false;
    NBool(string *text);
    complex_t *accept(Visitor &);
};

class NStringLiteral : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    string *text;
    NStringLiteral(string *text) : text(text) {}
    complex_t *accept(Visitor &);
};

class NBinaryOperator : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    Operators op;
    NExpression *lhs;
    NExpression *rhs;
    NBinaryOperator(NExpression *lhs, Operators op, NExpression *rhs) :
        lhs(lhs), rhs(rhs), op(op) {}
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

class NTAssignments : public NStatement {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    vector<pair<string *, NExpression *expression>> list_pairs;
    complex_t *accept(Visitor &);
};

//Done
class NPrint : public NStatement {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NExpressions *expressions;
    NPrint(NExpressions * expressions): expressions(expressions) {}
    complex_t *accept(Visitor &);
};

class NExpressions : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    vector<NExpression *> expressions;
    void push_argument(NExpression * argument);
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

class NFunctionCall : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    vector<NExpression *> arguments;
    NIdentifier *id;
    NFunctionCall(NIdentifier *id, vector<NExpression *> arguments) : id(id), 
    arguments(arguments) {}
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
    int op = 0;
    NExpression *primary;
    int type;
    NTypeCheck(int op, NExpression *expression, int type) : 
        op(op), primary(expression), type(type) {}
    NTypeCheck(NExpression *expression, int type) : 
        primary(expression), type(type) {}
    complex_t *accept(Visitor &);
};

class NArray : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NExpressions *expressions = nullptr;
    NArray(NExpressions * exp) : expressions(exp) {}
    NArray() {}
    complex_t *accept(Visitor &);
};

class NTuple : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NTAssignments *pair;
    void push_assignment(NExpression *, NExpressions *);
    void push_assignment(NExpression *);
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

class NReadIntInput : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NReadIntInput() {}
    complex_t *accept(Visitor &);
};

class NReadRealInput : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NReadRealInput() {}
    complex_t *accept(Visitor &);
};

class NReadStringInput : public NExpression {
private:
    friend class Evaluate; 
    friend class Traverse;
public:
    NReadStringInput() {}
    complex_t *accept(Visitor &);
};

#include "traverse.h"
#include "evaluate.h"