def sum_of_multiples(limit, multiples):
    unique_multiples = set()
    
    for i in range(1, limit):
        for factor in multiples:
            if factor > 0 and i % factor == 0:
                unique_multiples.add(i)
                break
                
    return sum(unique_multiples)