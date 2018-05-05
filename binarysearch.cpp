#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

int binarysearch(int search, int arr[], int low, int high);

int main(int argc, char const *argv[])
{
    int amount = 100;
    int* values = new int[amount];
    for (int i = 0; i < amount; i++)
    {
        values[i] = rand() % (amount * 10);
    }

    // Selectionsort
    for (int i = 0; i < amount - 1; i++)
    {
        int lowest = i;
        for (int j = i; j < amount; j++)
        {
            if (values[j] < values[lowest])
            {
                lowest = j;
            }
        }

        if (lowest != i)
        {
            int temp = values[lowest];
            values[lowest] = values[i];
            values[i] = temp;
        }
    }

    for (int i = 0; i < amount; i++)
    {
        cout << values[i] << ", ";
    }

    int searchValue = 24;

    int exist = binarysearch(searchValue, values, 0, amount);

    cout << endl << "Found " << searchValue << " @ index " << exist << endl;

    return 0;
}


int binarysearch(int search, int arr[], int low, int high)
{
    int middle = (high + low) / 2;

    if (low <= high)
    {
        if (arr[middle] == search)
        {
            return middle;
        }
        else if (search < arr[middle])
        {
            return binarysearch(search, arr, low, middle - 1);
        }
        else
        {
            return binarysearch(search, arr, middle + 1, high);
        }
    }

    return -(low + 1);
}
