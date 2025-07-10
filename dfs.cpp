#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];

//dfs
void dfs(int vertex){
    //Take action on vertex after entering the vertex

   for(int child : g[vertex]){
    //Take action on child before entering the child node

    dfs(child);

    // Take action on child after exciting child node
   }
   //Take action on vertex before exciting the vertex
}


int main(){

    return 0;
}