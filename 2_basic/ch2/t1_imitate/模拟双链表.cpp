#include <iostream>

using namespace std;

const int N = 100010;

/*
    l[] , 左边指向
    r[] , 右边指向
    e[] , 数值

*/
int m;
int l[N] , r[N] , idx , e[N];

void init()
{
    //0表示左端点，1表示右端点
    //0号点右侧指向1号点，1号点左侧指向0号点
    r[0] = 1;
    l[1] = 0;

    idx = 2;
}

//左侧头插法
void addl(int x)
{
    e[idx] = x;

    l[idx] = 0;
    r[idx] = r[0];      //这里保存过r[0]
    
    r[0] = idx;
    l[r[idx]] = idx;    
    idx++;
}

void addr(int x)
{
    e[idx] = x;

    l[idx] = l[1];
    r[idx] = 0;

    l[1] = idx;
    r[l[idx]] = idx;
    
    idx++;
}

//将x插入到第k个插入的点的左边
void add_left(int k , int x)
{
    e[idx] = x;
    l[idx] = l[k];
    r[idx] = k;
    //先修改r[l[k]]
    r[l[k]] = idx;
    l[k] = idx;
    idx++;     
}

void add_right(int k , int x)
{   
    e[idx] = x;

    r[idx] = r[k];
    l[idx] = k;

    l[r[k]] = idx;
    r[k] = idx;
    
    idx++;
}

//删除第k个添加的节点
void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{

}
