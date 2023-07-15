 #include <stdio.h>
 #include <stdlib.h>
 
 typedef int ElemType;

//Day01
//在带头结点的单链表L中,删除所有值为x的结点,并释放其空间,假设值为x的结点不唯一
//编写算法以实现上述操作
void Del_x(LinkList &L , ElemType x)
{
    LNode *pre = L , *cnt = L->next;
    while(cnt != NULL)  
    {
        if(cnt->data == x) 
        {   
            LNode tem = cnt;        //待删除的节点
            pre->next = cnt->next;    
            cnt = cnt.next;         //pre保持不变，cnt移动
            free(tem);  
        }
        else
        {
            pre = cnt;
            cnt = cnt->next;
        }
    }
}

//Day02
//将两个有序顺序表合并为一个新的有序顺序表,并由函数返回结果顺序表
void Merge(SqList A , SqList B , SqList &C)
{
    if(A.length + B.length > C.length)  
        return false;
    int i = 0 , j = 0 , z = 0;
    while(i < A.length && j < B.length)
    {
        if(A.data[i] <= B.data[j])
            C.data[z++] = A.data[i++];
        else
            C.data[z++] = B.data[j++];
    }
    while(i < A.length) C.data[z++] = A.data[i++];
    while(j < B.length) C.data[z++] = B.data[j++];
    C.length = z + 1;
    return true;
}


//Day03
//设计一个高效算法,将顺序表L的所有元素逆置,要求算法的空间复杂度为O(1)
// 1 2 3 4 5 6
// 5 4 3 2 1
void Reverse(SqList &A)
{
    int i = 0 ,  j = A.length - 1; 
    while(i < j)
    {
        ElemType t = A.data[i];
        A.data[i] = A.data[j];
        A.data[j] = t;
        i++ , j--;
    }
}
//递归法
void R2(SqList &A, int left , int right)
{
    if(left < right)
    {
        swap(A.data[left] , A.data[right]);
        R2(A , left+1 , right-1);
    }
}

//Day04
//对长度为n的顺序表L,编写一个时间复杂度为O(n),空间复杂度为O(1)的算法,
//该算法删除线性表中所有值为x的数据元素

//双指针
//如果 k != i，那么k指向的一定是x
//知道i找到下一个非x的数值，可以直接替换k下标的数值
void Del_x(SqList &L , ElemType x)
{
    int i = 0 , k = 0;  //k下标左边均无x的值
    while(i < L.length)
    {
        if(L.data[i] == x)  i++;    //等于x，i下标右移
        else    //不等于x，将i指针的值复制到k下标
        {
            L.data[k] = L.data[i];
            k++; i++;
        }
    }
    L.length = k;
}

//精简版本
void Del_x(SqList &L , ElemType x)
{
    int i = 0 , k = 0;  //k下标指向，新顺序表的最右端节点+1的位置。
    while(i++ < L.length)
    {
        if(L.data[i] != x)
            L.data[k++] = L.data[i];
    }
    L.length = k;
}


//Day05
//从顺序表中删除其值在给定值s与t之间(包含s和t,要求s < t）的所有元素
//如果s或t不合理或顺序表为空,则显示出错信息并退出运行
bool Del_form_s_to_t(SqList &L , ElemType s , ElemType t)
{
    if(s >= t || L.length == 0)  
    {
        return fasle;
    }
    int i = 0 , k = -1;     //k指向新顺序表的最右端节点
    while(i++ < L.length)
    {
        if( !(L.data[i] >= s && L.data[i] <= t) )  
        {   
            L.data[++k] = L.data[i];        //k下标先右移，再赋值。
        }
    }
    L.length = k+1;         //这里是和上一题k值设置的区别
    return true;
}

//Day06
//从有序顺序表中删除所有其值重复的元素,使表中所有元素的值均不同
void Del_same1(SqList &L)
{
    // int arr[L.length];
    // memset(arr , 0 , sizeof arr);
    // int i = 0 , k = -1;
    // while(i++ < L.length)
    // {
    //     if(arr[L.data[i]] == 0) 
    //     {
    //         L.data[++k] = L.data[i];
    //         arr[L.data[i]]++;
    //     }
    //     else
    //     {
    //         i++;
    //     }
    // }
    // L.length = k+1;

    //有序顺序表
    int i = 1 , k = 0;  //顺序表第一个数默认保存，i从第二个开始判断
    while(i++ < L.length)
    {
        if(L.data[k] != L.data[i])
        { 
            L.data[++k] = L.data[i];
        }
    }
    L.length = k+1;
}


//Day07
//已知在一维数组A[m+n]中依次存放两个顺序表(a1,a2,a3 ...,am)和(b1,b2,b3 ...,bn)。
//试编写一个函数,将数组中两个顺序表的位置互换,即将(b1,b2,b3 ...bn)放在(a1, a2,a3 ...,am)的前面

