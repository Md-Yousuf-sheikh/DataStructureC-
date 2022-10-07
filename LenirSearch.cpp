#include <bits/stdc++.h>

using namespace std;

int main()
{
    int size;
    cin >> size;

    int array[size];
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    // check user search (Y/N)
    char c;
    cout << "Do you wont to search (Y/N) ";
    cin >> c;

    while (toupper(c) == 'Y')
    {
        // search
        int userCheckValue;
        cout << "Please enter the value you wont search:-";
        cin >> userCheckValue;

        int flag = 0;

        for (int i = 0; i < size; i++)
        {
            if (array[i] == userCheckValue)
            {
                cout << "Position ->" << i << " The index ->" << i + 1;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << "Not Found!\n";
        }

        cout << "Do you wont to Continue (Y/N) ";
        cin >> c;
    }

    return 0;
}