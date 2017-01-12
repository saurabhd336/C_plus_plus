#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

//Given two strings, calculate lenght of lcs
//f(i, j) = 1 + f(i + 1, j + 1) if a[i] == b[j] else max(f(i, j + 1), f(i + 1, j))
//dp[i][j] = LCS till a[i..n], b[j..m]
int lcs_rec(string a, string b, int i, int j)
{
	if(i >= a.length() || j >= b.length())
		return 0;
	if(a[i] == b[j])
		return 1 + lcs_rec(a, b, i + 1, j + 1);
		
	return max(lcs_rec(a, b, i, j + 1), lcs_rec(a, b, i + 1, j));
}

int lcs_dp1(string a, string b, int i, int j)
{
	if(i >= a.length() || j >= b.length())
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	if(a[i] == b[j])
		return dp[i][j] = 1 + lcs_dp1(a, b, i + 1, j + 1);		
	return dp[i][j] = max(lcs_dp1(a, b, i, j + 1), lcs_dp1(a, b, i + 1, j));
}

int lcs_dp2(string a, string b)
{
	int dp2[100][100];
	for(int i = b.length(); i >= 0; i--)
		dp2[a.length()][i] = 0;
	
	for(int i = a.length(); i >= 0; i--)
		dp2[i][b.length()] = 0;
	
	for(int i = a.length() - 1; i >= 0; i--)
		for(int j = b.length() - 1; j >= 0; j--)
		{
			dp2[i][j] = dp2[i + 1][j + 1];
			if(a[i] == b[j])
				dp2[i][j] = 1 + dp2[i + 1][j + 1];
			else
				dp2[i][j] = max(dp2[i][j + 1], dp2[i + 1][j]);
		}
	
	//Print LCS
	//Start from 0,0 and keep checking three values max. move in that direction and check if x[i] == y[j]
	
	int i, j, max_val, i_temp, j_temp;
	i = j = 0;
	while(i < a.length() && j < b.length())
	{
		
		//cout<<i<<" "<<j<<" "<<dp2[i + 1][j + 1]<<"\n";
		if(a[i] == b[j])
		{
			cout<<a[i];
			i++;
			j++;
			continue;
		}
			
		max_val = -1;
		if(dp2[i + 1][j] > max_val)
		{
			max_val = dp2[i + 1][j];
			i_temp = i + 1;
			j_temp = j;
		}
		
		if(dp2[i + 1][j + 1] > max_val)
		{
			max_val = dp2[i + 1][j + 1];
			i_temp = i + 1;
			j_temp = j + 1;
		}
		
		if(dp2[i][j + 1] > max_val)
		{
			max_val = dp2[i][j + 1];
			i_temp = i;
			j_temp = j + 1;
		}
		
		i = i_temp;
		j = j_temp;
	}
	
	cout<<"\n";
	
	return dp[0][0];
}

int main()
{
	string a, b;
	
	a = "abcbdab";
	b = "bdcaba";
	
	cout<<lcs_rec(a, b, 0, 0)<<"\n";
	memset(dp, -1, sizeof(dp));
	cout<<lcs_dp1(a, b, 0, 0)<<"\n";
	cout<<lcs_dp2(a, b);
	return 0;
}
