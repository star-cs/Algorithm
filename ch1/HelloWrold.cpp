//头文件
#include <cstdio>
#include <iostream>

//std命名空间
using namespace std;

//函数执行入口
int main()
{

    /*
        bool false / true
        char 'c' , 'a' , '/n'
        int -2147483648 ~ 2147483647
        float 1.23 , 2.5 , 1.235e2 单精度浮点数，6-7位有效数字
        double 15-16位有效数字

        long long -2^63 ~ 2^63-1
        long double 18-19位有效数字
         
    */

    int a , b ;

    // cin >> a >> b;
    // cout << a + b;
    // cout << ' ';
    // cout << a * b << endl;    

    scanf("%d%d" , &a , &b);

    printf("%d\n%d\n" , a + b , a * b);

    /*
        int : %d
        float : %f
        double : %lf 
        char : %c
        longlong : %lld
    */

   /*
    Ascii表
        'a' 97
        'A' 65
        '0' 48
        ' ' 32
   */

    return 0;
}