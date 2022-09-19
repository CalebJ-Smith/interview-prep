// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Accepted
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //two pointers. fast goes until it hits the end
        //slow trails behind N nodes
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0; i < n; i ++){
            //we know n <= size of list by problem constraints
            fast = fast->next; 
        }
        if(fast == nullptr){
          return head->next;
        }
        while(fast->next){
          slow = slow->next;
          fast = fast->next;
        }
        //At here, slow points to the nth node from the end
        //TODO: check off-by-one
        slow->next = slow->next->next;
        //normally would `delete` here
        return head;
    }
};