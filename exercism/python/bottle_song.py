def get_verse(number):
    numbers_upper = {
        10: "Ten", 9: "Nine", 8: "Eight", 7: "Seven", 6: "Six",
        5: "Five", 4: "Four", 3: "Three", 2: "Two", 1: "One"
    }
    
    numbers_lower = {
        9: "nine", 8: "eight", 7: "seven", 6: "six", 5: "five",
        4: "four", 3: "three", 2: "two", 1: "one", 0: "no"
    }
    
    current_bottles = "bottle" if number == 1 else "bottles"
    next_bottles = "bottle" if (number - 1) == 1 else "bottles"
    
    num_str = numbers_upper[number]
    next_num_str = numbers_lower[number - 1]
    
    line1 = line2 = f"{num_str} green {current_bottles} hanging on the wall,"
    line3 = "And if one green bottle should accidentally fall,"
    line4 = f"There'll be {next_num_str} green {next_bottles} hanging on the wall."
    
    return [line1, line2, line3, line4]


def recite(start, take=1):
    result = []
    
    for i in range(take):
        current_verse = get_verse(start - i)
        result.extend(current_verse)
        
        if i < take - 1:
            result.append("")
            
    return result