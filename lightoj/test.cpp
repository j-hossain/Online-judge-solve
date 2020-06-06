#include<cstdio>
#include<iostream>
#include<vector>
#define MAX 32000 // sqrt(1000000000)
#define ll long long //using ll = long long;
using namespace std;

bool isPrime[MAX]; //all values = false
vector <int> prime;
int i, j;

void sieve()
{
    //bool isPrime[MAX];
    for(i = 0; i < MAX; i++) isPrime[i] = false;

    for(i = 3; i * i <= MAX; i += 2)
    {
        if(!isPrime[i])
        {
            for(j = i * i; j <=MAX-1; j += i) isPrime[j] = true;
        }
    }

    prime.push_back(2);
    for(i = 3; i < MAX ; i += 2)
    {
        if(!isPrime[i]) prime.push_back(i);
    }
}

void segSieve(int l, int r)
{
    //bool isPrime[r-l+1];
    for(i = 0; i < r-l+1; i++) isPrime[i] = true;
    if(l == 1) isPrime[0] = false;

    for(i = 0; prime[i] * prime[i] <= r; i++)
    {
        int cp = prime[i]; //cp = CurrentPrime
        int base = (l / cp) * cp;
        if(base < l) base += cp;

        for(j = base; j <= r; j +=cp) isPrime[j-l] = false; //***
        if (base == cp) isPrime[base-l] = true;
    }

    for(i = 0; i < r-l+1; i++)
    {
        if (isPrime[i]) printf("%d\n", i + l);
    }
}

int main()
{
    sieve();

    int t, l, r;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &l, &r);
        segSieve(l, r);
    }

    return 0;
}
