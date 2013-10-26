#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <ctime>
using namespace std;

// 0-based k
int select(vector<int> &arr, int k)
{
    assert(arr.size() >= k);

    srand((unsigned)time(NULL));
    int start = 0, end = arr.size() - 1, i, j, pivot;

    while (start < end)
    {
        pivot = arr[start + rand() % (int)(end - start + 1)];
        i = start;
        j = end;

        while (i <= j)
        {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            if (i <= j)
            {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        // start .. j, i .. right
        if (k < i) end = j;
        if (k > j) start = i;
    }

    return arr[k];
}

int main(int argc, char const *argv[])
{
    int a[] = {16, 2, 77, 29}; vector<int> va(a, a + sizeof(a) / sizeof(int));
    int b[] = {2, 2, 2, 2}; vector<int> vb(b, b + sizeof(b) / sizeof(int));
    int c[] = {1, 2, 3, 4, 5, 6, 7}; vector<int> vc(c, c + sizeof(c) / sizeof(int));
    int d[] = {7, 6, 5, 4, 3, 2, 1}; vector<int> vd(d, d + sizeof(d) / sizeof(int));
    int e[] = {0}; vector<int> ve(e, e + sizeof(e) / sizeof(int));

    assert(select(va, 0) == 2);
    assert(select(va, 1) == 16);
    assert(select(va, 2) == 29);
    assert(select(va, 3) == 77);
    assert(select(vb, 2) == 2);
    assert(select(vc, 0) == 1);
    assert(select(vc, 3) == 4);
    assert(select(vc, 6) == 7);
    assert(select(vd, 0) == 1);
    assert(select(vd, 3) == 4);
    assert(select(vd, 6) == 7);

    return 0;
}
