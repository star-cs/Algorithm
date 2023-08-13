## Day1
<img src="./image/1.jpg">


## Day2 
<img src="./image/2.jpg">



## Day3

### 模板
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
<img src="./image/3.jpg">
