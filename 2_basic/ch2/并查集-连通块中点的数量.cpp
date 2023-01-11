/*
给定一个包含 n 个点（编号为 1∼n ）的无向图，初始时图中没有边。

现在要进行 m 个操作，操作共有三种：

    C a b，在点 a 和点 b 之间连一条边， a 和 b 可能相等；
    Q1 a b，询问点 a 和点 b 是否在同一个连通块中， a 和  b 可能相等；
    Q2 a，询问点 a 所在连通块中点的数量；

输入格式
第一行输入整数 n 和 m。
接下来 m行，每行包含一个操作指令，指令为 C a b，Q1 a b 或 Q2 a 中的一种。

输出格式
对于每个询问指令 Q1 a b，如果 a 和 b 在同一个连通块中，则输出 Yes，否则输出 No。
对于每个询问指令 Q2 a，输出一个整数表示点 a 所在连通块中点的数量

每个结果占一行。

数据范围
1≤n,m≤10^5
*/
#include <iostream>
using namespace std;
const int N = 100010;

int n , m;
int num[N] , p[N];

int find(int x)
{
    if(p[x] != x)   p[x] = find(p[x]);
    return p[x];
}

void insert(int x , int y)
{
    int X = find(x);
    int Y = find(y);
    if(X != Y)
    {
        p[X] = Y;
        num[Y] += num[X];
    }
}

void query1(int x , int y)
{
    if(find(x) == find(y))      puts("Yes");
    else    puts("No");
}

void query2(int x)
{
    printf("%d\n" , num[find(x)]);
} 

int main()
{
    scanf("%d%d" , &n , &m);

    for(int i = 1 ; i <= n ; i++)   p[i] = i;
    for(int i = 1 ; i <= n ; i++)   num[i] = 1;
    while(m--)
    {
        char op[2];
        int a , b;
        scanf("%s" , op);
        if(op[0] == 'C')
        {
            scanf("%d%d" , &a , &b);
            insert(a , b);      
        }
        else if(op[1] == '1')
        {
            scanf("%d%d" , &a , &b);
            query1(a , b);
        } 
        else if(op[1] == '2')
        {
            scanf("%d" , &a);
            query2(a);
        }
    }

    return 0;
}