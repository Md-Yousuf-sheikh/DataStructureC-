#include <bits/stdc++.h>

using namespace std;

int main()
{
    int size, min, max, indexMin = 0, indexMax;
    cin >> size;

    int array[size];
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    max = array[0];
    min = array[0];

    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            indexMax = i;
        }
        if (array[i] < min)
        {
            min = array[i];
            if (i != 0)
            {
                indexMin = i;
            }
        }
    }

    cout << "Max: " << max << ", Index: " << indexMax;
    cout << "\nMin: " << min << ", Index: " << indexMin;

    return 0;
}