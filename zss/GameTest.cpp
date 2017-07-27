//
//  GameTest.cpp
//  zss
//
//  Created by Shishen Zhang on 2017/4/27.
//  Copyright © 2017年 Shishen Zhang. All rights reserved.
//

#include <stdio.h>
#include "vector"
#include "map"
#include "iostream"
#define LEFT(r) std::pair<int,int>((-r.second),(r.first))
#define RIGHT(r) std::pair<int,int>((r.second),(-r.first))
std::vector<std::vector<std::pair<int,int>>> dirMap;
void calcRoute(std::pair<int,int> start,std::pair<int,int> dir,int lr,std::vector<std::vector<int>>& map){
    
    while(1){
        std::pair<int,int> turn;
        if(lr==0)
            turn = LEFT(dir);
        else turn = RIGHT(dir);
        if(map[start.first+turn.first][start.second+turn.second]==-1||map[start.first+turn.first][start.second+turn.second]==-4){
            dir = turn;
        }
        if(map[start.first+dir.first][start.second+dir.second]==-2){
            dir.first=-turn.first;dir.second=-turn.second;
        }
        if(map[start.first+dir.first][start.second+dir.second]==-4){
            dirMap[start.first][start.second]=dir;
            return;
        }
        dirMap[start.first][start.second]=dir;
        start.first+=dir.first;
        start.second+=dir.second;
    }
}
void calcDir(const std::vector<std::pair<int,int>>& cur,std::vector<std::vector<int>> &map){
    int width = static_cast<int>(map.size());
    int height = static_cast<int>(map[0].size());
    std::pair<int,int> dir;
    if(cur[0].first>0){
        if(map[cur[0].first-1][cur[0].second]==-1)
            dir = {-1,0};
    }
    if(cur[0].first<width-1){
        if(map[cur[0].first+1][cur[0].second]==-1)
            dir = {1,0};
    }
    if(cur[0].second>0){
        if(map[cur[0].first][cur[0].second-1]==-1)
            dir = {0,-1};
    }
    if(cur[0].second<height-1){
        if(map[cur[0].first][cur[0].second+1]==-1)
            dir = {0,1};
    }
    calcRoute(cur[0], dir, 0,map);
    calcRoute(cur[1], dir, 1,map);
}
#include<functional>// std::function

class A
{
public:
    int i_ = 0; // C++11允许非静态（non-static）数据成员在其声明处（在其所属类内部）进行初始化
    
    void output(int x, int y)
    {
        std::cout << x << "" << y << std::endl;
    }
    
};

//int main()
//{
//    A a;
//    // 绑定成员函数，保存为仿函数
//    std::function<void(int, int)> fr = std::bind(&A::output, &a, std::placeholders::_1, std::placeholders::_2);
//    // 调用成员函数
//    fr(1, 2);
//    
//    // 绑定成员变量
//    std::function<int&(void)> fr2 = std::bind(&A::i_, &a);
//    fr2() = 100;// 对成员变量进行赋值
//    std::cout << a.i_ << std::endl;
//    
//    
//    return 0;
//}
