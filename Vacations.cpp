#include <bits/stdc++.h>
using namespace std; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<vector<int>> dp(n + 1, vector<int>(3, -1e9));
    dp[0][0]=0;

    for(int i=1;i<=n;i++){
        dp[i][0]=max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        if(a[i-1]==1||a[i-1]==3) 
            dp[i][1]=max(dp[i-1][0], dp[i-1][2])+1;
        if(a[i-1]==2||a[i-1]==3) 
            dp[i][2]=max(dp[i-1][0], dp[i-1][1])+1;

        
    }
    int maxi=max({dp[n][0], dp[n][1], dp[n][2]});
    cout<<n-maxi<<"\n";
}