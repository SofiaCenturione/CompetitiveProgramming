#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int cont=0;
    getline(cin,s);
    for(int i=0; i<s.length();i++){
        if(isalnum(s[i])){
            if(!isalnum(s[i-1])||i==0)
                cont++;
        }
    }
    cout<<cont<<"\n";
}