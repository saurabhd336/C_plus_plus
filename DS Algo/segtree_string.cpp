//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/akash-and-too-many-assignments/description/
//Segtree with hash

#include<bits/stdc++.h>
using namespace std;

vector<char> v;
vector<vector<int> > tree (4 * 1000001, vector<int> (26, 0));

void build(long long node, long long start, long long end)
{
    if(start == end)
    {
        tree[node][v[start] - 'a'] = 1;
        return;
    }
    
    long long mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    
    for(int i = 0; i < 26; i++)
        tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
}

void update(long long node, long long start, long long end, long long pos, char ch)
{
    if(start == end)
    {
        for(int i = 0; i < 26; i++)
            tree[node][i] = 0;
        v[start] = ch;
        tree[node][ch - 'a'] = 1;
        return;
    }
    
    long long mid = (start + end) / 2;
    if(pos <= mid)
        update(2 * node, start, mid, pos, ch);
    else
        update(2 * node + 1, mid + 1, end, pos, ch);
    
    for(int i = 0; i < 26; i++)
        tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
}

vector<int> query(long long node, long long start, long long end, long long l, long long r)
{
    if(start > end || end < l || start > r)
    {
        vector<int> v (26, 0);
        return v;
    }
    
    if(start >= l && end <= r)
        return tree[node];
    
    long long mid = (start + end) / 2;
    vector<int> q1 = query(2 * node, start, mid, l, r);
    vector<int> q2 = query(2 * node + 1, mid + 1, end, l, r);
    
    for(int i = 0; i < 26; i++)
        q1[i] += q2[i];
    return q1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, q, type, l, r, idx, k;
    char ch;
    cin>>n>>q;
    for(int i = 0; i < n; i++)
    {
        cin>>ch;
        v.push_back(ch);
    }
    
    build(1, 0, n - 1);
    
    while(q--)
    {
        cin>>type;
        if(type == 0)
        {
            cin>>idx>>ch;
            update(1, 0, n - 1, idx - 1, ch);
        }
        else
        {
            char ans = 'a';
            cin>>l>>r>>k;
            vector<int> temp = query(1, 0, n - 1, l-1, r-1);
            for(int i = 0; i < temp.size(); i++)
            {      
                if(temp[i] >= k)
                {
                	k -= temp[i];
                    ans = (char)('a' + i);
                    break;
                }
                else
                    k -= temp[i];
            }
            
            if(k > 0)
                cout<<"Out of range\n";
            else
                cout<<ans<<"\n";
        }
    }
    return 0;
}
