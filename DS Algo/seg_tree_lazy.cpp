#include<bits/stdc++.h>
using namespace std;

vector<int> tree (1000);
vector<int> lazy (1000, 0);
vector<int> v;

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
	if(lazy[node])
	{
		tree[node] += (end - start + 1) * lazy[node];
		if(start != end)
		{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	
	if(start > r || end < l)
		return 0;
		
	if(start >= l && end <= r)
		return tree[node];
	
	int mid = (start + end) / 2;
	return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}

void update(int node, int start, int end, int l, int r, int val)
{
	if(lazy[node])
	{
		tree[node] += (end - start + 1) * lazy[node];
		if(start != end)
		{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	
	if(start > r || end < l)
		return;
	
	if(start >= l && end <= r)
	{
		lazy[node] += val;
		return;
	}
	
	int mid = (start + end) / 2;
	update(2 * node, start, mid, l, r, val);
	update(2 * node + 1, mid + 1, end, l, r, val);
	
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main()
{
	int type, n, val, l, r;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>val;
		v.push_back(val);
	}
	
	build(1, 0, n - 1);
	
	for(int i = 0; i < 4 * n; i++)
		cout<<tree[i]<<" ";
	cout<<"\n\n";
	
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
			cin>>l>>r>>val;
			update(1, 0, n - 1, l, r, val);
			for(int i = 0; i < 4 * n; i++)
				cout<<tree[i]<<" ";
			cout<<"\n";
		}
	}
	
	return 0;
}
