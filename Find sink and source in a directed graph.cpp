#include <iostream>
#include <vector>
#include <utility>
#include <bits/stdc++.h> 
using namespace std;
stack <int> s;
int *visited;
int *component;
int *in;
int *out;
int *net;
int size=0;
int Explore(vector<vector<int>> &adj, int v ,int c){
    visited[v] = 1;
    component[v] = c;
    s.push(v);
    for(auto it = adj[v].begin(); it!= adj[v].end(); ++it){
        if(!visited[*it])
            Explore(adj, *it ,c);
    }
    s.pop();
}

int number_of_components(vector<vector<int> > &adj){
	int res = 0;
	//write your code here
	for(size_t i =0;i<size;i++){
		if(visited[i]==0){
			res++;
	  		Explore(adj, i ,res);
		}
	}
	return res;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    visited = new int[n];
    component = new int[n];
    in = new int[n];
    out = new int[n];
    net = new int[n];
    for(size_t i = 0; i<n ; i++){
		visited[i] = 0;
		component[i]= 0;
		in[i] = 0;
		out[i] = 0;
		net[i] = 0;
		size++;
	}
    vector<vector<int> > adj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x].push_back(y);
        out[x]++;
        in[y]++;
    }
    
    for (size_t i = 0; i < n; i++) {
        net[i]=in[i]-out[i];
    }
    int num_comp = number_of_components(adj);
    std::cout << num_comp <<endl;
    
    //assinging the component no. to each vertices;
	vector< pair<int , int>> status;
	for(size_t i = 0; i<n ; i++){
		status.push_back(make_pair(visited[i], component[i]));
	}
	
	vector<pair <int ,int>> sink ; //(num_comp , pair <int ,int>);
	vector<pair <int ,int>> source; //(num_comp, pair <int ,int>);

	for (size_t i = 1; i <=num_comp; i++){
	    int sk =0;
	    int sc =0;
        for(size_t j = 0; j < n; j++){
            if(component[j]== i){
                if(net[j]!=0){
                    if(net[j]>0){
                        if(out[j]==0){
                            sk = sk+1;
                            sink.push_back(make_pair(j,sk));}
                    }
                    else{
                        if(in[j]==0){
                            sc= sc+1;
                            source.push_back(make_pair(j,sc));} //source[i]++;
                    }
                }
            }
        }
    }
    for (size_t i = 0; i < num_comp; i++) {
        cout<<"Source["<<source[i].first<<"] "<<source[i].second<<" and Sink ["<<sink[i].first<<"]  "<<sink[i].second<<endl;
    }
}



