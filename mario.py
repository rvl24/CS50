from cs50 import get_int

while True:
    h = get_int("Height: ")
    if 0 < h < 9:
        break
for i in range(h):
    print("{}{}{}{}".format(" "*(h-(i+1)), "#"*(i+1), "  ", "#"*(i+1)))