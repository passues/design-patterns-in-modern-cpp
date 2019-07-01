#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

struct Flower
{
  virtual string str() = 0;
};

struct Rose : Flower
{
  string str() override {
    ostringstream oss;
    oss << "A rose";
    return oss.str();
  }
};
struct Decorator{};

struct RedFlower : Flower, Decorator
{
    
    Flower* object;
    RedFlower(Flower&obj): object(&obj){
    };
    string str() override{
        ostringstream oss;
        Decorator* dec_ptr = dynamic_cast<Decorator*>(object);
        
        if(dec_ptr==nullptr)
        {
            oss << object-> str() << " that is red";
        }
        else{
	    std::string base_string = object->str();

	    if (base_string.find("red") != string::npos)
		return base_string;
	    else
		oss << object-> str() << " and red";
        }
        
        return oss.str();
            
    }
};

struct BlueFlower : Flower, Decorator
{
    Flower* object;
    BlueFlower(Flower&obj): object(&obj){};
    string str() override{
        ostringstream oss;
        Decorator* dec_ptr = dynamic_cast<Decorator*>(object);
        
        if(dec_ptr==nullptr)
        {
            oss << object-> str() << " that is blue";
        }
        else{
	    std::string base_string = object->str();

	    if (base_string.find("blue") != string::npos)
		return base_string;
	    else
		oss << object-> str() << " and blue";
        }

        return oss.str();
    }
};
