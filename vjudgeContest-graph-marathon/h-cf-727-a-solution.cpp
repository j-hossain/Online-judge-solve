#include <iostream>
#include <vector>
using namespace std;

// for faster cin cout
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

bool flag;
vector<int> ans;

void getAns(int a, int b)
{
    if (b == a)
    {
        ans.push_back(a);
        return;
    }
    if (b % 2 == 0)
    {
        ans.push_back(b / 2);
        getAns(a, b / 2);
        return;
    }
    else if (b % 10 == 1)
    {
        ans.push_back((b - 1) / 10);
        getAns(a, (b - 1) / 10);
        return;
    }
    else
    {
        flag = false;
        return;
    }
}
// for file input output
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

int main()
{
    fast();
    inout();
    int a, b;
    cin >> a >> b;
    flag = true;
    ans.push_back(b);
    while (b > a)
    {
        if (b % 2 == 0)
        {
            ans.push_back(b / 2);
            b /= 2;
        }
        else if (b % 10 == 1)
        {
            ans.push_back((b - 1) / 10);
            b = (b - 1) / 10;
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (flag and a == b)
    {
        cout << "YES\n";
        cout << ans.size() << "\n";
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "NO\n";
    }
}