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
#define test()     	int t;cin>>t;while(t--)
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

int grid[55][55];
int i,j,r,c,cnt;

int check(int rr, int cc)
{
    int i;

    for(i=0;i<r;i++)
    {
        if(grid[i][cc])
            return 0;
    }
    for(i=0;i<c;i++)
    {
        if(grid[rr][i])
            return 0;
    }
    return 1;
}

MM{
    inout();
    fast();


    test()
    {
        cnt=0;
        cin>>r>>c;

        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            cin>>grid[i][j];

        }

        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(!grid[i][j] && check(i,j))
                {
                    grid[i][j]=1;
                    cnt++;
                }
            }
        }
        //cout<<cnt<<endl;
        if(cnt%2)
            cout<<"Ashish"<<endl;
        else
            cout<<"Vivek"<<endl;
    }
    return 0;
}
