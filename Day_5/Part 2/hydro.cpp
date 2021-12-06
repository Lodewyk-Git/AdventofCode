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

bool isY(pair<int,int> Original, pair<int,int> Changed){ //VERTICAL
    return (Original.second == Changed.second ?  true :  false);
}

bool isDiag(pair<int,int> Original, pair<int,int> Changed){ //VERTICAL
    return ((Original.first > Changed.first ?  Original.first - Changed.first :  Changed.first - Original.first)==(Original.second > Changed.second ?  Original.second - Changed.second :  Changed.second - Original.second)) ? true: false;
}

void diagonalOrder(int *arr[1000], int n, int xSTART, int m, int ySTART)
{
    // we will use a 2D vector to
    // store the diagonals of our array
    // the 2D vector will have (n+m-1)
    // rows that is equal to the number of
    // diagonals
    vector<vector<int> > ans;//(n + m - 1);
    //25,153 -> 765,893 ans(740 + 740 -1 )
    // we have a matrix of n rows - x
    // and m columns - y
    //cout << "start " << ySTART << " " << m;
    for (int i = ySTART; i < (ySTART+m); i++)
    {
        for (int j = xSTART; j < (xSTART+n); j++)
        {
            //map[j][i] += 1;
            //cout << "y: " << i << " x: " << j << '\n';
        }
    }
}

