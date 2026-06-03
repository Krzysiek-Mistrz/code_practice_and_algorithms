def encode(numbers):
    encoded_bytes = []
    
    for number in numbers:
        if number == 0:
            encoded_bytes.append(0)
            continue
            
        current_number_bytes = []
        is_first_byte = True
        
        while number > 0:
            seven_bits = number & 0x7F
            
            if not is_first_byte:
                seven_bits |= 0x80
                
            current_number_bytes.append(seven_bits)
            is_first_byte = False
            number >>= 7
            
        encoded_bytes.extend(reversed(current_number_bytes))
        
    return encoded_bytes


def decode(bytes_):
    if not bytes_:
        return []
        
    if bytes_[-1] & 0x80 != 0:
        raise ValueError("incomplete sequence")
        
    decoded_numbers = []
    current_value = 0
    
    for byte in bytes_:
        current_value = (current_value << 7) | (byte & 0x7F)
        
        if byte & 0x80 == 0:
            decoded_numbers.append(current_value)
            current_value = 0
            
    return decoded_numbers