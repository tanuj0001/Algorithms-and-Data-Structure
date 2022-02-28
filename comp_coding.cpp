//#include <boost/algorithm/string.hpp>
#include <bits/stdc++.h>
using namespace std;
// Longest Palindromic String


// LCM using Factorization method
void lcm(vector<int>Arr){
    map<int,int>fact;
    for(int i=0;i<Arr.size();i++){
        int j=2;
        while(j*j<=Arr[i]){
            if(Arr[i]%j==0){
                int power=0;
                while(Arr[i]%j==0){
                        power++;
                        Arr[i]/=j;
                    }
                if(power>0){
                    if(fact.find(j)==fact.end()){ fact[j]=power;}
                    else fact[j]=max(fact[j],power);
                }
            }
            j++;
        }
        if(Arr[i]>1){
            if(fact.find(Arr[i])==fact.end()) fact[Arr[i]]=1;
        }
    }
    map<int,int> ::iterator it;
    int ans=1;
    for(it=fact.begin();it!=fact.end();it++){
         ans=ans*pow(it->first,it->second);
         cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<ans;
}

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
