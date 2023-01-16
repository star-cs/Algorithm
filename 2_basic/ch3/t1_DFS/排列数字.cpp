/*
给定一个整数n，将数字1~n排成一排，将会有很多种排列方法。
现在，请你按照字典序将所有的排列方法输出。
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n ;
int path[N];
bool st[N]; //false没有选中
void dfs(int u)
{
    if(u == n) 
    {
        for(int i = 0; i < n ; i++) printf("%d" , path[i]);
        printf("\n");
        return;
    }
    for(int i = 0; i < n ; i++)
    {
        if(!st[i])
        {
            path[u] = i;
            
            st[i] = true;
            dfs(u+1);
            st[i] = false; 
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}
