from cs50 import get_string
from sys import argv


# from @jrsacher's section example
class Dictionary:
    def __init__(self):
        self.words = set()

    def load(self, file):
        with open(file, "r") as d:
            for word in d:
                self.words.add(word.strip())
        return True
        
    def check(self, word):
        if word.lower() in self.words:
            return "*"*len(word)
        else:
            return word


def main():
    if len(argv) != 2:
        print("Usage:  python bleep.py dictionary")
        exit(1)
    
    d = Dictionary()
    d_loaded = d.load(argv[1])
    
    if not d_loaded: 
        print("Could not load $dictionary.")
        exit(1)
    
    message = get_string("What would you like to censor?\n")
    message_clean = ""
    for word in message.split():
        message_clean += d.check(word) + " "
    print(f"{message_clean}")
        

if __name__ == "__main__":
    main()