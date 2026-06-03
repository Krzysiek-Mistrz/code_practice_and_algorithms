import re
from collections import Counter

def count_words(sentence):
    sentence = sentence.lower()
    words = re.findall(r"[a-z0-9]+(?:'[a-z0-9]+)?", sentence)
    
    return dict(Counter(words))