// C++ Program to print the Diagonals of a Matrix
#include <iostream> 
using namespace std;
 
const int MAX = 100;

int main()
{
    int n = 4;
    int a[][MAX] = { { 1, 2, 3, 4 },
                     { 5, 6, 7, 8 },
                     { 1, 2, 3, 4 },
                     { 5, 6, 7, 8 } };
 
    //printPrincipalDiagonal(a, n);
    //printPrincipalDiagonal(a, n);
    for (int i = 0; i < 2000; i++) // top left to bottom right
    {
        int k = i - 1;
        for (int i = 0; i < 50; i++) {
            if(k > -1 && k < 4)
                cout << i << "," << k << " ";
            k--;
        }
        cout << '\n';
    } 

    /*for (int i = 8; i > 0; i--) // bottom right to top left
    {
        int k = i - 1;
        for (int i = 0; i < 4; i++) {
            // Printing secondary diagonal
            if(a[i][k] != 0)
                cout << a[k][i] << ", ";
            k--;
        }
        cout << '\n';
    } */

    /*for (int i = -4; i < 3; i++) //bottom left to top right
    {
        int k = i + 1;
        for (int i = 0; i < 4; i++) {
            // Printing secondary diagonal
            if(k>-1 && k < 4){
                //cout << k << "," << i << " ";
                cout << a[k][i] << " ";}
            //if(a[i][k]==0)
            //    cout << '\n' << i << ","<< k << '\n';
            k++;
        }
        cout << '\n';
    } */

/*  { 1, 2, 3, 4 }                     
    { 5, 6, 7, 8 }
    { 1, 2, 3, 4 }
    { 5, 6, 7, 8 } */ 
    return 0;
}