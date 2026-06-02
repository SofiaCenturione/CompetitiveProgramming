#include <bits/stdc++.h>
using namespace std;
#define ll long long

int pai[1005],tamanho[1005];
int find_set(int v){
    if(v==pai[v]) return v;
    return pai[v]=find_set(pai[v]);
}

bool union_set(int a, int b){
    a=find_set(a);
    b=find_set(b);

    if(a==b) return false;
    if(tamanho[a]<tamanho[b]) swap(a,b);
    pai[b]=a;
    tamanho[a]+=tamanho[b];
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;

    for(int k=1;k<=T;k++){
        int N,R,W;
        double U,V;
        cin>>N>>R>>W>>U>>V;
        vector<pair<int,int>> cid(N+1);

        for(int j=1;j<=N;j++){
            cin>>cid[j].first>>cid[j].second;
        }
        vector<vector<double>> aresta;

        for(int i=1;i<=N;i++){
            for(int j=i+1;j<=N;j++){
                double dx=cid[i].first-cid[j].first;
                double dy=cid[i].second-cid[j].second;
                double dist=sqrt(dx*dx+dy*dy);
                aresta.push_back({dist,(double)i,(double)j});
            }
        }
        sort(aresta.begin(), aresta.end());
        for(int i=1;i<=N;i++){
            pai[i]=i;
            tamanho[i]=1;
        }

        int usado=0;
        double utp=0.0,fibra=0.0;

        for(auto &e:aresta){
            double dist=e[0];
            int u=(int)e[1];
            int v=(int)e[2];
            if(union_set(u,v)){
                usado++;
                if(dist<=R){
                    utp+=dist*U;
                }
                else{
                    fibra+=dist*V;
                }
                if(usado==N-W) break;
            }
        }
        cout<<fixed<<setprecision(3);
        cout<<"Caso #"<<k<< ": "<<utp<<" "<<fibra<<"\n";
    }
}