#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

#define DN          int main()
#define li          long long int
#define test()      int t;cin>>t;while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define DEC         int i,n,j,cnt=0,flag;
#define mx          100005

#define ff(s,e)         for(i=s;i<e;i+=r)
#define bf(s,e)         for(i=s;i>e;i-=r)
#define ff2(j,s,e,r)    for(j=s;j<e;j+=r)
#define bf2(j,s,e,r)    for(j=s;j>e;j-=r)

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}


DN
{
    fast();
    inout();

    int n,i,now,prev,cnt;
    char inp[55];
    stack<char>st;

    test()
    {
        cnt=0;
        cin>>n;
        cin>>inp;

        now=0;

        for(i=0;i<n;i++)
        {
            if(inp[i]=='(')
                st.push(inp[i]);
            else
            {
                if(!st.empty())
                {
                    if(st.top()=='(')
                        st.pop();
                    else
                       st.push(inp[i]);
                }
                else
                    st.push(inp[i]);
            }
        }
        cnt=st.size();
        cout<<(cnt/2)<<endl;

        while(!st.empty())
        {
            st.pop();
        }
    }

    return 0;
}
