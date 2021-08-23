#include <string>
#include <iostream>
#include <map>
#include <algorithm> // sort, pair
#include <vector>

using namespace std;

int main(){
    string x;
    getline(cin, x);
    map<string,int> word2count;
    string temp = "";
    for(int i=0;i<x.size();i++){
        if(x[i]==' '){
            if(temp != ""){
                word2count[temp] ++;
                temp = "";
            }
        }else{
            temp += x[i];
        }
    }
    if(temp != ""){
        word2count[temp] ++;
        temp = "";
    }

    // 现在要来排序
    // map<string,int> word2count;
    vector<pair<int,string>> count2word;
    for(auto keyValue: word2count){
        count2word.push_back({keyValue.second, keyValue.first});
    }
    sort(count2word.begin(),count2word.end());
    reverse(count2word.begin(),count2word.end());
    for(auto keyValue: count2word){
        cout << keyValue.second << " " << keyValue.first << endl;
    }
}


// aa bb    ccc

// 0  temp = "a"
// 1  temp = "aa"
// 2  "aa" -> 1,temp = ""
// 3  temp = "b"
