/*This program implements an algorithm to find the connected components in the input graph*/
#include <bits/stdc++.h>
using namespace std;

struct A{
  bool all_true;
  int first_false_index;
}; //the struct which will contain the result of all true function

void find_connected(vector< vector<int> >, int);
void dfs_iter(vector< vector<int> >, int);

A all_true();



vector<bool> visited;

int main(){
  int n;
  cout<<"Enter the number of nodes in the graph (nodes will be numbered from zero): "; cin>>n;
  for(int i=0; i<n; i++){
    visited.push_back(false);
  }

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
  //print_graph(graph);
  cout<<endl;
  int start;
  cout<<"Enter the start node: "; cin>>start;
  find_connected(graph, start);
}

void dfs_iter(vector< vector<int> >g, int src_node){
  int n_nodes = g.size();
  stack<int> to_be_visited;

  to_be_visited.push(src_node);
  visited[src_node] = true;
  int vertex;
  while(!to_be_visited.empty()){
    vertex = to_be_visited.top();
    to_be_visited.pop();
    cout<<"Visiting node: "<<vertex<<endl;
    for(auto itr = g[vertex].begin(); itr != g[vertex].end(); itr++){
      if(!visited[*itr]){
        to_be_visited.push(*itr);
        visited[*itr] = true;
      }
    }
  }
}

A all_true(){
  A ret;
  bool flag = true;
  int n_nodes = visited.size();
  for(int i=0; i<n_nodes; i++){
    if(!visited[i]){
      //cout<<i<<" is not visited yet"<<endl;
      ret.all_true = false;
      ret.first_false_index = i;
      flag = false;
      break;
    }
  }
  if(flag){
    ret.all_true = true;
    ret.first_false_index = -1;
  }
  return ret;
}

void find_connected(vector< vector<int> >g, int src_node){
  int n_connected = 0;
  A res = all_true();
  while(!res.all_true){
    int src;
    if(n_connected == 0){
      src = src_node;
    }
    else{
      src = res.first_false_index;
    }
    dfs_iter(g, src);
    cout<<"___________________"<<endl;
    n_connected++;
    res = all_true();
  }
  cout<<"Number of connnected components are: "<<n_connected<<endl;
}
