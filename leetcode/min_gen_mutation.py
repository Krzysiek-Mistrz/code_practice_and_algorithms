# A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
# Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.
# For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
# There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.
# Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.
# Note that the starting point is assumed to be valid, so it might not be included in the bank.

# Example 1:
# Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
# Output: 1

from collections import deque
from email.errors import MultipartInvariantViolationDefect
from random import choices


class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        bank_set = set(bank)
        
        if endGene not in bank_set:
            return -1
        
        queue = deque([(startGene, 0)])
        visited = {startGene}
        
        choices = ['A', 'C', 'G', 'T']
        
        while queue:
            current_gene, dist = queue.popleft()
            
            if current_gene == endGene:
                return dist
            
            for i in range(len(current_gene)):
                for char in choices:
                    if char == current_gene[i]:
                        continue
                    
                    mutated = current_gene[:i] + char + current_gene[i + 1:]
                    
                    if mutated in bank_set and mutated not in visited:
                        visited.add(mutated)
                        queue.append((mutated, dist + 1))
                        
        return -1