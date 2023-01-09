/*
给定一个按照升序排列的长度为 n 的整数数组，以及 q 个查询。
对于每个查询，返回一个元素 k 的起始位置和终止位置（位置从 0开始计数）。
如果数组中不存在该元素，则返回“-1”。

输入格式
第一行包含整数 n和 q，表示数组长度和询问个数。
第二行包含 n个整数（均在1~ 10000范围内），表示完整数组。
接下来 q行，每行包含一个整数 k，表示一个询问元素。

输出格式
共 q行，每行包含两个整数，表示所求元素的起始位置和终止位置。
如果数组中不存在该元素，则返回“-1”。

数据范围
1 ≤ k ≤ 10000 1≤k≤10000 1≤k≤10000
*/

#include <iostream>

using namespace std;

const int N = 100010;
int n , q , a[N];

int main()
{
    scanf("%d%d" , &n , &q);
    for(int i = 0 ; i < n ; i ++)   scanf("%d" , &a[i]);

    while(q--)
    {
        int t;
        scanf("%d" , &t);

        //左边界
        int l = 0 , r = n-1;
        while(l < r)
        {
            int mid = r + l >> 1;
            if(a[mid] >= t) r = mid;
            else l = mid + 1;
        }
        int left = r;

        if(a[left] != t)    puts("-1 -1");
        else
        {   
            cout << l << ' ';

            //右边界
            l = 0 , r = n-1;
            while(l < r)
            {
                int mid = l + r + 1 >> 1;
                if(a[mid] <= t) l = mid;
                else r = mid - 1;
            }
            int right = l;
            
            cout << l << endl;
        }
        
    }

    return 0;
}
