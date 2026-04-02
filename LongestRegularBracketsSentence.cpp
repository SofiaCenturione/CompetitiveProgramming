#include <bits/stdc++.h>
using namespace std;  
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int t=s.length();
    vector<int> dp (t,0);//preenche td com 0
    int m=0, cont=1;
    for(int i=1;i<t;i++){
        if(s[i]==')'){
            if(s[i-1]=='(') dp[i]=(i>= 2 ? dp[i-2] : 0)+2;
            else{
                int j=i-dp[i-1]-1;
                if(j>=0 && s[j]=='('){
                    int anterior=(j>=1) ? dp[j-1] : 0;
                    dp[i]=dp[i-1]+2+anterior;
                }
            }
            if(dp[i]>m){
                m=dp[i];
                cont=1;
            } 
            else if(dp[i]>0 && dp[i]==m) cont++;
        }
    }
    if(m==0) cout<<"0 1\n";
    else cout<<m<<" "<<cont<<"\n"; 
}