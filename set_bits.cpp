#include <cassert>
#include <iostream>
using namespace std;

// number of set bits
int setBits(unsigned n)
{
	int c = 0;
	for ( ; n; n &= n - 1) c++;
	return c;
}

int main(int argc, char const *argv[])
{
	assert(setBits(3) == 2);
	assert(setBits(4) == 1);
	assert(setBits(123) == 6);
	assert(setBits(2147483647) == 31);
	assert(setBits(2147483548) == 27);

	return 0;
}
