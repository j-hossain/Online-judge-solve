#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// accepted

string strt, endd;
int n;
map<string, int> mp;

typedef struct
{
    int a;
    int b;
    int c;
} con;

string getStr(string a, int pos, int type)
{
    string x = a;
    if (x[pos] + type < 'a')
    {
        x[pos] = 'z';
    }
    else if (x[pos] + type > 'z')
    {
        x[pos] = 'a';
    }
    else
    {
        x[pos] = x[pos] + type;
    }
    return x;
}
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

// for faster cin cout
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int main()
{
    fast();
    inout();
    string a, b, c, temp;
    con cn;
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cin >> strt;
        cin >> endd;

        cin >> n;
        temp.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b >> c;
            for (int x = 0; x < a.size(); x++)
            {
                for (int y = 0; y < b.size(); y++)
                {
                    for (int z = 0; z < c.size(); z++)
                    {
                        temp.push_back(a[x]);
                        temp.push_back(b[y]);
                        temp.push_back(c[z]);
                        mp[temp] = -1;
                        temp.clear();
                    }
                }
            }
        }
        cout << "Case " << tc << ": ";
        if (mp[strt] == -1 or mp[endd] == -1)
        {
            cout << "-1\n";
            mp.clear();
            continue;
        }
        queue<string> qq;
        qq.push(strt);
        mp[strt] = 1;
        while (!qq.empty())
        {
            temp = qq.front();
            qq.pop();
            for (int i = 0; i < 3; i++)
            {
                a = getStr(temp, i, -1);
                b = getStr(temp, i, 1);
                if (!mp[a])
                {
                    qq.push(a);
                    mp[a] = mp[temp] + 1;
                }

                if (!mp[b])
                {
                    qq.push(b);
                    mp[b] = mp[temp] + 1;
                }
            }
            if (mp[endd])
                break;
        }
        if (mp[endd] > 0)
        {
            cout << mp[endd] - 1 << "\n";
        }
        else
        {
            cout << "-1\n";
        }
        mp.clear();
        while (!qq.empty())
        {
            qq.pop();
        }
    }
    return 0;
}