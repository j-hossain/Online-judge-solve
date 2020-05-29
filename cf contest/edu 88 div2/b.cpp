#include<stdio.h>

int main(){

    int r,c,x,y,i,j,cnt1,cnt2,temp,t,ans;
    char grid[105][1005];

    scanf("%d",&t);
    while(t--){

        scanf("%d %d %d %d",&r,&c,&x,&y);

        for(i=0;i<r;i++)
            scanf("%s",grid[i]);
        cnt1=cnt2=0;
        for(i=0;i<r;i++){

            for(j=0;j<c;j++){
                temp=0;
                while(grid[i][j+temp]=='.')
                    temp++;
                cnt1+= temp%2;
                cnt2+= temp/2;
                if(temp)
                    j+=(temp-1);
            }
        }

        if(2*x>y)
            ans=cnt1*x+cnt2*y;

        else
            ans=cnt1*x+cnt2*2*x;

        printf("%d\n",ans);
    }
}
