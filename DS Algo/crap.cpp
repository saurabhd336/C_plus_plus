#include<bits/stdc++.h>
using namespace std;

int possible(vector<vector<int> > &can, int pos, vector<int> &done)
{
	int flag = 0;
	for(int i = 0; i < done.size(); i++)
		if(!done[i])
		{
			flag = 1;
			break;
		}
	if(!flag)
		return 1;
	
	for(int i = 0; i < can[pos].size(); i++)
	{
		if(!done[can[pos][i]])
		{
			done[can[pos][i]] = 1;
			if(possible(can, pos + 1, done))
				return 1;
			done[can[pos][i]] = 0;
		}
	}
	
	return 0;
}

int main()
{
	long long q, val, sum, n, k;
	cin>>q;
	vector<string> ans;
	ans.push_back("Impossible");
	ans.push_back("Possible");
	while(q--)
	{
		cin>>n;
		vector<vector<long long> > v, v_new;
		vector<int> done (n, 0);
		vector<long long> type_count (n, 0);
		for(int i = 0; i < n; i++)
		{
			vector<long long> temp;
			sum = 0;
			for(int j = 0; j < n; j++)
			{
				cin>>val;
				sum += val;
				type_count[j] += val;
				temp.push_back(val);
			}
			v.push_back(temp);
			for(int j = 0; j < n; j++)
				temp[j] = sum - temp[j];
			v_new.push_back(temp);
		}
		
		vector<vector<int> > can;
		
		for(int i = 0; i < n; i++)
		{
			vector<int> temp;
			for(int j = 0; j < n; j++)
				if(v_new[i][j] == type_count[j] - v[i][j])
					temp.push_back(j);
			can.push_back(temp);
		}
		
		cout<<possible(can, 0, done);
	}
	return 0;
}
