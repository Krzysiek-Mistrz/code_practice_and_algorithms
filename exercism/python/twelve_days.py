def recite(start_verse, end_verse):
    days = [
        "first", "second", "third", "fourth", "fifth", "sixth",
        "seventh", "eighth", "ninth", "tenth", "eleventh", "twelfth"
    ]
    
    gifts = [
        "a Partridge in a Pear Tree.",
        "two Turtle Doves",
        "three French Hens",
        "four Calling Birds",
        "five Gold Rings",
        "six Geese-a-Laying",
        "seven Swans-a-Swimming",
        "eight Maids-a-Milking",
        "nine Ladies Dancing",
        "ten Lords-a-Leaping",
        "eleven Pipers Piping",
        "twelve Drummers Drumming"
    ]
    
    result = []
    
    for v in range(start_verse, end_verse + 1):
        idx = v - 1
        verse_str = f"On the {days[idx]} day of Christmas my true love gave to me: "
        
        if v == 1:
            verse_str += gifts[0]
        else:
            for i in range(idx, 0, -1):
                verse_str += gifts[i] + ", "
            verse_str += "and " + gifts[0]
            
        result.append(verse_str)
        
    return result