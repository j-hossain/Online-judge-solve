#include<stdio.h>
int main()
{
    int row,column,i,j,k,n,r,ri,ci,cnt,cnt2;
    int floor[101][101],ele[101][101],ex[100000],ey[100000];
    int t,tk,x,y;
    double sum;

    int X[]={0,0,1,-1};
    int Y[]={1,-1,0,0};

    scanf("%d",&t);
    tk=0;
    while(tk<t)
    {
        tk++;
        scanf("%d %d",&row,&column);
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                scanf("%d",&floor[i][j]);
                ele[i][j]=0;
            }
        }
        r=row*column;
        ci=0;
        while(r>0)
        {
            ri=0;
            n=0;
            for(i=0;i<row;i++)
            {
                for(j=0;j<column;j++)
                {
                    if(!ele[i][j])
                    {
                        ri+=floor[i][j];
                        sum=cnt=cnt2=0;
                        for(k=0;k<4;k++)
                        {
                            x=j+X[k];
                            y=i+Y[k];
                            if(x>=0 && x<column && y>=0 && y<row)
                            {

                                sum+=floor[y][x];
                                cnt++;
                            }
                        }
                        if(floor[i][j]<sum/cnt)
                        {
                            ex[n]=j;
                            ey[n++]=i;
                        }
                    }
                }
            }
            ci+=ri;
            if(n==0)
                break;
            for(i=0;i<n;i++)
            {
                ele[ey[i]][ex[i]]=1;
            }
            printf("%d\n",ri);
            r-=n;
        }
        printf("Case #%d: %d\n",tk,ci);
    }
}
