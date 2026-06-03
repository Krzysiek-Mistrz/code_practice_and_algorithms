def saddle_points(matrix):
    if not matrix or not matrix[0]:
        return []
        
    row_length = len(matrix[0])
    
    for row in matrix:
        if len(row) != row_length:
            raise ValueError("irregular matrix")
            
    num_rows = len(matrix)
    num_cols = row_length
    results = []
    
    for r in range(num_rows):
        for c in range(num_cols):
            current_tree = matrix[r][c]
            is_max_in_row = all(current_tree >= matrix[r][i] for i in range(num_cols))
            is_min_in_col = all(current_tree <= matrix[i][c] for i in range(num_rows))
            
            if is_max_in_row and is_min_in_col:
                results.append({"row": r + 1, "column": c + 1})
                
    return results