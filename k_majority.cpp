#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// find k-majority element i.e. element that appears more than n/k times
vector<int> findKMajority(vector<int> &arr, int k)
{
    vector<int> ret;
    if (k <= 1) return ret;

    // at most k-1 k-majority elements
    vector<int> majority(k - 1, arr[0]);
    vector<int> count(k - 1, 0);
    int i, j;

    for (i = 0; i < arr.size(); ++i)
    {
        for (j = 0; j < k - 1; ++j)
        {
            if (majority[j] == arr[i])
            {
                count[j]++;
                break;
            }
        }

        if (j >= k - 1)
        {
            for (j = 0; j < k - 1; ++j)
            {
                if (count[j] == 0)
                {
                    majority[j] = arr[i];
                    count[j] = 1;
                    break;
                }
            }
        }

        if (j >= k - 1)
        {
            for (j = 0; j < k - 1; ++j) count[j]--;
        }
    }

    for (j = 0; j < majority.size(); ++j)
    {
        count[j] = 0;
        for (i = 0; i < arr.size(); ++i)
        {
            if (arr[i] == majority[j]) count[j]++;
        }
        if (count[j] > (arr.size() / k)) ret.push_back(majority[j]);
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 1, 1}; vector<int> va(a, a + sizeof(a) / sizeof(int));
    int b[] = {2, 2, 3, 3, 1, 1, 1}; vector<int> vb(b, b + sizeof(b) / sizeof(int));
    int c[] = {1, 2, 3, 1, 2, 3, 1, 2}; vector<int> vc(c, c + sizeof(c) / sizeof(int));
    int d[] = {1, 1, 1, 1, 2}; vector<int> vd(d, d + sizeof(d) / sizeof(int));

    vector<int> ra = findKMajority(va, 2);
    assert(ra.size() == 1);
    assert(ra[0] == 1);

    vector<int> rb = findKMajority(vb, 3);
    assert(rb.size() == 1);
    assert(rb[0] == 1);

    vector<int> rc = findKMajority(vc, 3);
    assert(rc.size() == 2);
    assert(rc[0] == 1 && rc[1] == 2 || rc[0] == 2 && rc[1] == 1);

    vector<int> rd = findKMajority(vd, 3);
    assert(rd.size() == 1);
    assert(rd[0] == 1);

    return 0;
}
