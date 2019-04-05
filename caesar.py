from sys import argv
from cs50 import get_string

l_alphabet = 26


def main(argv):
    if len(argv) != 2 or not argv[1].isdigit():
        print("Usage: python caesar.py k")
        return 1
       
    plaintext = get_string("plaintext: ")
    key = int(argv[1])
    ciphertext = ""
    for character in plaintext:
        if character.isalpha():
            if character.isupper():
                ciphertext += chr(ord("A") + (ord(character) - ord("A") + key) % l_alphabet)
            elif character.islower:
                ciphertext += chr(ord("a") + (ord(character) - ord("a") + key) % l_alphabet)
        else:
            ciphertext += character
    print(f"ciphertext: {ciphertext}")        


if __name__ == "__main__":
    main(argv)