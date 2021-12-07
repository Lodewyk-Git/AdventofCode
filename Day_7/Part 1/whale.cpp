#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int median(vector<int> v) {  // https://www.geeksforgeeks.org/stdnth_element-in-cpp/
    int n = v.size() / 2;
    nth_element(v.begin(), v.begin()+n, v.end());
    return v[n];
} // https://www.mathsisfun.com/median.html

int main(){

    ifstream file("values.txt");
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
    int m = median(AllCrabs);
    int sum = 0;

    for ( int c : AllCrabs ) {
        sum += abs(c - m);
    }

	cout << "Fuel Spent: " << sum << std::endl;
}