//
//  GraphicsTest.cpp
//  zss
//
//  Created by Shishen Zhang on 2017/4/12.
//  Copyright © 2017年 Shishen Zhang. All rights reserved.
//

#include <stdio.h>
#include "iostream"
class vector2{
public:
    double x;
    double y;
    vector2(double x1,double y1):x(x1),y(y1){}
    vector2(){};
    bool operator==(const vector2& v){
        return v.x==x&&v.y==y;
    }
    
    vector2 operator-(){
        vector2 vr;
        vr.x= -x;
        vr.y= -y;
        return vr;
    }
    bool sameDir(const vector2& v){
        vector2 zero(0,0);
        if(x==0.0&&y==0.0) return true;
        if(v.x==0.0&&v.y==0.0) return true;
        double a = v.y/v.x;
        double b = y/x;
        if(a==b||a==-b) return true;
        return false;
    }
    vector2 operator-(const vector2& v){
        vector2 vr;
        vr.x= x-v.x;
        vr.y= y-v.y;
        return vr;
    }
};
inline double det(double v[2][2]){
    return v[0][0]*v[1][1]-v[0][1]*v[1][0];
}
bool intersect(vector2 a0,vector2 a1,vector2 b0,vector2 b1){
    vector2 dir1 = a1-a0;
    vector2 dir2 = b1-b0;
    if(dir1.sameDir(dir2)||dir1.sameDir(-dir2)){
        auto p1 = b0-a0;
        auto p2=b0-a1;
        if(p1.sameDir(p2)){
            if(a0.x<a1.x){
                auto temp = a0.x;
                a0.x=a1.x;
                a1.x=temp;
            }
            if(b0.x<=a0.x&&b0.x>=a1.x) return true;
            if(b1.x<=a0.x&&b1.x>=a1.x) return true;
            return false;
        }
        return false;
    }
    double v[2][2]={{dir1.x,-dir2.x},{dir1.y,-dir2.y}};
    double va[2][2];
    double m[2]={b0.x-a0.x,b0.y-a0.y};
    va[0][0]=m[0],va[1][0]=m[1];
    va[0][1]=v[0][1];
    va[1][1]=v[1][1];
    double t1 = det(va)/det(v);
    double val = t1*dir1.x+a0.x;
    if(val<=a0.x&&val>=a1.x) return true;
    if(val>=a0.x&&val<=a1.x) return true;
    return false;
}
//int main(){
//    vector2 c1(1,1),c2(1,3),b1(1,4),b2(1,6);
//    std::cout<<intersect(c1,c2,b1,b2);
//    return 0;
//}
