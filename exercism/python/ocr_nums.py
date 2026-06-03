def convert(input_grid):
    if len(input_grid) % 4 != 0:
        raise ValueError("Number of input lines is not a multiple of four")
    
    if any(len(line) % 3 != 0 for line in input_grid):
        raise ValueError("Number of input columns is not a multiple of three")

    digits_map = {
        (" _ ", "| |", "|_|", "   "): "0",
        ("   ", "  |", "  |", "   "): "1",
        (" _ ", " _|", "|_ ", "   "): "2",
        (" _ ", " _|", " _|", "   "): "3",
        ("   ", "|_|", "  |", "   "): "4",
        (" _ ", "|_ ", " _|", "   "): "5",
        (" _ ", "|_ ", "|_|", "   "): "6",
        (" _ ", "  |", "  |", "   "): "7",
        (" _ ", "|_|", "|_|", "   "): "8",
        (" _ ", "|_|", " _|", "   "): "9",
    }
    
    output_rows = []
    
    for r in range(0, len(input_grid), 4):
        row_digits = []
        line_length = len(input_grid[r])
        
        for c in range(0, line_length, 3):
            cell = (
                input_grid[r][c:c+3],
                input_grid[r+1][c:c+3],
                input_grid[r+2][c:c+3],
                input_grid[r+3][c:c+3]
            )
            row_digits.append(digits_map.get(cell, "?"))
            
        output_rows.append("".join(row_digits))
        
    return ",".join(output_rows)