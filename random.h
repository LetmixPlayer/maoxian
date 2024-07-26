#include <stdlib.h>
#ifndef MX_RANDOM
#define MX_RANDOM 1
int random(int x)
{
    return rand() % x + 1;
}
int random(int y, int x)
{
    int ans = rand() % x + y;
    while (ans > y)
    {
        ans %= x;
        if (ans < x)
            ans += y;
    }
    return ans;
}
#endif