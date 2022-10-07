#include <bits/stdc++.h>

using namespace std;

int main()
{

    int array[4];
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> array[i];
        if (array[i] >= 10)
        {
            sum += 1;
        }
    }
    cout << sum;

    return 0;
}