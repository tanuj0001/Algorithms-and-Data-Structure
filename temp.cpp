#include <bits/stdc++.h>
using namespace std;
vector<int> LPS(string s){
    int n = s.length();
    vector<int>lps(n);
    lps[0] = 0;
    int i = 1, len = 0;
    while(i<n){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len == 0){
                lps[i] = 0;
                i++;
            }
            else
                len = lps[len-1];
        }
    }
    return lps;
}
int main()
{ //  vector<string>A{"a", "ababa", "aba"};
    vector<int>res=LPS("aaaabaaa#aaabaaaa");
    for(auto i :res)
      cout<<i<<" ";
    return 0;
}
// int lcm(vector<int>Arr){
//     map<int,int>fact;
//     for(int i=0;i<Arr.size();i++){
//         int j=2;
//         while(j*j<=Arr[i]){
//             if(Arr[i]%j==0){
//                 int power=0;
//                 while(Arr[i]%j==0){
//                         power++;
//                         Arr[i]/=j;
//                     }
//                 if(power>0){
//                     if(fact.find(j)==fact.end()){ fact[j]=power;}
//                     else fact[j]=max(fact[j],power);
//                 }
//             }
//             j++;
//         }
//         if(Arr[i]>1){
//             if(fact.find(Arr[i])==fact.end()) fact[Arr[i]]=1;
//         }
//     }
//     map<int,int> ::iterator it;
//     int ans=1;
//     for(it=fact.begin();it!=fact.end();it++){
//          ans=ans*pow(it->first,it->second);
//     }
//     return ans;
// }
// int LPS(string s){
//     int n=s.length();
//     vector<int>lps(n,0);
//     int j=0;
//     for(int i=1;i<=n;i++){
//         while(j>0 && s[j]!=s[i])
//                 j=lps[j-1];
//         if(s[j]==s[i]){
//             j++; }
//         lps[i]=j;
//     }    
//     return lps[n-1];
// }
// int LPS(string s){
//     int n = s.length();
//     int lps[n];
//     lps[0] = 0;
//     int i = 1, len = 0;
//     while(i<n){
//         if(s[i] == s[len]){
//             len++;
//             lps[i] = len;
//             i++;
//         }
//         else{
//             if(len == 0){
//                 lps[i] = 0;
//                 i++;
//             }
//             else
//                 len = lps[len-1];
//         }
//     }
//     return lps[n-1];
// }
// int recurr(string s){
//     int maxi=LPS(s);
//     int n=s.length();
//     int t=n-maxi;
//     if(n%t)
//         return n;
//     else t;
// }
// int time(string s){
//     int freq=recurr(s);
//     for(int i=1;;i++){
//         int rot=i*(i+1)/2;
//         if(rot%freq==0)
//            return i;
//     }
// }
// int main()
// {   vector<string>A{"a", "ababa", "aba"};
//     vector<int>temp;
//     for(int i=0;i<A.size();i++){
//         temp.push_back(time(A[i]));
//     }
//     cout<<lcm(temp);
//     return 0;
// }
/*int main(){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;cin>>k;
    int ans=-1;
    int low=*max_element(arr.begin(),arr.end());int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
      int mid=(low+high)/2;
      int temp=0;
      int sum=0;
      for(int i=0;i<n;i++){
          sum+=arr[i];
          if(sum>mid){
            sum=0;
            temp++;
            sum+=arr[i];
          }
      }
      if(sum!=0)
        temp++;
      if(temp<=k){
        ans=mid;
        high=mid-1;
      }
      else
        low=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}*/

