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

    cout << "Before sort: ";
    printArray(array, size);
    // Bubble sort Implementation
    for (int i = 1; i < size; i++)
    {
        int flag = 0;
        cout << "Iteration No: " << i << endl;
        for (int j = 0; j < size - i; j++)
        {
            // if print small....big using ">"
            // if print big....small using "<"
            if (array[j] > array[j + 1])
            {
                // swap
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = 1;
            }
            printArray(array, size);
        }
        cout << endl;
        if (flag == 0)
            break;
    }

    cout << "After sort: ";
    printArray(array, size);

    return 0;
}