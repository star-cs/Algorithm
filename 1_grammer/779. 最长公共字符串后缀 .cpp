/*
给出若干个字符串，输出这些字符串的最长公共后缀。
*/

#include <iostream>
using namespace std;

const int N = 210;

int n;
string str[N];

int main()
{
    while(cin >> n , n)
    {
        int min_len = 1000;
        for(int i = 0; i < n ; i++)
        {
            cin >> str[i];
            if(min_len > str[i].size()) min_len = str[i].size();
        }

        
        //枚举后缀长度，从最长的可能性开始枚举
        while(min_len)
        {
            bool success = true;
            //遍历除第一个的其余字符串，分别和第一个字符串的 后缀长度n的子串 进行比较
            for(int i = 1 ; i < n ; i++)
            {
                bool is_same = true;
                for(int j = 1 ; j <= min_len ; j++)
                    if(str[0][str[0].size() - j] != str[i][str[i].size() - j])
                    {
                        is_same = false;
                        break;
                    }
                if(!is_same)
                {
                    success = false;
                    break;
                }
            }
            if(success) break;
            min_len--;
        }
        cout << str[0].substr(str[0].size() - min_len) << endl; 
    }
    return 0;
}