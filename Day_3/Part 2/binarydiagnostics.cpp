#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string calculateGammaRate(vector<string> binaryList){
    
    int binaryCount;
    string gammaRate;

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
        else if (binaryCount < 0)
        {
            gammaRate += '0';
        }else
        {
            gammaRate += '1';
        }
        
    }

    return gammaRate;
}

string calculateEpsilonRate(vector<string> binaryList){
    
    int binaryCount;
    string epsilonRate;

    for (int b = 0; b < 12; b++)
    {
        binaryCount = 0;

        for (int a = 0; a < binaryList.size(); a++)
        {
            if (binaryList[a][b] == '1')
            {
                binaryCount--;
            }
            else
            {
                binaryCount++;
            }
        }

        if (binaryCount > 0)
        {
            epsilonRate += '1';  
        }
        else if (binaryCount < 0)
        {
            epsilonRate += '0';
        } else 
        {
            epsilonRate += '0';
        }
        
    }

    return epsilonRate;
}

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

string calculateOxygen(vector<string> diagnosticList){

    int binaryCount;

    while (diagnosticList.size() > 1)
    {
        for (int b = 0; b < 12; b++)
        {
            binaryCount = 0;
            vector<string> commonList;
            for (int a = 0; a < diagnosticList.size(); a++)
            {
                if (diagnosticList[a][b] == '1')
                {
                    binaryCount++;
                }
                else
                {
                    binaryCount--;
                }
            }

            if (binaryCount >= 0) //1
            {
                for (int c = 0; c < diagnosticList.size(); c++)
                {
                    if (diagnosticList[c][b] == '1' && diagnosticList.size() > 1)
                    {
                        commonList.push_back(diagnosticList[c]);
                    }
                }
            }
            else if (binaryCount < 0) // 0
            {
                for (int c = 0; c < diagnosticList.size(); c++)
                {
                    if (diagnosticList[c][b] == '0' && diagnosticList.size() > 1)
                    {
                        commonList.push_back(diagnosticList[c]);
                    }
                }
            }
        diagnosticList = commonList;
        } 
    }

    return diagnosticList[0];
}

string calculateScrubber(vector<string> diagnosticList){

    int binaryCount;

    while (diagnosticList.size() > 1)
    {
        
        for (int b = 0; b < 12; b++)
        {
            binaryCount = 0;
            vector<string> commonList;
            for (int a = 0; a < diagnosticList.size(); a++)
            {
                if (diagnosticList[a][b] == '1')
                {
                    binaryCount++;
                }
                else
                {
                    binaryCount--;
                }
            }

            if (binaryCount >= 0) //1
            {
                for (int c = 0; c < diagnosticList.size(); c++)
                {
                    if (diagnosticList[c][b] == '0' && diagnosticList.size() > 1)
                    {
                        commonList.push_back(diagnosticList[c]);
                    }
                }
            }
            else if (binaryCount < 0) // 0
            {
                for (int c = 0; c < diagnosticList.size(); c++)
                {
                    if (diagnosticList[c][b] == '1' && diagnosticList.size() > 1)
                    {
                        commonList.push_back(diagnosticList[c]);
                    }
                }
            }
        diagnosticList = commonList;
        } 
    }

    return diagnosticList[0];
}

int main(){

    ifstream file("values.txt");
    string line, gammaRate, epsilonRate, oxygenRate, scrubberRate;
    int powerConsumption, lifeSupport;
    vector<string> binaryList;

    if(file.is_open()){
        while (getline(file,line))
        {
            binaryList.push_back(line);
        }
    }

    gammaRate = calculateGammaRate(binaryList);
    epsilonRate = calculateEpsilonRate(binaryList);
    powerConsumption = binaryToDecimal(epsilonRate)*binaryToDecimal(gammaRate);

    oxygenRate = calculateOxygen(binaryList);
    scrubberRate = calculateScrubber(binaryList);

    lifeSupport = binaryToDecimal(scrubberRate)*binaryToDecimal(oxygenRate);

    cout << "gamma rate: "<< gammaRate << " epsilon rate: " 
    << calculateEpsilonRate(binaryList) << " power consumption: " 
    << powerConsumption << "\noxygen generator rating: "
    << oxygenRate << "\nCO2 scrubber rating: "
    << scrubberRate << " life support: "
    << lifeSupport
    << '\n';
}


