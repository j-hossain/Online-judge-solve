#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int lenght,j,k,l,m,num;
char st[101],ans[10001];
int t,tk;

int main()
{
    int cnt;
    tk=0;
    scanf("%d",&t);
    while(tk<t)
    {
        tk++;
        scanf("%s",st);
        lenght=strlen(st);

        int a=0;
        cnt=0;
        for(j=0;j<lenght;j++)
        {
                while(cnt<st[j]-'0')
                {
                    ans[a++]='(';
                    cnt++;
                }
            ans[a++]=st[j];
                while(cnt>st[j+1]-'0' && cnt>0)
                {
                    ans[a++]=')';
                    cnt--;
                }
        }
        ans[a]='\0';
        printf("Case #%d: %s\n",tk,ans);
    }
    return 0;
}

