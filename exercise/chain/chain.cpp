#include <vector>
#include <string>
using namespace std;

struct Creature;

struct StatQuery
{
  enum Statistic { attack, defense } statistic;
  int result;
  StatQuery(const Statistic type): statistic(type)
  {
      
  }
};

struct Game
{
  vector<Creature*> creatures;
};
inline void query_adds(Game& game, StatQuery&q);
struct Creature
{
protected:
  Game& game;
  int base_attack, base_defense;

public:
  Creature(Game &game, int base_attack, int base_defense) : game(game), base_attack(base_attack),
                                                            base_defense(base_defense) {}
  virtual int get_attack() = 0;
  virtual int get_defense() = 0;
};


class Goblin : public Creature
{
public:
  Goblin(Game &game, int base_attack, int base_defense) : Creature(game, base_attack, base_defense) {}

  Goblin(Game &game) : Creature(game, 1, 1) {}

  int get_attack() override {
      StatQuery q{StatQuery::Statistic::attack};
      query_adds(game, q);
      return q.result + base_attack;
  }

  int get_defense() override {
      StatQuery q{StatQuery::Statistic::defense};
      query_adds(game, q);
      return q.result;
  }
};

class GoblinKing : public Goblin
{
public:
  GoblinKing(Game &game) : Goblin(game, 3, 3) {}
};
inline void query_adds(Game& game, StatQuery&q)
{

    int attack_adds = 0;
    int defense_adds = 0;
    for(auto obj:game.creatures)
    {
      if(dynamic_cast<GoblinKing*>(obj))
        attack_adds += 1;
      if(dynamic_cast<Goblin*>(obj))
        defense_adds += 1;
    }
    if(q.statistic == StatQuery::Statistic::attack)
    q.result = attack_adds;
    if(q.statistic == StatQuery::Statistic::defense)
    q.result = defense_adds;
};

int main()
{
}
