#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    int amount = 10000;
    int* values = new int[amount];
    for (int i = 0; i < amount; i++)
    {
        values[i] = rand() % (amount * 10);
    }

    clock_t t;
    t = clock();

    for (int gap = amount / 2; gap > 0; gap /= 2)
    {
        for (int i = 0; i < amount; i++)
        {
            int temp = values[i];

            int j;
            for (j = i; j >= gap && values[j - gap] > temp; j -= gap)
            {
                values[j] = values[j - gap];
            }
            values[j] = temp;
        }
    }

    t = clock() - t;

    cout << "Time: " << (((float)t)/CLOCKS_PER_SEC) << endl;

    return 0;
}
