/* Dijkstra's Algorithm
   Time Complexity : O(ElogN)
*/
#include "bits/stdc++.h"
using namespace std;
const int siz = 1e6 + 2;
const int inf = 1e9;
vector <pair<int,int> > graph[siz];

void dijkstra(int source,int n) {

        set <pair<int, int> > s;  // set to process edges
        vector <int> dist(n+1,inf); // store distance from source
        s.insert(make_pair(0,source));
        dist[source] = 0;

        while (!s.empty()) {

                pair <int, int> temp = *(s.begin());
                s.erase(s.begin());

                int u = temp.second;

                vector <pair<int,int> >::iterator it;

                for (it = graph[u].begin(); it != graph[u].end(); it++) {
                        int v = (*it).first;
                        int weight = (*it).second;

                        if (dist[v] > dist[u] + weight) {
                        	
                                if (dist[v] != inf)
                                        s.erase(s.find(make_pair(dist[v], v)));

                                dist[v] = dist[u] + weight;
                                s.insert(make_pair(dist[v], v));
                        }
                }
        }
        // final shortest distance from every other node
        for(int i = 1; i <= n; i++) {
                printf("Dist From %d To %d : %d\n",source,i,dist[i]);
        }
}

int main() {
        int t;
        scanf("%d", &t);
        while(t--) {
                int n, edges;
                scanf("%d%d", &n, &edges); // Input Number of Nodes and Edges
                while(edges--) {
                        int u, v, w;
                        scanf("%d%d%d", &u, &v, &w); // Input Edges
                        graph[u].push_back(make_pair(v,w));
                        graph[v].push_back(make_pair(u,w));
                }
                int source;
                scanf("%d", &source);
                dijkstra(source,n);
        }
}