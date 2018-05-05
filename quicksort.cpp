#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

void quicksort(int arr[], int left, int right);
int partitioner(int arr[], int left, int right);
int insertionsort(int arr[], int left, int right);
int median3(int arr[], int left, int right);

int main(int argc, char const *argv[])
{
    srand((float)time(0));
    long long amount = 1000000;

    int benchmarks = 10;
    clock_t totalTime = 0;
    clock_t bestTime = INT_MAX;
    clock_t worstTime = 0;


    for (int b = 0; b < benchmarks; b++)
    {
        int* values = new int[amount];
        for (int i = 0; i < amount; i++)
        {
            values[i] = rand() % (amount * 10);
        }

        clock_t t;
        t = clock();

        quicksort(values, 0, amount);

        totalTime += clock() - t;

        if (t < bestTime)
        {
            bestTime = t;
        }
        if (worstTime < t)
        {
            worstTime = t;
        }

        delete[] values;
    }

    cout << endl << "Average time: " << ((float)totalTime/CLOCKS_PER_SEC) / benchmarks << "s" << endl;
    cout << "Best time: " << ((float)bestTime/CLOCKS_PER_SEC) / benchmarks << "s" << endl;
    cout << "Worst time: " << ((float)worstTime/CLOCKS_PER_SEC) / benchmarks << "s" << endl;

    return 0;
}

// Function called to run the Quicksort algorithm
void quicksort(int arr[], int left, int right)
{
    if (left < right)
    {
        // Run insertionsort if there is only a few elements left
        int pivot;
        if ((right - left) < 6)
        {
            pivot = insertionsort(arr, left, right);
        }
        else
        {
            pivot = partitioner(arr, left, right);
        }


        // Recursevly call quicksort again, but on each half of the array
        quicksort(arr, left, pivot - 1);
        quicksort(arr, pivot + 1, right);
    }
}

// Moves all elements lower than the pivot element to the left side of it
int partitioner(int arr[], int left, int right)
{
    // The pivot is choosen by the median of 3 elements (left, middle , right)
    int pivot = median3(arr, left, right);
    int lowest = left;

    // Start at the lowest position of the partition
    for (int i = left; i < right; i++)
    {
        // If arr[i] is less than pivot's value, swap it's position with the pivot
        if (arr[i] <= pivot)
        {
            int temp = arr[lowest];
            arr[lowest] = arr[i];
            arr[i] = temp;
            lowest++;
        }
    }

    // Swap pivot and the largest element
    int temp = arr[lowest];
    arr[lowest] = arr[right];
    arr[right] = temp;

    // Position of the lowest index
    return lowest;
}

int insertionsort(int arr[], int left, int right)
{
    int amount = right - left;
    for (int i = 1; i < amount; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
	            arr[j] = arr[j-1];
  			    arr[j-1] = temp;
            }
        }
    }
    return left;
}

// Calculates the median of 3 elements of an array
int median3(int arr[], int left, int right)
{
    int middle = (left + right) / 2;
    int values[3] = {arr[left], arr[middle], arr[right]};

    insertionsort(values, 0, 3);
    return values[1];
}
