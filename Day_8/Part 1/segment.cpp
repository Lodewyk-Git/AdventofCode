#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){

    ifstream file("../values.txt");
    string line, token, delimiter = " ";
    int One, Four, Seven, Eight;
    size_t pos = 0;
    vector<string> input, output;
    One = 0;
    Four = 0;
    Seven = 0;
    Eight = 0;

    if(file.is_open()){
        while (getline(file,line)){
            bool digit = false;
            while ((pos = line.find(delimiter)) != string::npos) {
                token = line.substr(0, pos);
                //cout << token << endl;
                line.erase(0, pos + delimiter.length());
                if(digit == true && token != "|"){
                    output.push_back(token);
                }else if (token != "|"){
                    input.push_back(token);
                }else if(token == "|"){
                    digit = true; 
                }     
            }
            output.push_back(line);
        }
    }

    for(int i=0; i< output.size(); i++){\
        int size = output[i].size();

        if (size == 2)
        {
            One++;
        }else if (size == 3)
        {
            Seven++;
        }else if (size == 4)
        {
            Four++;
        }else if (size == 7)
        {
            Eight++;
        }    
    }
        cout << "1, 4, 7, 8 Total appearances: " << One+Four+Seven+Eight << endl;

}