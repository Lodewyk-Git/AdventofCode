#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<algorithm>
#include <typeinfo>

using namespace std;

string removeChars(string string1, string string2) { // https://www.geeksforgeeks.org/remove-characters-from-the-first-string-which-are-present-in-the-second-string/
       //we extract every character of string string 2
         for(auto i:string2)
        {
           //we find char exist or not
           while(find(string1.begin(),string1.end(),i)!=string1.end())
            {
                auto itr = find(string1.begin(),string1.end(),i);
               //if char exists we simply remove that char
                string1.erase(itr);
            }
        }
        return string1;
    }

int main(){

    ifstream file("../values.txt");
    string Numbers[10]; // was going to use to store all values, but ended up only needing to store 4 values.
    string line, token, delimiter = " "; //needed to get input
    string posA, posB, posC, posD, posE, posF, posG, EorG, CorF, BorD;
    size_t pos = 0; // used for token
    vector<string> output;
    long long Total = 0; //used to count 

    if(file.is_open()){
        while (getline(file,line)){

            bool digit = false;
            string ZeroorSixorNine = "", number = "";

            output.clear();//next line

            while ((pos = line.find(delimiter)) != string::npos) {
                token = line.substr(0, pos);
                int size = token.size();
                line.erase(0, pos + delimiter.length());
                if(digit == true && token != "|"){
                    output.push_back(token);
                }else if (token != "|"){
                    if(size == 3) //Number 7
                        Numbers[7] = token;
                    if(size == 2)// Number 1
                        Numbers[1] = token;
                    if(size == 4)
                        Numbers[4] = token;
                    if(size == 7)
                        Numbers[8] = token;
                    if(size == 6)
                        ZeroorSixorNine += token + " ";
                }else if(token == "|"){
                    digit = true; 
                }  

            }

            output.push_back(line); //get last value since delim is " " and string ends with '\n'
            
            posA = (removeChars(Numbers[7], Numbers[1]));
            EorG = (removeChars(Numbers[8], posA+Numbers[4]));
            CorF = (Numbers[1]);
            BorD = (removeChars(Numbers[8], posA+CorF+EorG));
            
            string ZSN = ZeroorSixorNine, ZSN2 = ZeroorSixorNine; //duplicate to get other values
            while ((pos = ZeroorSixorNine.find(delimiter)) != string::npos) {
                token = ZeroorSixorNine.substr(0, pos);
                ZeroorSixorNine.erase(0, pos + delimiter.length());
                if(removeChars(token, posA+CorF+EorG).size()==1)
                    posB = removeChars(token, posA+CorF+EorG); 
            }
            posD = removeChars(BorD, posB);

            while ((pos = ZSN.find(delimiter)) != string::npos) {
                token = ZSN.substr(0, pos);
                ZSN.erase(0, pos + delimiter.length());
                if(removeChars(token, posA+posB+posD+EorG).size()==1)
                    posF = removeChars(token, posA+posB+posD+EorG); 
            }
            posC = removeChars(CorF, posF);

            while ((pos = ZSN2.find(delimiter)) != string::npos) {
                token = ZSN2.substr(0, pos);
                ZSN2.erase(0, pos + delimiter.length());
                if(removeChars(token, posA+posB+posC+posD+posF).size()==1)
                    posG = removeChars(token, posA+posB+posC+posD+posF); 
            }
            posE = removeChars(EorG, posG);

            for (size_t i = 0; i < output.size(); i++)
            {
                if(removeChars(output[i],posA+posB+posC+posE+posF+posG).size() == 0 && output[i].size()==6)//0
                    number += '0';
                if(removeChars(output[i],posC+posF).size() == 0 && output[i].size()==2)//1
                    number += '1';
                if(removeChars(output[i],posA+posC+posD+posE+posG).size() == 0 && output[i].size()==5)//2
                    number += '2';
                if(removeChars(output[i],posA+posC+posD+posF+posG).size() == 0 && output[i].size()==5)//3
                    number += '3';
                if(removeChars(output[i],posB+posC+posD+posF).size() == 0 && output[i].size()==4)//4
                    number += '4';
                if(removeChars(output[i],posA+posB+posD+posF+posG).size() == 0 && output[i].size()==5)//5
                    number += '5';
                if(removeChars(output[i],posA+posB+posD+posE+posF+posG).size() == 0 && output[i].size()==6)//6
                    number += '6';
                if(removeChars(output[i],posA+posC+posF).size() == 0 && output[i].size()==3)//7
                    number += '7';
                if(removeChars(output[i],posA+posB+posC+posD+posE+posF+posG).size() == 0 && output[i].size()==7)//8
                    number += '8';
                if(removeChars(output[i],posA+posB+posC+posD+posF+posG).size() == 0 && output[i].size()==6)//9
                    number += '9';
            }
            Total += stoll(number);
        }
    }

    std::cout << "The number you are looking for is: "<< Total;

}