#include <stdio.h>
//print the board
void printBoard(char board[9]){
    printf("  OXOXOXOXOXOXOXOXOXOXO\n");
    printf(" X\t|%c||%c||%c|\tX\n",board[0],board[1],board[2]);
    printf(" O\t=========\tO\n");
    printf(" X\t|%c||%c||%c|\tX\n",board[3],board[4],board[5]);
    printf(" O\t=========\tO\n");
    printf(" X\t|%c||%c||%c|\tX\n",board[6],board[7],board[8]);
    printf("  OXOXOXOXOXOXOXOXOXOXO\n");
   
}
//take input and change board 


//check for

int main(){
    //make the variables
    char board[9]={'_','_','_','_','_','_','_','_','_'};
    //welcome the player 
    //make sure the game continues until winOrLose

    printBoard(board);
    

    return 0;
}