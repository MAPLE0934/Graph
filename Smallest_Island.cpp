#include <bits/stdc++.h>

using namespace std;
int explore(vector<vector<char>>& islands, int row, int col, unordered_set<string>& visited){
    bool rowBounds = 0 <= row && row < islands.size();
    bool colBounds = 0 <= col && col < islands[0].size();

    if(!rowBounds || !colBounds) return 0;
    if(islands[row][col] == 'W') return 0;

    string pos = to_string(row) + ',' + to_string(col);
    if(visited.find(pos) != visited.end()) return 0;
    visited.insert(pos);
    
    int size = 1;

    size += explore(islands,row-1,col,visited);
    size += explore(islands,row+1,col,visited);
    size += explore(islands,row,col-1,visited);
    size += explore(islands,row,col+1,visited);

    return size;
}
int main(){
    vector<vector<char>> islands =  {{'L', 'W', 'W', 'L', 'W'},
                                     {'L', 'W', 'W', 'L', 'L'},
                                     {'W', 'L', 'W', 'L', 'W'},
                                     {'W', 'L', 'W', 'L', 'W'},
                                     {'L', 'W', 'W', 'L', 'L'},
                                     {'L', 'L', 'W', 'W', 'W'}};
    unordered_set<string> visited;
    int minSize = islands.size()*islands[0].size();
    for(int i = 0; i<islands.size(); i++){
        for(int j = 0; j<islands[0].size(); j++){
            int currSize = explore(islands, i, j, visited);
            if(currSize > 0){
                minSize = min(currSize,minSize);
            }
        }
    }
    cout<<minSize;
    return 0;
}