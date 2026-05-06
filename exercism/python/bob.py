def response(phrase):
    phrase = phrase.strip()
    is_silence = not phrase
    is_question = phrase.endswith("?")
    is_yelling = phrase.isupper()

    if is_silence:
        return "Fine. Be that way!"

    if is_yelling and is_question:
        return "Calm down, I know what I'm doing!"

    if is_yelling:
        return "Whoa, chill out!"

    if is_question:
        return "Sure."

    return "Whatever."
