from cs50 import get_int


class Valid_Cards:
    def __init__(self, companies, starting_digits, number_lengths):
        self.companies = companies
        self.starting_digits = starting_digits
        self.number_lengths = number_lengths 
        
# Create object containing all info used to validate cards  


valid = Valid_Cards(["AMEX", "VISA", "MASTERCARD"], ["34", "37", "51", "52", "53", "54", "55", "4"], [15, 13, 16])


def main():
    s = str(get_int("Number: "))
    if not check_length(s) or not check_first(s) or not check_luhn(s):
        print("INVALID")
    else:
        if s[0] == "3":
            print(f"{valid.companies[0]}")
        elif s[0] == "4":
            print(f"{valid.companies[1]}")
        else:
            print(f"{valid.companies[2]}")
        
        
# Check that first two digits of input are valid  


def check_first(n):
    return n[0] or n[0]+n[1] in valid.starting_digits
         

# Check that length of input is valid


def check_length(n):
    return len(n) in valid.number_lengths

# Check checksum


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