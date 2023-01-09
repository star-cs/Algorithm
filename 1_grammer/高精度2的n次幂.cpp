#include <iostream>

using namespace std;

const int N = 3010;

int main()
{   
    int a[N] = {1};
    int n ;
    cin >> n;
    int m = 1;

    for(int i = 0 ; i < n ; i++)
    {
        int t = 0;
        for(int j = 0 ; j < m ; j++ )
        {
            t += a[j] * 2;
            a[j] = t % 10;
            t /= 10;
        }
        if(t)   a[m++] = 1;
    }
    
    for(int i = m - 1; i >= 0 ; i--)    cout << a[i];

    cout << endl;

    return 0;
}