#include <bits/stdc++.h>

using namespace std;

int main()
{
    int size, n;
    cin >> size;

    int array[size];
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    cin >> n;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == n)
        {
            cout << "FOUND at index position: " << i << " ";
        }
        else
        {
            cout << "NOT FOUND" << endl;
        }
    }

    return 0;
}