#include <stdio.h>

int main(){
   int year;
   printf("enter a year :");
   scanf("%d",&year);
   year%400==0 || year%4==0 && year%100!=0 ? printf("is leap "):printf("not leap");
    return 0;
}