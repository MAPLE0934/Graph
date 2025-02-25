#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<tuple>
#include<unordered_set>

using namespace std;

bool explore(unordered_map<int, vector<int>>& graph, int source, unordered_set<int>& visited){
    if(visited.find(source) != visited.end()) return false;

    visited.insert(source);

    for(auto neighbour : graph[source]){
        explore(graph,neighbour,visited);
    }
    return true;
}

int main(){
    unordered_map<int,vector<int>> graph;
    graph[0] = {8,1,5};
    graph[1] = {0};
    graph[5] = {0,8};
    graph[8] = {0,5};
    graph[2] = {3,4};
    graph[3] = {2,4};
    graph[4] = {3,2};

    unordered_set<int> visited;
    int count = 0;
    for(auto pair : graph){
        count += explore(graph,pair.first, visited)?1:0;
    }
    cout<<count;
    return 0;
}