/*
给定两个字符串 a 和 b，我们定义 a×b为他们的连接。

例如，如果 a=abc 而 b=def， 则 a×b=abcdef。

如果我们将连接考虑成乘法，一个非负整数的乘方将用一种通常的方式定义：a0=``(空字符串)，a(n+1)=a×(an)。
*/


#include <iostream>

using namespace std;

int main()
{
    string str;
    
    while(cin >> str , str != ".")
    {
        int len = str.size();
        for(int n = len  ; n ; n--)
        {
            // if(len % n != 0)    break;

            //必须是约数
            if(len % n == 0){
                int m = len / n;
                string s = str.substr(0 , m);
                string r ;
                for(int j = 0 ; j < n ; j++)    r += s;

                if(r == str){
                    cout << n << endl;
                    break;
                }

            }
        }
    }
    return 0;
}