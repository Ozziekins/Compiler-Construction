#include<map>
#include <list>
#include <math.h>

class Evaluate;

class Evaluate : public Visitor
{
public:
    typedef map<string, complex_t *>* SymbolTable;
    string str;
    int num;
    list<map<string, complex_t *>*> scopes = { new map<string, complex_t *>() };// scopes.push_front(  );

    void print_symbol_table();

    complex_t *visit(NProgram *);
    complex_t *visit(NBlock *);
    complex_t *visit(NDeclaration *);
    complex_t *visit(NArray *);
    complex_t *visit(NArrayElement *);
    complex_t *visit(NTupleElementIndex *);
    complex_t *visit(NTupleElementName *);
    complex_t *visit(NTuple *);
    complex_t *visit(NStatement *);
    complex_t *visit(NAssignment *);
    complex_t *visit(NTAssignments *);
    complex_t *visit(NPrint *);
    complex_t *visit(NFunctionDefinition *);
    complex_t *visit(NFunctionCall *);
    complex_t *visit(NParameters *,  NExpressions *);
    complex_t *visit(NExpressions *);
    complex_t *visit(NIf *);
    complex_t *visit(NIfElse *);
    complex_t *visit(NLoop *);
    complex_t *visit(NRangeLoop *);
    complex_t *visit(NReturn *);
    complex_t *visit(NExpression *);
    complex_t *visit(NIdentifier *);

    complex_t *visit(NIntegerLiteral *);
    complex_t *visit(NReal *);

    complex_t *visit(NBool *);
    complex_t *visit(NStringLiteral *);
    complex_t *visit(NBinaryOperator *);
    complex_t *visit(NTypeCheck *);
    complex_t *visit(NUnary *);
    complex_t *visit(NReadIntInput *);
    complex_t *visit(NReadRealInput *);
    complex_t *visit(NReadStringInput *);
};