#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// find majority element i.e. repeats more than n/2 times
// non majority elements are UNIQUE
int findMajority(vector<int> &arr)
{
    for (int i = 0; i + 1 < arr.size(); i += 2)
    {
        if (arr[i] == arr[i + 1]) return arr[i];
    }

    return arr[arr.size() - 1];
}

// find majority element i.e. repeats more than n/2 times
// non majority elements are NEEDLESS to be UNIQUE
int findMajority2(vector<int> &arr)
{
    int count = 0, majority = 0, i;

    for (i = 0; i < arr.size(); ++i)
    {
        if (count == 0)
        {
            majority = arr[i];
            count = 1;
        }
        else if (arr[i] == majority)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    for (count = 0, i = 0; i < arr.size(); ++i)
        if (arr[i] == majority) count++;

    if (count > (arr.size() >> 1)) return majority;
    else return 0; // return anything if no majority element found
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 1, 1}; vector<int> va(a, a + sizeof(a) / sizeof(int));
    int b[] = {2, 3, 2}; vector<int> vb(b, b + sizeof(b) / sizeof(int));
    int c[] = {2, 3, 2, 3, 3}; vector<int> vc(c, c + sizeof(c) / sizeof(int));
    int d[] = {10, 2, 3, 10, 1, 4, 10, 5, 10, 10, 10}; vector<int> vd(d, d + sizeof(d) / sizeof(int));
    int e[] = {3, 2, 3, 2, 2, 3, 3}; vector<int> ve(e, e + sizeof(e) / sizeof(int));
    int f[] = {3, 3, 0, 1, 2, 4}; vector<int> vf(f, f + sizeof(f) / sizeof(int));

    assert(findMajority(va) == 1);
    assert(findMajority(vb) == 2);
    assert(findMajority(vc) == 3);
    assert(findMajority(vd) == 10);

    assert(findMajority2(va) == 1);
    assert(findMajority2(vb) == 2);
    assert(findMajority2(vc) == 3);
    assert(findMajority2(vd) == 10);

    assert(findMajority2(ve) == 3);
    assert(findMajority2(vf) == 0);

    return 0;
}
