// This is for sharing linked list printing and inputing
#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* vec_to_linked_list(const std::vector<int>& vec){
  ListNode* last_created = nullptr;
  for(auto rit = vec.rbegin(); rit < vec.rend(); rit++){
    last_created = new ListNode(*rit, last_created);
  }
  return last_created;
}

std::vector<int> linked_list_to_vec(ListNode* head){
  std::vector<int> v;
  while (head){
    v.push_back(head->val);
    head = head->next;
  }
  return v;
}

std::ostream& printLinkedList(std::ostream& out, ListNode* head){
  while (head){
    out << head->val << " ";
    head = head->next;
  }
  return out;
}

std::ostream& printVec(std::ostream& out, std::vector<int> vec){
  out << "[";
  for(auto i : vec){
    out << i << " ";
  }
  return out << "]";
}