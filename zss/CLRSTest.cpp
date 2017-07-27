//
//  CLRSTest.cpp
//  zss
//
//  Created by Shishen Zhang on 2017/1/10.
//  Copyright © 2017年 Shishen Zhang. All rights reserved.
//

#include <stdio.h>
#include "iostream"
using namespace std;
#define N 15
struct Graph{
    int (*edge)[N];
    int data[N];
};
int ldst[N];
int front[N];
int LongestPath(struct Graph& G,int src,int dst){
    if(ldst[dst]!=0x10000000)
        return ldst[dst];
    if(src == dst) {
        ldst[dst] = 0;
        return 0;}
    int biggest = 0x80000000;
    int path = -1;
    for(int i = 0;i<N;i++){
        if(G.edge[i][dst]!=0){
            if(biggest<LongestPath(G,src,i)+G.edge[i][dst])
            biggest = LongestPath(G,src,i)+G.edge[i][dst];
            path = i;
            
        }
    }
    front[dst] = path;
    ldst[dst] = biggest;
    return biggest;
}
#define LEFT 1
#define UP 2
#define ARC 3
int lsize[N+1][N+1];
int path[N+1][N+1];
void palin(string s)
{
    for(int i = 0;i<N+1;i++){
        lsize[0][i] = 0;
        lsize[i][0] = 0;
    }
    int size = s.size();
    for(int i = 1;i<=size;i++){
        for(int j = 1;i<=size;j++)
        {
            if(s[i-1]==s[size-1-j+1])
            {
                if(i-1==size-1-j+1) {
                    break;
                }
                lsize[i][j] = lsize[i-1][j-1]+1;
                path[i][j] = ARC;
            }else{
                if(lsize[i-1][j]>lsize[i][j-1]){
                    lsize[i][j] = lsize[i-1][j];
                    path[i][j] = UP;
                }else{
                    lsize[i][j] = lsize[i][j-1];
                    path[i][j] = LEFT;
                }
            }
        }
    }
}
char* palindrome(char* s){
    int i = 0;
    while(s[i]!=0){
        
    }
    return s;
}
