/* Knuth Morris-Patt Algorithm
Kmp algorithm depends upon prefix function for its implementation
LPS[i]=P(i)=length of longest proper prefix of substring(0,i) which is also a suffix

LPS ALGORITHM
1)We compute the prefix values lps[i] in a loop by iterating from i=1 to n-1(lps[0] just gets assigned with 0)
2) To calculate the current value lps[i] we set the variable j denoting the length of the best suffix for i-1. Intially j=lps[i-1])
3) Test if the suffix of length j+1 is also prefix by comparing s[j] and s[i]. If they are equal then we assign lps[i]=j+1 and do j++ ,otherwise we reduce j =lps[j-1] and repeat this step
4) If e have reached the length j=0 and still don't have a matcch ,then we assign lps[i]=0 and go to the next index i+1
*/


#include <bits/stdc++.h>
using namespace std;
vector<int>LPS(string s){
    int n=s.length();
    vector<int>lps(n,0);
    int j=0;
    for(int i=1;i<=n;i++){
        while(j>0 && s[j]!=s[i])
                j=lps[j-1];
        if(s[j]==s[i]){
            j++; }
        lps[i]=j;
    }    
    return lps;
}
/* Text : codencode
   Pattern : cod
   searchstring=Pattern+"#"+Text
   
   c o d # c o d e n c o d e
   0 0 0 0 1 2 3 0 0 1 2 3 0
*/

int main(){
    string s,pattern;
    cin>>s>>pattern;
    string input=pattern+"#"+s;
    vector<int>temp=LPS(input);
    // for(int i:temp)
    //    cout<<i<<" ";
    // cout<<endl<<temp.size();
    for(int i=0;i<temp.size();i++){
        if(temp[i]==pattern.length())
          cout<<i+1-pattern.length()-1-pattern.length()<<" ";
    }
    return 0;
}
