#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10 , M = 2 * N;

int h[N] , e[M] , ne[M] , idx;
int n , ans = N;

bool st[N];//记录节点是否被访问过，访问过则标记为true

//a对应的单链表头插法插入b
void add(int a , int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

//返回以u为根的子树中节点的个数，包括u节点
int dfs(int u)
{
    int res = 0;
    st[u] = 1;
    int sum = 1;

    //访问u的每个子节点
    for(int i = h[u] ; i != -1 ; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            int s = dfs(j);     //j节点为头节点的子节点数
            res = max(res , s); //记录最大联通子图的节点数
            sum += s;           //以j为根的树 的节点树
        }
    }
    //n-sum 是u节点遍历不到的节点数
    res = max(res , n - sum);
    ans = min(res , ans);
    return sum;
}
int main()
{
    memset(h , -1 , sizeof h);
    cin >> n;

    for(int i = 0; i < n-1 ; i++)
    {
        int a , b;
        cin >> a >> b;
        add(a , b) , add(b , a);
    }
    dfs(1);
    cout << ans << endls;
    return 0;
}