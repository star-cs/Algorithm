/*
给定一个长度为 n 的整数数列，以及一个整数 k，请用快速选择算法求出数列从小到大排序后的第 k 个数。

输入格式
第一行包含两个整数 n 和 k。
第二行包含 n 个整数（所有整数均在 1∼10^9 范围内），表示整数数列。

输出格式
输出一个整数，表示数列的第 k 小数。

数据范围
1≤n≤100000，1≤k≤n 
*/

#include <iostream>

using namespace std;

const int N = 100010;
int n , k ,q[N];

void quick_sort(int l , int r)
{
    if(l >= r)  return;
    int x = q[l] , i = l-1 , j = r+1;
    while(i < j)
    {
        do i++ ; while(q[i] < x);
        do j-- ; while(q[j] > x);
        if(i < j)   swap(q[i] , q[j]);
    }
    quick_sort(l , j);
    quick_sort(j + 1 , r);
}   

int main()
{   
    scanf("%d %d" , &n , &k);
    for(int i = 0 ; i < n ; i++)    scanf("%d" , &q[i]);

    quick_sort(0 , n-1);
    //for(int i = 0 ; i < n ; i++)    f("%d " , q[i]);

    printf("%d" , q[k-1]);

    return 0;
}
