def answer(question):
    if not question.startswith("What is"):
        raise ValueError("unknown operation")

    content = question.removeprefix("What is").removesuffix("?").strip()
    
    if not content:
        raise ValueError("syntax error")

    content = content.replace("multiplied by", "multiplied")
    content = content.replace("divided by", "divided")
    
    tokens = content.split()
    
    try:
        result = int(tokens[0])
    except (ValueError, IndexError):
        raise ValueError("syntax error")

    i = 1
    
    while i < len(tokens):
        op = tokens[i]
        
        if op.lstrip('-').isdigit():
            raise ValueError("syntax error")

        valid_ops = ["plus", "minus", "multiplied", "divided"]
        if op not in valid_ops:
            raise ValueError("unknown operation")

        try:
            next_value = int(tokens[i + 1])
        except IndexError:
            raise ValueError("syntax error")
        except ValueError:
            raise ValueError("syntax error")

        if op == "plus":
            result += next_value
        elif op == "minus":
            result -= next_value
        elif op == "multiplied":
            result *= next_value
        elif op == "divided":
            result /= next_value
            
        i += 2

    return result