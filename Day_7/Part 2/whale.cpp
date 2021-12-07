#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

int mean(vector<int> v){ // sum /size
    
    int sum = 0;
    int size = v.size();
    for (int i = 0; i < v.size(); i++)
        sum += v[i];
    
    return ceil(sum/size); //https://stackoverflow.com/questions/47144083/why-has-stdreduce-been-added-in-c17/47144145 Has to be whole number
}//https://www.mathsisfun.com/mean.html


int main(){

    ifstream file("../values.txt");
    string line;
    char comma;
    int Temp, TotalFuel, holder;
    vector<int> AllCrabs;
    vector<pair<int,int>> BestAllignment; // { Position, Total }

    if(file.is_open()){
        while (getline(file,line)){
            stringstream ss(line);
            while (ss>>Temp){
                AllCrabs.push_back(Temp);
                ss>> comma;
            }
        }
    }
    int m = mean(AllCrabs); 
    int sum = 0;

    // previously the best distance was the distance between the middle and the current crab point - the middle, because it's the closest to every crab when all crabs have to move to a point
    // that was because every crab moved 1 step for every 1 point of difference
    // but now every crab moves x=(x+1) points for every 1 point of difference where x = previous point
    // also the best point != middle anymore, because every crab has a different starting point and the further the crab moves the more points rack up
    // now we have to look at the avg value of change for every crab and get the median distance for every crab 
    for ( int c : AllCrabs ) { 
        int cost = abs(c - m); // to do this we first get the change in difference for the crab or the total diff in position
        sum += cost *(cost+1)/2; // then instead of doing (x+(X+1))... etc we know that the diffrence between one pos and the next
        // will be the pos * ((pos+1)/2)
        // ex 1 to 4, 3 pos doff, 3*((3+1)/2) = 6 , 1+2+3 = 6
    }

    cout << "Total steps travelled " << sum;
}