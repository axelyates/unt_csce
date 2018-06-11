#include <stdio.h>
#include <stdlib.h>

#define SIZE 500


int main()
{
        int A[SIZE];
	int n = SIZE;
	int i,j;
	for( i = 0; i < n; i++ )
	{
		A[i] = random() % 100000;
	}


	printf("\n\n\nThe unsorted array is:\n");

	for( i = 0; i < n/10; i++ )
	{
		for(j = 0; j < 10; j++)
		{
			printf("%d ",A[i*10+j]);
		}
		printf("\n");
	}

	bubble(A,n);

	printf("\n\n\nThe sorted array is:\n");
	for( i = 0; i < n/10; i++ )
	{
		for(j = 0; j < 10; j++)
		{
			printf("%d ",A[i*10+j]);
		}
		printf("\n");
	}
}



int bubble(int X[], int n)
{
	int i,j;

	for(i = n-1; i > 0; i--)
	{
		for(j = 0; j < i;  j++)
		{
			if( X[j] > X[j+1] )
			{
				swap(&X[j],&X[j+1]);
			}
		}
	}
        return 0;
}


int swap(int *i,int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
        return 0;
}
