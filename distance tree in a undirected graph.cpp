#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue <int> Q;
int *dist;
int size;
int BFS(vector<vector<int> > &adj, int s, int t){
    for(size_t  i=0;i<size;i++){
	dist[i] = size+2;
    }
	dist[s] = 0;
	Q.push(s);
	int u = 0;
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		for(auto it = adj[u].begin(); it!= adj[u].end(); ++it){
	        if(dist[*it] == 7){
	            int i = *it;
	        	Q.push(i);
	        	dist[*it]=dist[u]+1;
	        	if(*it == t)
	        	    return dist[*it];
	        }
	    }
    }
    return -1;
}
int distance(vector<vector<int> > &adj, int s, int t) {
    int res = BFS(adj, s ,t);
    return res;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  size = n;
  dist = new int[n];
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  int a = 1;
  while(a){
      int s, t;
      cin >> s >> t;
      cout << distance(adj, s, t)<<endl;
      cout<<"if you want to check the path of length of between any  two edges of the graph enter 1 to continue , to exit enter 0 "<<endl;
      cin>>a;
    }
  return 0;
}


