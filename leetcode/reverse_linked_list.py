# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

from typing import Optional


class ListNode:
    def __init__(self, val, next) -> None:
        self.val = val
        self.next = next

class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if not head or left == right:
            return head
        
        dummy = ListNode(0, head)
        prev = dummy
        
        for _ in range(left - 1):
            prev = prev.next
            
        curr = prev.next
        
        for _ in range(right - left):
            temp = curr.next
            curr.next = temp.next
            temp.next = prev.next
            prev.next = temp
            
        # temp = curr.next: Zaznaczamy 3 jako nasz cel
        # curr.next = temp.next: Mówimy dwójce: „zapomnij o trójce, teraz patrz na czwórkę”.
        # Stan: 2 -> 4
        # temp.next = prev.next: Mówimy trójce: „teraz ty będziesz stać przed dwójką”.
        # Stan: 3 -> 2
        # prev.next = temp: Mówimy jedynce: „teraz twoim następnym sąsiadem jest trójka”.
        # Wynik po 1. kroku: 1 -> 3 -> 2 -> 4 -> 5
                
        return dummy.next