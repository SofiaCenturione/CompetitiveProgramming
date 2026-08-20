#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,u;
    char v;
    while(cin>>t){
        vector<int> d,e;
        for(int i=0;i<t;i++){
            cin>>u>>v;
            if(v=='E'){
                e.push_back(u);
            }
            else{
                d.push_back(u);
            }
        }
        sort(d.begin(), d.end());
        sort(e.begin(), e.end());
        int p1=0,p2=0;
        int cont=0;
        while(p1<d.size() &&p2<e.size()){
                if(d[p1]==e[p2]){
                    cont++;p1++;p2++;
                }
                else if(d[p1]>e[p2]){
                    p2++;
                }
                else p1++;
        }
        cout<<cont<<"\n";
    }
}