#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ContainsIntegers
{
    ContainsIntegers(){};
    virtual int sum() const=0;
};

struct SingleValue: ContainsIntegers
{
  int value{ 0 };

  SingleValue() = default;

  explicit SingleValue(const int value)
    : value{value}
  {
  }
    virtual int sum() const {return value;};

};

struct ManyValues : ContainsIntegers, vector<int>
{
  void add(const int value)
  {
    push_back(value);
  }
    virtual int sum() const
    {
    int res = 0;
    for(auto item: *this)
        res += item;
    return res;
    }
};

int sum(const vector<ContainsIntegers*> items);

