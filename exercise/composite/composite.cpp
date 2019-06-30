#include "composite.h"

int sum(const vector<ContainsIntegers*> items)
{
    int res = 0;
    for(auto item: items)
    res += item->sum();
    return res;
}

int main(){
    SingleValue single_value{1};
    ManyValues other_values;
    
    other_values.add(2);
    other_values.add(3);

    std::cout << sum({&single_value, &other_values}) << std::endl;
}
