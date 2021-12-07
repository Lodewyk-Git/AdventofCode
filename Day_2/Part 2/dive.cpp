#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){

    ifstream file("../values.txt");
    string line;
    string direction;
    int movement;
    vector<vector<int>> position = {{0, 0, 0}}; //{ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} }; {{"horizontal","depth", "aim"}

    if(file.is_open()){
        while (getline(file,line))
        {
            stringstream dirMove(line);
            dirMove >> direction >> movement;
            if (direction == "forward")
            {
                position[0][0] += movement;
                position[0][1] += position[0][2]*movement;
            }else if(direction == "up")
            {
                position[0][2] -= movement;
            }else if(direction == "down")
            {
                position[0][2] += movement;
            };
        }
    };
   cout << "Horizontal: " << position[0][0] << " Depth: " << position[0][1] << " Aim: " << position[0][2] <<'\n' << "Position: " << position[0][0]*position[0][1];
}