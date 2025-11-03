#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];


bool visited[N];
int level[N];


void bfs(int source){
    queue<int> q;
    q.push(source);
    visited[source]=true;

    while(!q.empty()){
        int cur_v=q.front();
        q.pop();
        cout<<cur_v<<endl;
        for(int child : g[cur_v]){
            if(!visited[child]){
                q.push(child);
                visited[child]=true;
                level[child]=level[cur_v]+1;
            }
        }



    }
}


int main(){
    int n;
    cin>>n;
    
    for(int i=1; i<=n; i++){
        int v1, v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    bfs(1);

    return 0;
}