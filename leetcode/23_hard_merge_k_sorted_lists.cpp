//https://leetcode.com/problems/merge-k-sorted-lists/ 
//works, but relatively slow
#include <vector>
#include <algorithm>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class nodeCompare{
    public:
    bool operator()(const ListNode* a, const ListNode* b){
        if(a && b) return a->val < b->val;
        if(b) return false;
        return true;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        auto min = min_element(lists.begin(), lists.end(), nodeCompare());
        if(!*min || min == lists.end()) {
            return nullptr;
        }
        ListNode* temp = *min;
        *min = temp->next;
        int tempVal = temp->val;
        delete temp;
        return new ListNode(tempVal, mergeKLists(lists));
    }
};
    
