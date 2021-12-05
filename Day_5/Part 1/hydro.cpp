#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int **map = new int*[1000]; 

bool isX(pair<int,int> Original, pair<int,int> Changed){ //HORIZONTAL
    return (Original.first == Changed.first ?  true :  false);
}

bool isY(pair<int,int> Original, pair<int,int> Changed){ //DIAGONAL
    return (Original.second == Changed.second ?  true :  false);
}

int main(){

    ifstream file("values.txt");
    string line;
    int x1, x2, y1, y2;
    char junk;
    vector<pair<int,int>> Original, Changed;

    for (int i = 0 ; i < 1000 ; i++) 
        map[i] = new int[1000];

    for (size_t i = 0; i < 1000; i++)
    {
        for (size_t a = 0; a < 1000; a++)
        {
            map[i][a] = 0;
        }
        
    }

    if(file.is_open()){
        while (getline(file,line))
        {
            stringstream Coordinates(line);
            Coordinates >> x1 >> junk >> y1 >> junk >> junk  >> x2 >> junk >> y2;
            Original.push_back(make_pair(x1,y1));
            Changed.push_back(make_pair(x2,y2));
        }
    };  

    int c=0;
    for (int bubbles = 0; bubbles < Original.size(); bubbles++){

        if(isX(Original[bubbles], Changed[bubbles])){
            int ydiff = (Original[bubbles].second > Changed[bubbles].second ? Original[bubbles].second - Changed[bubbles].second : Changed[bubbles].second - Original[bubbles].second);
            int ysmall = (Original[bubbles].second > Changed[bubbles].second ? Changed[bubbles].second : Original[bubbles].second); 
            for (int DIFF = 0; DIFF < ydiff+1; DIFF++)
            {
                map[Original[bubbles].first][ysmall+DIFF] += 1;
                //cout<< map[Original[bubbles].first][ysmall+x]<< " y\n";
            }
            //cout << Original[bubbles].second  << " new: " << Changed[bubbles].second << " smallest: " << ysmall << '\n';
            //cout << ydiff << " y " << ysmall << '\n'; 
        }

        if(isY(Original[bubbles], Changed[bubbles])){
            int xdiff = (Original[bubbles].first > Changed[bubbles].first ? Original[bubbles].first - Changed[bubbles].first : Changed[bubbles].first - Original[bubbles].first);
            int xsmall = (Original[bubbles].first > Changed[bubbles].first ? Changed[bubbles].first : Original[bubbles].first); 
            for (int DIFF = 0; DIFF < xdiff+1; DIFF++)
            {
                map[xsmall+DIFF][Original[bubbles].second] += 1;
                //cout<< map[xsmall+i][Original[bubbles].second]<< " x\n";
            }
            //cout << xdiff << " y " << xsmall << '\n'; 
        }
        
    }
    
    for (size_t i = 0; i < 1000; i++)
    {
        for (size_t a = 0; a < 1000; a++)
        {
            if(map[i][a] > 1)
                c++;
        }
        
    }  
    
    cout << c;
    delete(map);

}
//3990
 /*

    int xdiff, ydiff, xsmall, ysmall;
    for (int bubbles = 0; bubbles < Original.size(); bubbles++)
    {

        if(isX(Original[bubbles], Changed[bubbles])){
            ydiff = (Original[bubbles].second > Changed[bubbles].second ? Original[bubbles].second - Changed[bubbles].second : Changed[bubbles].second - Original[bubbles].second);
            ysmall = (Original[bubbles].second > Changed[bubbles].second ? Changed[bubbles].second : Original[bubbles].second); 
            for (int i = 0; i < ydiff; i++)
            {
                map[Original[bubbles].first][ysmall+ydiff] += 1;
                //cout<< map[Original[bubbles].first][ysmall+ydiff]<< " y\n";
            }  
            cout << ydiff << " y " << ysmall << '\n'; 
        }       
            
        if(isY(Original[bubbles], Changed[bubbles]))
        {
            xdiff = (Original[bubbles].first > Changed[bubbles].first ? Original[bubbles].first - Changed[bubbles].first : Changed[bubbles].first - Original[bubbles].first);
            xsmall = (Original[bubbles].first > Changed[bubbles].first ? Changed[bubbles].first : Original[bubbles].second); 
            for (int i = 0; i < xdiff; i++)
            {
                map[xsmall+xdiff][Original[bubbles].second] += 1;
                //cout << map[xsmall+xdiff][Original[bubbles].second] << " x\n";
            }
            cout << xdiff << " x " << xsmall << '\n'; 
        }

    }
}
*/