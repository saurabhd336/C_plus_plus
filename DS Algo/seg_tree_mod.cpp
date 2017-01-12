#include<bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> tree (1000, 0);
vector<set<int> > lazy (1000);

void build(int node, int start, int end)
{
	if(start == end)
	{
		tree[node] = v[start];
		return;
	}
	
	int mid = (start + end) / 2;
	build(2 * node, start, mid);
	build(2 * node + 1, mid + 1, end);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int start, int end, int l, int r)
{
	if(start > end || end < l || start > r)
		return 0;
	if(lazy[node].size())
	{
		for(auto i = lazy[node].begin(); i != lazy[node].end(); i++)
			tree[node] %= *i;
		if(start != end)
		{
			lazy[2 * node].insert(lazy[node].begin(), lazy[node].end());
			lazy[2 * node + 1].insert(lazy[node].begin(), lazy[node].end());
		}
		lazy[node].clear();
	}
	
	if(start >= l && end <= r)
		return tree[node];
	
	int mid = (start + end) / 2;
	return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}

void update(int node, int start, int end, int l, int r, int z)
{
	if(lazy[node].size())
	{
		for(auto i = lazy[node].begin(); i != lazy[node].end(); i++)
			tree[node] %= *i;
		if(start != end)
		{
			lazy[2 * node].insert(lazy[node].begin(), lazy[node].end());
			lazy[2 * node + 1].insert(lazy[node].begin(), lazy[node].end());
		}
		lazy[node].clear();
	}
	
	if(start > end || start > r || end < l)
		return;
	
	if(start >= l && end <= r)
	{
		tree[node] %= z;
		if(start != end)
		{
			lazy[2 * node].insert(z);
			lazy[2 * node + 1].insert(z);
		}
		return;
	}
	
	int mid = (start + end) / 2;
	update(2 * node, start, mid, l, r, z);
	update(2 * node + 1, mid + 1, end, l, r, z);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void print()
{
	cout<<"SEGTREE: ";
	for(int i = 1; i <= 7; i++)
		cout<<tree[i]<<" ";
	cout<<"\nLazy: ";
	for(int i = 1; i <= 7; i++)
	{
		cout<<i<<" : ";
		for(auto j = lazy[i].begin(); j != lazy[i].end(); j++)
			cout<<(*j)<<" ";
		cout<<"\n";
	}	
	cout<<"\n";
}

int main()
{
	long long n, l, r, val, z, type;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>val;
		v.push_back(val);
	}
	
	build(1, 0, n - 1);
	
	while(1)
	{
		cin>>type;
		if(type == 1)
		{
			cin>>l>>r;
			cout<<query(1, 0, n - 1, l, r)<<"\n";
		}
		
		else
		{
			cin>>l>>r>>z;
			update(1, 0, n - 1, l, r, z);
			print();
		}
	}
	return 0;
}
