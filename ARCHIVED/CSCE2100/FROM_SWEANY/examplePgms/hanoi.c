#include <stdio.h>

main()
{
    printf("The solution for 4 disks %s is\n",
            "where we move disks from tower 1 to tower 3");
    hanoi(1,2,3,4);
}

hanoi(int x,int y,int z,int n)
{
    if( n == 1 )
    {
        printf("     Move disk from %d to %d\n",x,z);
        sleep(5);
        system("clear");
    }
    else
    {
	// printf("Calling hanoi with %d %d %d %d\n", x,z,y,n-1);
        hanoi(x,z,y,n-1);
        printf("     Move disk from %d to %d\n",x,z);
        sleep(5);
        system("clear");
	// printf("Calling hanoi with %d %d %d %d\n", y,x,z,n-1);
        hanoi(y,x,z,n-1);
    }
}
