def primes(limit):
    if limit < 2:
        return []
        
    is_prime = [True] * (limit + 1)
    is_prime[0] = is_prime[1] = False
    
    for factor in range(2, int(limit**0.5) + 1):
        if is_prime[factor]:
            for multiple in range(factor * factor, limit + 1, factor):
                is_prime[multiple] = False
                
    return [num for num, prime in enumerate(is_prime) if prime]