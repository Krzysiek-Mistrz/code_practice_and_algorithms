# Implement the RandomizedSet class:

# RandomizedSet() Initializes the RandomizedSet object.
# bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
# bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
# int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
# You must implement the functions of the class such that each function works in average O(1) time complexity.

# Example 1:
# Input
# ["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
# [[], [1], [2], [2], [], [1], [2], []]
# Output
# [null, true, false, true, 2, true, false, 2]

import random


class RandomizedSet:
    """
    @brief Klasa przechowująca zbiór unikalnych liczb z operacjami w czasie O(1).
    """

    def __init__(self):
        """
        @brief Inicjalizuje struktury danych: listę i mapowanie indeksów.
        """
        self.data = []
        self.mapping = {}
        
    def insert(self, val: int) -> bool:
        """
        @brief Dodaje element do zbioru, jeśli go nie ma.
        @param val Wartość do dodania.
        @return bool True jeśli dodano, False jeśli już istniał.
        """
        if val in self.mapping:
            return False
        
        self.mapping[val] = len(self.data)
        self.data.append(val)
        
        return True

    def remove(self, val: int) -> bool:
        """
        @brief Usuwa element w czasie O(1) stosując trik z zamianą miejsc.
        @param val Wartość do usunięcia.
        """
        
        if val not in self.mapping:
            return False
        
        idx_to_remove = self.mapping[val]
        last_element = self.data[-1]
        
        self.data[idx_to_remove] = last_element
        self.mapping[last_element] = idx_to_remove
        
        self.data.pop()
        del self.mapping[val]
        
        return True

    def getRandom(self) -> int:
        """
        @brief Zwraca losowy element z jednostajnym prawdopodobieństwem.
        @return int Losowa wartość ze zbioru.
        """
        
        return random.choice(self.data)

# Testowanie
# obj = RandomizedSet()
# print(obj.insert(1)) # True
# print(obj.remove(2)) # False
# print(obj.getRandom())