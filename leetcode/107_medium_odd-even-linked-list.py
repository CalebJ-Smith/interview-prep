from typing import Optional

# slow, but low memory


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next: Optional[ListNode] = next


class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        if not head.next:
            return head
        oddTail = head
        evenTail = head.next
        i = 3  # operate on evenTail.next
        while evenTail.next:
            if i % 2 == 0:  # even
                evenTail = evenTail.next
            else:  # odd
                movNode = evenTail.next
                evenTail.next = evenTail.next.next  # remove movNode from list

                evenHead = oddTail.next
                oddTail.next = movNode
                oddTail = movNode
                oddTail.next = evenHead

            i += 1
        return head


def main():
    # test Solution
    sol = Solution()
    # test oddEvenList
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    result = sol.oddEvenList(head)
    while result:
        print(result.val)
        result = result.next


main()
