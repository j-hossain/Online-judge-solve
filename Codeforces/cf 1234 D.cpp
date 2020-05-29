#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>

using namespace std;

int main()
{
    int n,p,l,r,i,t,cnt;
    char ch[2],s[100001];
    vector<set<int>>c(26);
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++)
        c[s[i]-'a'].insert(i);
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%d %s",&p,ch);
            p--;
            c[s[p]-'a'].erase(p);
            s[p]=ch[0];
            c[ch[0]-'a'].insert(p);
        }
        else
        {
            scanf("%d %d",&l,&r);
            l--;
            r--;
            cnt=0;
            for(i=0;i<26;i++)
            {
                auto temp=c[i].lower_bound(l);
                if(temp!=c[i].end() && *temp<=r)
                    cnt++;
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}
