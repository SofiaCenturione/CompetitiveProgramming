#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    getline(cin,s1); getline(cin,s2);

    map<char,int> f;
    for(char c:s1){
        if(c!=' '){
            f[c]++;
        }
    }

    for(char c:s2){
        if(c!=' '){
            if(f[c]>0){
                f[c]--;
            }
            else{
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
}