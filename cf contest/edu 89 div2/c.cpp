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

typedef struct
{
    int zer;
    int one;
}groupPoint;

groupPoint groups[100];
int grid[35][35];
int r,c;



MM
{
    fast();
    inout();

    int i,j,cnt,z,o,k;
    test()
    {
        cin>>r>>c;
        cnt=0;
        for(i=0;i<100;i++)
            groups[i].zer=groups[i].one=0;

        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                cin>>grid[i][j];
            }

        }

        for(k=0;k<r-1;k++)
        {
            j=0;
            i=k;
            while(i>=0 && j<c)
            {
                if(grid[i][j])
                    groups[k].one++;
                else
                    groups[k].zer++;
                i--;
                j++;
            }
        }
        for(k=0;k<c;k++)
        {
            j=k;
            i=r-1;
            while(i>=0 && j<c)
            {
                if(grid[i][j])
                    groups[k+r-1].one++;
                else
                    groups[k+r-1].zer++;
                i--;
                j++;
            }
        }

        for(i=0;i<(r+c)/2;i++)
        {
            j=r+c-2-i;
            if(i!=j)
            {
                z=groups[i].zer+groups[j].zer;
                o=groups[i].one+groups[j].one;
                cnt+=(z<o?z:o);
            }
        }
        cout<<cnt<<endl;

    }
    return 0;
}
