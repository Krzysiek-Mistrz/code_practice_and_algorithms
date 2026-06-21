import math


def largest_product(series, size):
    if size < 0:
        raise ValueError("span must not be negative")
        
    if size > len(series):
        raise ValueError("span must not exceed string length")
        
    if not series.isdigit() and series != "":
        raise ValueError("digits input must only contain digits")
        
    if size == 0:
        return 1

    max_product = 0

    for i in range(len(series) - size + 1):
        window = series[i : i + size]
        
        current_product = math.prod(int(digit) for digit in window)
        
        if current_product > max_product:
            max_product = current_product

    return max_product