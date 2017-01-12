#include<bits/stdc++.h>
using namespace std;

//sum_here at i is the max sum including ith element
//Either extend or start new;

int main()
{
	int sum_here, max_sum;
	int arr[] = {1, -3, 4, -2, -1, 6};
	sum_here = max_sum = arr[0];
	for(int i = 1; i < 6; i++)
	{
		sum_here = max(arr[i], sum_here + arr[i]);
		max_sum = max(sum_here, max_sum);
	}
	
	cout<<max_sum<<"\n";
	
	sum_here = max_sum = arr[0];
	int start, end, actual_start, actual_end;
	start = end = 0;
	//Print the seq
	for(int i = 1; i < 6; i++)
	{
		if(sum_here + arr[i] > arr[i])
		{
			sum_here += arr[i];
			end = i;
		}
		else
		{
			sum_here = arr[i];
			start = i;
			end = i;
		}
		
		if(sum_here > max_sum)
		{
			max_sum = sum_here;
			actual_start = start;
			actual_end = end;
		}
	}
	
	for(int i = actual_start; i <= actual_end; i++)
		cout<<arr[i]<<" ";
	return 0;
}
