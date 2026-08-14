#include<string>

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