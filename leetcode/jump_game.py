from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        """!
        @brief Sprawdza, czy możliwe jest dotarcie do ostatniego indeksu tablicy.
        Algorytm wykorzystuje podejście zachłanne (greedy), śledząc najdalszy 
        osiągalny punkt w każdej iteracji.
        @param nums Lista nieujemnych liczb całkowitych, gdzie każda liczba reprezentuje maksymalną długość skoku z danej pozycji.
        @return bool True, jeśli można dotrzeć do ostatniego indeksu, w przeciwnym razie False.
        """
        
        max_reach = 0
        last_index = len(nums) - 1
        
        for i in range(len(nums)):
            if i > max_reach:
                return False
            
            max_reach = max(max_reach, i + nums[i])
            
            if max_reach >= last_index:
                return True
            
        return False