def resistor_label(colors):
    if len(colors) == 1:
        return "0 ohms"
        
    color_map = [
        "black", "brown", "red", "orange", "yellow", 
        "green", "blue", "violet", "grey", "white"
    ]
    
    tolerance_map = {
        "grey": "0.05%",
        "violet": "0.1%",
        "blue": "0.25%",
        "green": "0.5%",
        "brown": "1%",
        "red": "2%",
        "gold": "5%",
        "silver": "10%"
    }
    
    if len(colors) == 4:
        digits = color_map.index(colors[0]) * 10 + color_map.index(colors[1])
        multiplier = color_map.index(colors[2])
        tolerance_color = colors[3]
    else:
        digits = (color_map.index(colors[0]) * 100 + 
                  color_map.index(colors[1]) * 10 + 
                  color_map.index(colors[2]))
        multiplier = color_map.index(colors[3])
        tolerance_color = colors[4]
        
    total_ohms = digits * (10 ** multiplier)
    
    if total_ohms >= 1_000_000_000:
        value_str = f"{total_ohms // 1_000_000_000} gigaohms"
    elif total_ohms >= 1_000_000:
        if total_ohms % 1_000_000 == 0:
            value_str = f"{total_ohms // 1_000_000} megaohms"
        else:
            value_str = f"{total_ohms / 1_000_000} megaohms"
    elif total_ohms >= 1_000:
        if total_ohms % 1_000 == 0:
            value_str = f"{total_ohms // 1_000} kiloohms"
        else:
            value_str = f"{total_ohms / 1_000} kiloohms"
    else:
        value_str = f"{total_ohms} ohms"
        
    tolerance_val = tolerance_map[tolerance_color]
    
    return f"{value_str} ±{tolerance_val}"