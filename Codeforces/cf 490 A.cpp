#include<stdio.h>
int main()
{
    int cnt[4][50001],n,i,s,mn;

    cnt[1][0]=cnt[2][0]=cnt[3][0]=0; //the 0th index counts the member of the student category

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&s);
        cnt[s][++cnt[s][0]]=i; //storing the position of the student
    }

    mn=(cnt[1][0]<cnt[2][0])?cnt[1][0]:cnt[2][0];
    mn=(mn<cnt[3][0])?mn:cnt[3][0];

    printf("%d\n",mn);
    if(cnt[1][0] && cnt[2][0] && cnt[3][0])
    {
        for(i=1;i<=mn;i++)
            printf("%d %d %d\n",cnt[1][i],cnt[2][i],cnt[3][i]);
    }
    return 0;
}
