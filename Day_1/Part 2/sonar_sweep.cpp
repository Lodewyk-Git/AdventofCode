#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    
    std::ifstream file("../values.txt");
    std::string line;
    std::vector<int> numbers;
    
    int CurrentNumber;
    int PreviousNumber;
    int Total;
    int NumberOne;
    int NumberTwo;
    int NumberThree;
    int size;

    CurrentNumber = 0;
    PreviousNumber = 0;
    Total = -1;
    

    if(file.is_open()){
        while (getline(file,line))
        {
            std::stringstream lineNumber(line);
            lineNumber >> CurrentNumber;
            numbers.push_back(CurrentNumber);
        }
    
    size = numbers.size();

    for (int count = 0; count < (size-2); count++){
            
            NumberOne = numbers[count];
            NumberTwo = numbers[count+1];
            NumberThree = numbers[count+2];                    

            CurrentNumber = (NumberOne + NumberTwo + NumberThree);

            if (PreviousNumber < CurrentNumber)
            {
                Total++; 
            }
            PreviousNumber = CurrentNumber;
        }
        std::cout << "Sums larger than previous sum: " << Total;
    };
}