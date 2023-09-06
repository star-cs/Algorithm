# 30天30题（进阶）
## 必背模板
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

> 非常棒的模板！  
> 视频讲解 https://www.bilibili.com/video/BV1d54y1q7k7/  
> 
> 1. 建模：划分蓝红区域，确定 IsBlue()
> 2. 确定返回 L 还是 R
> 3. 套用算法模板
> 4. (后处理……)，包含只有蓝色区域/红色区域的返回值处理问题等

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


> 思路：...

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
   

> 思路：（这个思想很常用，务必熟稔于心）
> 1. 构造一个足够大的数组B[]（长度为2n），用于存储A[]数组每个数值的出现次数。（相当于排序+压缩）
> 2. 每次将 跨度k大小的两个数组 对应的B[]出现次数相乘。得到这次的二元组个数
> 3. 若 k = 0，那么每个数与其本身为一次二元组。
若 k != 0，那么每个二元组交换位置又是一个新二元组，res*2

> 空间复杂度O(n)  
> 时间复杂度O(n)

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


> 思考：  
> 如果题目改成 |A[i] - A[j]| <= k ，最后怎么处理得到二元组？
> 
> 答案：滑动窗口


## Day3

<img src="./image/3.jpg">

> 思路：... 

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

> 思路:  ...
>
> 

```c++
//优化  O(n) O(1)
int to_next(int A[] , int &i)   //引用i，需要修改i值
{
    while(A[i] == A[i-1]) i++;  //当前数值不等于前一个数值，说明当前是新数值。
}
int function(int A[] , int B[] , int C[] , int n)
{
    int i = 0 , j = 0 , z = 0;
    int ans = 0;
    while(i < j && j < z && z < n)
    {
        if(A[i] == B[j] && B[j] == C[z])
        {
            ans++;
            to_next(A[i] , i);
            to_next(B[j] , j);
            to_next(C[z] , z);
        }
        else
        {
            int Min = min(A[i] , B[j] , C[z]);  //三个数值中 最小值 移动

            if(A[i] == min) to_next(A[i] , i);
            if(B[j] == min) to_next(B[j] , j);
            if(C[z] == min) to_next(C[z] , z);
        }
    }
}
```

## Day 5

<img src="./image/5.jpg">

> 思想：滑动窗口

```c++
int function(int A[] , int n , int k)
{
    int i = 0 , j = 0 , sum = A[0] , ans = 0;
    while(i <= j && j < n)
    {
        if(sum < k) 
        {
            j++;
            sum += A[j];
        }
        else
        {
            ans = min(ans , j-i+1);
            sum -= A[i];
            i--;
        }
    }
    return ans;
}
```


## Day6

<image src="./image/6.jpg">

> 思想：
> 1. 对X[]从大到小遍历，每次记录当前列的最大temY。只要temY大于之前的Y上限，那么就是一个极大值，并且更新Y上限。

时间 O(nlogn)
空间 O(logn)

```c++
void qsort(int X[] , int Y[] , int l , int r)
{
    int i = l-1 , j = r+1 , mid = l+r>>1;
    while(i < j)
    {
        while(X[++i] < X[mid])
        while(X[--j] > X[mid])
        if(i < j)   
        {
            swap(X[i] , X[j]);
            swap(Y[i] , Y[j]);
        }
    }
    qsort(X , Y , l , i);
    qsort(X , Y , i+1 , r);
}

int function(int X[] , int Y[] , int n)
{
    int ans = 0;
    qsort(X , Y , 0 , n-1);
    //从大到小遍历X[]
    int i = n-1 ;
    int Y = 0; // Y上限
    while(i >= 0)
    {
        int temX = X[i];
        int temY = 0;   //当前列的最大值temY
        while(X[i] == temX)
        {
            temY = max(temY , Y[i]);
            i--;
        }
        if(temY > Y)  
        {
            Y = temY;
            ans++;
        }
    }
    return ans;
}
```

## Day7
<image src="./image/7.jpg">

> 思想：  
> 前缀和  
> 连续子数组元素和的最大值，那么就是 当前前缀和-最小前缀和  
> 假设 最小前缀和在x点取到（sum[0,x]是最小的）。  
> 即，当前 [0,i]之间sum - [0,x]之前sum == [x,i]之前的sum

