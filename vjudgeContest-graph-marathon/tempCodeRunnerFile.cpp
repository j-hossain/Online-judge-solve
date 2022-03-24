if (grid[x][y] == 'X')
                {
                    grid[x][y] = '*';
                    dfs(x, y);
                    cnt++;
                }
                grid[x][y] = '.';