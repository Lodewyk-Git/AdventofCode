#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    
    std::ifstream file("../values.txt");
    std::string line;

    int CurrentNumber;
    int PreviousNumber;
    int Total;

    Total = -1;
    PreviousNumber = 0;

    if(file.is_open()){
        while (getline(file,line))
        {
            std::stringstream lineNumber(line);
            lineNumber >> CurrentNumber;
            //std::cout << CurrentNumber << "  " << PreviousNumber << '\n';
            if (PreviousNumber < CurrentNumber)
            {
                Total++;
            }
            PreviousNumber = CurrentNumber;
        }
    std::cout << Total; 
    };
}