#include <iostream>
#include <string>
#include <array>
#include <random>
#include "./adventurer/adventurer.h"
#include "./monster/monster.h"
#include "./main.h"

int getRandomNumber(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

int getDeadAdventurers(std::array<Adventurer, TOTAL_ADVENTURERS> adventurers)
{
    int deadAdventurers = 0;
    for (int i = 0; i < adventurers.size(); i++)
    {
        if (adventurers[i].currentHealth <= 0)
        {
            deadAdventurers++;
        }
    }
    return deadAdventurers;
}

int getDeadMonsters(std::array<Monster, TOTAL_MONSTERS> monsters)
{
    int deadMonsters = 0;

    for (int i = 0; i < monsters.size(); i++)
    {
        if (monsters[i].currentHealth <= 0)
        {
            deadMonsters++;
        }
    }
    return deadMonsters;
}

bool isGameOver(std::array<Adventurer, TOTAL_ADVENTURERS> &adventurers,
                std::array<Monster, 3> &monsters)
{
    const int deadAdventurers = getDeadAdventurers(adventurers);
    const int deadMonsters = getDeadMonsters(monsters);

    return deadAdventurers == adventurers.size() || deadMonsters == monsters.size();
}

void initiateMonsterAttack(Monster &monster, std::array<Adventurer, TOTAL_ADVENTURERS> &adventurers)
{
    Adventurer &adventurerToAttack = adventurers[getRandomNumber(0, 2)];
    adventurerToAttack.currentHealth -= monster.attackPower;
}

void initiateAdventurerAttack(Monster &monster, std::array<Adventurer, TOTAL_ADVENTURERS> &adventurers)
{
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
            monster.currentHealth -= adventurers[i].attackPower;
        }
        else if (chosenAction == getAdventurerAction(heal))
        {
            adventurers[i].currentHealth += adventurers[i].healPower;
        }
        else if (chosenAction == getAdventurerAction(flee))
        {
            adventurers[i].currentHealth = 0;
        }

        if (monster.currentHealth <= 0)
            return;
    }
}

bool isCurrentRoundOver(std::array<Adventurer, TOTAL_ADVENTURERS> adventurers, Monster currentMonster)
{
    const int deadAdventurers = getDeadAdventurers(adventurers);
    return deadAdventurers == adventurers.size() || currentMonster.currentHealth <= 0;
}

void beginGame()
{
    int currentRound{0};
    std::array<Adventurer, 3> adventurers{getAdventurers()};
    std::array<Monster, 3> monsters{getMonsters()};

    while (currentRound < TOTAL_ROUNDS)
    {
        std::cout << "Beginning round: " << currentRound + 1 << '\n';
        std::cout << '\n';

        Monster &currentMonster = monsters[currentRound];

        while (!isCurrentRoundOver(adventurers, currentMonster))
        {

            std::cout << "Monster current health: " << currentMonster.currentHealth << '\n';
            std::cout << '\n';

            initiateAdventurerAttack(currentMonster, adventurers);

            if (isGameOver(adventurers, monsters))
            {
                std::cout << "Game is over. Thank you for playing.";
                return;
            }

            initiateMonsterAttack(currentMonster, adventurers);

            if (isGameOver(adventurers, monsters))
            {
                std::cout << "Game is over. Thank you for playing.";
                return;
            }
        }
        currentRound++;
    }
}

int main()
{
    std::cout << "Welcome to dungeon crawler." << '\n';
    std::cout << "Let the game begin." << '\n';
    std::cout << '\n';
    beginGame();
    return 0;
}