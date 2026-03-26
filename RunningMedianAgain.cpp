#include <bits/stdc++.h>
using namespace std;  

void balanceia(priority_queue<int>& max, priority_queue<int, vector<int>, greater<int>>& min){
    if(max.size()>min.size()+1){
        min.push(max.top());
        max.pop();
    } 
    else if(min.size()>max.size()){
        max.push(min.top());
        min.pop();
    }
}

void resolve(){
    int n;
    priority_queue<int> max; //max-heap para a metade da esquerda
    priority_queue<int, vector<int>, greater<int>> min;//min-heap para a metade da direita

    while(cin>>n&&n!=0){
        if(n==-1){
            //a mediana sempre estará no topo do maxheap
            if(!max.empty()){
                cout<<max.top()<<"\n";
                max.pop();
                balanceia(max, min);
            }
        } 
        else {
            //inserindo no lugar certo
            if(max.empty()||n<=max.top()) 
                max.push(n);
            else
                min.push(n);
            balanceia(max, min);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        resolve();
    }
}
