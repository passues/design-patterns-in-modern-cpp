#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

struct ClassElement{
    string name;
    string type;
    vector<ClassElement> elements;
    ClassElement(){};
    ClassElement(const string& name, const string& type)
    :name(name), type(type){};
    
};
class CodeBuilder
{
    ClassElement root;
public:
  CodeBuilder(const string& clos_name)
  {
      root.name = clos_name;
  }

  CodeBuilder& add_field(const string& name, const string& type)
  {
      ClassElement e(name, type);
      root.elements.emplace_back(e);
      return *this;
  }

  friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
  {
     os << "class " << obj.root.name<< endl;
     os <<"{" << endl;
     for(auto e: obj.root.elements)
        os << "  " <<  e.type << " " << e.name << ";" << endl;
     os << "};" <<endl;
     return os;
  }
};

int main()
{
    auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
    std::cout << cb;
}
