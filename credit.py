from cs50 import get_int

class Valid_Cards:
    def __init__(self, companies, starting_digits, number_lengths):
        self.companies = companies
        self.starting_digits = starting_digits
        self.number_lengths = number_lengths
        
valid = Valid_Cards(["AMEX","MASTERCARD","VISA"],["34","37","51","52","53","54","55", "4"], [15, 13, 16])


def main():
    s = str(get_int("Number: "))
    if not check_length(s) or not check_first(s) or not check_luhn(s):
        print("INVALID")
    else:
        if s[0] == "3":
            print("AMEX")
        elif s[0] == "4":
            print("VISA")
        else:
            print("MASTERCARD")
        
def check_first(n):
     return n[0] or n[0]+n[1] in valid.starting_digits
         

def check_length(n):
    return len(n) in valid.number_lengths

def check_luhn(n):
    digits = list(n)
    digits_reversed = digits[::-1]
    every_other_even = digits_reversed[0::2]
    every_other_odd = digits_reversed[1::2]
    odd_sum = sum(sum(divmod(int(digit), 10)) for digit in every_other_odd)
    even_sum = sum(int(digit) for digit in every_other_even)
    return odd_sum + even_sum

if __name__ == "__main__":
    main()