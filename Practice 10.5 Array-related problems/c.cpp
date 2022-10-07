#include <bits/stdc++.h>

using namespace std;

int main()
{
    int size, temp, i, j;
    cin >> size;

    int array[size];
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    for (i = 0, j = size - 1; i < size / 2; i++, j--)
    {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    for (i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}