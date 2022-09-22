/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Lesson4a
//Author: Kevin Zhang
//make a chessboard
#include <iostream>
using namespace std;

enum pieces {
    pawn = 1, 
    knight, 
    bishop, 
    rook, 
    queen,
    king};
    
int main()
{
    pieces arr [8][8] = {};
    for (int i = 0; i < 8; i++){
        if (i == 0 || i == 7) {
          arr[i][0]=rook;
          arr[i][1]=knight;
          arr[i][2]=bishop;
          
          if (i == 0) {
          arr[i][3]=queen;
          arr[i][4]=king;
          }
          
         if (i == 7) {
          arr[i][3]=king;
          arr[i][4]=queen;
         }
         
          arr[i][5]=bishop;
          arr[i][6]=knight;
          arr[i][7]=rook;
        }
        
        if (i == 1 || i == 6) {
            for (int j = 0; j < 8; j++){
                arr[i][j] = pawn;
            }
        }
        
    }
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
        cout << arr[i][j];
        }
        cout<<"\n";
    }

}


