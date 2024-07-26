#include <iostream>
#include <fstream>
#include <windows.h>
#include "error.h"
#include "player.h"
#ifndef MX_IO
#define MX_IO 1
using namespace std;
int filescan() {
    if (access("mxsaves.sav", F_OK) == -1) {
        return error("[Error] Archive file does not exist");
    }
    if (access("mxsaves.sav", R_OK) == -1) {
        return error("[Error] Archive file is not readable");
    }
    return 0;
}
void output(string s, bool endline = true) {
    for (int i = 0; i < s.size(); i++) {
        cout << s[i];
        Sleep(50);
    }
    if (endline)
        cout << '\n';
}
int write(Player player, int mode = 0) {
    if (mode = 1) goto wout;
    if (filescan()) return 1;
    wout:
    ofstream file("mxsaves.sav");
    if (!file.is_open()) {
        return error("[Error] Unable to open archive file for writing");
    }
    file << player.base.name << ' ' << player.power << ' ' << player.killed_sum << ' ' << player.score;
    file.close();
    return 0;
}

int load(Player& player, int mode = 0) {
    if (mode = 1) goto lout;
    if (filescan()) return 1;
    lout:
    ifstream file("mxsaves.sav");
    if (!file.is_open()) {
        return error("[Error] Unable to open archive file for reading");
    }
    file >> player.base.name >> player.power >> player.killed_sum >> player.score;
    file.close();
    return 0;
}
 
#endif