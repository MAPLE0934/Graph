#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<tuple>
#include<unordered_set>
using namespace std;

unordered_map<char,vector<char>> makeGraph (vector<tuple<char,char>>& edges){
    unordered_map<char, vector<char>> graph;

    for (const auto& pair : edges) {
        char u = get<0>(pair);
        char v = get<1>(pair);
        if (graph.find(u) == graph.end()) {
            graph[u] = vector<char>();  
        }
        if (graph.find(v) == graph.end()) {
            graph[v] = vector<char>();  
        }
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}

bool has_path(unordered_map<char,vector<char>>& graph,char source, char des, unordered_set<char>& visited){
    if(source == des) return true;
    if(visited.find(source) != visited.end()) return false;

    visited.insert(source);
    
    for(auto neighbour : graph[source]){
        if(has_path(graph,neighbour,des,visited)) return true;
    }
    return false;
}
int main(){
    vector<tuple<char,char>> edges = {{'i','j'},
                                      {'k','i'},
                                      {'m','k'},
                                      {'k','l'},
                                      {'o','n'}};
                                    
    unordered_map<char,vector<char>> graph;
    graph = makeGraph(edges);
    unordered_set<char> visited;
    has_path(graph,'j','m',visited)?cout<<"TRUE":cout<<"FALSE";
    return 0;
}