#include <iostream>
#include <vector>
#include <map>
using namespace std;

inline vector<string> split(const string& stringToSplit)
{
  vector<string> result;
  size_t pos = 0, lastPos = 0;
  while ((pos = stringToSplit.find_first_of("+-", lastPos)) != string::npos)
  {
    result.push_back(stringToSplit.substr(lastPos, pos-lastPos+1));
    lastPos = pos+1;
  }
  result.push_back(stringToSplit.substr(lastPos));
  return result;
}



struct ExpressionProcessor
{
  map<char,int> variables;

  int calculate(const string& expression)
  {
      vector<string> items=split(expression);
      
      int sign = 1;
      int res = 0;
      int current = 0;
      for(auto item:items)
      {
          if(item =="+"|| item == "-")
          {
              sign = item == "+"? 1:-1;
              continue;
          }
          try{
              current =  stoi(item);
          }
          catch( const invalid_argument&)
          {
              if(item.size() == 1 && variables.find(item[0])!= variables.end())
                  current = variables[item[0]];
              else
                return 0;
          }
          if(sign!=0)
            res += sign*current;
      }
      return res;
  }
};