```c++
int function(int A[] , int n)
{
    //cnt 当前前缀和，m 最小前缀和
    int cnt = 0 , m = 0;
    int ans = -INF;
    for(int i = 0 ; i < n ; i++)
    {
        cnt += A[i];
        ans = max(cnt - m , ans);
        m = min(cnt , m);
    }
    return ans;
}
```
## Day8
<image src="./image/8.jpg">

>思路：  
> 

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
int function(int A[] , int n , int k)
{
    qsort(A , 0 , n-1);
    int i = 0 , j = n-1;
    while(i <= j)
    {
        if(A[i] + A[j] > k) j--;  //两端相加大于k，只能减少右端
        else if(A[i] + A[j] < k) i++; //两端相加小于k，只能增加左端
        else(A[i]+A[j] == k) //两端相加等于k，之后的二元组只会在区间内部取到
        {
            if(i == j) 
            {
                ans ++;
                break;  //i==j，直接break，跳过下面的(i,i)(j,j)判断。
            }
            else ans += 2;
            i++; j--;
        }
        if(A[i] * 2 == k) ans++;    
        //当 (i,i) 也满足时，得另外判断。因为，i，j两个指针不会在当前位置会合。
        if(A[j] * 2 == k) ans++;
    }
    return ans;
}
```


## Day9
<image src="./image/9.jpg">

> 分析：（非常棒的思想！！！）
> 1. 每计算一个前缀和，对其进行取余k，余数相同的可以作为满足题意的首尾。

```c++
int function(int A[] , int n , int k)
{
    int hash[k];
    int sum = 0;
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        sum += A[i];
        ans += hash[ sum % k];
        hash[ sum % k]++;
    }
    return ans;
}
```


## Day10

<image src="./image/10.png">


```c++
int function(int A[] , int n)
{
    for(int i = 1 ; i < n ; i++) A[i] += A[i-1];    //前缀和

    int j = 0 , k = 0;  //k指向的是刚好不满足S2 <= S3的位置
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        int s1 = A[i];
        // 两个分割点必须保持前后顺序
        j = max(i+1 , j);
        //  s1 <= s2 <= s3  找s2的左右边界
        while(j < n && (A[j] - A[i]) < s1) j++;
        while(k < n && (A[k] - A[i]) <= (A[n-1] - A[k])) k++;
        ans += k - j;
    }
    return ans;
}
```


## Day11

<image src="./image/11.jpg">

> 思想：  
> 滑动窗口
>
> 时间O(n)  
> 空间O(n)

```c++
int function(int A[] , int n)
{
    int hash[n];
    malloc(hash , 0 , sizeof(hash));

    int i = 0 , j = 0 ;
    int ans = 0;
    while(i <= j && j < n)
    {
        while(hash[ A[j] ] == 0) 
        {
            hash[A[j]] = 1;
            j++;
        }
        //当前j指向 第二个重复元素
        ans = max(ans , j-i);

        while(i <= j && A[i] != A[j])
        {
            hash[A[i]] = 0;
            i++;
        }
        //当前i指向 第一个重复元素
        i++ ; j++ ;
        //i,j 移动，重复元素不用修改。
    }
    return ans;
}

```


## Day12

<image src="./image/12.jpg" >

> 思路：  
> 滑动窗口记录，窗口内 在 范围内 的元素的个数
> num 记录窗口内 在范围内 的元素的种类

```c++
int function(int A[] , int n , int k)
{
    int hash[k];
    malloc(hash , 0 , sizeof(hash));
    int i = 0 , j = 0;
    int num = 0;
    int ans = 0;
    while(i <= j && j < n)
    {
        if(num < k)
        {
            int t = A[j];
            j++;        //j指向下一个将进入窗口的元素
            if(t >= k) continue;
            else
            {
                if(hash[t] == 0) num++; //进入窗口的元素种类+1
                hash[t]++;
            }
        }
        else
        {
            ans = min(ans , j - i);
            int t = A[i];
            i++;
            if(t >= k) continue;
            else
            {
                hash[t]--;              //不会减到负数
                if(hash[t] == 0) num--;
            }
        }
    }
    return ans;
}

