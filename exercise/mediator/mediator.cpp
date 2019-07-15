#include<vector>
using namespace std;
struct IParticipant
{};
struct Participant;

struct Mediator{
    vector<Participant*> participants;
    inline void broadcast(int add_value, Participant* initiator);
};
struct Participant : IParticipant
{
    int value{0};
    Mediator& mediator;

    Participant(Mediator &mediator) : mediator(mediator)
    {
      mediator.participants.push_back(this);
    }

    void say(int value)
    {
        mediator.broadcast(value, this);
    }
};
inline void Mediator::broadcast(int add_value, Participant* initiator)
{
    for(auto participant:participants)
        if(participant!=initiator)
            participant->value += add_value;
}
