#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int k;
    cin >> k;
    vector<pair<int, int>> nodes;
    int res = INT_MAX;
    for (int i = 0; i < k; i++)
    {
        string str;
        cin >> str;
        int midIndx;
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == ',')
            {
                midIndx = j;
            }
        }

        int m = stoi(str.substr(0, midIndx));
        int n = stoi(str.substr(midIndx + 1, str.size() - midIndx - 1));
        nodes.push_back({n, m});
        res = min(res, m + min(n, m));
    }
    int a;
    cin >> a;
    res = min(res, a);
    cout << res;
}