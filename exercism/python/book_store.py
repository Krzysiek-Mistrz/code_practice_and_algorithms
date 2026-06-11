def total(basket):
    PRICES = {
        0: 0,
        1: 800,          
        2: 2 * 800 * 0.95, 
        3: 3 * 800 * 0.90, 
        4: 4 * 800 * 0.80, 
        5: 5 * 800 * 0.75  
    }
    
    memo = {}

    counts = [0] * 5
    for book in basket:
        counts[book - 1] += 1
    
    starting_state = tuple(sorted(counts, reverse=True))

    def find_min_price(state):
        if sum(state) == 0:
            return 0
        if state in memo:
            return memo[state]
        
        min_price = float('inf')
        available_unique_books = sum(1 for count in state if count > 0)
        
        for size in range(1, available_unique_books + 1):
            next_state = list(state)
            for i in range(size):
                next_state[i] -= 1
                
            next_state = tuple(sorted(next_state, reverse=True))
            
            current_price = PRICES[size] + find_min_price(next_state)
            min_price = min(min_price, current_price)
            
        memo[state] = min_price
        return min_price

    return find_min_price(starting_state)