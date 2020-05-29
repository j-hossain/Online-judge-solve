#include <bits/stdc++.h>
using namespace std;
int at(int a)
{
    if(a<0)
        return 0;
    return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	int a, b, c, n, f[40001];
	cin >> n >> a >> b >> c;
	memset(f, -1, sizeof(f));
	f[0] = 0;
	f[a]=f[b]=f[c]=1;

	for (int i = c; i <= n; ++i)
	{
		int temp = max( f[at((i-a))], max(f[at(i-b)],f[at(i-c)]));
		if(temp == -1)
			f[i] = -1;
		else
			f[i] = temp + 1;
			cout<< f[i] <<" "<<temp<< endl;
	}
	cout << f[n] << "\n";
}
