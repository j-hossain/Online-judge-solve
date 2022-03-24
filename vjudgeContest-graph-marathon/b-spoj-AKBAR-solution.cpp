/*
    ▀ ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ ▀
    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
    ░░░░░░░░░█▀▀▄▄░░░░░░░░░░░░░░░░░░
    ░░░░░░░░░█░░░░▀▀▄░░░░░░░░░░░░░░░
    ░░░░░░░░░█░░░░░░░▀▄░░░░░░░░░░░░░
    ░░░░░░░░░█░░░░░░░░░█░░░░░░░░░░░░
    ░░░░░░░░░█░░░░░░░░░█░░░░░░░░░░░░
    ░░░░░░░░░█░░░░░░░▄▀░░░░░░░░░░░░░
    ░░░░░░░░░█░░░░▄▄▀░░░░░░░░░░░░░░░
    ░░░░░░░░░█▄▄▀▀░░░░JOKER░░░░░░░░░
    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
    ▄ ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ ▄
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MM (int)1e6 + 5

// for faster cin cout
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

// for file input output
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

int n, m, r;
int dis[MM], vis[MM];
vector<int> grph[MM];

bool bfs(int s, int k, int p)
{
    queue<int> qq;
    if (vis[s] < p)
    {
        return false;
    }
    vis[s] = p;
    dis[s] = 0;
    qq.push(s);
    bool flag = true;
    while (!qq.empty())
    {
        int u = qq.front();
        qq.pop();
        if (dis[u] == k)
        {
            break;
        }
        for (auto v : grph[u])
        {
            if (vis[v] < p)
            {
                flag = false;
                break;
            }
            if (vis[v] != p)
            {
                dis[v] = dis[u] + 1;
                vis[v] = p;
                qq.push(v);
            }
        }
        if (!flag)
            break;
    }
    while (!qq.empty())
        qq.pop();
    return flag;
}

void answer()
{
    int u, v, s, k;
    cin >> n >> r >> m;
    for (int i = 0; i < r; i++)
    {
        cin >> u >> v;
        grph[u].push_back(v);
        grph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 0;
        vis[i] = m + 1;
    }
    bool flag = true;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> k;
        if (flag)
        {
            flag = bfs(s, k, i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == m + 1)
            flag = false;
        grph[i].clear();
    }
    if (flag)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}

int main()
{
    // inout();
    fast();
    int t;
    cin >> t;
    while (t--)
    {
        answer();
    }
}