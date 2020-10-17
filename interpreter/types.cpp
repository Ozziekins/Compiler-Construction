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

string gettype(complex_t complex){
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
            cout << "empty :- not implemented";
    }
}

int main()
{
    complex_t variable1;
    variable1.type = FLOAT;
    variable1.floatVal = 2.43;
    
    complex_t variable2;
    variable2.type = INTEGER;
    variable2.intVal = 10;
    
    complex_t variable3;
    variable3.type = BOOL;
    variable3.boolVAl = true;
    
    complex_t variable4;
    variable4.type = STRING;
    variable4.stringVAl = new string("Daniel");
    cout << *(variable4.stringVAl);
    cout << endl;
    
    complex_t variable5;
    variable5.type = ARRAY;
    variable5.arrayVal = new vector<complex_t>;
    variable5.arrayVal->push_back(variable1);
    variable5.arrayVal->push_back(variable2);
    variable5.arrayVal->push_back(variable3);
    variable5.arrayVal->push_back(variable4);
    for (complex_t x : *(variable5.arrayVal)) 
        cout << gettype(x) << " ";
    cout << endl;
    
    
    vector<pair<string, complex_t>> *tupleVal;
    complex_t variable6;
    variable6.type = TUPLE;
    variable6.tupleVal = new vector<pair<string, complex_t>>;
    variable6.tupleVal->push_back(pair(string("name"), variable4));
    variable6.tupleVal->push_back(pair(string("age"), variable2));
    variable6.tupleVal->push_back(pair(string("married"), variable3));
    for (auto x : *(variable6.tupleVal)) 
        cout << x.first << " " << gettype(x.second);
    cout << endl;
    return 0;
}