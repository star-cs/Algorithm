/*
对于一个字符串来说，定义一次循环移位操作为：将字符串的第一个字符移动到末尾形成新的字符串。
给定两个字符串 s1 和 s2 ，要求判定其中一个字符串是否是另一字符串通过若干次循环移位后的新字符串的子串。
例如 CDAA 是由 AABCD 两次移位后产生的新串 BCDAA 的子串，而 ABCD 与 ACBD 则不能通过多次移位来得到其中一个字符串是新串的子串。
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{ 
    string a , b ;
    
    cin >> a >> b;

    //保证a是长度最长的字符串
    if(a.size() < b.size())
        swap(a , b);

    for(int i = 0 ; i < a.size() ; i++)
    {
        a = a.substr(1) + a[0];
        for(int j = 0 ; j + b.size() <= a.size() ; j++)
        {
            int k = 0;
            for( ; k < b.size() ; k++)
                if(a[j+k] != b[k])
                    break;
            
            if(k == b.size())
            {
                puts("true");
                return 0;
            }
        }
    }
    puts("false");
    return 0;
}