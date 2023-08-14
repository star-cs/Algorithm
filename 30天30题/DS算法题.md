# 30天30题（进阶）
## 模板
##### 快排
```c++
void qsort(int A[] , int l , int r)
{
    int i = l-1 , j = r+1 , x = mid[l + r >> 1];
    while(i <= j)
    {
        while(A[++i] < x);
        while(A[--j] > x);
        if(i < j)   swap(A[i] , A[j]);
    }
    qsort(A , l , j);
    qsort(a , j+1, r);
}
```

##### 二分查找
非常棒的模板！

视频讲解 https://www.bilibili.com/video/BV1d54y1q7k7/

1. 建模：划分蓝红区域，确定 IsBlue()
2. 确定返回 L 还是 R
3. 套用算法模板
4. (后处理……)，包含只有蓝色区域/红色区域的返回值处理问题等

```c++
//伪代码

//n数组长度 k寻找的数值
int bsearch(int A[] , int n , int k)    
{
    int l = -1 , r = n+1;
    while(l+1 != r)
    {
        int mid = l + r >> 1;

        if(IsBlue(mid,k))  
            l = mid;
        else 
            r = mid;
        
        return l or r;
    }
}
```
## Day1
<img src="./image/1.jpg">

思路：

```c++
void qsort(int A[] , int l , int r)
{
    int i = l-1 , j = r+1 , mid = l+r>>1;
    while(i <= j)
    {
        while(A[++i] < A[mid]);
        while(A[--j] > A[mid]);
        if(i < j) swap(A[i] , A[j]);
    }
}

void function(int A[] , int B[] , int n)
{
    qsort(A , 0 , n-1);
    qsort(B , 0 , n-1);
    int M = max(abs(A[n-1]-B[0]) , abs(A[0]-B[n-1]);
    int m = Max_Int;
    int i = 0 , j = 0;
    while(i < n || j < n)
    {
        m = min(m , abs(A[i]-B[i]));
        if(A[i] > B[j])     j++;
        else i++;
    }
    count << "最小值" << m;
    count << "最大值" << M;
    return;
}
```

## Day2 
<img src="./image/2.jpg">  
   

思路：（这个思想很常用，务必熟稔于心）
1. 构造一个足够大的数组B[]（长度为2n），用于存储A[]数组每个数值的出现次数。（相当于排序+压缩）
2. 每次将 跨度k大小的两个数组 对应的B[]出现次数相乘。得到这次的二元组个数
3. 若 k = 0，那么每个数与其本身为一次二元组。
若 k != 0，那么每个二元组交换位置又是一个新二元组，res*2

```c++
int function(int A[] , int n, int k)
{
    int B[2n];
    int res = 0;
    memset(B , 0 , sizeof(B));
    for(int i = 0 ; i < n ; i++)
    {
        B[A[i]]++;
    }
    for(int i = 0 ; i < 2n-k ; i++)
    {
        res += B[i] * B[i+k];
    }

    if(k == 0)  return res;
    else return res * 2;
}  
```
空间复杂度O(n)  
时间复杂度O(n)

> 思考：  
> 如果题目改成 |A[i] - A[j]| <= k ，最后怎么处理得到二元组？
> 
> 答案：滑动窗口


## Day3

<img src="./image/3.jpg">

思路： 

```c++
int Qsort(int A , int l , int r)
{
    if(l >= r)  return l;
    int i = l-1 , j = r+1 , x = A[l + r >>1];
    if(l < r)
    {
        while(A[++i] < x);
        while(A[--j] > x);
        if(i < j) swap(A[i] , A[j]);
    }
    Qsort(A , l , j);
    Qsort(A , j+1 , r);
}
/*
方便划分边界的二分查找法
*/
int Bsearch(int A[] , int n , int k)
{
    int l = -1 , r = n; 
    while(l + 1 != r)
    {
        int m = A[l + r >> 1];
        if(m < k) l = m;
        else r = m; 
    }
    return r; //满足条件的右边一位，方便计算ans
}

int Function(int A[] , int B[] , int C[] , int n)
{
    int ans = 0;
    Qsort(A , 0 , n-1);
    Qsort(B , 0 , n-1);
    Qsort(C , 0 , n-1);
    int i = 0 , z = 0;
    for(int j = 0 ; j < n ; j++)
    {
        i = bsearch_l(A , n , B[j]);    // i为，小于B[j]，右边一个点
        z = bsearch_l(C , n , B[j]+1);  // z为，小于B[j]+1，即大于B[j]，右边一个点。
        ans += i * (n-z);
    }
    return ans;
}
```
## Day 4

<img src="./image/4.jpg">

思路:  
1. 创建一个足够大的数组D[N]，记录每个数组的出现情况
2. 

```c++

//偷懒  O(n) O(n)
int function(int A[] , int B[] , int C[] , int n)
{
    int D[0x3f3f3f];
    memset(D , 0 , sizeof(D));

    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(D[ A[i] ] == 0)  D[ A[i] ]++;
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(D[ B[i] ] == 1)  D[ B[i] ]++;
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(D[ C[i] ] == 2)  //该数值前两个数组出现过
        {
            D[ C[i] ]++;
            ans++;
        }
    }
    return ans;
}

//优化  O(n) O(1)
void to_next(int A[] , int n , int &z)
{
    do ++z; while(z < n && A[z] == A[z-1]);
}

int function(int A[] , int B[] , int C[] , int n)
{
    int i = 0 , j = 0 , z = 0;
    int ans = 0;
    while(i < j && j < z && z < n)
    {
        if(A[i] == B[j]  && B[j] == C[z])
        {
            ans++;
            to_next(A,n,i);
            to_next(B,n,j);
            to_next(C,n,z);
        }else if(A[i] < B[j] && A[i] < C[z])    //A[i]最小，i右移。其余同理
            to_next(A,n,i);
        else if(B[j] < A[i] && B[j] < C[z])     
            to_next(B,n,j);
        else    
            to_next(C,n,z);
    }
}
```