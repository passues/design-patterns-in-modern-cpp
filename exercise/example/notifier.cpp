#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Notifier
{
public:    
    class Listener;
    Notifier() {};
    virtual void subscribe(Listener *listener)
    {
	listeners.push_back(listener);
    }
    void publishMessage(string message){
	cout << "publsihing  message " << endl;
	for(auto listener:listeners)
	    listener->onCall(message);
    }
    int getNewId()
    {
	return listeners.size();
    }
    class Listener
    {
    public:
	Listener(Notifier& notifier) {
	    id = notifier.getNewId();
	    notifier.subscribe(this);
	    }
	virtual void onCall(string message){
	    cout <<"Id="<< id << "|message=" << message << endl;
	}
    private:
	int id;
    };
private:
    vector<Listener*> listeners;
};
int main()
{
    Notifier notifier;
    Notifier::Listener l1(notifier), l2(notifier);
    notifier.publishMessage("hello world" );
    printf("%f", 0);
}

