#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int n,g,s,r,m[1000],i,j=0,k,l=1,win=0,sz;
    while(scanf("%d%d",&n,&g)==2)
    {
        int max;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&s,&r);
            if(s>r)
                win++;
            if(s==r)
            {
                g--;
                win++;
            }
            if(s<r)
            {
                m[j++]=r-s;
            }
        }
        sz=j;
        printf("%d\n",j);
        for(j=0;j<sz-1;j++)
        {
            for(k=j;k<sz;k++)
            {
                if(m[k]>m[j])
                {
                    max=m[j];
                    m[j]=m[k];
                    m[k]=max;
                }

            }
        }
        for(j=0;j<sz;j++)
        {
            printf("%d ",m[j]);
        }
        printf("\n");
        j=0;
        while(g>m[j++]&&j<sz)
        {
            g-=m[j];
            win++;
            l++;
        }
        int x=win*3;
        if(g==m[l])
        {
           printf("%d\n",x+1);
        }
        else
            printf("%d\n",x);



    }

   return 0;
}

