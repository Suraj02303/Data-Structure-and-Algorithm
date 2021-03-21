#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
stack <int> s;
int *visited;
int *bipartiteArray;
int size=0;
int status=1;
int Explore(vector<vector<int>> &adj, int v){
    visited[v] = 1;
    s.push(v);
    for(auto it = adj[v].begin(); it!= adj[v].end(); ++it){
        if(!visited[*it]){
        	if(bipartiteArray[v] == 1){
        		bipartiteArray[*it]= 0;
			}
			if(bipartiteArray[v] == 0){
        		bipartiteArray[*it]= 1;
			} 
        	Explore(adj, *it);
		}
        if(bipartiteArray[v]==bipartiteArray[*it])
        	status = -1;    
    }
    s.pop();
}
int bipartite(vector<vector<int> > &adj) {
  int res = 0;
	//write your code here
	
	for(size_t i = 0;i<size;i++){
		if(visited[i]==0){
			res++;
			bipartiteArray[i] = 1;
	  		Explore(adj, i);
		}
	}
	return status;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  visited = new int[n];
  bipartiteArray = new int[n];
  size = n;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  for(size_t i =0;i<n;i++){
	 bipartiteArray[i] = 0;
  }
 
  cout<<bipartite(adj);
}
