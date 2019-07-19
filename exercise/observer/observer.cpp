#include <iostream>
#include <vector>

using namespace std;

struct IRat{
    virtual void change_attack(int value_change) =0;
};
struct Game
{
    vector<IRat*> listeners;
    void add_rat(IRat* rat)
    {
        listeners.emplace_back(rat);
        for(auto listener:listeners)
            listener->change_attack(1);
    }
    void reduce_rat(IRat* rat)
    {
        for(auto it= listeners.begin();it!=listeners.end();)
            if(*it==rat)
                it = listeners.erase(it);
            else{
                
                (*it)->change_attack(-1);
                it ++;
            }
        
    }
};

struct Rat : IRat
{
    Game& game;
    int attack{1};

    Rat(Game &game) : game(game)
    {
        attack = game.listeners.size();
        game.add_rat(this);
    }
    virtual void change_attack(int value_change)
    {
        attack += value_change;
    }

    ~Rat() 
    { 
        game.reduce_rat(this);
    }
};
