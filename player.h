#include "obj_base.h"
#include "random.h"
#include <string>

#ifndef MX_PLAYER
#define MX_PLAYER 1
struct Player
{
    ObjectiveBase base;
    int power = 10, killed_sum = 0, score = 0;
    Player()
    {
        base.type = "Player";
    }
    void rename(std::string newname)
    {
        base.name = newname;
    }
    void game_over()
    {
        power -= random(3);
        if (score - 10 < 0)
            score = 0;
        else
            score -= 10;
        if (power < 10)
            power = 10;
    }
    void you_win()
    {
        power += random(10);
        killed_sum++;
        score += random(5);
    }
};
#endif