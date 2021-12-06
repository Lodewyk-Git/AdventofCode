#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int TotalFish;

int main(){

    ifstream file("values.txt");
    string line;
    char comma;
    int Timer, days;
    vector<int> LanternFishes;
    days - 256;

    if(file.is_open()){
        while (getline(file,line)){
            stringstream ss(line);
            while (ss>>Timer){
                LanternFishes.push_back(Timer);
                ss>> comma;
            }
        }
    }

    long long timers[9] = { 0 };

    for (int lf : LanternFishes)
    {
        ++timers[lf];
    }

    for (int i = 0; i < days; ++i)
    {
        rotate(&timers[0], &timers[0] + 1, &timers[9]);
        timers[6] += timers[8];
    }

    long long TotalFish = 0;
    for (int i = 0; i < 9; ++i)
    {
        TotalFish += timers[i];
    }

    cout << TotalFish; 

}