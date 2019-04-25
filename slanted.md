# Complementary Questions

## Questions

7.1. A secure cipher is one which is difficult to crack without knowing the key. 
     A more complex or obscure key (one that is difficult to guess or obtain), 
     as well as a complex encoding system, make for a secure cipher. 

7.2. Caesar's cipher is not very insecure because it merely shifts each character 
     by a set amount, so the only information needed to crack the code is number. 
     Since alphabets are limited, the numbers available to shift by are also limited
     by the length of the alphabet (larger numbers would result in wrapping back
     around to the start of the alphabet). Khmer evidently has the longest alphabet
     of any language, at 74 characters, and even 74 possible keys wouldn't take a 
     computer long to try. Even if you didn't already know the message was encrypted
     with Caesar's chipher it would be trivial to test all the keys. 

7.3. Similarly, the number of possible rows for a phrase is relatively small, assuming 
     the phrase isn't too long. It wouldn;t take long to try all the possibilities. 

7.4. Slanting a message of n characters to a depth n would yeild the same message, 
     so the cipher would be not so much insecure as entirely ineffectual. 

7.5. Hashing a message would mean taking the message and using some hash function
     to produce a value that will be used as an index in a table. In the table at
     that index will be stored a pointer which points to the location of the actual 
     message. So unlike encrypting hashing doesn't actually alter the message; it 
     just generates a random, near-impossible-to-guess place to store it. 

7.6. See `slanted.py`.

## Debrief

a. <https://www.geeksforgeeks.org/hashing-set-1-introduction/>, 
   <https://www.nku.edu/~christensen/092hnr%20304%20section%209%20transposition.pdf>

b. 2,10,10,3,15,60
