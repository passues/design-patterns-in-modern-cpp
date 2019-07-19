#include <iostream>
#include <vector>
#include <memory>
using namespace std;

struct Token
{
  int value;

  Token(int value) : value(value) {}
};

struct Memento
{
  vector<shared_ptr<Token>> tokens;
  int currIndex = 0;
};

struct TokenMachine
{
  vector<shared_ptr<Token>> tokens;
  

  Memento add_token(int value)
  {
    return add_token(make_shared<Token>(value));
  }

  // adds the token to the set of tokens and returns the
  // snapshot of the entire system
Memento add_token(const shared_ptr<Token>& token)
  {
    tokens.push_back(token);
    Memento m;
    for (auto t : tokens)
      m.tokens.emplace_back(make_shared<Token>(t->value));
    return m;
  }

  void revert(const Memento& m)
  {
    tokens.clear();
    for (auto t : m.tokens)                                                                 
      tokens.emplace_back(make_shared<Token>(t->value));
  }

};
