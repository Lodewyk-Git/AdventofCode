#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

pair<string, string> splitArrow(string input) {
    pair<string, string> rv;
    int pos = input.find('-');
    rv.first = input.substr(0, pos-1);
    rv.second = input.substr(pos + 3);
    return rv;
}

pair<int, int> getCsvInt(string input) {
    pair<int, int> rv;
    int pos = input.find(",");
    rv.first = stoi(input.substr(0,pos));
    rv.second = stoi(input.substr(pos+1));
    return rv;
}

int main(int argc,  char** argv) {
    fstream file;
    file.open("values.txt", ios::in);
    if(!file || !file.is_open()) {
        printf("skill issue. File not found\n");
        return 1;
    }

    string line;
    map<string, int> collisions;
    while(getline(file, line)) {
        auto gang = splitArrow(line);
        pair<pair<int,int>, pair<int,int>> t;
        t.first = getCsvInt(gang.first);
        t.second = getCsvInt(gang.second);

        bool diagonal = !(t.first.first != t.second.first ^ t.first.second != t.second.second);
        bool lr = t.first.first != t.second.first;

        // This is a horrible way to do this. I do not care
        if(!diagonal) {
            // keep code from part 1
            if(lr) {
                int to = max(t.first.first, t.second.first);
                int from = min(t.first.first, t.second.first);
                for(int i = from; i < to+1; i++) {
                    string pos = to_string(i) + "|" + to_string(t.second.second);
                    if(!collisions[pos]) collisions[pos] = 0;
                    collisions[pos]++;
                }
            } else {
                int to = max(t.first.second, t.second.second);
                int from = min(t.first.second, t.second.second);
                for(int i = from; i < to+1; i++) {
                    string pos = to_string(t.first.first) + "|" + to_string(i);
                    if(!collisions[pos]) collisions[pos] = 0;
                    collisions[pos]++;
                }
            }
        } else {
            int stretch = abs(t.first.first - t.second.first);
            int mode = 0;

            if(t.first.first < t.second.first && t.first.second < t.second.second) mode = 1; // ↗
            else if(t.first.first > t.second.first && t.first.second > t.second.second) mode = 2; // ↙
            else if(t.first.first < t.second.first && t.first.second > t.second.second) mode = 3; // ↘
            else if(t.first.first > t.second.first && t.first.second < t.second.second) mode = 4; // ↖

            // ngl just adding +1 to stretch was a total fluke but it got me the correct answer
            for(int i = 0; i < stretch+1; i++) {
                string pos;
                switch (mode)
                {
                    case 1: 
                        pos = to_string(t.first.first + i) + "|" + to_string(t.first.second + i);
                    break;
                    case 2:
                        pos = to_string(t.first.first - i) + "|" + to_string(t.first.second - i);
                    break;
                    case 3:
                        pos = to_string(t.first.first + i) + "|" + to_string(t.first.second - i);
                    break;
                    case 4:
                        pos = to_string(t.first.first - i) + "|" + to_string(t.first.second + i);
                    break;
                }
                if(!collisions[pos]) collisions[pos] = 0;
                collisions[pos]++;
            }
        }
    }

    cout << collisions.size() << endl;

    int tally = 0;
    for(auto it = collisions.begin(); it != collisions.end(); it++)
        if(it->second >= 2) tally++;
    printf("Answer: %d\n",tally);
}
