def recite(start_verse, end_verse):
    animals = ["fly", "spider", "bird", "cat", "dog", "goat", "cow", "horse"]
    comments = {
        "spider": "It wriggled and jiggled and tickled inside her.",
        "bird": "How absurd to swallow a bird!",
        "cat": "Imagine that, to swallow a cat!",
        "dog": "What a hog, to swallow a dog!",
        "goat": "Just opened her throat and swallowed a goat!",
        "cow": "I don't know how she swallowed a cow!",
    }
    spider_modifier = "spider that wriggled and jiggled and tickled inside her."
    result = []
    
    for v in range(start_verse, end_verse + 1):
        idx = v - 1
        current_animal = animals[idx]
        verse_lines = [f"I know an old lady who swallowed a {current_animal}."]
        
        if current_animal == "horse":
            verse_lines.append("She's dead, of course!")
            result.extend(verse_lines)
            if v < end_verse:
                result.append("")
            continue
            
        if current_animal in comments:
            verse_lines.append(comments[current_animal])
            
        if idx > 0:
            for i in range(idx, 0, -1):
                predator = animals[i]
                prey = animals[i-1]
                
                if prey == "spider":
                    verse_lines.append(f"She swallowed the {predator} to catch the {spider_modifier}")
                else:
                    verse_lines.append(f"She swallowed the {predator} to catch the {prey}.")
                    
        verse_lines.append("I don't know why she swallowed the fly. Perhaps she'll die.")
        result.extend(verse_lines)
        
        if v < end_verse:
            result.append("")
            
    return result