//Seg tree
#include<bits/stdc++.h>
using namespace std;

void build(vector<int> &tree, vector<int> &v, int start, int end, int node)
{
	if(start > end)
		return;
	if(start == end )
	{
		tree[node] = v[start];
		return;
	}
	
	int mid = (start + end) / 2;
	
	build(tree, v, start, mid, 2 * node);
	build(tree, v, mid + 1, end, 2 * node + 1);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int sum(vector<int> &tree, int start, int end, int node, int l, int r)
{
	if(start >= l && end <= r)
		return tree[node];
	
	if(end < l || start > r)
		return 0;
	
	int mid = (start + end) / 2;
	
	return sum(tree, start, mid, 2 * node, l, r) + sum(tree, mid + 1, end, 2 * node + 1, l, r);
}

void update(vector<int> &tree, int start, int end, int node, int index, int val)
{
	if(start == end)
	{
		tree[node] = val;
		return;
	}
	
	int mid = (start + end) / 2;
	if(index <= mid)
		update(tree, start, mid, 2 * node, index, val);
	else
		update(tree, mid + 1, end, 2 * node + 1, index, val);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main()
{
	int n, val;
	cin>>n;
	vector<int> v;
	vector<int> tree (4 * n);
	
	for(int i = 0; i < n; i++)
	{
		cin>>val;
		v.push_back(val);
	}
	
	build(tree, v, 0, n - 1, 1);
	cout<<"Here\n";
	for(int i = 0; i < tree.size(); i++)
		cout<<tree[i]<<" ";
	int q, l, r;
	cin>>q;
	for(int i = 0; i < q; i++)
	{
		cin>>l>>r;
		cout<<sum(tree, 0, n-1, 1, l, r)<<"\n";
	}
	while(q--)
	{
		cin>>l>>r;
		v[l] = r;
		update(tree, 0, n - 1, 1, l, r);
		for(int i = 0; i < tree.size(); i++)
			cout<<tree[i]<<" ";
		cout<<"\n";
	}
	return 0;
	
}
