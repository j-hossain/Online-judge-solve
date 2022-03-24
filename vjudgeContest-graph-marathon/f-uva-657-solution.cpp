#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
char grid[55][55];
vector<int> ans;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};

int valid(int i, int j)
{
    if (i < 0 or j < 0 or i >= n or j >= m)
        return 0;
    if (grid[i][j] == '.')
        return 0;
    return 1;
}

int dot(int i, int j)
{
    if (i < 0 or j < 0 or i >= n or j >= m)
        return 0;
    if (grid[i][j] == 'X')
        return 1;
    return 0;
}

void dfs(int i, int j)
{
    for (int k = 0; k < 4; k++)
    {
        if (dot(i + di[k], j + dj[k]))
        {
            grid[i + di[k]][j + dj[k]] = '*';
            dfs(i + di[k], j + dj[k]);
        }
    }
}

int bfs(int i, int j)
{
    int cnt = 0;
    int x, y;
    queue<pair<int, int>> qq;
    qq.push({i, j});
    if (grid[i][j] == 'X')
    {
        grid[i][j] = '*';
        dfs(i, j);
        cnt++;
    }
    grid[i][j] = '.';
    while (!qq.empty())
    {
        tie(x, y) = qq.front();
        qq.pop();

        for (int k = 0; k < 4; k++)
        {
            if (valid(x + di[k], y + dj[k]))
            {
                if (grid[x][y] == 'X')
                {
                    grid[x][y] = '*';
                    dfs(x, y);
                    cnt++;
                }
                grid[x][y] = '.';
                qq.push({x + di[k], y + dj[k]});
            }
        }
    }
    return cnt;
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
    inout();
    int tc = 1;
    while (cin >> m >> n)
    {
        if (!n and !m)
            break;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] != '.')
                {
                    ans.push_back(bfs(i, j));
                }
            }
        }
        sort(ans.begin(), ans.end());
        cout << "Throw " << tc << "\n";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
            if (i != ans.size() - 1)
            {
                cout << " ";
            }
        }
        cout << "\n\n";
        tc++;
        ans.clear();
    }
    return 0;
}