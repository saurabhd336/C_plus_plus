#include<bits/stdc++.h>
using namespace std;

vector<int> tree (4 * 100001, 0);
vector<int> lazy (4 * 100001, 0);

void update(int node, int start, int end, int l, int r)
{
	if(lazy[node])
	{
		int curr_val = tree[node];
		tree[node] = (end - start + 1) - curr_val;
		if(start != end)
		{
			lazy[2 * node] = !lazy[2 * node];
			lazy[2 * node + 1] = !lazy[2 * node + 1];
		}
		lazy[node] = 0;
	}
	
	if(start > end || end < l || start > r)
		return;
	
	if(start >= l && end <= r)
	{
		int curr_val = tree[node];
		tree[node] = (end - start + 1) - curr_val;
		if(start != end)
		{
			lazy[2 * node] = !lazy[2 * node];
			lazy[2 * node + 1] = !lazy[2 * node + 1];
		}
		return;
	}
	
	int mid = (start + end) / 2;
	update(2 * node, start, mid, l, r);
	update(2 * node + 1, mid + 1, end, l, r);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int start, int end, int l, int r)
{
	if(start > end || start > r || end < l)
		return 0;
	if(lazy[node])
	{
		int curr_val = tree[node];
		tree[node] = (end - start + 1) - curr_val;
		if(start != end)
		{
			lazy[2 * node] = !lazy[2 * node];
			lazy[2 * node + 1] = !lazy[2 * node + 1];
		}
		lazy[node] = 0;
	}
	
	if(start >= l && end <= r)
		return tree[node];
	
	int mid = (start + end) / 2;
	return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}

void print()
{
	cout<<"SEGTREE: ";
	for(int i = 1; i <= 7; i++)
		cout<<tree[i]<<" ";
	cout<<"\nLazy: ";
	for(int i = 1; i <= 7; i++)
		cout<<lazy[i]<<" ";
	cout<<"\n";
}

int main()
{
	int type, l, r, n, q;
	cin>>n>>q;
	
	while(q--)
	{
		cin>>type>>l>>r;
		if(type == 0)
		{
			update(1, 0, n-1, l, r);
			//print();
		}
			
		else
			cout<<query(1, 0, n-1, l, r)<<"\n";
	}
	return 0;
}
