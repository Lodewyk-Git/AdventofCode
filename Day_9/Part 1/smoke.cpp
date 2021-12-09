#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<pair<int, int>> LRUD = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // to get left, right, up and down

int heightAt(int i, int j, const vector<string> &map) //get height value at point
{
    if (j < 0 || j >= map.size() || i < 0 || i >= map[j].size())
        return 1000;
    return map[j][i] - '0';
}

bool isLowPoint(int i, int j, const vector<string> &map) //measure current point vs surrounding points
{
    int h = heightAt(i, j, map);
    for (auto XY : LRUD) // for 
        if (h >= heightAt(i + XY.first, j + XY.second, map))
            return false;

    return true;
}

int main()
{
    vector<string> map;
    ifstream file("../values.txt");
    string line;

    if(file.is_open()){
        while (getline(file,line))
        {
            map.push_back(line);
        }
    }

    int sum = 0;
    for (int j = 0; j < map.size(); j++)
        for (int i = 0; i < map[j].size(); i++)
            if (isLowPoint(i, j, map))//Check if current point is low point
                sum += heightAt(i, j, map) + 1;

    cout << "Total Low Points: "<< sum << endl;
}