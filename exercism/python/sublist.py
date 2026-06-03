# Definiujemy stałe, które zazwyczaj są wymagane w tym zadaniu
SUBLIST = "sublist"
SUPERLIST = "superlist"
EQUAL = "equal"
UNEQUAL = "unequal"

def sublist(list_one, list_two):
    if list_one == list_two:
        return EQUAL

    def is_subsequence(small, large):
        if not small:
            return True
        
        if len(small) > len(large):
            return False
        
        for i in range(len(large) - len(small) + 1):
            if large[i : i + len(small)] == small:
                return True
            
        return False

    if is_subsequence(list_one, list_two):
        return SUBLIST
    
    if is_subsequence(list_two, list_one):
        return SUPERLIST
        
    return UNEQUAL