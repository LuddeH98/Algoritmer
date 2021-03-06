#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    int amount = 1000000;
    int* values = new int[amount];
    for (int i = 0; i < amount; i++)
    {
        values[i] = rand() % (amount * 10);
    }

    clock_t t;
    t = clock();

    for (int i = 0; i < amount -1; i++)
    {
        for (int j = i; j < amount; j++)
        {
            if (values[j] < values[i])
            {
                int temp = values[j];
                values[j] = values[i];
                values[i] = temp;
            }
        }
    }

    t = clock() - t;
    /*
    for (int i = 0; i < amount; i++)
    {
        //cout << values[i] << ", ";
    }
    */

    cout << "Time: " << (((float)t)/CLOCKS_PER_SEC) << endl;

    return 0;
}
