#include<iostream>
using namespace std;

void reverseArray(int *arr, int size){
  if(size <= 0){
    return;
  }
  int temp = arr[0];
  arr[0] = arr[size-1];
  arr[size-1] = temp;
  reverseArray(arr+1, size-2); //putting the recursive call at the end makes it a tail call
}


int main(){
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int length = 8;
  reverseArray(arr, length);
  for(int i = 0; i < length; i++){
    cout << arr[i] << " ";
  } 
  cout << endl;
  return 0;
}