#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MM          int main()
#define ll          long long int
#define test        int t;scanf("%d",&t);while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define DEC         int i,n,j,cnt=0,flag;
#define mx          100005

#define ff(j,s,e,r)     for(j=s;j<e;j+=r)
#define bf(j,s,e,r)     for(j=s;j>e;j-=r)

ll arr[mx];
ll tree[3*mx];

void makeTree(int st, int en, int nd)
{
    if(st==en)
    {
        tree[nd]=arr[st];
        return;
    }

    int md = (st+en)/2;
    int l = nd*2;
    int r = l+1;
    makeTree(st,md,l);
    makeTree(md+1,en,r);

    tree[nd]=tree[l]+tree[r];
}

void changeTree(int st, int en, int nd, int pos, int vl)
{
    if(st>pos || en<pos)
        return;
    if(st==en)
    {
        if(st==pos)
        {
            if(vl==0)
                cout<<tree[nd]<<endl;
            tree[nd]= vl==0?0:tree[nd]+vl;
        }
        return;
    }

    int md = (st+en)/2;
    int l = nd*2;
    int r = l+1;

    changeTree(st,md,l,pos,vl);
    changeTree(md+1,en,r,pos,vl);
    tree[nd] = tree[l] + tree[r];
}

ll askTree(int st,int en,int nd,int p1,int p2)
{
    if(st>p2 || en<p1)
        return 0;

    if(p1<=st && p2>=en)
        return tree[nd];

    int md = (st+en)/2;
    ll l = askTree(st,md,nd*2,p1,p2);
    ll r = askTree(md+1,en,nd*2+1,p1,p2);

    return l+r;
}

int main()
{
    fast();
    int ans,n,q,tp,s,e,i,v,tk;
    tk=0;
    test
    {
        cin>>n>>q;
        tk++;

        for(i=0; i<n; i++)
            cin>>arr[i];

        makeTree(0,n-1,1);
        cout<<"Case "<<tk<<":"<<endl;
        while(q--)
        {
            cin>>tp>>s;

            if(tp==1)
            {
                changeTree(0,n-1,1,s,0);
            }
            else if(tp==2)
            {
                cin>>v;
                changeTree(0,n-1,1,s,v);
            }
            else
            {
                cin>>e;
                ans=askTree(0,n-1,1,s,e);
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}









