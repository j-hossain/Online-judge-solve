#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

typedef long long int ll;
typedef char ch;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll r,a,b,i,j,st1,st2,sm;
    ch s[100],ans[400];
    memset(ans,'0',400);

    st2=1;

    while(1)
    {
        r=0;
        cin>>s;
        if(!strcmp(s,"0"))
            break;
        st1=strlen(s);
        r=0;
        for(i=st1-1,j=0;i>=0;j++,i--)
        {
            a=s[i]-'0';
            b=ans[j]-'0';

            sm=a+b+r;
            r=sm/10;
            sm%=10;
            ans[j]=sm+'0';
        }
        while(r>0)
        {
            a=ans[j]-'0';
            sm=a+r;
            r=sm/10;
            sm%=10;
            ans[j]=sm+'0';
            j++;
        }
        if(j>st2)
            st2=j;

        printf("%d\n",st2);

        for(i=st2-1;i>=0;i--)
            printf("%c",ans[i]);
        printf("\n");
    }
        //st2=strlen(ans);

}

