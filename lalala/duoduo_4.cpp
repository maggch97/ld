// https://www.nowcoder.com/question/next?pid=30579184&qid=1712517&tid=47166791

#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<vector<int>, int> count;
    for (int i = 0; i < n; i++)
    {
        vector<int> x(6);
        for (int i = 0; i < 6; i++)
        {
            cin >> x[i];
        }
        vector<int> key = {min(x[0], x[1]), min(x[2], x[3]), min(x[4], x[5])};
        int s = 0;
        for(int i=0;i<6;i+=2){
            if(x[i]<x[i-1])
        }
        sort(key.begin(), key.end());
        count[key]++;
    }
    cout << count.size() << endl;
    vector<int> output;
    for (auto kv : count)
    {
        output.push_back(kv.second);
    }
    sort(output.begin(), output.end());
    reverse(output.begin(), output.end());
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
}