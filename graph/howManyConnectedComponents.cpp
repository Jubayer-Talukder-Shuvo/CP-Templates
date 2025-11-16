#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> cc;   //for storing connected components
vector<int> current_cc; // for storing connected components

const int N = 1e5 + 10;
vector<int> g[N];
bool visited[N];

//dfs
void dfs(int vertex){
    //Take action on vertex after entering the vertex
    visited[vertex]=true; 
    current_cc.push_back(vertex);

    for(int child : g[vertex]){
        if(visited[child]) continue;
        //Take action on child before entering the child node

        dfs(child);

        // Take action on child after exciting child node
   }
   //Take action on vertex before exciting the vertex
}


int main(){
    int n, m;
    cin>>n>>m;

    for(int i=1; i<=m; i++){
        int v1, v2;
        cin>>v1>>v2;

        g[v1].push_back(v2);
        g[v2].push_back(v1);

    }

    int count=0;

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            count++;
            current_cc.clear();
            dfs(i);
            cc.push_back(current_cc);


        }
    }

    for(auto &i:cc){    //for showing connected components
        for(auto &j:i) cout<<j<<' ';
        cout<<endl;
    }


    cout<<count<<endl;

    return 0;
}