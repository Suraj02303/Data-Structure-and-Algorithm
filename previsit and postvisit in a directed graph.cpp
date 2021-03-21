#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;
stack <int> s;
int *visited;
int CLOCK = 1;
int *previsit;
int *postvist;
int size=0;
int Explore(vector<vector<int>> &adj, int v){
    visited[v] = 1;
    previsit[v] = CLOCK++;
    s.push(v);
    for(auto it = adj[v].begin(); it!= adj[v].end(); ++it){
        if(!visited[*it])
            Explore(adj, *it);
    }
    postvist[v] = CLOCK++;
    s.pop();
}

int number_of_components(vector<vector<int> > &adj) {
	int res = 0;
	//write your code here
	for(size_t i =0;i<size;i++){
		if(visited[i]==0){
			res++;
	  		Explore(adj, i);
		}
	}
	return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  visited = new int[n];
  previsit = new int[n];
  postvist = new int[n];
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
  }
  for(size_t i = 0; i<n ; i++){
		visited[i] = 0;
		size++;
		previsit[i] = -1;
		postvist[i] = -1;
	}
  std::cout << number_of_components(adj)<<endl;
  for(size_t i = 0; i<n ; i++){
		cout<<i<<"previsit =>" << previsit[i]<<" postvist => "<<postvist[i]<<endl;
	}
}




