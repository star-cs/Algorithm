/*
动物王国中有三类动物 A,B,C，这三类动物的食物链构成了有趣的环形。
A 吃 B，B 吃 C，C 吃 A。

现有 N 个动物，以 1∼N 编号。

每个动物都是 A,B,C 中的一种，但是我们并不知道它到底是哪一种。

有人用两种说法对这 N 个动物所构成的食物链关系进行描述：

第一种说法是 1 X Y，表示 X 和 Y 是同类。

第二种说法是 2 X Y，表示 X 吃 Y。

此人对 N 个动物，用上述两种说法，一句接一句地说出 K 句话，这 K 句话有的是真的，有的是假的。

当一句话满足下列三条之一时，这句话就是假话，否则就是真话。
1. 当前的话与前面的某些真的话冲突，就是假话；  
2. 当前的话中 X 或 Y 比 N 大，就是假话；
3. 当前的话表示 X 吃 X，就是假话。

你的任务是根据给定的 N 和 K 句话，输出假话的总数。

输入格式
第一行是两个整数 N 和 K ，以一个空格分隔。
以下 K 行每行是三个正整数 D，X，Y，两数之间用一个空格隔开，其中 D 表示说法的种类。
若 D=1 ，则表示 X 和 Y 是同类。
若 D=2 ，则表示 X 吃 Y。

输出格式
只有一个整数，表示假话的数目。
数据范围
1≤N≤50000,0≤K≤100000
*/


/*
记录每个点到根节点的关系<距离>

    根节点
      | 
      A     距离1   A吃根节点
      |
      B     距离2   B吃A    B被C吃
      |
      C     距离3   C和根节点是同类

距离 mod 3      1       可以吃根节点
                2       可以被根节点吃
                0       和根节点同类       

*/
#include <iostream>
using namespace std;
const int N = 500010;
int n , m;
int p[N] , d[N];

int find(int x)
{
    if(p[x] != x){
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main()
{
    scanf("%d%d" , &n , &m);

    for(int i = 1 ; i <= N ; i++)   p[i] = i;

    int res = 0;
    while(m--)
    {
        int t , x , y;
        scanf("%d%d%d" , &t , &x , &y);
        if(x > n || y > n) res++;
        else
        {
            int px = find(x) , py = find(y);
            if(t == 1)
            {
                // px == py 在同一树上
                if(px == py && (d[x] - d[y]) % 3 != 0)  res++;
                else if(px != py)
                {
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else
            {
                if(px == py && (d[x] - d[y] - 1) % 3 != 0) res++;
                else if(px != py)
                {
                    p[px] = py;
                    d[px] = d[y] - d[x] + 1;
                } 
            }
        }
    }
    printf("%d" , res);
    return 0;
}