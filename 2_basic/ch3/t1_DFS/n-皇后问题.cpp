#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n ;
char mp[N][N];
// col[]列，dg[]正对角线，udg[]反对角线
bool col[N] , dg[N] , udg[N];   
void dfs(int u)
{
    if(u == n)
    {
        for(int i = 0 ; i < n ; i++)    puts(mp[i]);
        puts("");
        return;
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(!col[i] && !dg[i+u] && !udg[i-u+n])
        {
            mp[u][i] = 'Q';
            col[i] = dg[i+u] = udg[i-u+n] = 1;

            dfs(u+1);
            col[i] = dg[i+u] = udg[i-u+n] = 0;
            mp[u][i] = '.';
        }
    }
}
int main()
{
    scanf("%d" , &n);
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mp[i][j] = '.';
        }
    }
    dfs(0);

    return 0;
}