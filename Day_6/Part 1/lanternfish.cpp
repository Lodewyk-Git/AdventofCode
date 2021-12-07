#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class LanternFish {
    public:
        int Timer;
};

vector<LanternFish*> nextDay(vector<LanternFish*> FishList){

    vector<LanternFish*> AllFish;

    AllFish = FishList;

    for (int currentFish = 0; currentFish < AllFish.size(); currentFish++)
    {
        int Time = AllFish[currentFish]->Timer;
        
        
        
        if(Time == 0){
            AllFish[currentFish]->Timer = 6;
            LanternFish* fish = new LanternFish;
            fish->Timer = 9;
            AllFish.push_back(fish);
        }

        if(Time > 0)
            AllFish[currentFish]->Timer--;
    }
    
    return AllFish;
}

int main(){

    ifstream file("../values.txt");
    string line;
    char comma;
    int Temp, days;
    vector<LanternFish*> AllFish;
    days = 80;

    if(file.is_open()){
        while (getline(file,line)){
            stringstream ss(line);
            while (ss>>Temp){
                LanternFish* fish = new LanternFish;
                fish->Timer = Temp;
                AllFish.push_back(fish);
                ss>> comma;
            }
        }
    }

    for (size_t i = 0; i < days; i++)
    {
        AllFish = nextDay(AllFish);
    }
       
    cout << AllFish.size();

    vector<LanternFish*>::iterator iter, end;
    for(iter = AllFish.begin(), end = AllFish.end() ; iter != end; ++iter)
        delete (*iter);
}