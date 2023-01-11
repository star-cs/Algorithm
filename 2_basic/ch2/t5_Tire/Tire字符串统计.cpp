/*
维护一个字符串集合，支持两种操作：

    I x 向集合中插入一个字符串 x；
    Q x 询问一个字符串在集合中出现了多少次。

共有 N 个操作，输入的字符串总长度不超过 10^5 ，字符串仅包含小写英文字母。

输入格式
第一行包含整数 N，表示操作数。
接下来 N 行，每行包含一个操作指令，指令为 I x 或 Q x 中的一种。

输出格式
对于每个询问指令 Q x，都要输出一个整数作为结果，表示 x 在集合中出现的次数。
每个结果占一行。

数据范围
1≤N≤2∗10^4
*/
#include <iostream>
using namespace std;

const int N = 100010;

//son[][]每个节点最多会有26个子节点，cnt[]当前位置有多少个数结束
//idx每个节点的下标，idx=0，即使根节点，也是空节点。
int son[N][26] , cnt[N] , idx;
char op , str[N];

void insert(char str[])
{
    int p = 0;
    for(int i = 0; str[i] ; i++)
    {
        int n = str[i] - 'a';
        if(!son[p][n])  son[p][n] = ++idx;
        p = son[p][n];
    }
    cnt[p]++;
}

int query(char str[])
{
    int p = 0;
    bool f = true;
    for(int i = 0 ; str[i] ; i++)
    {
        int n = str[i] - 'a'; 
        if(son[p][n])   p = son[p][n];
        else    return 0;
    }
    return cnt[p];
}

int main()
{
    int n;
    scanf("%d" , &n);
    while(n--)
    {
        char op[2];
        scanf("%s%s" , op ,str);
        if(op[0] == 'I')    insert(str);
        else printf("%d\n" , query(str));
    } 

    return 0;
}