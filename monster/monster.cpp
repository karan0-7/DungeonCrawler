#include <array>
#include "./monster.h"

std::array<Monster, TOTAL_MONSTERS> getMonsters()
{

    Monster ragul{"ragul", 200, 200, 40};
    Monster azriel{"azriel", 300, 300, 100};
    Monster lucifer{"lucifer", 400, 400, 140};

    return {ragul,azriel,lucifer};
}

