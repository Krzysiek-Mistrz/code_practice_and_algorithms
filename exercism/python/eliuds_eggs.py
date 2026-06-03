def egg_count(display_count: int) -> int:
    count = 0
    
    while display_count > 0:
        # brian kernighanan's algorithm
        display_count &= (display_count - 1)
        count += 1
        
    return count