def find_anagrams(word, candidates):
    target_lower = word.lower()
    target_sorted = sorted(target_lower)
    anagrams = []
    
    for candidate in candidates:
        candidate_lower = candidate.lower()
        
        if candidate_lower == target_lower:
            continue
        
        if sorted(candidate_lower) == target_sorted:
            anagrams.append(candidate)
            
    return anagrams