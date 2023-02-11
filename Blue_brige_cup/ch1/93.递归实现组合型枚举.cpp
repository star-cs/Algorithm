/*

*/

#include <bits/stdc++.h>
using namespace std;
const int N = 30;

int n , m ;
int st[N];

void dfs(int u , int s)
{
    //剪枝
    if(u + n - s < m)   return ;
    if(u == m+1)
    {
        for(int i = 1 ; i <= m ; i++)
            cout << st[i] << " ";
        cout << endl;
        return;
    }
    for(int i = s ; i <= n ; i ++)
    {
        st[u] = i;
        dfs(u+1 , i+1);
        st[u] = 0;
    }
}

int main()
{
    cin >> n >> m;

    dfs(1 , 1);

    return 0;
}