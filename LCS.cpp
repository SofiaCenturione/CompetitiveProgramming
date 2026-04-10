#include <bits/stdc++.h>
using namespace std; 
#define ll long long 

int dp[3001][3001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;

    for(int i=1;i<=s.size();i++){ 
        for(int j=1;j<=t.size();j++){
            if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string resp=" ";
    int a=s.size(), b=t.size();
    while(a>0 &&b>0){
        if(s[a-1]==t[b-1]){
            resp+=s[a-1];a--;b--;
        }
        else if(dp[a-1][b]>dp[a][b-1]) a--;
        else b--;
    }
    reverse(resp.begin(),resp.end());
    cout<<resp<<"\n";
}