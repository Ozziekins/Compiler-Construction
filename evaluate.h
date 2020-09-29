#include<map>

class Evaluate;

class Evaluate : public Visitor
{
private:
    map<string, int> ST_primary;
    map<string, vector<int> > ST_composite;
    string str;
    int num;

public:
    int visit(NProgram *);
    int visit(NBlock *);
    int visit(NDeclaration *);

    int visit(NArray *);
    int visit(NTuple *);
    int visit(NStatement *);
    int visit(NAssignment *);
    int visit(NPrint *);
    int visit(NFunctionDefinition *);
    int visit(NParameters *);
    int visit(NIf *);
    int visit(NIfElse *);
    int visit(NLoop *);
    // int visit(NRangeLoop *);
    int visit(NReturn *);
    int visit(NExpression *);
    int visit(NIdentifier *);

    int visit(NIntegerLiteral *);
    int visit(NReal *);

    int visit(NBool *);
    int visit(NStringLiteral *);
    int visit(NBinaryOperator *);
    int visit(NTypeCheck *);
    int visit(NUnary *);
    int visit(NReadInput *);
};