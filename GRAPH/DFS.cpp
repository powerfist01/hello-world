/*
Depth First Search
*/
#include <bits/stdc++.h>
using namespace std;
const int siz=1e6+2;
vector <int> graph [siz];
bool visited[siz];

void DFS(int source){ 
    stack <int> s;
    s.push(source);
    visited[source]=true;
    while(!s.empty()){
        int temp=s.top();
        s.pop();
        cout<<temp<<endl;
        for(int i=0;i<graph[temp].size();i++){
            if(visited[graph[temp][i]]==false){
                visited[graph[temp][i]]=true;
                s.push(graph[temp][i]);
            }
        }   
    }
}//end of function...

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,edges;
        memset(visited,false,sizeof visited);
        scanf("%d%d",&n,&edges);
        while(edges--){
            int u,v;
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int source;
        scanf("%d",&source);
        DFS(source);
    }
    return 0;
}
