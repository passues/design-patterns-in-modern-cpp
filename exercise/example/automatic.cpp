#include<iostream>

using namespace std;

struct Buffer
{
    bool isIndent = false;
    struct Indent{
	Buffer& buffer;
	Indent(Buffer & buff) :buffer(buff){
	    buffer.isIndent = true;
	}
	~Indent(){
	    buffer.isIndent = false;
	}
    };
    friend ostream& operator<<(ostream& os, const Buffer& obj)
    {
	if(obj.isIndent)
	    return os <<"	" << "hello world";  
	else
	    return os << "hello world";
    }
};
int main()
{
    Buffer test;
    {
	Buffer::Indent indent(test);
	cout << test << endl;
    }
    cout <<  test << endl;
}

