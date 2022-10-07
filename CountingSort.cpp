#include <bits/stdc++.h>

using namespace std;
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
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
    cout << "Before Sort" << endl;
    printArray(array, size);

    // Setp 1 : Finding Max
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    // Setp 2 : Initialization of "count" array
    int count[max + 1];
    for (int i = 0; i < max; i++)
    {
        count[i] = 0;
    }
    cout << "Before Sort2" << endl;
    // Setp 3 : Frequency Calculation
    for (int i = 0; i < size; i++)
    {
        count[array[i]]++;
    }
    cout << "Before Sort3" << endl;
    // Setp 4 : Cumulative sum
    for (int i = 0; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    // Setp 5 : Final Array --- Backward Traversal of Basic Array
    cout << "Before Sort4-8" << endl;
    int final[size];
    for (int i = size - 1; i >= 0; i--)
    {
        count[array[i]]--;
        int k = count[array[i]];
        final[k] = array[i];
    }
    cout << "Before Sort4" << endl;
    cout << "After Sort" << endl;
    printArray(final, size);

    return 0;
}