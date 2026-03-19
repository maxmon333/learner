#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <unistd.h> 
#include <time.h>
void CheckResult(const char *options[],int choice,int PC_choice){
    if (options[choice-1]==options[PC_choice]){
        printf("YOU: %s\n",options[choice-1]);
        printf("PC: %s\n",options[PC_choice]);
        printf("IT'S A TIE!\n");
    }
    else if (choice-1==0){
        if (PC_choice==1){
            printf("YOU: %s\n",options[choice-1]);
            printf("PC: %s\n",options[PC_choice]);
            printf("YOU LOST!!\n");            
        }
        else{
            printf("YOU: %s\n",options[choice-1]);
            printf("PC: %s\n",options[PC_choice]);
            printf("YOU WON!!\n");
        }
    }
    else if (choice-1==1){
        if (PC_choice==2){
            printf("YOU: %s\n",options[choice-1]);
            printf("PC: %s\n",options[PC_choice]);
            printf("YOU LOST!!\n");
        }
        else{
            printf("YOU: %s\n",options[choice-1]);
            printf("PC: %s\n",options[PC_choice]);
            printf("YOU WON!!\n");
        }
    }
    else if (choice-1==2){
        if (PC_choice==0){
            printf("YOU: %s\n",options[choice-1]);
            printf("PC: %s\n",options[PC_choice]);
            printf("YOU LOST!!\n");   
        }
        else{
            printf("YOU: %s\n",options[choice-1]);
            printf("PC: %s\n",options[PC_choice]);
            printf("YOU WON!!\n");
        }   
    }   
}
int main(){
    srand(time(NULL));
    int choice;
    int PC_choice;
    const char *options[3]={"Rock🪨","paper📃","sciossors✂️"};
    printf("choose (1)%s,(2)%s,(3)%s :",options[0],options[1],options[2]);
    scanf("%d",&choice);
    PC_choice= rand() % 3 ;
    printf("1\n");
    sleep(1);
    printf("2\n");
    sleep(1);
    printf("3\n");
    sleep(1);
    printf("GO!!\n");
    CheckResult(options,choice,PC_choice);
    return 0;
}