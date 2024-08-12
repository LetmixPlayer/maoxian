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
        system("color");
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
                        system("color 40");
                        player.game_over();
                        output("Game Over...");
                        system("pause > nul");
                        break;
                        system("color");
                    }
                }
                else if (a == 2)
                {
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
        system("color");
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
        system("color F3");
        system("cls");
        cout << "Hello! " << player.base.name << '\n';
        cout << "1. Start adventure\n";
        cout << "2. Your infomation\n";
        cout << "3. Save\n";
        cout << "4. Settings\n";
        cout << "5. Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
            load(player);
            adv();
            break;
        case 2:
            system("cls");
            cout << "Your nickname: " << player.base.name << "\n";
            cout << "Your score: " << player.score << "\n";
            cout << "Your power: " << player.power << "\n";
            cout << "You killed " << player.killed_sum << " monster";
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
        setting:
            system("color F4");
            system("cls");
            cout << "Setting Options\n";
            cout << "1. Rename\n";
            cout << "2. Restart game\n";
            cout << "3. About";
            cin >> n;
            switch (n)
            {
            case 1:
                cout << "Enter your new nickname:";
                cin >> player.base.name;
                if (write(player))
                    return 255;
                break;
            case 2:
            restart:
                cout << "Are you agree to restart game?\n";
                cout << "Your archive will be delete if you restart game!\n";
                cout << "1. I am agree\n";
                cout << "2. I am not agree\n";
                cin >> n;
                if (n == 1)
                {
                    system("del mxsaves");
                    return 0;
                }
                else if (n == 2)
                    break;
                else
                    goto restart;
            case 3:
                output("Adventure game 1.0.3");
                break;
            default:
                output("Invalid option...");
                system("pause > nul");
                goto setting;
            }
            goto setting;
        case 5:
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