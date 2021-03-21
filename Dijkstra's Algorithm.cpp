#include <iostream>
#include <vector>
#include <queue>
#define max 1000
using namespace std;
int size=0;
int *processed;
int *dist;
int *prev;
// this will given the weight of the edge 
int w(vector<vector<int> > &cost , int u, int pos){
    for(auto ct = cost[u].begin() ; ct!=cost[u].end();++ct){
        pos=pos-1;
        if(pos == 0){
            return *ct;
        }
    }
    //return max;
}
int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t, int prev[], int dist[]) {
  //write your code her
  dist[s]=0;
  priority_queue<int , vector<int>, greater<int> > PQ;
  PQ.push(dist[s]);
  //processed[0]= 1;
  while(!PQ.empty()){
        int u = PQ.top();
        //cout<<u;
        PQ.pop();
        int num=0;
        int l=-1, count=0;
        for(int i=0;i<size;i++){
            if(!processed[i]){
                if(u==dist[i]){
                    l=i;
                    count=1;
                    processed[i]=1;
                    break;
                }
            }
        }
        if(count!=0){
            for(auto it = adj[l].begin() ; it!=adj[l].end(); ++it){
                num=num+1;  // here num is used to store the location of edge to get it's weight.
                //cout<<"start of "<<l<<endl;
                //cout<<*it<<endl;
                if(dist[*it]>u+w(cost, l ,num)){
                    dist[*it]=u+w(cost, l ,num);
                    prev[*it] = l;
                   //cout<<"dist["<<*it<<"] "<<dist[*it]<<endl;
                    PQ.push(dist[*it]);
                }
            }
        }
  }
  return dist[t];
}

int main() {
  int n, m;
  cin >> n >> m;
  size = n;
  int *dist = new int[n];
  int *prev = new int[n];
  processed  = new int[n]; 
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x].push_back(y);
    cost[x].push_back(w);
  }

  int a=1;
  while(a){
      int s, t;
      std::cin >> s >> t;
        for(size_t i=0;i<size;i++){
      	dist[i] = max;
      	prev[i]= -1;
      	processed[i]=0;
        }
        cout<<distance(adj, cost, s, t, prev, dist)<<endl;
        cout<<"a : ? ";
        cin>>a;
        } 
}






