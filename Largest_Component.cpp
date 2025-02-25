#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>

using namespace std;
int exploreSize(unordered_map<int,vector<int>>& graph, int source, unordered_set<int>& visited){
    if(visited.find(source) != visited.end()) return 0;

    visited.insert(source);
    int count = 1;
    for(auto neighbour : graph[source]){
       count += exploreSize(graph,neighbour,visited);
    }
    return count;
}
int main(){
    unordered_map<int, vector<int>> graph;
    graph[0] = {8,1,5};
    graph[1] = {0};
    graph[5] = {0,8};
    graph[8] = {0,5};
    graph[2] = {3,4};
    graph[3] = {2,4};
    graph[4] = {3,2};

    int longest = 0;
    unordered_set<int> visited;
    for(auto pair : graph){
        int size = exploreSize(graph, pair.first, visited);
        longest = max(longest,size);
    }
    cout<<longest;
    return 0;
}