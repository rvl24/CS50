import sys
from cs50 import get_string


def main():

    # Ensure proper usage
    if len(sys.argv) != 2 or not sys.argv[1].isdigit():
        exit("Usage: python slanted.py depth")
    depth = int(sys.argv[1])

    # Encrypt message
    message = get_string("Message: ")
    if len(message) >= depth:
        print("Slanted:", slant(message, depth))


def slant(message, depth):
    """Return an encrypted message slanted to provided depth"""
    slanted_rows = ["" for row in range(depth)]
    i = 0
    for character in message:
        slanted_rows[i] += character
        if i is depth-1:
            i = 0
        else:
            i += 1
    return ''.join(slanted_rows)


if __name__ == "__main__":
    main()
