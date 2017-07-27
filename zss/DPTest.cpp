    //
//  DPTest.cpp
//  zss
//
//  Created by Shishen Zhang on 2017/1/11.
//  Copyright © 2017年 Shishen Zhang. All rights reserved.
//

#include <stdio.h>
#include "string"
#include "stdlib.h"
#include "thread"
#include "iostream"
#include "vector"
#include "unordered_map"
#include "queue"
#include "map"
#include "string"
#include "set"
#include "stack"
#include "unordered_set"
#include "list"

using namespace std;
struct trie{
    trie* next[26]={0};
    bool end=false;
    void add(const string& s){
        trie* cur = this;
        for(auto c:s){
            if(cur->next[c-'a']==NULL)
                cur->next[c-'a'] = new trie();
            cur = cur->next[c-'a'];
        }
        cur->end = true;
    }
    int find(const string& s){
        trie* cur = this;
        int res = 0;
        for(auto c:s){
            if(cur->next[c-'a']!=NULL){
                
                if(cur->end==true) return res;
                cur = cur->next[c-'a'];
                res++;
                
            }else{
                if(cur->end==true) return res;
                else
                return 0;
            }
        }
        return 0;
    }
};
class Solution {
public:
    string replaceWords(const vector<string>& dict, string sentence) {
        trie* root = new trie;
        for(auto& s:dict){
            root->add(s);
        }
        string res;
        vector<string> sen;
        string t;
        for(auto c:sentence){
            if(c!=' '){
                t+=c;
            }else{
                sen.push_back(t);
                t.clear();
            }
        }
        sen.push_back(t);
        for(auto s:sen){
            cout<<s<<' ';
        }
        for(auto& s:sen){
            int m = root->find(s);
            if(m!=0)
                res+=s.substr(0,m);
            else res+=s;
            res+=' ';
        }
        res.pop_back();
        return res;
    }
};
int main(){
    Solution s;
    vector<vector<int>> a = {{-10,-8},{8,9},{-5,0},{6,10},{-6,-4},{1,7},{9,10},{-4,7}};
    cout<<s.replaceWords({"a", "aa", "aaa", "aaaa"}, "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa");
}

