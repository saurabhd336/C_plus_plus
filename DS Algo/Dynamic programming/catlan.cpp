#include<bits/stdc++.h>
using namespace std;

//Catlan number
// (2n)! / (n! * (n + 1)! )

int dp[100];

int catlan_dp(int n)
{
	if(dp[n] != -1)
		return dp[n];
	
	dp[n] = 0;
	for(int i = 1; i <= n; i++)
		dp[n] += catlan_dp(i - 1) * catlan_dp(n - i);
	return dp[n];
}

int main()
{
	memset(dp, -1, sizeof(dp));
	dp[0] = 1;
	cout<<catlan_dp(5);
	return 0;
	
}
