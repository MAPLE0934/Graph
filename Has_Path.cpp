#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

//..........DFS...............

bool depthFirstSearch(unordered_map<char, vector<char>>& graph, char source, char des){
    if(source == des) return true;

    for(auto neighbour : graph[source]){
        if(depthFirstSearch(graph, neighbour, des) == true){
            return true;
        }
    }
    return false;
}
//.........BFS................

bool breadthFirstSearch(unordered_map<char, vector<char>>& graph, char source, char des){
    queue<char> q;

    q.push(source);

    while(!q.empty()){
        char current = q.front();
        if(current == des) return true;
        q.pop();
        for(auto neighbour : graph[current]){
            q.push(neighbour);
        }
    }
    return false;
}
int main(){
    unordered_map<char,vector<char>> graph;
    graph['f'] = {'g','i'};
    graph['g'] = {'h'};
    graph['h'] = {};
    graph['i'] = {'g','k'};
    graph['j'] = {'i'};
    graph['k'] = {};

    depthFirstSearch(graph, 'f', 'k')? cout<<"TRUE":cout<<"FALSE";
    cout<<endl;
    depthFirstSearch(graph, 'j', 'f')? cout<<"TRUE":cout<<"FALSE";
    cout<<endl;
    breadthFirstSearch(graph, 'f', 'k')? cout<<"TRUE":cout<<"FALSE";
    cout<<endl;
    breadthFirstSearch(graph, 'j', 'f')? cout<<"TRUE":cout<<"FALSE";
    return 0;
}