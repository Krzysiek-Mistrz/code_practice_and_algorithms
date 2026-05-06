def is_armstrong_number(number):
    str_number = str(number)
    power = len(str_number)
    total = sum(int(digit) ** power for digit in str_number)
    
    return total == number