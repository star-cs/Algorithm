/*
给定一个大小为 n≤10^6 的数组。

有一个大小为 k 的滑动窗口，它从数组的最左边移动到最右边。

你只能在窗口中看到 k 个数字。

每次滑动窗口向右移动一个位置。

输入格式
输入包含两行。
第一行包含两个整数 n 和 k，分别代表数组长度和滑动窗口的长度。
第二行有 n 个整数，代表数组的具体数值。
同行数据之间用空格隔开。

输出格式

输出包含两个。
第一行输出，从左至右，每个位置滑动窗口中的最小值。
第二行输出，从左至右，每个位置滑动窗口中的最大值。

*/
#include <iostream>

using namespace std;

const int N = 100010;

//单调队列存储的是下标，队头 是整个数的最大值或最小值 的下标。
int q[N] , hh , tt = -1;

int n , k , a[N];

int main()
{
    scanf("%d%d" , &n , &k);
    for(int i = 0 ; i < n ; i ++)   scanf("%d" , &a[i]);

    //滑动窗口中的最小值
    int hh = 0 , tt = -1;
    for(int i = 0; i < n ; i++)
    {
        if(hh <= tt && i-k+1 > q[hh])   hh++;
        while(hh <= tt && a[q[tt]] >= a[i]) tt--;//把队列里所有比a[i]大的数都踢掉，从队尾开始删除
        q[++tt] = i;
        if(i >= k-1)    printf("%d " , a[q[hh]]);
    }
    puts("");
    //滑动窗口中的最大值    
    hh = 0 , tt = -1;
    for(int i = 0 ; i < n ; i++)
    {
        if(hh <= tt && i-k+1 > q[hh]) hh++;
        while(hh <= tt && a[q[tt]] <= a[i]) tt--;//把队列里所有比a[i]小的数都踢掉
        q[++tt] = i;
        if(i >= k-1)    printf("%d " , a[q[hh]]);
    }
    
    puts(""); 
    return 0;
}

