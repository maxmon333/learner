#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
//printboard
void printBoard(char *board[]){
    printf("|%s|%s|%s|\n",board[0],board[1],board[2]);
    printf("*******\n");
    printf("|%s|%s|%s|\n",board[3],board[4],board[5]);
    printf("*******\n");
    printf("|%s|%s|%s|\n",board[6],board[7],board[8]);   
} 
//take input
void playerInput(char *board[],char currentplayer[]){
    int choice ;
    printf("Enter a number 1-->9 :");
    scanf("%d",&choice);
    if (strcmp(board[choice-1],"-")==0){
        if(strcmp(currentplayer,"X")==0){
            board[choice-1]="X";
        }
        else if (strcmp(currentplayer,"O")==0){
           board[choice-1]="O";
        }   
    }
    else if (choice<1||choice>9){
        printf("I said from 1 to 9!! \n");
    }
    else{
        printf("This place is already taken!!\n");
    }    
}
//check tie
bool checkTie(char *board[]){
    for (int i=0;i<9;i++){
        if (strcmp(board[i],"-")==0){
            return false;
        }
    }
    printf("IT'S A TIE!!\n");
    return true;
}
//checkH
bool checkH(char *board[],char winner[]){
    
    if(board[0]==board[1]&&board[1]==board[2]&&board[1]!="-"){
        strcpy(winner,board[1]);
        return true;
    }
    else if(board[3]==board[4]&&board[4]==board[5]&&board[4]!="-"){
        strcpy(winner,board[4]);
        return true;
    }
    else if(board[6]==board[7]&&board[7]==board[8]&&board[7]!="-"){
        strcpy(winner,board[7]);
        return true;
    }
    else{
        return false;
    }
}
//checkV
bool checkV(char *board[],char winner[]){

    if(board[0]==board[3]&&board[3]==board[6]&&board[3]!="-"){
        strcpy(winner,board[3]);
        return true;
    }
    else if(board[1]==board[4]&&board[4]==board[7]&&board[4]!="-"){
        strcpy(winner,board[4]);
        return true;
    }
    else if(board[2]==board[5]&&board[5]==board[8]&&board[5]!="-"){
        strcpy(winner,board[5]);
        return true;
    }
    else{
        return false;
    }
}
//checkD
bool checkD(char *board[],char winner[]){
    if(board[2]==board[4]&&board[4]==board[6]&&board[4]!="-"){
        strcpy(winner,board[4]);
        return true;
    }
    else if(board[0]==board[4]&&board[4]==board[8]&&board[4]!="-"){
        strcpy(winner,board[4]);
        return true;
    }
    else{
        return false;
    }
}
//check win 
bool checkWin(char *board[],char winner[] ){
    if (checkD(board,winner)||checkH(board,winner)||checkV(board,winner)){
        printf("PLAYER %s WON!!\n", winner);
        printf("|%s|%s|%s|\n",board[0],board[1],board[2]);
        printf("*******\n");
        printf("|%s|%s|%s|\n",board[3],board[4],board[5]);
        printf("*******\n");
        printf("|%s|%s|%s|\n",board[6],board[7],board[8]); 
        return true;
    }
    else{
        return false;
    }
}
//switch player
void switchplayer(char currentplayer[]){
    if (strcmp(currentplayer,"X")==0){
        strcpy(currentplayer,"O");
    }
    else{
        strcpy(currentplayer,"X");
    }
}
int main(){
char *board[9]={"-","-","-",
                "-","-","-",
                "-","-","-"};
char currentplayer[2]= "X";
char winner[10]="";
bool isrunning=true;
while(isrunning){
    printBoard(board);
    playerInput(board,currentplayer);
    switchplayer(currentplayer);
    if (checkTie(board)){
        isrunning=false;
    }
    else if (checkWin(board,winner)){
         isrunning=false;
    }   
}
}