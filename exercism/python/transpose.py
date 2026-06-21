def transpose(text):
    if not text:
        return ""
        
    lines = text.split("\n")
    max_len = max(len(line) for line in lines)
    result_columns = [[] for _ in range(max_len)]
    
    for r_idx, line in enumerate(lines):
        for c_idx in range(max_len):
            if c_idx < len(line):
                result_columns[c_idx].append(line[c_idx])
            else:
                if any(c_idx < len(future_line) for future_line in lines[r_idx + 1:]):
                    result_columns[c_idx].append(" ")
                    
    return "\n".join("".join(col) for col in result_columns)