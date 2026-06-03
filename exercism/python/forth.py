class StackUnderflowError(Exception):
    def __init__(self, message):
        self.message = message


def evaluate(input_data):
    stack = []
    user_words = {}

    for line in input_data:
        tokens = line.upper().split()
        if not tokens:
            continue

        if tokens[0] == ":":
            if tokens[-1] != ";":
                raise ValueError("Macro definition missing a semicolon")
            
            word_name = tokens[1]
            
            # Zmiana komunikatu na "illegal operation", którego żądają testy
            if word_name.isdigit() or (word_name.startswith("-") and word_name[1:].isdigit()):
                raise ValueError("illegal operation")
            
            definition = tokens[2:-1]
            
            resolved_definition = []
            for t in definition:
                if t in user_words:
                    resolved_definition.extend(user_words[t])
                else:
                    resolved_definition.append(t)
            
            user_words[word_name] = resolved_definition
            continue

        expanded_tokens = []
        for token in tokens:
            if token in user_words:
                expanded_tokens.extend(user_words[token])
            else:
                expanded_tokens.append(token)

        for token in expanded_tokens:
            if token.isdigit() or (token.startswith("-") and token[1:].isdigit()):
                stack.append(int(token))
                
            elif token in ("+", "-", "*", "/"):
                if len(stack) < 2:
                    raise StackUnderflowError("Insufficient number of items in stack")
                b = stack.pop()
                a = stack.pop()
                
                if token == "+": stack.append(a + b)
                elif token == "-": stack.append(a - b)
                elif token == "*": stack.append(a * b)
                elif token == "/":
                    if b == 0:
                        raise ZeroDivisionError("divide by zero")
                    stack.append(int(a / b))
                    
            elif token == "DUP":
                if len(stack) < 1:
                    raise StackUnderflowError("Insufficient number of items in stack")
                stack.append(stack[-1])
                
            elif token == "DROP":
                if len(stack) < 1:
                    raise StackUnderflowError("Insufficient number of items in stack")
                stack.pop()
                
            elif token == "SWAP":
                if len(stack) < 2:
                    raise StackUnderflowError("Insufficient number of items in stack")
                stack[-1], stack[-2] = stack[-2], stack[-1]
                
            elif token == "OVER":
                if len(stack) < 2:
                    raise StackUnderflowError("Insufficient number of items in stack")
                stack.append(stack[-2])
                
            else:
                raise ValueError("undefined operation")

    return stack