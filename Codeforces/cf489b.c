#include<stdio.h>
#include<math.h>
void sorted(int* a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				a[i]=a[i]+a[j];
				a[j]=a[i]-a[j];
				a[i]=a[i]-a[j];
				
			}
		}
	}
}

int main()
{
	int n,a[101],m,b[101],i,j,c=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	sorted(a,n);
	scanf("%d",&m);
	for(i=0;i<m;i++)
	scanf("%d",&b[i]);
	sorted(b,m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(b[j]!=0 && abs(a[i]-b[j])==1 || a[i]==b[j] )
			{
				c++;
				b[j]=0;
				a[i]=0;
				break;
			}
		}
	}	
		printf("%d\n",c);
}
