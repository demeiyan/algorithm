//
// Created by dell on 2019/1/19.
//

//
// Created by dell on 2018/12/22.
//
#include<bits/stdc++.h>
#include <bitset>
#include <string> 
#include <math.h>   
#include<map>
#include<algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    vector<int> arrays;
    vector<int> tmp;
    vector<vector<int> > res;
    void backtracking(int target, int idx){
        if(target == 0){
          cout<<idx<<" "<<target<<" "<<"\n";
          res.push_back(tmp);
          return;

        }
        if(idx>=arrays.size())return;
        int cnt = target/arrays[idx];
       
        for(int i=0;i<=cnt;i++){
           
            int t = i;
            while(t--){
                tmp.push_back(arrays[idx]);
            }
            backtracking(target - i*arrays[idx], idx+1);
            t = i;
            while(t--){
                tmp.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        res.clear();
        res.clear();
        arrays = candidates;
        tmp.clear();
        backtracking(target, 0);
        return res;
    }
};

int main(){
  // Solution solu;
  // vector<int> cand;
  // cand.push_back(2);
  // cand.push_back(3);
  // cand.push_back(6);
  // cand.push_back(7);
  // solu.combinationSum(cand, 7);
 std::string str ("Please, replace the vowels in this sentence by asterisks.");
  std::size_t found = str.find_first_of("aeiou");
    cout<<found; 



  return 0;
}