/*
vector<vector<pair<int,int>>> getTOPLEFT(){

    vector<pair<int,int>> diagList;
    vector<vector<pair<int,int>>> TOPLEFT;

    for (int i = 0; i < 1999; i++) //top left to bottom right - TOPLEFT
    {
        int k = i - 1;
        diagList.clear();
        for (int i = 0; i < 1000; i++) {
            if(k > -1 && k < 1000){
                diagList.push_back(make_pair(k,i));
            }
            k--;
        }
        TOPLEFT.push_back(diagList);
    } 

    return TOPLEFT;
}

vector<vector<pair<int,int>>> getBOTTOMLEFT(){

    vector<vector<pair<int,int>>> BOTTOMLEFT;
    vector<pair<int,int>> diagList; 

    for (int i = -2000; i < 1000; i++) //top right to bottom left BOTTOMLEFT
    {
        int k = i + 1;
        diagList.clear();
        for (int i = 0; i < 1000; i++) {

            if(k>-1 && k < 1000)
                diagList.push_back(make_pair(i,k));  
            k++;
        }
        BOTTOMLEFT.push_back(diagList);
    }

    return BOTTOMLEFT;
}

bool isTL(pair<int,int> Original, pair<int,int> Changed, vector<vector<pair<int,int>>> TOPLEFT, vector<vector<pair<int,int>>> BOTTOMLEFT){ //TL DIAGONAL

    bool OG = false, CH = false, TL = false;
    
    for (int i = 0; i < TOPLEFT.size(); i++)
    {
        for (int list = 0; list < TOPLEFT[i].size(); list++)
        {
            if(OG == false)
                OG = (TOPLEFT[i][list].first == Original.first)&&(TOPLEFT[i][list].second == Original.second) ? true : false;
            if(CH == false)
                CH = (TOPLEFT[i][list].first == Changed.first)&&(TOPLEFT[i][list].second == Changed.second) ? true : false;
        }
        if(TL == false)
            TL = OG&&CH;
    }

    return TL;
}

bool isBL(pair<int,int> Original, pair<int,int> Changed, vector<vector<pair<int,int>>> TOPLEFT, vector<vector<pair<int,int>>> BOTTOMLEFT){ //TL DIAGONAL


    bool OG = false, CH = false, BL = false;

    for (int i = 0; i < BOTTOMLEFT.size(); i++)
    {
        for (int list = 0; list < BOTTOMLEFT[i].size(); list++)
        {
            if(OG == false)
                OG = (BOTTOMLEFT[i][list].first == Original.first)&&(BOTTOMLEFT[i][list].second == Original.second) ? true : false;
            if(CH == false)
                CH = (BOTTOMLEFT[i][list].first == Changed.first)&&(BOTTOMLEFT[i][list].second == Changed.second) ? true : false;
        }
        if(BL == false)
            BL = OG&&CH;
    }
    
    //bool OG = (find(diagMap.begin(), diagMap.end(), (Original)) != diagMap.end()); doesn't work :(
    //bool CH = (find(diagMap.begin(), diagMap.end(), (Changed)) != diagMap.end()); doesn't work :(
    return BL; 
}
*/
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

    vector<pair<int,int>> diagLine;
    int diag=0;
    for (int bubbles = 0; bubbles < Original.size(); bubbles++){
        int X1, X2, Y1, Y2;
        X1 = Original[bubbles].first;
        X2 = Changed[bubbles].first;
        Y1 = Original[bubbles].second;
        Y2 = Changed[bubbles].second;
        int xdiff = (X1 > X2 ? X1 - X2 : X2 - X1);
        int xsmall = (X1 > X2 ? X2 : X1);
        int ydiff = (Y1 > Y2 ? Y1 - Y2 : Y2 - Y1);
        int ysmall = (Y1 > Y2 ? Y2 : Y1); 

        if(isX(Original[bubbles], Changed[bubbles])){ 
            for (int DIFF = 0; DIFF < ydiff+1; DIFF++)
            {
                map[ysmall+DIFF][X1] += 1;
            }
        }

        if(isY(Original[bubbles], Changed[bubbles])){
            for (int DIFF = 0; DIFF < xdiff+1; DIFF++)
            {
                map[Y1][xsmall+DIFF] += 1;
            }
        }

        if(isDiag(Original[bubbles],Changed[bubbles])){

            for (int i = 0; i < (xsmall+xdiff)*2; i++) // top left to bottom right //used for top and bottom part
            {
                int k = i - 1;
                diagLine.clear();
                for (int i = xsmall; i < xsmall+xdiff; i++) { // this i = rows 
                    if(k > (ysmall-1) && k < ysmall+ydiff){ //k = cols
                        map[i][k] += 1;
                        //cout << i << "," << k << " ";
                    }
                    k--;
                }
            } 
            
            //diagonalOrder(map, xdiff, xsmall, xdiff, ysmall);
            //cout << " x1: "<< X1 << " x2: "<< X2 << " y1: "<< Y1 << " y2: " << Y2 << '\n';
            diag++;
        }
        

       /* if(isBL(Original[bubbles], Changed[bubbles], TOPLEFT, BOTTOMLEFT)){
            int xdiff = 91;
            int ydiff = 91;
            int xsmall = 78;
            int ysmall = 319;
            int ybig = 410;
            for (int i = -xdiff; i < xdiff-1; i++) //bottom left to top right
            {
                int k = i + 1;
                for (int i = ydiff; i < ydiff; i++) {
                    // Printing secondary diagonal
                    if(k>( ysmall-1) && k < ybig)
                        map[i][k] += 1;
                    //if(a[i][k]==0)
                    //    cout << '\n' << i << ","<< k << '\n';
                    k++;
                }
            }
        }
        if(!isY(Original[bubbles], Changed[bubbles])&&!isX(Original[bubbles], Changed[bubbles])){
            int rows = 1000, cols = 1000;
            int diagonals = 1999;
            int m = ( Y1 - Y2 ) / ( X1 - X2 );
            int b = ( ( X1 * X2 ) - ( X2 * Y1 ) ) / ( X1 - X2 );

            if(X2 > X1){
                for(int k = X1;  k < X2-1;  k++){
                    int i=k;
                    int j=0;
                    while(i >= 0){
                        map[i][j] += 1;  
                        i--;
                        j++;
                    }
                }
            }
        }*/
        
    }
    

    int c=0;
    for (size_t i = 0; i < 1000; i++)
    {
        for (size_t a = 0; a < 1000; a++)
        {
            if(map[i][a] > 1)
                c++;
        }
        
    }  

  
    // we have a matrix of n rows - x 
    // and m columns - y
    // Function call
    // (arr, x, ystart, yend)
    //781,721 -> 781,611
    //78,410 -> 169,319
    //25,153 -> 765,893
    diagonalOrder(map, 91, 78, 91, 319);
    diagonalOrder(map, 740, 25, 740, 153);
    
    cout << c << '\n';
    cout << diag << '\n';

    delete(map);
}
