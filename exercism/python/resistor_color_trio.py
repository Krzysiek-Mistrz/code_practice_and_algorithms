def label(colors):
    color_map = [
        "black", "brown", "red", "orange", "yellow", 
        "green", "blue", "violet", "grey", "white"
    ]
    
    base_value = color_map.index(colors[0]) * 10 + color_map.index(colors[1])
    zeros = color_map.index(colors[2])
    total_ohms = base_value * (10 ** zeros)
    
    if total_ohms >= 1_000_000_000:
        return f"{total_ohms // 1_000_000_000} gigaohms"
    elif total_ohms >= 1_000_000:
        return f"{total_ohms // 1_000_000} megaohms"
    elif total_ohms >= 1_000:
        return f"{total_ohms // 1_000} kiloohms"
    else:
        return f"{total_ohms} ohms"