#include "vector"
#include "string"
#include "iostream"
using namespace std;
int memo[1000][1000];
int ma(int i,int j,int m[]){
    if(i==j) return 0;
    int ret = 0x7fffffff;
    if(memo[i][j]!=0) return memo[i][j];
    for(int c = i;c<j;c++){
        int a = ma(i,c,m)+ma(c+1,j,m)+m[i-1]*m[c]*m[j];
        if(ret > a)ret = a;
        
    }
    memo[i][j] = ret;
    return ret;
}
int matrix(int m[],int n){
    int ret = 0;
    ret = ma(1,n,m);
    return ret;
}

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    int myAtoi(string str) {
        int i=0;
        int sign = 0;
        int plus=0;
        int minus=0;
        while(str[i]>'9'||str[i]<'0'){
            if(str[i]==' ') ;else
                if(str[i]=='+') plus++;
                else if(str[i]=='-') minus++;
            i++;
        }
        if(minus==0) sign=1;
        else if(minus==plus) return 0;
        int length = str.length();
        int ret = 0;
        for(int i = 0;i<length;i++){
            if(str[i]<='9'&&str[i]>='0'){
                ret*=10;
                ret+=str[i]-'0';
            }else break;
        }
        return ret*sign;
    }
};
//int main(){
//    Solution s;
//    auto c = s.myAtoi("12");
//    cout<<c;
//    //cout<<matrix(m,3);
//    //uniquePathsWithObstacles(a);
//    //cout<<sa;
//}
