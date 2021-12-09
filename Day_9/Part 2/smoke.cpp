#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

vector<pair<int, int>> LRUD = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int heightAt(int i, int j, const vector<string> &map)
{
    if (j < 0 || j >= map.size() || i < 0 || i >= map[j].size())
        return 1000;
    return map[j][i] - '0';
}

bool isLowPoint(int i, int j, const vector<string> &map)
{
    int h = heightAt(i, j, map);
    for (auto nCoord : LRUD)
        if (h >= heightAt(i + nCoord.first, j + nCoord.second, map))
            return false;

    return true;
}

void visitBasin(int i, int j, const vector<string> &map, set<pair<int, int>> &basin)
{
    int h = heightAt(i, j, map);
    if (h >= 9 || basin.count({i, j}) != 0)
        return;

    basin.insert({i, j});

    for (auto coord : LRUD)
        if (h < heightAt(i + coord.first, j + coord.second, map))
            visitBasin(i + coord.first, j + coord.second, map, basin);
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

    vector<int> Basins;
    for (int j = 0; j < map.size(); j++)
    {
        for (int i = 0; i < map[j].size(); i++)
        {
            if (isLowPoint(i, j, map))
            {
                set<pair<int, int>> basin;
                visitBasin(i, j, map, basin);
                Basins.push_back(basin.size());
            }
        }
    }
    sort(Basins.begin(), Basins.end());
    int s = Basins.size();
    cout << "The size of your top 3 basins are: " << Basins[s - 1] * Basins[s - 2] * Basins[s - 3] << endl;
}