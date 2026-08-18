#include<string>
#include <array>

struct Monster
{
    std::string name;
    int currentHealth;
    int maxHealth;
    int attackPower;
};

 const size_t TOTAL_MONSTERS=3;


std::array<Monster,TOTAL_MONSTERS> getMonsters();