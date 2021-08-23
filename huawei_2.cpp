#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<char,int> wordCount(string word) {
    map<char,int> tempCount;
    for(int i=0;i<word.size();i++){
        char c = word[i];
        tempCount[c] ++;
    }
    return tempCount;
}

int check(map<char,int> Count, string word){ 
    // 返回 word 是否能够通过 chars 组成, 能的话返回1，不能返回0
    // Count： chars 中每一个字母出现的次数
    map<char,int> wordC = wordCount(word);

    // catcat - > c , a, t
    set<char> uniqueChar;
    for(auto c:word){
        uniqueChar.insert(c);
    }

    for(auto c: uniqueChar){
        // c ： word 中出现的字符
        if(Count[c] < wordC[c]){
            return 0;
        }
    }
    return 1;
}

int main(){
    string chars = "atach";
    vector<string> words = {"cat","bt","hat","tree"};
    map<char,int> Count = wordCount(chars);
    int result = 0;
    for(auto word: words){
        if(check(Count, word)){
            cout << word << endl;
            result += word.size();
        }
    }
    cout << result;
}