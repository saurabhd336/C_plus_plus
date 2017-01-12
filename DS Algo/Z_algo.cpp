#include<bits/stdc++.h>
using namespace std;

//Z[i] = Max length substring starting at i that is also a prefix.
//http://codeforces.com/blog/entry/3107
//Z[0] = 0;
int main()
{
	string s;
	cin>>s;
	int l, r;
	l = r = -1;
	vector<int> z (s.length(), 0);
	z[0] = s.length();
	
	for(int i = 1; i < s.length(); i++)
	{
		if(i > r)
		{
			//Calculate naively
			l = r = i;
			while(r < s.length() && s[r - l] == s[r])
				r++;
			z[i] = r - l;
			r--;
		}
		
		else
		{
			int k = i - l;
			if(z[k] < r - i + 1)
				z[i] = z[k];
			else
			{
				//Calculate again
				l = i;
				while(r < s.length() && s[r - l] == s[r])
					r++;
				z[i] = r - l;
				r--;
			}
		}
	}
	
	for(int i = 0; i < z.size(); i++)
		cout<<z[i]<<" ";
	return 0;
}
