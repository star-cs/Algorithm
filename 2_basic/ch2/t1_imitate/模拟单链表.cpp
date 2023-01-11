/*
实现一个单链表，链表初始为空，支持三种操作：

    向链表头插入一个数；
    删除第 k 个插入的数后面的数；
    在第 k 个插入的数后插入一个数。

现在要对该链表进行  M 次操作，进行完所有操作后，从头到尾输出整个链表。

注意:题目中第 k 个插入的数并不是指当前链表的第 k 个数。
例如操作过程中一共插入了 n 个数，则按照插入的时间顺序
这 n 个数依次为：第 1 个插入的数，第 2 个插入的数，…第 n 个插入的数。

输入格式
第一行包含整数 M，表示操作次数。
接下来 M 行，每行包含一个操作命令，操作命令可能为以下几种：

    H x，表示向链表头插入一个数 x。
    D k，表示删除第 k 个插入的数后面的数（当 k 为 0 时，表示删除头结点）。
    I k x，表示在第 k 个插入的数后面插入一个数 x（此操作中 k 均大于 0）。

输出格式

共一行，将整个链表从头到尾输出。

数据范围
1≤M≤100000
*/
#include <iostream>

using namespace std;

const int N = 100010;

/*
    e[i]  idx为i的实际数值
    ne[i] idx为i的下一个连接节点的idx编号
    head  初始指向-1，表示空节点。指向的是下一个节点的idx编号
*/

int head , e[N] , ne[N] , idx;


void init()
{
    head = -1;
    idx = 0;
}

//头插法
void add_to_head(int x)
{
    e[idx] = x;
    ne[x] = head;
    head = idx++;
}

void del(int x)
{
    ne[x] = ne[ne[x]];
}

//在下标为k的节点后添加x
void add(int k , int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

int main()
{
    int m;
    init();
    cin >> m;
    while(m--)
    {
        char op ; int x;
        cin >> op;
        if(op == 'H')
        {
            cin >> x;
            add_to_head(x);
        }
        else if(op == 'D')
        {
            cin >> x;
            if(!x)  head = ne[head];    //删除头节点
            else del(x-1);
        }
        else if(op == 'I')
        {
            int k ;
            cin >> k >> x;
            add(k-1 , x);
        }
    }
    for(int i = head ; i != -1 ; i = ne[i]){
        cout << e[i] << ' ';
    }
    cout << endl;

    return 0;
}

