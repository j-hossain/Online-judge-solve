#include<stdio.h>
#include<string.h>
int main()
{
	char a[101],b,c[101];
	int i,j;
	scanf("%s",a);
	int st=strlen(a);
	for(i=0;i<st/2+2;i++)
	c[i]=a[i*2];
	st=strlen(c);
	for(i=0;i<st-1;i++)
	{
		for(j=i+1;j<st;j++)
		{
			if(c[i]>=c[j])
			{
				
				b=c[i];
				c[i]=c[j];
				c[j]=b;
			}
		}
	}
	for(i=0;i<st;i++)
	{
		a[i*2]=c[i];
	}
	printf("%s",a);
	return 0;
}