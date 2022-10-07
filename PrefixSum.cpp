#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[5] = {10, 8, 1, 2, 5};
    int pre[5], sum = 0;
    pre[0] = arr[0];
    for (int i = 1; i < 5; i++)
    {
        pre[i] = arr[i] + pre[i - 1];
    }

    for (int i = 0; i < 5; i++)
    {
        cout << pre[i] << " ";
        sum += pre[i];
    }
    cout << "\nTotal sum: " << sum;
    return 0;
}