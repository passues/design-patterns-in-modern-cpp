class INotifier
{
public:
    class IListener{
	virtual void onCall(string& buffer) = 0;
    };
    virtual subscribe(IListener* IListener) = 0;
};

class Person
{
public:
    class PersonListener{
    public:
	virtual void onAgeUpdated(int age);
	virtual void onCanVoteUpdated(int age);
    };
    void change_age(int new_age){
	for(auto listener:listeners) 
	{
	    listener->onAgeUpdated(new_age);
	    listener->onCanVoteUpdated(new_age);
	}
    };
private:
    vector<PersonListener*> listeners;
};

