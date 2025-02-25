#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>

using namespace std;

bool explore(vector<vector<char>>& islands, int row, int col, unordered_set<string>& visited){
    bool rowBounds = 0 <= row && row < islands.size();
    bool colBounds = 0 <= col && col < islands[0].size();

    if(!rowBounds || !colBounds) return false;
    if(islands[row][col] == 'W') return false;
    string pos = to_string(row) + ',' + to_string(col);
    
    if(visited.find(pos) != visited.end()) return false;
    visited.insert(pos);
    explore(islands,row - 1, col, visited);
    explore(islands,row + 1, col, visited);
    explore(islands,row, col - 1, visited);
    explore(islands,row, col + 1, visited);

    return true;
}
int main(){
    vector<vector<char>> islands;
    unordered_set<string> visited;
    int count = 0;
    islands = {{'W', 'L', 'W', 'W', 'W'},
               {'W', 'L', 'W', 'W', 'W'},
               {'W', 'W', 'W', 'L', 'W'},
               {'W', 'W', 'L', 'L', 'W'},
               {'L', 'W', 'W', 'L', 'L'},
               {'L', 'L', 'W', 'W', 'W'},};
    for(int row = 0; row<islands.size(); row++){
        for(int col = 0; col<islands[0].size(); col++){
            count += explore(islands, row, col, visited)?1:0;
        }
    }
    cout<<count;
    return 0;
}