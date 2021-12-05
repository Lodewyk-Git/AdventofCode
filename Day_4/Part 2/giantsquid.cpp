#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){

    ifstream file("values.txt");
    string line;
    vector<string> binaryList;

    if(file.is_open()){
        while (getline(file,line))
        {
            binaryList.push_back(line);
        }
    }

}


