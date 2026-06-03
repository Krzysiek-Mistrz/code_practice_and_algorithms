def rebase(input_base, digits, output_base):
    if input_base < 2:
        raise ValueError("input base must be >= 2")
    if output_base < 2:
        raise ValueError("output base must be >= 2")
    
    decimal_value = 0
    for d in digits:
        if not 0 <= d < input_base:
            raise ValueError("all digits must satisfy 0 <= d < input base")
        decimal_value = decimal_value * input_base + d
        
    if decimal_value == 0:
        return [0]
        
    new_digits = []
    while decimal_value > 0:
        decimal_value, reminder = divmod(decimal_value, output_base)
        new_digits.append(reminder)
        
    return new_digits[::-1]