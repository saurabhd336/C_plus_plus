#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> &v, int start, int mid, int end)
{
	vector<int> temp;
	
	int i, j, ans = 0;
	i = start;
	j = mid + 1;
	
	while(i <= mid && j <= end)
	{
		if(v[i] < v[j])
		{
			temp.push_back(v[i]);
			i++;
		}
		
		else
		{
			ans += mid - i + 1;
			temp.push_back(v[j]);
			j++;
		}
	}
	
	while(i <= mid)
		temp.push_back(v[i++]);
	while(j <= end)
		temp.push_back(v[j++]);
	
	for(int i = start; i <= end; i++)
		v[i] = temp[i - start];
	return ans;
}

int merge_sort(vector<int> &v, int start, int end)
{
	if(start >= end)
		return 0;
	int mid = (start + end) / 2;
	
	return merge_sort(v, start, mid) + merge_sort(v, mid + 1, end) + merge(v, start, mid, end);
}

int main()
{
	int val;
	long long n;
	vector<int> v;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>val;
		v.push_back(val);
	}
	
	for(int i = 0; i < n; i++)
		cout<<v[i]<<" ";
	cout<<"\n";
	
	cout<<merge_sort(v, 0, n - 1)<<"\n";
	
	for(int i = 0; i < n; i++)
		cout<<v[i]<<" ";
	return 0;
}
