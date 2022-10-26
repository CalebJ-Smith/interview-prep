// https://leetcode.com/problems/number-of-islands/
// accepted, but slow and big memory

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //let '.' mean that this square has been visited
        int count = 0;
        for(int row = 0; row < grid.size(); ++row){
            for(int col = 0; col < grid[row].size(); ++col){
                switch(grid[row][col]){
                    case '.':
                        break;
                    case '0':
                        grid[row][col] = '.';
                        break;
                    case '1': //land. Explore all the adjacent land and mark it as '.'
                        ++count;
                        {
                            queue<pair<int, int>> todo;
                            grid[row][col] = '.';
                            todo.push({row, col});
                            while(!todo.empty()){
                                int row = todo.front().first;
                                int col = todo.front().second; //variable shaddowing cause I feel lazy
                                todo.pop();
                                if(row - 1 >= 0 && grid[row-1][col] == '1' ){
                                    todo.push({row-1, col});
                                    grid[row-1][col] = '.';
                                }
                                if(col - 1 >= 0 && grid[row][col-1] == '1'){
                                    todo.push({row, col-1});
                                    grid[row][col-1] = '.';
                                }
                                if(row + 1 < grid.size() && grid[row+1][col] == '1'){
                                    todo.push({row+1, col});
                                    grid[row+1][col] = '.';
                                }
                                if(col + 1 < grid[row].size() && grid[row][col+1] == '1'){
                                    todo.push({row, col+1});
                                    grid[row][col+1] = '.';
                                }
                            }
                        }
                        break;
                    default:
                        break;
                }
            }
        }
        return count;
    }
};
