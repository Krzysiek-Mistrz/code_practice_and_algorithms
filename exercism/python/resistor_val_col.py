def value(colors):
    color_map = [
        "black", "brown", "red", "orange", "yellow", 
        "green", "blue", "violet", "grey", "white"
    ]
    first_digit = color_map.index(colors[0])
    second_digit = color_map.index(colors[1])
    
    return first_digit * 10 + second_digit