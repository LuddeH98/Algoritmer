#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    int amount = 1000;
    int* values = new int[amount];
    for (int i = 0; i < amount; i++)
    {
        values[i] = rand() % (amount * 10);
    }

    clock_t t;
    t = clock();

    for (int i = 1; i < amount; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (values[j] < values[j - 1])
            {
                int temp = values[j];
	            values[j] = values[j-1];
  			    values[j-1] = temp;
            }
        }
    }

    t = clock() - t;

    for (int i = 0; i < amount; i++)
    {
        cout << values[i] << ", " ;
    }
    cout << endl;

    cout << "Time: " << (((float)t)/CLOCKS_PER_SEC) << endl;

    return 0;
}
