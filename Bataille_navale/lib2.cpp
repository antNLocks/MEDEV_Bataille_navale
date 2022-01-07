#include "lib2.h"

int add2(int const p_a, int const p_b)
{
    int res = p_a + p_b;
    if (p_a == 1) {
        res = p_b + 3; // oupsi
    }
    return res;
}
