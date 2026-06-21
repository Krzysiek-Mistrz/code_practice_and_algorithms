def prime(number):
    if number < 1:
        raise ValueError('there is no zeroth prime')
        
    if number == 1:
        return 2
        
    count = 1
    candidate = 3
    
    while count < number:
        if is_prime(candidate):
            count += 1
            if count == number:
                return candidate
        candidate += 2
    
    return candidate


def is_prime(n):
    if n < 2:
        return False
    
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
        
    return True