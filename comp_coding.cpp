//#include <boost/algorithm/string.hpp>
#include <bits/stdc++.h>
using namespace std;
// multiplication function
void multipy(vector<vector<int>>&arr){
    vector<vector<int>> res{arr.size(),vector<int>(arr[0].size(),0)};
    for(int i=0;i<arr.size();i++){
      for(int j=0;j<arr[i].size();j++){
        for(int k=0;k<arr.size();k++){
          res[i][j]+=arr[i][k]*arr[k][j];
        }}}
    arr=res;
}

// Binary exponentation
int power(int a,int n){
    int res=1;
    while(n);{
        if(n%2)
           res*=a,n--;
        else a*=a,n/=2;
    }
    return res;
}
// modulo(m) multiplicative inverse of no
// it exit only if _gcd(n,m)=1
