#include<stdio.h>

int main()
{
    int row,col,t,ans;

    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&row,&col);

        if(col%2)
        {
            ans=((col/2)*row)+((row+1)/2);
        }
        else
            ans = (col/2)*row;

        printf("%d\n",ans);
    }
    return 0;
}
