/*
给定你一个长度为 n 的整数数列。
请你使用快速排序对这个数列按照从小到大进行排序。
并将排好序的数列按顺序输出。

输入格式
输入共两行，第一行包含整数 n。
第二行包含  n 个整数（所有整数均在 1∼10^9 范围内），表示整个数列。

输出格式
输出共一行，包含 n 个整数，表示排好序的数列。

数据范围
1≤n≤100000
*/

#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r){
    if(l >= r)  return;

    //确定分界点，i，j分别余处一格进行比较
    int x = q[l] , i = l - 1 , j = r + 1;

    while(i < j)
    {
        while(q[++ i] < x){}
        while(q[-- j] > x){}

        //此时 q[i] > x ， q[j] < x
        if(i < j)   swap(q[i] , q[j]);
    }
    //递归处理左右两边，上面循环完之后，i == j
    quick_sort(q , l , j);
    quick_sort(q , j + 1, r);
}

int main()
{
    scanf("%d" , &n);
    for(int i = 0 ; i < n ; i++)   scanf("%d" , &q[i]);

    quick_sort(q , 0 , n-1);
    
    for(int i = 0 ; i < n ; i++)   printf("%d " , q[i]);

    return 0;
}
