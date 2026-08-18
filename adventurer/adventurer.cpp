#include "./adventurer.h"
#include <array>
#include<iostream>


std::array<Adventurer, 3> getAdventurers()
{

    Adventurer thomas{"thomas", Warrior, 100, 100, 85, 30};
    Adventurer arthur{"arthur", Mage, 150, 150, 50, 20};
    Adventurer john{"john", Rogue, 180, 180, 85, 10};

    return {thomas, arthur, john};
}

std::string getAdventurerClassType(AdventurerClasses classType)
{

    switch (classType)
    {
    case Warrior:
        return "Warrior";
        break;
    case Mage:
        return "Mage";
        break;
    case Rogue:
        return "Rogue";
        break;
    default:
        break;
    }
}

std::string getAdventurerAction(AdventurerAction classType)
{

    switch (classType)
    {
    case attack:
        return "attack";
        break;
    case heal:
        return "heal";
        break;
    case flee:
        return "flee";
        break;
    default:
        break;
    }
}

void printAdventurerStats(Adventurer adventurer)
{

    std::cout << "Adventurer stats: " << '\n';
    std::cout << "Name: " << adventurer.name << '\n';
    std::cout << "Class Type: " << getAdventurerClassType(adventurer.classType) << '\n';
    std::cout << "Current Health: " << adventurer.currentHealth << '\n';
    std::cout << "Max Health: " << adventurer.maxHealth << '\n';
    std::cout << "Attack Power: " << adventurer.attackPower << '\n';
    std::cout << "Healing Power: " << adventurer.healPower << '\n';
    std::cout << '\n';
}

