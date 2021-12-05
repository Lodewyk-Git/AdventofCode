#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Player {
    public:
        int Number;
        vector<vector<pair<int,bool>>> Ballot;
        int bestline;
        bool Winner;
};

vector<vector<pair<int,bool>>> checkNumber(vector<vector<pair<int,bool>>> Ballot, int number){
    
    vector<vector<pair<int,bool>>> newBallot;

    for (int a = 0; a < 5; a++)
        {
            vector<pair<int,bool>> ballotLine;
            for (int b = 0; b < 5; b++)
            {
                if (Ballot[a][b].first == number)
                {
                    ballotLine.push_back(make_pair(Ballot[a][b].first,true));
                }else if ((Ballot[a][b].first != number) && (Ballot[a][b].second == false)){
                    ballotLine.push_back(make_pair(Ballot[a][b].first,false));
                }else if((Ballot[a][b].first != number) && (Ballot[a][b].second == true)){
                    ballotLine.push_back(make_pair(Ballot[a][b].first,true));
                }else{
                    ballotLine.push_back(make_pair(Ballot[a][b].first,false));
                }
            }
            newBallot.push_back(ballotLine); 
        }

    return newBallot;
}

int getBest(vector<vector<pair<int,bool>>> Ballot){ 
    int best, best2;

    for (int a = 0; a < 5; a++)
        {
            best = 0;
            best2 = 0;
            for (int b = 0; b < 5; b++)
            {
                if (Ballot[a][b].second == true)
                    best++;
                if (Ballot[b][a].second == true)
                    best2++;

                if ((best == 5) || (best2 == 5))
                {
                    return (best<best2 ? best2 : best);
                }  
            }
        }

    if (best < best2)
        return best2;
    else
        return best;
}

vector<int> getLotteryNumbers(string line){
    
    int lottery;
    char comma;
    vector<int> lotteryList;
    stringstream lotteryNumber(line);

    while (lotteryNumber >> lottery)
    {
        lotteryList.push_back(lottery);
        lotteryNumber >> comma;   
    }

    return lotteryList;
}

void printBallot(vector<vector<pair<int,bool>>> Ballot){
    for (int rows = 0; rows < Ballot.size(); rows++)
    {
            for (int columns = 0; columns < Ballot[rows].size(); columns++)
            {
                cout << Ballot[rows][columns].first << " {" << Ballot[rows][columns].second << "} ";
            }
            cout <<  "\n";
    }
}

int main(){

    ifstream file("values.txt");
    string line;
    int playerCounter;
    vector<int> lotteryList;
    vector<string> playerBallot;
    vector<vector<string>> playerList;
    vector<Player*>Players;

    getline(file, line);
    lotteryList = getLotteryNumbers(line);
    playerCounter = 0;

    if(file.is_open()){
        while (getline(file,line))
        {
            if (line == "")
            {
                playerCounter++;
                playerList.push_back(playerBallot);
                Player* player = new Player;
                
                for (int a = 0; a < playerBallot.size(); a++)
                {
                    vector<pair<int,bool>> ballotLine;
                    stringstream  ss(playerBallot[a]); 
                    int Temp;
                    while (ss>>Temp)
                    {
                        ballotLine.push_back(make_pair(Temp,false));
                    }
                    player->Ballot.push_back(ballotLine);
                }
                player->Number = playerCounter-1;
                player->Winner = false;
                player->bestline = 0;
                Players.push_back(player);
                playerBallot.clear();

            }else{
                playerBallot.push_back(line);
            }      
        }
    }

    int MaxWin, longest;
    longest = 0;
    for (int number = 1; number < Players.size(); number++)
    {
        MaxWin = 0;
        for (int c = 0; c < lotteryList.size(); c++)
        {
            MaxWin++;
            if (Players[number]->Winner != true)
            {
                Players[number]->Ballot = checkNumber(Players[number]->Ballot,lotteryList[c]);
                Players[number]->bestline = getBest(Players[number]->Ballot);
                if (Players[number]->bestline >= 5){
                    cout << "Winner: " << Players[number]->Number << '\n';
                    cout << "lotteryNumber: " << lotteryList[c] << '\n';
                    Players[number]->Winner = true;
                    break;
                }
            }      
        }
        longest<MaxWin ? longest = MaxWin : longest=longest;
        cout << "Current Longest " << longest << '\n';   
    }
    
    cout << "I choose Ballot: " << Players[95]->Number << '\n';
    printBallot(Players[95]->Ballot);

    vector<Player*>::iterator iter, end;
    for(iter = Players.begin(), end = Players.end() ; iter != end; ++iter) {
        delete (*iter);
    }    
}