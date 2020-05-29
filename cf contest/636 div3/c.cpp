#include<bits/stdc++.h>
using namespace std;

main()
{
    int t,cou=0;
    cin>>t;

    for(int i=1; i<=t; i++)
    {
        int n,j=3;
        cin>>n;
        for(j=3; j<=n; j++)
        {
            if(n%j==cou)
            {
                int a=n/j;
                cout<<a<<endl;
                break;
            }
        }



    }
}
