/*
基本原理：每个集合用一棵树来表示，树根的编号就是整个集合的编号，每个结点存储它的父节点，p[x]表示x的父节点

问题1：如何判断树根：if(p[x]==x
问题2：如何求x的集合编号：while(p[x]!=x) x=p[x];
问题3：如何合并两个集合   px是x的集合编号，py是y的集合编号，p[x]=y


一共有 n 个数，编号是 1∼n ，最开始每个数各自在一个集合中。

现在要进行 m 个操作，操作共有两种：

    M a b，将编号为 a 和 b 的两个数所在的集合合并，如果两个数已经在同一个集合中，则忽略这个操作；
    Q a b，询问编号为 a 和 b 的两个数是否在同一个集合中；

输入格式
第一行输入整数 n 和 m。
接下来 m 行，每行包含一个操作指令，指令为 M a b 或 Q a b 中的一种。

输出格式
对于每个询问指令 Q a b，都要输出一个结果，如果 a 和 b 在同一集合内，则输出 Yes，否则输出 No。
每个结果占一行。

数据范围
1≤n,m≤10^5
*/

#include <iostream>
using namespace std;
const int N = 100010;
int n , m;
int p[N]; 
int find(int x)
{
    if(p[x] != x)   p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d" , &n , &m);
    for(int i = 1 ; i <= n ; i++)   p[i] = i;
    while(m--)
    {
        char op[2];
        int a , b;
        scanf("%s%d%d" , op , &a, &b);
        if(op[0] == 'M')    p[find(a)] = find(b);
        else
        {
            if(find(a) == find(b))    puts("Yes");
            else   puts("No");
        }
    }
    return 0;
}