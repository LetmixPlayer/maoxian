#include <iostream>
using namespace std;
#ifndef MX_ERROR
#define MX_ERROR 1
int error(string error_info = "") {
    system("cls");
    cout << error_info << "\nPress any key to exit...";
    system("pause > nul");
    return 1;
}
#endif