//整体翻转，再内部翻转
//反过来同理，反过来写，边界更加好判断一点
void Reserve_a_b(SqList &A , int m , int n) //前m个，后n个
{
    //a [0,m-1]
    //b [m,m+n-1]
    //转换后，前n个，后m个
    reserve(A , 0 , m+n-1);
    reserve(A , 0 , n-1);
    reserve(A , n , m+n-1);
}
void reserve(SqList &A , int l , int r)
{
    int i = l , j = r;
    while(i < j)
    {
        int t = A.data[r];
        A.data[r] = A.data[l];
        A.data[l] = t;
        i++ , j--;
    }
}


//Day08
//2010统考真题
//


//Day09
//试编写带头结点的的单链表L中删除一个最小值结点的高效算法(假设最小值结点是唯一的)
LinkList Del_min_node(LinkList &L)
{
    LNode *cnt = L->next;
    LNode *pre_min_node = L->next;  //记录最小节点的前一个节点
    int min = cnt->data;            //最小数值
    while(cnt != NULL)
    {
        LNode *cnt_next = cnt->next;    
        if(cnt_next->data < min)    //cnt下一个节点是最小节点时
        {
            pre_min_node = cnt;
            min = cnt_next->data;   
        }
        cnt = cnt->next;
    }
    LNode *min_node = pre_min_node->next;
    pre_min_node->next = pre_min_node->next->next;  //删除最小值
    free(min_node);
    return L;
}

//Day10
//使用头插法建立单链表
LinkList init_head(LinkList &L)
{
    LNode *temp;
    L = new LNode();
    L->next = NULL;
    int x;
    cin >> x;
    while(x != -1)
    {
        temp = new LNode();
        temp->data = x;

        temp->next = L->next;
        L->next = temp;

        cin >> x;
    }
    return L;
}

//Day11
//使用尾插法建立单链表
LinkList init_end(LinkList &L)
{
    L = new LNode();
    L->next = NULL;
    LNode *cur = L->next;
    int x;
    cin >> x;
    while(x != -1)
    {
        LNode *tem = new LNode();
        tem->data = x;
        tem->next = NULL;
        cur->next = tem;

        cur = tem;
    }
    return L;
}

//Day12
//试编写算法将带头结点的单链表就地逆置，
//所谓的“就地”是指辅助空间的复杂度为O (1)
// 1-2-3-4-5
//     3 4-5 

LinkList reserve(LinkList &L){
    LNode *p1 = L->next;
    LNode *p2 = p1->next;
    while(p2->next != NULL)    
    {
        LNode *p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    p2->next = p1;  //最后p2到了最后一个节点
    L->next->next = NULL;    //将之后的尾节点->next = NULL;
    L->next = p1;   //L头节点重新换位子
    return L;
}


//Day13
//设在一个带表头结点的单链表中所有元素的结点的数据值无序，试编写一个函数，
//删除表中所有介于给定的的两个值(作为函数的参数给出）之间的元素的元素(若存在)。
void del(LinkList &L , int min , int max)
{
    LNode *p = L->next;
    while(p->next != NULL)
    {
        LNode *p1 = p->next;
        if(p1->data >= min && p1->data <= max)
        {
            p->next = p1->next;
            free(p1);
        }
        else
        {
            p = p1;
        }
    }
}

//Day14(上)
//给定两个单链表，编写算法找出两个单链表的公共结点
LNode same_node(LinkList &L1 , LinkList &L2)
{
    int L1_len = 0;
    int L2_len = 0;
    LNode *t1 = L1->next;
    LNode *t2 = L2->next;
    while(t1 != NULL)   
    {
        L1_len++;
        t1 = t1->next;
    }
    while(t2 != NULL)
    {
        L2_len++;
        t2 = t2->next;
    }
    t1 = L1->next;  //t1 t1重置
    t2 = L2->next;
    while(L1_len++ < L2_len) t2 = t2->next;     //L2长，那么t2得提前移动 L2_len-L1_len
    while(L1_len > L2_len++) t1 = t1->next;     //L1长，那么t1得提前移动
    //保证 t1 t2 从距离末端 相同的位置出发。
    while(t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;
    }
    return t1;
}

//时间复杂度 O(len1 + len2);
    
//Day15
//将一个带头结点的单链表A分解为两个带头结点的单链表A和B，
//使得A表中含有原表中序号为奇数的元素，
//而B表中含有原表中序号为偶数的元素，且保持其相对顺序不变。
LinkList Divide(LinkList &A)
{
    LNode *p = A->next;
    LNode *p1 = A;
    //LinkList B = new LinkList();
    LinkList B = (LinkList)malloc(sizeof(LNode));
    B->next = NULL;
    LNode *p2 = B;
    int i = 0;
    while(p != NULL)
    {
        i++;
        if(i % 2 != 0)  //奇数节点
        {
            p1->next = p;
            p1 = p;
        }
        else
        {
            p2->next = p;
            p2 = p;
        }
        p = p->next;
    }
    p1->next = NULL;
    p2->next = NULL;
    return B;
}