def is_pangram(sentence):
    sentence = sentence.lower()
    found_letters = {char for char in sentence if char.isalpha()}
    
    return len(found_letters) == 26