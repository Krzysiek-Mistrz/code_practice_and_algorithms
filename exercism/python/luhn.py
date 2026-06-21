class Luhn:
    def __init__(self, card_num):
        self._card_num = card_num

    def valid(self):
        clean_num = self._card_num.replace(" ", "")
        
        if len(clean_num) <= 1:
            return False
            
        if not clean_num.isdigit():
            return False
            
        total_sum = 0
        
        for idx, char in enumerate(reversed(clean_num)):
            digit = int(char)
            
            if idx % 2 == 1:
                digit *= 2
                if digit > 9:
                    digit -= 9
                    
            total_sum += digit
            
        return total_sum % 10 == 0