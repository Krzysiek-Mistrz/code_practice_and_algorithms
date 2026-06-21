def triplets_with_sum(number):
    result = []
    N = number
    
    for a in range(1, N // 3):
        numerator = N**2 - 2 * N * a
        denominator = 2 * N - 2 * a
        
        if numerator % denominator == 0:
            b = numerator // denominator
            c = N - a - b
            
            if a < b:
                result.append([a, b, c])
                
    return result