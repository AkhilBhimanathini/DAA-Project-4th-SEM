// C Source Code to implement cost based Tower of Hanoi 
#include <stdio.h>  
#define RODS 3 
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int N;


int dp[10][RODS + 1][RODS + 1]; 
int c=0;
int min(int a,int b)
{
	return a<b? a:b;
}
void initialize() 
{ 

	int i,j,k;
	for (i = 0; i <= N; i += 1) { 
		for (j = 1; j <= RODS; j++) { 
			for (k=1; k <= RODS; k += 1) { 
				dp[i][j][k] = INT_MAX; 
			} 
		} 
	} 
} 
// Function to return the minimum cost 
int mincost(int idx, int src, int dest, 
			int costs[RODS][RODS]) 
{ 

	 
	if (idx > N) 
		return 0; 
 
	if (dp[idx][src][dest] != INT_MAX) 
		return dp[idx][src][dest]; 

	int rem = 6 - (src + dest); 

	int ans = INT_MAX; 
//	printf("Move disk %d from rod  %d to rod  %d \n",idx ,src,dest);

	int case1 =
	            mincost(idx + 1, rem, dest, costs) 
	            + costs[src - 1][dest - 1]  
	            + mincost(idx + 1, src, rem, costs);
		
	 
	int case2 = costs[src - 1][rem - 1] 
				+ mincost(idx + 1, src, dest, costs) 
				+ mincost(idx + 1, dest, src, costs) 
				+ costs[rem - 1][dest - 1] 
				+ mincost(idx + 1, src, dest, costs); 

 
	ans = min(case1, case2); 
/*	if (case1<case2)
	{
		 
    }
    else
    {
    	printf("Move disk %d from rod  %d to rod  %d \n", idx ,src,rem); 
    	printf("Move disk %d from rod  %d to rod  %d \n", idx ,rem,dest); 
	}*/
 

	dp[idx][src][dest] = ans;

	return ans; 
  // printf("Move disk %d from rod  %d to rod  %d \n", idx ,src,dest);
} 

/*void path() 
{ 

	int i,j,k;
	for (i = 0; i <= N; i += 1) { 
		for (j = 1; j <= RODS; j++) { 
			for (k=1; k <= RODS; k += 1) { 
				printf("\n%d ",dp[i][j][k]); 
			} 
		} 
	} 
} */


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

int main() 
{ 
    
    int ch,y;
    int i,j;
    int costs[RODS][RODS];
    printf("**************************************************\n");
    printf("******************TOWER OF HANOI******************\n");
    printf("**************************************************\n");
    printf("\n");
    printf("\n");
    printf("Enter the no of discs: ");
    scanf("%d", &N);

    do
    {
     printf("Choose the below options:\n");
     printf("1.Minimum no of Moves\n2.Minimum cost to transfer all the discs\n");
     scanf("%d", &ch);
     switch(ch)
     {
     	case 1:	moves(N);
     	        printf("\nMoves to transfer all the discs:\n");
     	        printf("\n");
	            towerOfHanoi(N, 'A', 'C', 'B');
	            
	            break;
	            
	    case 2: 
	            printf("\nEnter the cost Matrix:\n");
	            for (i=0;i<RODS;i++)
	            {
	            	for(j=0;j<RODS;j++)
	            	{
	            		scanf("%d", &costs[i][j]);
					}
				}
    
             	initialize(); 
             	printf("Minimum Cost to transfer all the discs is %d", mincost(1, 1, 3, costs));
             	//path();
             	
             	
             	break;
             	
        default:printf("\nInvalid Choice\n");
     }
     printf("\nEnter 1 to go to menu or 0 to exit:");
     scanf("%d", &y);
    }
    while(y==1);
    printf("\nProgram Terminated");
     
 	return 0; 
} 

