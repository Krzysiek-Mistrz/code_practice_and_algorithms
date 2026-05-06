def square(number):
    """Oblicza liczbę ziaren na konkretnym polu."""
    
    if not 1 <= number <= 64:
        raise ValueError("square must be between 1 and 64")
    
    return 2 ** (number - 1)


def total():
    """Oblicza sumę wszystkich ziaren na szachownicy (64 pola). ze wzoru na sume cg geometrycznego"""

    return (2 ** 64) - 1