#include<stdio.h>
#include<string.h>

char p[11][13],name[13];
int given, num,taken,n,i,net[11],j;

void add(char nam[],int t)
{
    int k;
    for(k=0;k<n;k++)
    {
        if(!strcmp(nam,p[k]))
        {
            //printf("skhgksfgh\n");
            net[k]+=t;
            break;
        }
    }
}
int main()
{
    //freopen("uva119.txt","w",stdout);
    int flag=0;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",p[i]);
            net[i]=0;
        }
        for(i=0;i<n;i++)
        {
            scanf("%s %d %d",name,&given,&num);
            if(num>0)
            {
                taken=given/num;
                add(name,((given%num)-given));
                for(j=0;j<num;j++)
                {
                    scanf("%s",name);
                    add(name,taken);
                }
            }
        }
        if(flag)
            printf("\n");
        flag=1;
        for(i=0;i<n;i++)
            printf("%s %d\n",p[i],net[i]);
    }
    return 0;
}
