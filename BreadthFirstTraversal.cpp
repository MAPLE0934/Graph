#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;

void breadthFirstTraversal(unordered_map<char,vector<char>>& graph, char source){
    queue<char> q;
    q.push(source);

    while(!q.empty()){
        char current = q.front();
        cout<<current;
        q.pop();
        for(auto neighbour : graph[current]){
            q.push(neighbour);
        }
    }
}
int main(){
    unordered_map<char, vector<char>> graph;
    graph['a'] = {'c', 'b'};
    graph['b'] = {'d'};
    graph['c'] = {'e'};
    graph['d'] = {'f'};
    graph['e'] = {};
    graph['f'] = {};
    
    breadthFirstTraversal(graph, 'a');
    return 0;
}