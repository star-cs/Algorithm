#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int A , B , C , D;
    // cin >> A >> B >> C >> D;

    // cout << "DIFERENCA = " << A * B - C * D << endl; 

    scanf("%d%d%d%d" , &A , &B , &C , &D);

    printf("%d" , (A * B ) - (C * D));

    return 0;
}