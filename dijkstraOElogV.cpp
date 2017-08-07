#include<bits/stdc++.h> 

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;
void addEdge(vector <pair<int, int> >adj[], int u,int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
} 

void printGraph(vector<pair<int,int> >adj[], int V)
{
    cout << endl;
    int v, w;
    for (int u = 0; u < V; u++)
    {
        cout << "Node " << u << " makes an edge with \n";
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}

void dijkstra(vector<pair<int,int>> adj[],int V,int src)
{
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
 
     vector<int> dist(V,INT_MAX);
     vector<bool> visited(V,false);

 
     pq.push(mp(0,src));
     dist[src]=0;

     while(!pq.empty())
     {
      int u=pq.top().second;
      pq.pop();

      if(visited[u])
            continue;
      visited[u]=true;
        
      
      for (auto i = adj[u].begin(); i!=adj[u].end(); i++)
      {
        int v=(*i).first;
        int weight=(*i).second;

        if(dist[v]>dist[u]+weight)
        {
          dist[v]=dist[u]+weight;
          pq.push(mp(dist[v],v));
        }
      }
     }
     cout << "Vertex   Distance from Source\n";
     
     for(int i=0;i<V;i++)
      printf("%d \t\t %d\n",i,dist[i]);

}
 
 
int main()
{

  int v=9;

  vector<pair<int,int>> adj[v];

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);
    
  //  printGraph(adj,v);    
 dijkstra(adj,v,0);//0 is source vertex
 
    return 0;
}