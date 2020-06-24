#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

#define MM          int main()
#define li          long long int
#define test()      int t;cin>>t;while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define DEC         int i,n,j,cnt=0,flag;
#define mx          100005

#define ff(j,s,e,r)     for(j=s;j<e;j+=r)
#define bf(j,s,e,r)     for(j=s;j>e;j-=r)

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}

int check(int a, int b)
{
    if(a>b)
        return 1;
    if(a==b)
        return 0;
    return check(a*a,b);
}

MM
{
    fast();
    inout();

    int n,num,i,ans1[500007],ans2[500007],j,sq,temp;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>num;
        sq=sqrt(num);
        for(j=2;j<sq;j++)
        {
            if(num%j==0)
            {
                if(check(j,num))
                {
                    temp
                }
            }
        }
    }

    return 0;
}
