#include<stdio.h>
int main()
{
    char image[26];

    int row,i,mn,mx,space_count[14],j,cnt;
    while(scanf("%d",&row) && row)
    {
        mn=0;
        cnt=0;
        getchar();
        j=0;
        while(j<row)
        {
            space_count[j]=0;
            gets(image);
            for(i=0;i<25;i++)
            {
                if(image[i]=='X')
                    space_count[j]++;
            }
            if(space_count[j]>mn)
                mn=space_count[j];
                j++;
        }
        for(i=0;i<row;i++)
            cnt+=(mn-space_count[i]);
        printf("%d\n",cnt);
    }
    return 0;
}
