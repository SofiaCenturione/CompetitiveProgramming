#include <bits/stdc++.h>
using namespace std; 
#define ll long long 

int dp[1001][1001];
char grid[1001][1001]={0};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, MOD=1e9+7;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    if(grid[0][0]=='.'){
        dp[0][0] = 1;
    }
    for(int i=0;i<n;i++){ 
        for(int j=0;j<n;j++){
            if(grid[i][j]=='*'){
                dp[i][j]=0;
            }
            else if(grid[i][j]=='.'){
                if(i>0){
                    dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
                }
                if(j>0){
                    dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
                }
            }
        }
    }
    
    cout<<dp[n-1][n-1]<<"\n";
}