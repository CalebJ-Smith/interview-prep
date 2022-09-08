//calebsSudokuThing
#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>

class SudokuSolver{
private:
  bool hasSolution = false;
  std::ostream& os;
  uint32_t numSolutions = 0;
  uint32_t numGuesses = 0;
  std::stringstream originalInput;
  std::vector<std::vector<char>> board;
  std::vector<std::vector<bool>> cellsHaveNums;
  std::vector<std::vector<bool>> rowsHaveNums;
  std::vector<std::vector<bool>> colsHaveNums;

  size_t coord2CellNum(size_t r, size_t c){
    return 3 * (r/3) + c/3;
  }

  bool genPerms(size_t r, size_t c){
    ++numGuesses;
    if(r == 9){ //This is where it'll get to when it's done
      ++numSolutions;
      return true;
    }
    if(board[r][c] != '.'){
      if(c == 8)
        return genPerms(r+1, 0);
      else 
        return genPerms(r, c+1);
    }

    for(size_t testNum = 1; testNum <= 9; ++testNum){
      if(  !cellsHaveNums[coord2CellNum(r, c)][testNum]
        && !rowsHaveNums[r][testNum]
        && !colsHaveNums[c][testNum])
      {
        cellsHaveNums[coord2CellNum(r, c)][testNum] = true;
        rowsHaveNums[r][testNum] = true;
        colsHaveNums[c][testNum] = true;
        board[r][c] = char('0' + testNum);

        if(c == 8){
          if(genPerms(r + 1, 0))
            return true;
        }else{
          if(genPerms(r, c + 1))
            return true;
        }

        cellsHaveNums[coord2CellNum(r, c)][testNum] = false;
        rowsHaveNums[r][testNum] = false;
        colsHaveNums[c][testNum] = false;
        board[r][c] = '.'; // this line isn't strictly necessary
      }
    }
    return false;
  }
  

  
public:
  SudokuSolver(std::string& str, std::ostream& os)
  : os(os),
    board(9, std::vector<char>(9)),
    cellsHaveNums(9, std::vector<bool>(10, false)),//don't want to deal with 0 indexing
    rowsHaveNums(9, std::vector<bool>(10, false)),
    colsHaveNums(9, std::vector<bool>(10, false))
  {
    //read in board from file
    for(size_t r = 0; r < 9; ++r){
      for(size_t c = 0; c < 9; ++c){
        char num = str[9*r+c];
        originalInput << num;
        board[r][c] = num;
        if(num != '.'){
          size_t a = num - '0';
          cellsHaveNums[coord2CellNum(r, c)][a] = true;
          rowsHaveNums[r][a] = true;
          colsHaveNums[c][a] = true;
        }
      }
    }
  } 

  bool solve(){
    //backtracking approach
    hasSolution = genPerms(0, 0);
    return hasSolution;
  }

  void print(){
    os << originalInput.str() << ':' 
      << hasSolution;
    if(hasSolution){
      os << ':';
      for(size_t i = 0; i < 9; ++i){
        for(size_t j = 0; j < 9; ++j)
          os << board[i][j];
      }
    }
    os << '\n';
  }


};





#endif