#include <bits/stdc++.h>

using namespace std;

int main()
{
    int size, sum = 0;
    cin >> size;

    int array[size];
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
        if (i % 2 == 0)
        {
            sum += array[i];
        }
    }
    cout << sum << endl;

    return 0;
}