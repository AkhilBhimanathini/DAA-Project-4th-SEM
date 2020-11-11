// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
#define RODS 3 
#define N 3 
int dp[N + 1][RODS + 1][RODS + 1]; 

// Function to initialize the dp table 
void initialize() 
{ 

	// Initialize with maximum value 
	for (int i = 0; i <= N; i += 1) { 
		for (int j = 1; j <= RODS; j++) { 
			for (int k = 1; k <= RODS; k += 1) { 
				dp[i][j][k] = INT_MAX; 
			} 
		} 
	} 
} 
// Function to return the minimum cost 
int mincost(int idx, int src, int dest, 
			int costs[RODS][RODS]) 
{ 

	// Base case 
	if (idx > N) 
		return 0; 

	// If problem is already solved, 
	// return the pre-calculated answer 
	if (dp[idx][src][dest] != INT_MAX) 
		return dp[idx][src][dest]; 

	// Number of the auxilary disk 
	int rem = 6 - (src + dest); 

	// Initialize the minimum cost as Infinity 
	int ans = INT_MAX; 

	// Calculationg the cost for first case 
	int case1 = costs[src - 1][dest - 1] 
				+ mincost(idx + 1, src, rem, costs) 
				+ mincost(idx + 1, rem, dest, costs); 

	// Calculating the cost for second case 
	int case2 = costs[src - 1][rem - 1] 
				+ mincost(idx + 1, src, dest, costs) 
				+ mincost(idx + 1, dest, src, costs) 
				+ costs[rem - 1][dest - 1] 
				+ mincost(idx + 1, src, dest, costs); 

	// Minimum of both the above cases 
	ans = min(case1, case2); 

	// Store it in the dp table 
	dp[idx][src][dest] = ans; 

	// Return the minimum cost 
	return ans; 
} 

// Driver code 
int main() 
{ 
	int costs[RODS][RODS] = { { 0, 1, 2 }, 
							{ 2, 0, 1 }, 
							{ 3, 2, 0 } }; 
	initialize(); 
	cout << mincost(1, 1, 3, costs); 

	return 0; 
} 

