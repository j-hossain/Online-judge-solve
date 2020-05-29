#include<stdio.h>
#include<ctype.h>

int main()
{
   int n,i,let[26],cnt;
   char s[101],c;
    scanf("%d",&n);
    scanf("%s",s);
    cnt=0;
    for(i=0;i<26;i++)
        let[i]=0;
    for(i=0;i<n;i++)
    {
        c=tolower(s[i]);
        if(!let[c-'a'])
        {
            let[c-'a']=1;
            cnt++;
        }
    }
    if(cnt==26)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
