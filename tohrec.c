// C recursive function to 
// solve tower of hanoi puzzle 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void towerOfHanoi(int n, char from_rod, 
					char to_rod, char aux_rod) 
{ 
	if (n == 1) 
	{ 
		printf("Move disk 1 from rod  %c to rod  %c\n",from_rod,to_rod); 
		return; 
	} 
	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod); 
	printf("Move disk %d from rod  %c to rod  %c \n", n ,from_rod, 
								 to_rod); 
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); 
} 

void moves(int n)
{
	int i;
	int h[100];
	h[1]=1;
	for (i=2;i<=n;i++)
	{
		h[i]=2*h[i-1]+1;
	}
	printf("No of moves required: %d\n", h[n]);
}

// Driver code 
int main() 
{ 
	int n;
	
	printf("\nenter the no of discs:");
	scanf("%d", &n);
	 // Number of disks 
	moves(n);
	towerOfHanoi(n, 'A', 'C', 'B');
 // A, B and C are names of rods 
    
	return 0; 
} 

// This is code is contributed by rathbhupendra 

