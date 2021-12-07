#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}

int main(){

    ifstream file("../values.txt");
    string line, gammaRate, epsilonRate;
    int powerConsumption;
    vector<string> binaryList;

    gammaRate = "";
    epsilonRate = "";

    if(file.is_open()){
        while (getline(file,line))
        {
            binaryList.push_back(line);
        }
    }

    int binaryCount;

    for (int b = 0; b < 12; b++)
    {
        binaryCount = 0;

        for (int a = 0; a < binaryList.size(); a++)
        {
            if (binaryList[a][b] == '1')
            {
                binaryCount++;
            }
            else
            {
                binaryCount--;
            }
        }

        if (binaryCount > 0)
        {
            gammaRate += '1';  
        }
        else
        {
            gammaRate += '0';
        }
        
    }

    for (int c = 0; c < gammaRate.size(); c++)
    {
        if (gammaRate[c] == '0')
        {
            epsilonRate += '1';  
        }
        else
        {
            epsilonRate += '0';
        } 
    }

    powerConsumption = binaryToDecimal(epsilonRate)*binaryToDecimal(gammaRate);

    cout << gammaRate << " " << epsilonRate << " " << powerConsumption << '\n';
}//3808
//287

