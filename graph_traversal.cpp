/*This file is to implement the BFS traversal on a general graph
The graph will be stored as an adjacency list of nodes and a marked array
will be maintained to keep track of marked vertices*/

#include <bits/stdc++.h>
using namespace std;

void print_graph(vector< vector<int> >);
void bfs(vector< vector<int> >, int); //this function prints the stats as traversing through the graph

int main(){
  int n;
  cout<<"Enter the number of nodes in the graph (nodes will be numbered from zero): "; cin>>n;
  vector< vector<int> >graph(n, vector<int>());
  cout<<"---------------------------------------------------------------------------"<<endl;

  //filling the graph
  int temp;
  int n_v;
  for(int i=0; i<n; i++){
    cout<<endl;
    cout<<"Enter the number of nodes connected with node "<<i<<" :"; cin>>n_v;
    //cout<<endl;
    for(int u=0; u<n_v; u++){
      cout<<"Enter the nodes adjacent to node "<<i<<" one by one: "<<endl;
      cin>>temp;
      graph[i].push_back(temp);
    }
  }
  cout<<endl;
  //printing the graph
  print_graph(graph);
  cout<<endl;
  int start;
  cout<<"Enter the start node for bfs: "; cin>>start;
  bfs(graph, start);
}

void print_graph(vector< vector<int> >g){
  int n_nodes = g.size();
  for(int i=0; i<n_nodes; i++){
    cout<<i<<"-> {";
    for(auto itr = g[i].begin(); itr != g[i].end(); itr++){
      if(itr == g[i].begin()){
        cout<<*itr;
      }
      else{
        cout<<","<<*itr;
      }
    }
    cout<<"}"<<endl;
  }
}

void bfs(vector< vector<int> >g, int start_node){
  int n_nodes = g.size();
  vector<bool> visited(n_nodes,false);
  queue<int> processing; //to contain the visited nodes as they are being processed

  visited[start_node] = true;
  processing.push(start_node);
  while(!processing.empty()){
    cout<<"________________________________________"<<endl;
    cout<<"processing node "<<processing.front()<<":"<<endl;
    bool neig_already_visited = true;
    for(auto itr = g[processing.front()].begin(); itr != g[processing.front()].end(); itr++){
      if(!visited[*itr]){
        neig_already_visited = false;
        cout<<"visiting node "<<*itr<<endl;
        visited[*itr] = true;
        processing.push(*itr);
      }
    }
    if(neig_already_visited){
      cout<<"all nighbours already visited."<<endl;
    }
    processing.pop();
  }
}
