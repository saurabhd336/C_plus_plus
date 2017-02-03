#include<bits/stdc++.h>

using namespace std;

int getMaxArea(int arr[], int n)
{
	int pos, ans = 0, left;
	vector<int> v (n);
	stack<int> s;
	for(int i = 0; i < n; i++)
	{
		while(!s.empty() && (i == n - 1 || arr[s.top()] > arr[i]))
		{
			pos = s.top();
			s.pop();
			left = s.empty() ? 0 : s.top();
			v[pos] = arr[pos] * (i - left);
		}
		s.push(i);
	}
	
	
	for(int i = 0; i < n; i++)
		cout<<v[i]<<" ";
	cout<<"\n";
	
	return ans;
}

int main()
{
    int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
    cout << "Maximum area is " << getMaxArea(hist, n);
    return 0;
}
