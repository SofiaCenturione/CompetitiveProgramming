#include <bits/stdc++.h>
using namespace std; 
#define ll long long 

ll dp[3005][3005], a[3005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){ 
        for(int i=0;i<=n-k;i++){
            int j=i+k-1;
            if(i==j) dp[i][j] = a[i];
            else{
                dp[i][j]=max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]);
            }
        }
    }
    cout<<dp[0][n-1]<<"\n";
}