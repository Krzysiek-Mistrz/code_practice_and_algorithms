def proverb(*args, qualifier=None):
    if not args:
        return []
        
    lines = []
    
    for i in range(len(args) - 1):
        lines.append(f"For want of a {args[i]} the {args[i+1]} was lost.")
        
    first_item = f"{qualifier} {args[0]}" if qualifier else args[0]
    lines.append(f"And all for the want of a {first_item}.")
    
    return lines