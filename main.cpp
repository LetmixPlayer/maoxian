#include <iostream>
#include <fstream>
#include <io.h>
#include "player.h"
#include "io.h"
#include "random.h"
using namespace std;
Player player;
void first()
{
    string name;
    output("Hello! Welcome to Adventure Game!");
    output("Are you playing this game for the first time? Enter your nickname:", false);
    cin >> name;
    player.base.name = name;
    output("OK, Thank you, we will finish your settings");
    write(player, 1);
    system("pause > nul");
}
int init()
{
    srand(time(0));
    system("color F3");
    if (access("mxsaves.sav", 0))
    {
        first();
        system("exit");
    }
    load(player);
    return 0;
}
void adv()
{
    while (1)
    {
        system("cls");
        output("On the adventure...");
        system("pause > nul");
        short n = random(10), a;
        switch (n)
        {
        case 1:
        case 2:
        case 3:
            while (1)
            {
                output("On no! You saw a monster!");
                output("1. Attack");
                output("2. Run away");
                cin >> a;
                n = random(player.power + player.score);
                if (a == 1)
                {
                    if (n <= player.power)
                    {
                        player.you_win();
                        output("You Win!");
                        system("pause > nul");
                        break;
                    }
                    else
                    {
                        player.game_over();
                        output("Game Over...");
                        system("pause > nul");
                        break;
                    }
                }
                else if (a == 2)
                {
                    player.game_over();
                    output("Runned away...");
                    system("pause > nul");
                    break;
                }
                else
                {
                    output("Invalid option...");
                    system("pause > nul");
                }
            }
            break;
        case 10:
            output("Oh! You saw a power stick");
            for (int i = 0; i < random(3); i++)
                player.power += random(10);
            system("pause > nul");
            break;
        default:
            output("Nothing...");
            system("pause > nul");
        }
        write(player);
    cont:
        system("cls");
        output("1. Continue");
        output("2. End");
        cin >> a;
        if (a == 1)
            continue;
        else if (a == 2)
            break;
        else
        {
            output("Invalid option...");
            system("pause > nul");
            goto cont;
        }
    }
}
int main(int argc, char **argv)
{
    if (init())
        return 255;
    int n;
    system("cls");
    output("Hello! Welcome to play Adventure Game");
    output("Powered by console, by Letmix");
    output("Press any key to start game...");
    system("pause > nul");
    while (1)
    {
        system("cls");
        cout << "Hello! " << player.base.name << '\n';
        cout << "1. Start adventure\n";
        cout << "2. Your infomation\n";
        cout << "3. Save\n";
        cout << "4. Exit\n";
        cin >> n;
        switch (n) 
        {
        case 1:
            load(player);
            adv();
            break;
        case 2:
            system("cls");
            cout << "Your nikename: " << player.base.name << "\n"; 
            cout << "Your score: " << player.score << "\n";
            cout << "Your power: " << player.power << "\n";
            cout << "You killed " << player.killed_sum << " monsters";
            if (player.killed_sum > 1)
                cout << 's';
            cout << '\n';
            system("pause > nul");
            break;
        case 3:
            system("cls");
            if (write(player))
                return 255;
            output("Saved.");
            system("pause > nul");
            break;
        case 4:
            if (write(player))
                return 255;
            return 0;
        default:
            output("Invalid option...");
            system("pause > nul");
        }
    }
    return 0;
}