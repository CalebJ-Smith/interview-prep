#include <iostream>
using namespace std;
//https://leetcode.com/problems/add-two-numbers/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return nullptr;
        if(!l1) return new ListNode(l2->val, l2->next);
        if(!l2) return new ListNode(l1->val, l1->next);

        int sum = l1->val + l2->val;
        ListNode* sumList = sum ? int2List(sum) : new ListNode();
        int firstSum = sumList->val;

        if(l1->next && l2->next) {
            l1->next = addTwoNumbers(l1->next, sumList->next);
            delete sumList;
            return new ListNode(firstSum, addTwoNumbers(l1->next, l2->next));  
        }if(l1->next){
            l1->next = addTwoNumbers(l1->next, sumList->next);
            delete sumList;
            return new ListNode(firstSum, addTwoNumbers(l1->next, nullptr));
        }else if(l2->next){
            l2->next = addTwoNumbers(l2->next, sumList->next);
            delete sumList;
            return new ListNode(firstSum, addTwoNumbers(nullptr, l2->next));
        }else{
            return sumList;
        }
    }

    void printNode(ListNode* l, ostream& os){
      os << "[ ";
      while(l){
        os << l->val << " ";
        l = l->next;
      }
      os << "]" << endl;
    }
    
private:
    ListNode* int2List(int a){
        if(a == 0) return nullptr;
        int ones = a % 10;
        int tensplus = a / 10;
        return new ListNode(ones, int2List(tensplus));
    }
};

int main(){
  cout <<"inputs" << endl;
  ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  //ListNode* l1 = new ListNode(2);
  ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
  //ListNode* l2 = new ListNode(8, new ListNode(1));
  Solution s;

  s.printNode(l1, cout);
  s.printNode(l2, cout);
  ListNode* answer = s.addTwoNumbers(l1, l2);
  cout << "output" << endl;
  s.printNode(answer, cout);

  ListNode* a = new ListNode();
  ListNode* b = new ListNode();
  cout << "other ones" << endl;
  s.printNode(a, cout);
  s.printNode(b, cout);
  s.printNode(s.addTwoNumbers(a, b), cout);

  delete l1;
  delete l2;
  delete a; delete b;
}