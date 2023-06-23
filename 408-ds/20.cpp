/*
D = abs(a - b) + abs(b - c) + abs(c - a)

有点像三数之和

*/
#include<bits/stdc++.h>
using namespace std;

int get_D(int a , int b , int c)
{
    return abs(a - b) + abs(b - c) + abs(c - a);
}
//暴力 O(n^3)
void fun1(vector<int> s1 , vector<int> s2 , vector<int> s3)
{
    int tar = 0x3f3f;
    int a1 , a2 , a3;
    for(int num1 : s1)
    {
        for(int num2 : s2)
        {
            for(int num3 : s3)
            {
                int t = get_D(num1 , num2 , num3);
                if(t < tar)
                {
                    tar = t;
                    a1 = num1;
                    a2 = num2; 
                    a3 = num3;
                }
            }
        }
    }
    cout << tar << endl;
    cout << a1 << " " << a2 << " " << a3 << endl;
}

//最优解...
void fun2(vector<int> s1 , vector<int> s2 , vector<int> s3)
{}

int main()
{
    vector<int> s1 = {-1,0,9};
    vector<int> s2 = {-25,-10,10,11};
    vector<int> s3 = {2,9,17,30,41};
    fun1(s1 , s2 , s3);

    return 0;
}