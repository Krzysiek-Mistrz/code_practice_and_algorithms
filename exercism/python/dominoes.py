def can_chain(dominoes):
    if not dominoes:
        return []
    
    def backtrack(current_node, remaining_dominoes, current_chain):
        if not remaining_dominoes:
            if current_chain[0][0] == current_chain[-1][1]:
                return current_chain
            return None
            
        for i, (u, v) in enumerate(remaining_dominoes):
            if u == current_node:
                result = backtrack(v, remaining_dominoes[:i] + remaining_dominoes[i+1:], current_chain + [(u, v)])
                if result is not None:
                    return result
            elif v == current_node:
                result = backtrack(u, remaining_dominoes[:i] + remaining_dominoes[i+1:], current_chain + [(v, u)])
                if result is not None:
                    return result
                    
        return None

    first = dominoes[0]
    res = backtrack(first[1], dominoes[1:], [first])
    if res is not None:
        return res
        
    res = backtrack(first[0], dominoes[1:], [(first[1], first[0])])
    return res