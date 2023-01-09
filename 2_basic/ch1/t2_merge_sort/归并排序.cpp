#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n , q[N] , t[N];

void merge_sort(int q[] , int l , int r)
{
    if(l >= r)  return;

    int mid = l + r >> 1;

    merge_sort(q , l , mid) , merge_sort(q , mid+1 , r);
    //归并 --- 合二为一
    int i = l , j = mid+1 , k = 0;
    while(i <= mid && j <= r)
    {
        //当i，j指向两个相等的数时，优先选取i指向的数，保证整个排序是稳定的。
        if(q[i] <= q[j])    t[k++] = q[i++];
        else    t[k++] = q[j++];
    }
    while(i <= mid) t[k++] = q[i++];
    while(j <= r)   t[k++] = q[j++];

    for(int i = l , j = 0; i <= r ; i++ , j++ )
    {
        q[i] = t[j];
    }

}

int main()
{
    scanf("%d" , &n);
    for(int i = 0 ; i < n ; i++)    scanf("%d" , &q[i]);

    merge_sort(q , 0 , n - 1);

    for(int i = 0 ; i < n ; i++)    printf("%d " , q[i]);

    return 0;
}