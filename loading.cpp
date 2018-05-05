#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <string>
#include <unistd.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    int resolution = 100;
    for (int i = 0; i < resolution; i++)
    {
        line += ".";
    }
    line.insert(0, "[");
    line += "] |";

    int tick = 4;
    char chars[4] = {'|', '/', '-', '\\'};
    for (int i = 0; i < resolution; i++)
    {
        tick = i % 4;
        line[line.length() - 1] = chars[tick];

        line[line.find(".")] = '#';
        cout << "\r" << line << "\t" << flush;
        usleep(50000);
    }

    cout << endl;

    return 0;
}
