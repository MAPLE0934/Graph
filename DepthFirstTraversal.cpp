#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;

//...........ITERATIVE APPROACH..................

void depthFirstTraversal_Iter(unordered_map<char,vector<char>>& graph, char source){
    stack<char> st;
    st.push(source);
    
    while(!st.empty()){
        char current = st.top();
        cout<<current;
        st.pop();
        for(char neighbour : graph[current]){
            st.push(neighbour);
        } 
    }
}

//..........RECURSIVE APPROACHH.................

void depthFirstTraversal_Recur(unordered_map<char,vector<char>>& graph, char source){
    cout<<source;
    for(auto neighbour : graph[source]){
        depthFirstTraversal_Recur(graph, neighbour);
    }
}

int main(){
    unordered_map<char, vector<char>> graph;
    graph['a'] = {'b', 'c'};
    graph['b'] = {'d'};
    graph['c'] = {'e'};
    graph['d'] = {'f'};
    graph['e'] = {};
    graph['f'] = {};


    depthFirstTraversal_Iter(graph,'a');
    cout<<endl;
    depthFirstTraversal_Recur(graph,'a');
    return 0;
}