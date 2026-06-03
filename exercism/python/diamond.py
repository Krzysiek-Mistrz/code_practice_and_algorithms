def rows(letter):
    distance = ord(letter) - ord('A')
    size = 2 * distance + 1
    diamond_rows = []

    for i in range(distance + 1):
        current_char = chr(ord('A') + i)
        row = [' '] * size
        left_pos = distance - i
        right_pos = distance + i
        row[left_pos] = current_char
        row[right_pos] = current_char
        diamond_rows.append("".join(row))

    return diamond_rows + diamond_rows[:-1][::-1]