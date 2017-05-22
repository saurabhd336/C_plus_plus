#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long t, n;
	int val;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int> v;
		for(int i = 0; i < n; i++)
		{
			cin>>val;
			v.push_back(val);
		}
		
		int ans, sorted = 0;
		for(ans = 0; !sorted; ans++)
		{
			sorted = 1;
			for(int i = 0; i < n - 1; i++)
				if(v[i] == 0 && v[i + 1] == 1)
				{
					swap(v[i], v[i + 1]);
					i++;
					sorted = 0;
				}
		}
	
		cout<<ans - 1<<"\n";
	}
	return 0;
}
