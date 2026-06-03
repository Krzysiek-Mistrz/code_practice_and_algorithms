import string

def atbash_transform(text):
    alphabet = string.ascii_lowercase
    reversed_alphabet = alphabet[::-1]
    table = str.maketrans(alphabet, reversed_alphabet)
    clean_text = "".join(char.lower() for char in text if char.isalnum())
    
    return clean_text.translate(table)

def encode(plain_text):
    transformed = atbash_transform(plain_text)
    result = []
    
    for i in range(0, len(transformed), 5):
        result.append(transformed[i : i + 5])
    
    return " ".join(result)

def decode(ciphered_text):
    return atbash_transform(ciphered_text)