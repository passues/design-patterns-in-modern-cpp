#include <string>
using namespace std;

struct Person
{
  int id;
  string name;
};

class PersonFactory
{
    static int person_id;
public:
  Person create_person(const string& name)
  {
    Person p;
    p.id = person_id;
    p.name = name;
    person_id += 1;
    return p;
  }
};
int PersonFactory::person_id=0;

int main()
{
    PersonFactory f;
    auto p1=f.create_person("Jim");
    auto p2=f.create_person("Chris");
}
