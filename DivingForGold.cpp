#include <bits/stdc++.h>
using namespace std; 


struct treasure {
    int d, g;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, w, n;
    bool first=true;

    while(cin>>t>>w){
        cin >>n;
        vector<int> depth(n), gold(n);
        for(int i=0; i<n; i++){
            cin>>depth[i]>>gold[i];
        }
        vector<vector<int>> dp(n+1, vector<int> (t+1, 0));
        dp[0][0]=0;
        for(int i=1; i<=n; i++){
            int custo=3*w*depth[i-1];
            for(int j=0; j<=t; j++){
                if(custo<=j) dp[i][j]=max(dp[i-1][j], gold[i-1]+dp[i-1][j-custo]);
                else dp[i][j]=dp[i-1][j];
            }
        }
        vector<treasure> escolhe;
        int tempo=t;
        for(int i=n; i>0; i--){
            int custo=3*w*depth[i-1];
            if(tempo>=custo && dp[i][tempo] != dp[i-1][tempo]) {
                escolhe.push_back({depth[i-1], gold[i-1]});
                tempo-=custo;
            }
        }

        if(!first) cout<<"\n";
        first=false;

        cout<<dp[n][t]<<"\n";
        cout<<escolhe.size()<<"\n";
        for(int i=escolhe.size()-1; i>=0; i--) 
            cout<<escolhe[i].d<<" "<<escolhe[i].g<<"\n";
    }
}