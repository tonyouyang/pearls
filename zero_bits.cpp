#include <iostream>
#include <cassert>
using namespace std;

// count zero bits
int zeroBits(unsigned n)
{
    int c = 0;
    for ( ; n != (unsigned) -1; n |= n + 1) c++;
    return c;
}

int main(int argc, char const *argv[])
{
    assert(zeroBits(2147483647) == 1);

    return 0;
}
