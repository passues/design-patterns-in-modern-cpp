#include <thread>
#include <map>
#include <iostream>
#include <mutex>
#include <unistd.h>

using namespace std;

struct SharedObject
{
    std::mutex mapMu;
    SharedObject(){};
    std::map<int, int> sharedMap;
    void add_item()
    {	
	while(true)
	{
	    std::lock_guard<std::mutex> guard(mapMu);
	    for(int i = 0; i < 10; ++i) 
		sharedMap[i] = i;
	}
    }
    void print_item()
    {
	while(true) 
	{
	    cout << "reading maps" << endl;
	    {
		std::lock_guard<std::mutex> guard(mapMu);
		for(auto item:sharedMap)
		    cout << item.first  << ":" << item.second << endl;
		sharedMap.clear();
	    }
	    cout << "finished reading map" << endl;
	    sleep(1);
	}
	return;
    }
};

void add_obj(SharedObject& obj)
{
    obj.add_item();
    return;
}
void read_obj(SharedObject& obj)
{
    obj.print_item();
    return;
}
int main()
{
    SharedObject obj;
    std::thread t(read_obj, std::ref(obj));
    add_obj(obj);

    t.join();
}
