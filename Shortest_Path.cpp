#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<tuple>
#include<unordered_set>
using namespace std;

unordered_map<char,vector<char>> makeGraph(vector<tuple<char,char>>& edges){
    unordered_map<char,vector<char>> graph;
    for(const auto& pair : edges){
        char u = get<0>(pair);
        char v = get<1>(pair);
        if(graph.find(u) == graph.end()) graph[u] = vector<char>();
        if(graph.find(v) == graph.end()) graph[v] = vector<char>();

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}
int shortestPath(unordered_map<char,vector<char>>& graph, char source, char des, unordered_set<char> visited){
    queue<pair<char,int>> q;
    q.push({source,0});

    while(!q.empty()){
        auto pair = q.front();
        char current = pair.first;
        int length = pair.second;
        if(visited.find(current) != visited.end()) return 0;
        if(current == des) return length;
        q.pop();
        for(auto neighbour : graph[current]){
            q.push({neighbour,length+1});
        }
    }
    return -1;
}
int main(){
    vector<tuple<char,char>> edges = {{'w','x'},
                                      {'x','y'},
                                      {'z','y'},
                                      {'z','v'},
                                      {'w','v'}};
    unordered_map<char,vector<char>> graph;
    graph = makeGraph(edges);
    unordered_set<char> visited;

    cout<<shortestPath(graph,'w','z',visited);
    return 0;
}