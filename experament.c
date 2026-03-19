#include <stdio.h>
void increment( int &a )
{
a = a + 1;
printf( "a in increment: %d", a );
}
int main()
{
int q = 3;
increment( q );
printf( "q in main: %d", q );
return 0;
}
