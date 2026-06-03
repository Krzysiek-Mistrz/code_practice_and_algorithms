def is_valid(isbn):
    clean_isbn = isbn.replace("-", "")

    if len(clean_isbn) != 10:
        return False

    total_sum = 0
    
    for i in range(10):
        char = clean_isbn[i]
        
        if char == 'X':
            if i != 9:
                return False
            value = 10
        elif char.isdigit():
            value = int(char)
        else:
            return False
        
        total_sum += value * (10 - i)

    return total_sum % 11 == 0