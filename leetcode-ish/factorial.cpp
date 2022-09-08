#include<string>
#include<iostream>
#include<fstream>
#include<cassert>
#include<cstring>
#include<unordered_map>

using namespace std;


unordered_map<int, unsigned long int> map = {
  {0, 1},
  {1, 1}
};

// REQUIRES: n >= 0
// EFFECTS: computes and returns n!
unsigned long int fact(int n, int& stack_frames) {
  assert(n>=0);
  auto search = map.find(n);

  if(search == map.end()){
    unsigned long int answer =  n * fact(n-1, ++stack_frames);
    map.insert({n, answer});
    return answer;
  }else{
    cout << "found " << search->first << ":" << search->second << endl;
    return search->second;
  }
}

int main(){
  int stack_frames = 1;
  cout << fact(5, stack_frames) << " took " << stack_frames << " stack frames" << endl;
  stack_frames = 1;
  cout << fact(20, stack_frames) << " took " << stack_frames << " stack frames" << endl;
  stack_frames = 1;
  cout << fact(6, stack_frames) << " took " << stack_frames << " stack frames" << endl;
  stack_frames = 1;
  cout << fact(19, stack_frames) << " took " << stack_frames << " stack frames" << endl;
  return 0;
}