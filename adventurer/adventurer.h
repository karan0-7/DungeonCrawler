#include<string>
#include <array>

enum AdventurerClasses
{
    Warrior,
    Mage,
    Rogue
};

enum AdventurerAction{
    attack,
    heal,
    flee
};

struct Adventurer
{
    std::string name;
    AdventurerClasses classType;
    int currentHealth;
    int maxHealth;
    int attackPower;
    int healPower;
};

std::array<Adventurer, 3> getAdventurers();
std::string getAdventurerAction(AdventurerAction classType);
void printAdventurerStats(Adventurer adventurer);
 const size_t TOTAL_ADVENTURERS=3;