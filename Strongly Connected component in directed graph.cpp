#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;
stack <int> s;
queue<int> sq ;
stack <int> reverse_preorder;
int *visited_G;
int *visited_RG;
int CLOCK = 1;
int *previsit;
int *postvist;
int size=0;

int Explore_G(vector<vector<int>> &G, int v){
    visited_G[v] = 1;
    sq.push(v);
    for(auto it = G[v].begin(); it!= G[v].end(); ++it){
        if(!visited_G[*it])
            Explore_G(G, *it);
    }
    while(!s.empty()){
        cout<<sq.front()<<"  ";
        sq.pop();
    }
    cout<<endl;
}
int Explore(vector<vector<int>> &RG, int v){
    visited_RG[v] = 1;
    previsit[v] = CLOCK++;
    s.push(v);
    for(auto it = RG[v].begin(); it!= RG[v].end(); ++it){
        if(!visited_RG[*it])
            Explore(RG, *it);
    }
    postvist[v] = CLOCK++;
    reverse_preorder.push(v);
    s.pop();
}

int number_of_strongly_connected_components(vector<vector<int> > G, vector<vector<int> > RG) {
    int res = 0;
    //write your code here
    for(size_t i =0;i<size;i++){
		if(visited_RG[i]==0){
			res++;
	  		Explore(RG, i);
		}
	}
	while(!reverse_preorder.empty()){
	    if(!visited_G[reverse_preorder.top()]){
	        Explore_G(G, reverse_preorder.top());
	    }
	}
    return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  visited_G = new int[n];
  visited_RG = new int[n];
  previsit = new int[n];
  postvist = new int[n];
  vector<vector<int> > G(n, vector<int>());
  vector<vector<int> > RG(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    G[x].push_back(y);
    RG[y].push_back(x);
  }
  for(size_t i = 0; i<n ; i++){
		visited_G[i] = 0;
		visited_RG[i] = 0;
		size++;
		previsit[i] = -1;
		postvist[i] = -1;
	}
	//number_of_strongly_connected_components(G, RG);
    cout << number_of_strongly_connected_components(G, RG);
    cout<<endl<<"++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  for(size_t i = 0; i<n ; i++){
		cout<<i<<"previsit =>" << previsit[i]<<" postvist => "<<postvist[i]<<endl;
	}
}


