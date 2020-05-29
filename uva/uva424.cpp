#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

typedef long long int ll;
typedef char ch;

void rev(char *c,int n)
{
    char temp;
    int i;
    for(i=0;i<n/2;i++)
    {
        temp=c[i];
        c[i]=c[n-1-i];
        c[n-1-i]=temp;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll r,a,b,i,j,st1,st2,sm;
    ch s[100],ans[200];
    ans[0]='\0';
    while(1)
    {
        r=0;
        cin>>s;
        if(!strcmp(s,"0"))
            break;
        st1=strlen(s);
        st2=strlen(ans);
        for(i=st1-1,j=0;i>=0;j++,i--)
        {
            a=s[i]-48;
            if(ans[j]=='\0')
            {
                sm=a+r;
                r=sm/10;
                sm%=10;
                ans[j]=a+r+48;
                ans[j+1]='\0';
            }
            else
            {
                b=ans[j]-48;
                sm=a+b+r;
                r=sm/10;
                sm%=10;
                ans[j]=sm+48;
            }
        }
        if(r!=0)
        {
            st2=strlen(ans);
            if(st2==j)
            {
                ans[j]=r+48;
                ans[j+1]='\0';
            }
            else
            {
                //j--;
                while(ans[j]!='\0')
                {
                    a=ans[j]-48+r;
                    if(a<10)
                    {
                        ans[j]=a+48;
                        r=a/10;
                    }

                    else
                    {
                        r=a/10;
                        a%=10;
                        ans[j]=a+48;
                    }
                    j++;
                }
                if(r!=0)
                {
                    ans[j]=r+48;
                    ans[j+1]='\0';
                }
            }
        }
    }
        st2=strlen(ans);
        for(i=st2-1;i>=0;i--)
            printf("%c",ans[i]);
        printf("\n");
}
