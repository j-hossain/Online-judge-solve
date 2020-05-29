#include<stdio.h>
int main()
{
	int n,a[]={0,0,0,0},i,j,x[100001],f=0;
	int c[]={0,0,0,0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
	for(i=0;i<n;i++)
	{
		if(x[i]==1)
		{
			a[0]+=1;
		}
		else if(x[i]==2)
		{
			a[1]+=1;
		}
		else if(x[i]==3)
		{
			a[2]+=1;
		}
		else if(x[i]==4)
		{
			a[3]+=1;
		}
	}
	c[3]=a[3];
	c[2]=a[2];
	if(a[0]>0 && c[2]!=0)
	{
		a[0]-=c[2];
		if(a[0]<0)
		a[0]=0;
	}
	if(a[1]%2==0)
	c[1]=a[1]/2;
	else
	{
		c[1]=a[1]/2+1;
		if(a[0]>0 && c[1]!=0)
	{
		a[0]-=2;
		if(a[0]<0)
		a[0]=0;
	}
	}
	if(a[0]>0)
	{
		if(a[0]<=4)
		c[0]=1;
		else{
          c[0]=a[0]/4;
          if(a[0]%4!=0)
                c[0]++;
		}

	}
	for(i=0;i<4;i++)
	f=f+c[i];

	printf("%d\n",f);
}
