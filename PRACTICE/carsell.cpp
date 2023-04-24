#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define akka long long
const int N = 1e9+7;
int main()
{
    akka t;
    cin>>t;
    while (t--)
    {
        akka n;
        cin>>n;
        akka a[n];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        sort(a,a+n,greater<akka>());
        akka q=0;
        akka s=0;
        for (int i = 0; i < n; i++)
        {
            a[i]-=q;
            if (a[i]<0)
            {
                a[i]=0;
            }
            s+=(a[i]%N);
            s%=N;
            q++;
        }
        cout<<s<<endl;
    }
    return 0;
}
