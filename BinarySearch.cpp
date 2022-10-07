#include <bits/stdc++.h>

using namespace std;
// lb = Lower Bound
// ub = Upper Bound
// x  = array(mid)
int BinarySearch(int array[], int x, int lb, int ub)
{
    if (lb <= ub)
    {
        int mid = (lb + ub) / 2; // get array med
        if (x == array[mid])
        {
            return mid;
        }
        else if (x > array[mid])
        {
            BinarySearch(array, x, mid + 1, ub); // right side array
        }
        else
            BinarySearch(array, x, lb, mid - 1); // Left side array
    }
    else
        return -1;
}

int main()
{
    int size;
    cin >> size;

    int array[size];
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    int userCheckValue;
    cout << "Please enter the value you wont search:-";
    cin >> userCheckValue;

    int indexNumber;
    indexNumber = BinarySearch(array, userCheckValue, 0, size - 1);
    if (indexNumber != -1)
    {
        cout << "Index No " << indexNumber << " Position No " << indexNumber + 1 << endl;
    }
    else
    {
        cout << "Not Found\n";
    }

    return 0;
}