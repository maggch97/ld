#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define dbg(x) cout << (#x) << " = " << (x) << endl
map<char, int> count(string chars)
{
    map<char, int> result;
    for (int i = 0; i < chars.size(); i++)
    {
        char temp = chars[i];
        result[temp]++;
    }
    return result;
}

int main()
{
    vector<string> words = {"cat", "bt", "hat", "tree"};
    string chars = "atach";
    int total = 0;
    map<char, int> input = count(chars);
    for(int i=0; i< words.size();i++)
    {
        map<char,int> num = count(words[i]);
        bool flag=true;
        for(int j=0; j<words[i].size(); j++)
        {
            char c = words[i][j];
            if (num[c]>input[c])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            total += words[i].size();
        }
    }
    cout<<total<<endl;
    return 0;
}