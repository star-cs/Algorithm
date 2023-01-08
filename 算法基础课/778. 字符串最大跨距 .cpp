/*
有三个字符串 S,S1,S2，其中，S 长度不超过 300，S1 和 S2 的长度不超过 10。

现在，我们想要检测 S1 和 S2 是否同时在 S 中出现
且 S1 位于 S2 的左边，并在 S 中互不交叉（即，S1 的右边界点在 S2 的左边界点的左侧）。

计算满足上述条件的最大跨距（即，最大间隔距离：最右边的 S2 的起始点与最左边的 S1 的终止点之间的字符数目）。

如果没有满足条件的 S1，S2 存在，则输出 −1。

例如，S=abcd123ab888efghij45ef67kl, S1= ab, S2= ef
其中，S1 在 S 中出现了 2 次，S2 也在 S 中出现了 2 次，最大跨距为：18。
*/

//这题可以用KMP算法进行优化，这里图方便，就使用暴力求解了。

#include <iostream>

using namespace std;

int main()
{
    string s , s1 , s2;
    
    char c;
    while(cin >> c , c != ',')  s += c;
    while(cin >> c , c != ',')  s1 += c;
    while(cin >> c )  s2 += c;

    if(s.size() < s1.size() || s.size() < s2.size())    puts("-1");
    else
    {
        int l = 0;
        while( l + s1.size() <= s.size())
        {
            int j = 0;
            while(j < s1.size())
            {
                if(s[l+j] != s1[j])     break;
                j++;
            }
            if(j == s1.size())  break;
            l++;
        } 

        int r = s.size() - s2.size();
        while(r >= 0)
        {
            int k = 0;
            while(k < s2.size())
            {
                if(s[r+k] != s2[k]) break;
                k++;
            }
            if(k == s2.size())  break;
            r--;
        } 
        l += s1.size() - 1;
    
        if(l >= r)  puts("-1");
        else printf("%d\n" , r-l-1);
    }
    return 0;
}