#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    int amount = 100;
    int* values = new int[amount];
    for (int i = 0; i < amount; i++)
    {
        values[i] = rand() % (amount * 10);
    }

    clock_t t;
    t = clock();

    

    t = clock() - t;

    cout << "Time: " << (((float)t)/CLOCKS_PER_SEC) << endl;

    return 0;
}
