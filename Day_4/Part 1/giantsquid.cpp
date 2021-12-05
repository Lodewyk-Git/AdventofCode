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

    /*Player b = *Players[1];
        cout << b.Ballot[0][0].second << '\n';
    Player c = *Players[15];
        cout << c.Ballot[2][0].first;
    */

    bool winner = false;
    int winNumber;
    for (int c = 0; c < lotteryList.size(); c++)
    {
            for (int d = 1; d < playerCounter; d++)
            {
                Players[d]->Ballot = checkNumber(Players[d]->Ballot,lotteryList[c]);
                Players[d]->bestline = getBest(Players[d]->Ballot);
                if (Players[d]->bestline >= 5){
                    cout << "Winner: " << d << '\n';
                    cout << "lotteryNumber: " << lotteryList[c] << '\n';
                    winNumber = d;
                    Players[d]->Winner = winner = true;
                    break;
                }
            }
            if (winner == true)
                break;         
    } 

    printBallot(Players[winNumber]->Ballot);

    vector<Player*>::iterator iter, end;
    for(iter = Players.begin(), end = Players.end() ; iter != end; ++iter) {
        delete (*iter);
    }    
}

/*
 //   pair<int,bool> bingoNumber; // 5 values
    xline // bingoNumber, bingoNumber
    yline     bingoNumber
                bingoNumber
                bingoNumber
            
    playerBingoPaper  bingoNumber, bingoNumber
                        bingoNumber, bingoNumber
                    // 5*5 values
    playerList // playerBingoPaper, playerBingoPaper
*/

//10680
// board 10