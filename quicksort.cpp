#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

void quickSort(int arr[], int left, int right)
{
	if (left >= right) return;

    srand((unsigned)time(NULL));
    int pivot = arr[left + (rand() % (int)(right - left + 1))], i = left, j = right;

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

    if (left < j) quickSort(arr, left, j);
    if (right > i) quickSort(arr, i, right);
}

int main(int argc, char const *argv[])
{
	int a[] = {1, 2, 3};
	int b[] = {3, 2, 1};
    int c[] = {1, 1, 1, 1, 1};
    int d[] = {1, 99, 28, 3, 2, 10, 7};

	quickSort(a, 0, 2); for (int i = 0; i < 3; ++i) cout << a[i] << " "; cout << endl;
	quickSort(b, 0, 2); for (int i = 0; i < 3; ++i) cout << b[i] << " "; cout << endl;
    quickSort(c, 0, 4); for (int i = 0; i < 5; ++i) cout << c[i] << " "; cout << endl;
    quickSort(d, 0, 6); for (int i = 0; i < 7; ++i) cout << d[i] << " "; cout << endl;

    return 0;
}
