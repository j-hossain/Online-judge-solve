#include<stdio.h>
#include<math.h>
int is_even(int a)
{
	if(a%2==0)
	return 1;
	else
	return 0;
}
int is_squar(long long int a)
{
	long long int i;
	i=sqrt((double)a);
	if(i*i==a)
	return 1;
	else
	return 0;
}
int is_prime(long long int a)
{
	long long int i;
	if(a==2 || a==3)
	return 1;
	else
	{
		for(i=2;i<=sqrt(a);i++)
		{
		if(a%i==0)
		break;
		}
		if(i>sqrt(a))
		return 1;
		else
		return 0;
		
	}
}
void print(char x)
{
	if(x=='y')
	printf("YES\n");
	else
	printf("NO\n");
}
int main()
{
	int n,i;
	scanf("%d",&n);	
	long long int num;
	char ans[n];

	for(i=0;i<n;i++)
	{
		scanf("%lld",&num);
		ans[i]='n';
		if(num>4)
		{
		if(!is_even(num))
		{
			long long int sq=sqrt(num);
			if(is_squar(num))
			{
				if(is_prime(sq))
				ans[i]='y';
			}
		}
		}
		else if(num==4)
		ans[i]='y';
	}
	for(i=0;i<n;i++)
	print(ans[i]);
	return 0;
}








    