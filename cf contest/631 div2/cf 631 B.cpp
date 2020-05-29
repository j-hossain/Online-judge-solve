#include<stdio.h>
int main()
{
    int l1,l2,t,s,n[200002],found1,i,mx,flag=0,found2;
    int mp[200002],tempmx,cnt2;
    int cnt;
    //freopen("output.txt","w+",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&s);
        mx=0;
        for(i=1;i<=s;i++)
        {
            scanf("%d",&n[i]);
            if(n[i]>mx)
                mx=n[i];
        }
        for(i=0;i<=mx;i++)
            mp[i]=0;

        cnt=flag=found1=found2=0;
        tempmx=0;
        for(i=1;i<s;i++)
        {
            if(!mp[n[i]])
            {
                mp[n[i]]=1;
                cnt++;
            }
            else
            {
                break;
            }
            if(tempmx<n[i])
                tempmx=n[i];
            if(cnt==tempmx)
            {
                flag=1;
                l1=i;
            }
        }
        cnt=cnt2=0;
        tempmx=0;
        for(i=1;i<=mx;i++)
            mp[i]=0;
        for(i=l1+1;flag && i<=s;i++)
        {
            cnt2++;
            if(!mp[n[i]])
            {
                mp[n[i]]=1;
                cnt++;
            }
            if(tempmx<n[i])
                tempmx=n[i];
        }
        if(cnt==tempmx && cnt==cnt2 && flag)
            found1=1;

        tempmx=cnt=flag=0;
        for(i=0;i<=mx;i++)
            mp[i]=0;

        for(i=s;i>1;i--)
        {
            if(!mp[n[i]])
            {
                mp[n[i]]=1;
                cnt++;
            }
            else
            {
                break;
            }
            if(tempmx<n[i])
                tempmx=n[i];
            if(cnt==tempmx)
            {
                flag=1;
                l2=i;
            }
        }
        cnt=cnt2=0;
        tempmx=0;
        for(i=1;i<=mx;i++)
            mp[i]=0;
        for(i=l2-1;flag && i>0;i--)
        {
            cnt2++;
            if(!mp[n[i]])
            {
                mp[n[i]]=1;
                cnt++;
            }
            if(tempmx<n[i])
            tempmx=n[i];
        }
        if(cnt==tempmx && cnt==cnt2 && flag && l1!=l2-1)
            found2=1;

        printf("%d\n",found1+found2);
        if(found1 && found2)
        {
            printf("%d %d\n",l1,s-(l1));
            printf("%d %d\n",l2-1,s-(l2-1));
        }
        else if(found1)
            printf("%d %d\n",l1,s-(l1));
        else if(found2)
            printf("%d %d\n",l2-1,s-(l2-1));
    }
    return 0;
}
