#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int lenght,j,k,l,m,open_pos[10000],close_pos[10000],num,o,c;
char st[101],ans[10001];
int t,tk;

void recursion(int start, int ennd,int s)
{
    if(s==10)
        return;
    int open,close;
    open=close=-99;
    int i;
    for(i=start;i<ennd;)
    {
        if(st[i]-'0'>=s)
        {
            while(st[i]-'0'>=s)
            {
                i++;
                if(i==ennd)
                {
                    break;
                }

            }
            close=i;
            i--;
            while(st[i]-'0'>=s)
            {
                i--;
                if(i==start)
                {
                    i--;
                    break;
                }

            }
            open=i;
            if(open!=close)
            {
                open_pos[o++]=open;
                close_pos[c++]=close;
            }
            recursion(open,close,s+1);
            i=close;
        }
        else
            i++;
    }
}

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
        o=c=0;
        recursion(0,lenght,1);

        sort(open_pos,open_pos+o);
        sort(close_pos,close_pos+c);

        k=l=0;

        int a=0;
        cnt=0;
        for(j=0;j<lenght;j++)
        {
            if(k<o)
            {
                while(open_pos[k]<=j-1 && cnt<st[j]-'0')
                {
                    ans[a++]='(';
                    k++;
                    cnt++;
                    if(k==o)
                        break;
                }

            }
            ans[a++]=st[j];
            if(l<c)
            {
                while(close_pos[l]<=j+1 && cnt>st[j+1]-'0' && cnt>0)
                {
                    ans[a++]=')';
                    l++;
                    cnt--;
                    if(l==c)
                        break;
                }
            }
        }
        ans[a]='\0';
        printf("Case #%d: %s\n",tk,ans);
    }
    return 0;
}
