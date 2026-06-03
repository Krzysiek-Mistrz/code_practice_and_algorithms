def annotate(garden):
    if not garden:
        return []
    
    rows = len(garden)
    cols = len(garden[0])
    
    if any(len(row) != cols for row in garden):
        raise ValueError("The board is invalid with current input.")

    result = []
    for r in range(rows):
        current_row = ""
        for c in range(cols):
            if garden[r][c] == '*':
                current_row += '*'
            elif garden[r][c] == ' ':
                count = count_flowers(garden, r, c, rows, cols)
                current_row += str(count) if count > 0 else ' '
            else:
                raise ValueError("The board is invalid with current input.")
        result.append(current_row)
        
    return result

def count_flowers(garden, r, c, rows, cols):
    flowers = 0
    
    for dr in range(-1, 2):
        for dc in range(-1, 2):
            if dr == 0 and dc == 0:
                continue
            
            nr, nc = r + dr, c + dc
            
            if 0 <= nr < rows and 0 <= nc < cols:
                if garden[nr][nc] == '*':
                    flowers += 1
                    
    return flowers