#include <iostream>

using namespace std;

const int N = 100010;

int stk[N] , tt;

void push(int x)
{  
    stk[++ tt] = x;
}

int poll()
{
    return stk[tt -- ];
}

bool isEmpty()
{
    return tt == 0;
}

int top()
{
    return stk[tt];
}