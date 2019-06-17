#include "exercise.h"


struct ContainsIntegers
{
    ContainsIntegers(){}
    int sum()
    {
        int res = 0;
        for(auto item: *this)
            res += item.value;
        return res;
    }
};
struct SingleValue:public ContainsIntegers
{
    SingleValue(int value):value(value){}
    SingleValue * begin(){return this;}
    SingleValue* end(){return this +1;}
    int value;
};

struct ManyValues:public ContainsIntegers
{
    ManyValues(){};
    void add(int item){
        object.push_back(item);
    }
    vector<int> objects;
};


int sum(const vector<ContainsIntegers*> items)
{
    int res = 0;
    for(auto item: items)
    res += item->sum();
    return res;
}
