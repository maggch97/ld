#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

map<string, vector<string>> father2son;
// person
// fater2son["person"] person 的所有子概念，
map<string, vector<string>> class2instance;
// person
// class2instance["person"] person 对应的所有实例
vector<string> result;
set<string> s; // 已经遍历过的节点（概念）集合
void dfs(string x) // x 当前遍历到的节点对应的概念
{
    if(s.find(x)!=s.end()){
        return ;
    }
    s.insert(x);
    for (int i = 0; i < class2instance[x].size(); i++)
    {
        result.push_back(class2instance[x][i]);
    }
    for (int i = 0; i < father2son[x].size(); i++)
    {
        dfs(father2son[x][i]);
    }
}
int main()
{
    int n;
    cin >> n;
    string l, op, r;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> op >> r;
        if (op == "instanceOf")
        {
            class2instance[r].push_back(l);
        }
        else if (op == "subClassOf")
        {
            father2son[r].push_back(l);
        }
    }
    string target;
    cin >> target;
    dfs(target);
    sort(result.begin(), result.end());
    if (result.empty())
    {
        cout << "empty";
        return 0;
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}

/**

12
a subClassOf b
c subClassOf b
y subClassOf b
d subClassOf c
b subClassOf x
1 instanceOf a
2 instanceOf a
3 instanceOf b
4 instanceOf b
5 instanceOf c
6 instanceOf d
8 instanceOf x
b
*/