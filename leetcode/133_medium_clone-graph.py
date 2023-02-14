# https://leetcode.com/problems/clone-graph/submissions/
# 90th percentile speed, 70th percentile memory


# Definition for a Node.
class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


from collections import deque


class Solution:
    def cloneGraph(self, node: "Node") -> "Node":
        if not node:
            return None
        nodeClone = Node(node.val)

        alreadyCloned = {nodeClone.val: nodeClone}
        todoStack = deque()  # contains node,node objects from og graph
        todoStack.append(node)

        while todoStack:
            current = todoStack.pop()  # og node
            currentClone = alreadyCloned[current.val]
            # print(current.val)

            for explore in current.neighbors:
                if explore.val not in alreadyCloned.keys():
                    todoStack.append(explore)
                    alreadyCloned[explore.val] = Node(explore.val)

                exploreClone = alreadyCloned[explore.val]
                exploreClone.neighbors.append(currentClone)

        return nodeClone
