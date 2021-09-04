#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> mt; // m*n 的输入
vector<vector<int>> flag;

void dfs(int i, int j)
{
    if (i < 0 || j < 0 || i >= mt.size() || j >= mt[i].size())
    {
        return;
    }
    if (flag[i][j] || mt[i][j] != 0)
    {
        return;
    }
    flag[i][j] = true;

    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
}

int main()
{
    int m, n;
    cin >> m >> n;
    mt = vector<vector<int>>(m, vector<int>(n));
    flag = vector<vector<int>>(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mt[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!(flag[i][j]) && mt[i][j] == 0)
            {
                count++;
                dfs(i, j);
            }
        }
    }
    if (count <= 1)
    {
        cout << 0;
    }
    else
    {
        // 多试几次
        cout << 1;
    }
    return 0;
}