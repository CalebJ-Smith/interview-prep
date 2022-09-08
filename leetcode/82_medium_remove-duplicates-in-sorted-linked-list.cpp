// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
#include <iostream>
#include <vector>

#include "linked_list_io.h"
using namespace std;
//TO EXECUTE:
//g++ -std=c++1z -Wconversion -Wall -Werror -Wextra -pedantic 82_medium_remove-duplicates-in-sorted-linked-list.cpp linked_list_io.h -o 82.exe; ./82.exe

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return nullptr;
    if (!head->next) return head;
    ListNode* sentinal = new ListNode(-101, head);

    ListNode* slow = sentinal;  // slow is the node that definitley will be
                                // included in the output
    ListNode* fast = sentinal->next;  // fast needs to end up as the first
                                            // node of the new section

    while (slow && fast && fast->next) {
      fast = fast->next;
      cerr << "slow is at " << slow->val << "; ";
      // get rid of multiple sets of duplicate groups
      while (fast &&
             slow->next && 
             slow->next->next &&
             (slow->next->val == slow->next->next->val)) {
        // skip duplicates
        if(fast)
          cerr << "fast is at " << fast->val << "; ";
        while (fast && slow->next->val == fast->val) {
          fast = fast->next;
        }
        slow->next = fast; //remove the middle section from the list
        if(fast)
          fast = fast->next;
      }
      slow = slow->next;
    }

    cerr << endl;
    return sentinal->next;
  }
};

void test_case(vector<int> input, vector<int> expected) {
  std::cout << "executing case "; printVec(cout, input); std::cout << ": " << flush;
  Solution s;
  auto n = vec_to_linked_list(input);
  auto output = s.deleteDuplicates(n);
  auto output_vec = linked_list_to_vec(output);
  if (output_vec == expected) {
    std::cout << "PASS" << std::endl;
  } else {
    std::cout << "FAIL: returned "; printVec(cout, output_vec); 
    std::cout << " instead of "; printVec(cout, expected); std::cout << std::endl;
  }
}

int main() {
  test_case({1, 2, 3, 3, 4, 4, 5}, {1, 2, 5});
  test_case({1, 1, 1, 2, 3}, {2, 3});
  test_case({}, {});
  test_case({1}, {1});
  test_case({1, 1}, {});
  test_case({1, 1, 2, 2}, {});
  test_case({1, 1, 2}, {2});
  test_case({1, 2, 2}, {1});
  test_case({1, 2, 3}, {1,2,3});

  return 0;
}