```

## Day13

<image src="./image/13.jpg">


> 思想：  
> 1. 依次比较两个指针

```c++
typedef struct LNode
{
    int data;
    struct LNode * next;
} LNode , *LinkList;

LinkList function(LinkList &ha , LinkList &hb)
{
    LNode * p1 = ha -> next;
    LNode * p2 = hb -> next;

    ha = NULL;
    LNode * t = ha;

    while(p1 != NULL && p2 != NULL)
    {
        if(p1->data <= p2->data)    
        {
            t->next = p1;
            t = t->next;
            p1 = p1->next;
        }
        else
        {
            t->next = p2;
            t = t->next;
            p2 = p2->next;
        }
    }

    return ha;
}
```

## Day14

<image src="./image/14.jpg">

> 思路：  
> 将hb

```c++
struct typedef LNode
{
    int data;
    struct LNode * next;
}LNode , *LinkList;

void reserve(LinkList &L)
{
    LNode cnt = L->next , pre = L;
    while(cnt->next != NULL)
    {
        LNode t = cnt->next;
        cnt->next = pre;
        pre = cnt; 
        cnt = t;
    }
    L->next = cnt;
}

LinkList function(LinkList &ha , LinkList &hb)
{
    reserve(hb);

    LNode p1 = ha->next , p2 = hb->next;

    ha->next = NULL;

    LNode t = ha;

    while(p1 != NULL && p2 != NULL)
    {
        if(p1->data <= p2->data)
        {
            t->next = p1;
            p1 = p1->next;
        }
        else
        {
            t->next = p2;
            p2 = p2->next;
        }
    }
    if(p1 != NULL)   t->next = p1;
    if(p2 != NULL)   t->next = p2;
    
    return ha;
}
```

## Day 15

<image src="./image/15.jpg">

> 思想：  
> 1. 对链表的右半边就行转置  
> 2. 从链表的左右两边向中间移动，并记录节点数值之和  
>   

```c++
typedef struct Node
{
    int data;
    struct Node * next;
}Node , *LinkList;


int function(LinkList &L)
{
    Node *p = L->next;  int len = 0;
    while(p != NULL)
    {
        len++;
        p = p->next;
    }

    int mid = len/2;
    p = L;        //重置p

    while(mid--)
    {
        p = p->next;
    }//p指向中间偏左的节点

    Node *cnt = p->next;

    while(cnt != NULL)
    {
        t = cnt->next;
        cnt->next = p;
        p = cnt;
        cnt = t;
    }//p最后指向尾节点

    int ans = 0;
    Node *h = L->next;
    // while(h->next != q)     //这里的判断条件有待商榷
    // {
    //     ans = max(ans , h->data + p->data);
    //     h = h->next;
    //     p = p->next;
    // }

    for(int i = 0 ; i < len/2 ; i++)
    {
        ans = max(ans , h->data+p->data);
        h = h->next;
        p = p->next;
    }

    return ans;
}
```

## Day 16

<image src='./image/16.jpg'>

```c++
typedef struct Node
{
    int data;
    struct Node * next;
} Node , *List;

int function(List &L)
{
    Node *cnt = L->next , *pre = L;     //前后指针
    while(p1->next != NULL)
    {
        if(cnt->data == cnt->next->data)
        {
            pre->next = cnt->next;
            free(cnt);
            cnt = pre->next;
        }
        else
        {
            pre = cnt;
            cnt = cnt->next;
        }
    }
    return L;
}

```


## Day 17

<image src="./image/17.jpg">


```c++
typedef struct Node
{
    int data;
    struct Node * next;
} Node , *List;

Node* function(List &L)
{
    Node *cnt = L->next , *ans;
    int flag = 0;   //标志为0，严格递增；标志为1，严格递减
    while(cnt != NULL)
    {  
        if(flag == 0)
        {
            if(cnt->data < cnt->next->data)
                cnt = cnt->next;
            else if(cnt->data > cnt->next->data)
            {
                ans = cnt;
                flag = 1;
            }
            else
                //不是严格递增时
                return NULL;
        }
        else if(flag == 1)
        {
            if(cnt->data > cnt->next->data)
                cnt = cnt->next;
            else
                //不符合规定
                return NULL;
        }
    }
    return ans;
}

```