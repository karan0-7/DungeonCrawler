#include <iostream>
#include <string>
#include <array>
#include "./headers/adventurer.h"
#include "./headers/monster.h"

std::array<Adventurer, 3> getAdventurers()
{

    Adventurer thomas{"thomas", Warrior, 100, 100, 85, 30};
    Adventurer arthur{"arthur", Mage, 150, 150, 50, 20};
    Adventurer john{"john", Rogue, 180, 180, 85, 10};

    return {thomas, arthur, john};
}

std::array<Monster, 1> getMonsters()
{

    Monster ragul{"ragul", 200, 200, 40};
    Monster azriel{"azriel", 300, 300, 100};
    Monster lucifer{"lucifer", 400, 400, 140};

    return {ragul};
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
        return "Attack";
        break;
    case heal:
        return "Heal";
        break;
    case flee:
        return "Flee";
        break;
    default:
        break;
    }
}

void printAdventurerStats(Adventurer adventurer)
{

    std::cout << "Name: " << adventurer.name << '\n';
    std::cout << "Class Type: " << getAdventurerClassType(adventurer.classType) << '\n';
    std::cout << "Current Health: " << adventurer.currentHealth << '\n';
    std::cout << "Max Health: " << adventurer.maxHealth << '\n';
    std::cout << "Attack Power: " << adventurer.attackPower << '\n';
    std::cout << "Healing Power: " << adventurer.healPower << '\n';
    std::cout << '\n';
}

bool isGameOver(std::array<Adventurer, 3> adventurers,
                std::array<Monster, 1> &monsters)
{
    std::cout << "cehccccccccccc" << &monsters[0] << '\n';
    int deadAdventurers = 0, deadMonsters = 0;
    for (int i = 0; i < adventurers.size(); i++)
    {
        if (adventurers[i].currentHealth <= 0)
        {
            deadAdventurers++;
        }
    }
    for (int i = 0; i < monsters.size(); i++)
    {
        if (monsters[i].currentHealth <= 0)
        {
            deadMonsters++;
        }
    }
    std::cout << "deadMonsters" << deadMonsters;
    return deadAdventurers == adventurers.size() || deadMonsters == monsters.size();
}

void beginGame()
{
    int currentRound{0};

    std::array<Adventurer, 3> adventurers{getAdventurers()};
    std::array<Monster, 1> monsters{getMonsters()};
    std::cout << "startinggg add" << &monsters << '\n';

    while (!isGameOver(adventurers, monsters))
    {
        std::cout << "Beginning round: " << currentRound + 1 << '\n';
        std::cout << '\n';

        Monster &currentMonster = monsters[currentRound];
        std::cout << "currentMonster address" << &currentMonster << '\n';

        for (int i = 0; i < adventurers.size(); i++)
        {
            std::string chosenAction;
            printAdventurerStats(adventurers[i]);
            std::cout << "Please choose an action for adventurer." << '\n';
            std::cout << "1: " << getAdventurerAction(attack) << '\n';
            std::cout << "2: " << getAdventurerAction(heal) << '\n';
            std::cout << "3: " << getAdventurerAction(flee) << '\n';
            std::cin >> chosenAction;
            std::cout << chosenAction << '\n';

            if (chosenAction == getAdventurerAction(attack))
            {
                currentMonster.currentHealth -= adventurers[i].attackPower;
            }
            else if (chosenAction == getAdventurerAction(heal))
            {
                adventurers[i].currentHealth += adventurers[i].healPower;
            }
            else if (chosenAction == getAdventurerAction(flee))
            {
                adventurers[i].currentHealth = 0;
            }

            std::cout << "Monster current health: " << currentMonster.currentHealth << '\n';
            std::cout << '\n';
        }
    }

    std::cout << "Game is over. Thank you for playing.";
}

int main()
{
    std::cout << "Welcome to dungeon crawler." << '\n';
    std::cout << "Let the game begin." << '\n';
    std::cout << '\n';
    beginGame();
    return 0;
}