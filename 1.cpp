#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

void func(char *b){
      for(int i=0;b[i]!=0;i++){
            cout << int(b[i]) << endl;
      }
}

int main(){
      // // key ,value

      // pair<string,int> y;
      // vector<pair<string,int>> xa;
      // xa.push_back({"张三",1});
      // xa.push_back({"李四",3});
      // xa.push_back({"王五",4});
      // // O(xa.size())
      // for(int i=0;i<xa.size();i++){
      //       if(xa[i].first == "王五"){
      //             cout << xa[i].second;
      //       }
      // }

      // // 二叉搜索树
      // map<string,int> x;
      // x["张三"] =1;
      // x["李四"] =3;
      // x["王五"] = 4;
      // x["张三"] =2; // 覆盖掉1
      // // x["张三"] 时间复杂度是 O(log(x.size()))
      // cout << x["张三"];

      // // 二叉搜索树
      // cout <<endl<< "set" << endl;
      // set<string> s;
      // s.insert("张三"); 
      // s.insert("李四");
      // s.insert("张三");
      // // s.size() == 2;
      // for(auto x:s){
      //       cout << x << endl;
      // }

      // char a[10] = "abc";

      // char *b = "abc"; // 4*sizeof(char)
      // func(b);
      vector<int> x = {1,4,2,3};
      sort(x.begin(),x.end());
      for(int value: x){
            cout << value <<endl;
      }
}