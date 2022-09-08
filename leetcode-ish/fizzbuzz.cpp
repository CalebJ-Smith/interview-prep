#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv){
  int count_to = atoi(argv[1]);
  for(int i = 1; i <= count_to; i++){
    string word = "";
    if(i % 3 == 0)
      word += "Fizz";
    if(i % 5 == 0)
      word += "Buzz";
    if(word == "")
      word = to_string(i);
    cout << word << endl;
  }
}
