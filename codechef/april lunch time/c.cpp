#include<bits/stdc++.h>
using namespace std;

main()
{
    int a,b;
    int j=1;

   cin>>a>>b;
   cout<<a<<b;
    int tem = b;

    while(tem<10)
    {
        tem=tem/10;
        j++;
    }

    if(a*j<b)
    {
        cout<<"-1"<<endl;
    }

    else
    cout<<"yes"<<endl;



}
