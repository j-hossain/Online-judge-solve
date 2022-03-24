#include <iostream>
#include <queue>
using namespace std;

int dis[2005][2005], vis[2005][2005];

int d[] = {1, -1, 0, 0};

queue<pair<int, int>> qq;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, k, u, v, md = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        vis[u][v] = 1;
        dis[u][v] = 0;
        qq.push(make_pair(u, v));
    }
    while (not qq.empty())
    {
        int ui = qq.front().first;
        int uj = qq.front().second;
        qq.pop();
        for (int i = 0; i < 4; i++)
        {
            int ni = ui + d[i];
            int nj = uj + d[3 - i];
            if (0 <= ni and ni < n and 0 <= nj and nj < m)
            {
                if (not vis[ni][nj])
                {
                    qq.push(make_pair(ni, nj));
                    vis[ni][nj] = 1;
                    dis[ni][nj] = dis[ui][uj] + 1;
                    md = max(md, dis[ni][nj]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dis[i][j] == md)
            {
                cout << i + 1 << ' ' << j + 1 << "\n";
                goto end;
            }
        }
    }
end:
    return 0;
}