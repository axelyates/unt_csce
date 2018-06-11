#include <stdio.h>
int sweany(int N)
{

        if( N == 0 ) return 0;

        if( N == 1 ) return 1;

        if( N == 2)  return 3;

        return N + sweany(N-1) + (sweany(N-2) * sweany(N-3));

}

int main()
{
    int i;
    for(i = 0; i <= 11; i++)
        printf("sweany(%2d) = %25d\n",i,sweany(i));
}
