#include<bits/stdc++.h>
using namespace std;

//http://e-maxx-eng.appspot.com/data_structures/fenwick.html

int sum(vector<int> &bit, int a)
{
	int ans = 0;
	for(; a >= 0; a = (a & (a + 1)) - 1)
	{
		ans += bit[a];
		//cout<<a<<"\n";
	}
		
	return ans;
}

void update(vector<int> &bit, int pos, int val)
{
	while(pos < bit.size())
	{
		//cout<<pos<<"\n";
		bit[pos] += val;
		pos = pos | (pos + 1);
	}
}

void construct(vector<int> &bit, vector<int> &v)
{
	for(int i = 0; i < v.size(); i++)
		update(bit, i, v[i]);
}

int main()
{
	vector<int> v;
	int n, val;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>val;
		v.push_back(val);
	}
	
	vector<int> bit (n, 0);
	construct(bit, v);
	
	//for(int i = 0; i < bit.size(); i++)
	//	cout<<bit[i]<<" ";
	//cout<<"\n";
	
	int a;
	while(1)
	{
		cin>>a;
		cout<<sum(bit, a)<<"\n";
	}
	return 0;
}
