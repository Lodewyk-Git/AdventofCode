#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm> // to use sort

using namespace std;

int median(vector<int> v) { //middle value of ordered array  Size +1 /2 //thus sorting order does not matter
    
    int n = v.size() / 2; // element in middle
    sort(v.begin(), v.end(), greater<int>()); // sort in desc order https://www.geeksforgeeks.org/how-to-sort-a-vector-in-descending-order-using-stl-in-c/

        return v[n];
} // https://www.mathsisfun.com/median.html

int main(){

    ifstream file("../values.txt");
    string line;
    char comma;
    int Temp;
    vector<int> AllCrabs;

    if(file.is_open()){
        while (getline(file,line)){
            stringstream ss(line);
            while (ss>>Temp){
                AllCrabs.push_back(Temp);
                ss>> comma;
            }
        }
    }
    int m = median(AllCrabs); // get middle of sorted Crablist
    int sum = 0;

    //crab moves amount of steps == to difference between starting point and best point (middle when arr is sorted) 
    for ( int c : AllCrabs ) { // for every value in Crab
        sum += abs(c - m); // add difference between middle and current crab value
    }

	cout << "Fuel Spent: " << sum << '\n';
}