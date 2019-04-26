# Complementary Questions

## Questions

1.1. 10000011. 

1.2. 11111101. 

1.3. A negative result of the sum of two positive numbers (the number of views so
     far plus one more) represented in 2's complement form is indicative of overflow. 
     Essentially, when numbers are represented in 2's complement form, the leftmost
     bit indicates whether a number is positive or negative (0 being positive and 1
     negative), and then the following bits are interpreted accordingly, based on the 
     sign of the number. When numbers are added, if the result is greater than the number of bits
     allocated to store it, the extraneous leftmost bits are lopped off. So in this case
     the first bit could appropriately identify the number as positive or negative, but 
     if it is not stored, and the second number indicates the opposite (which will be the 
     case with very positive or very negative numbers), then the 
     value is inappropriately interpreted as either positive or negative (the opposite
     of what it should be.)
     
     Boy, this stuff is hard to write out in words. 

1.4. It goes negative for the reason described above. Then it goes to 0 because, 
     when that huge number is doubled, suddenly the rightmost 16 bits of the result 
     are all 0, and since ints in c are only 16 bits long, those 0s are all that 
     are kept.

1.5. Essentially the same thing described above--a big number got truncated because 
     the program taking it in only expected it to be 16 bits long, when in fact it
     could have been as many as 64 bits. All the bits to the left of the first 16
     were lost, and so the number was not properly represented in the program taking
     it in. The number was bigger than anticipated because the programs controlling the 
     rocket were initially written for a slower rocket--presumably the number relied 
     somehow on the magnitude of the rocket's acceleration. 

## Debrief

a. <https://www.geeksforgeeks.org/1s-2s-complement-binary-number/>
   <https://en.wikipedia.org/wiki/Two%27s_complement>

b. 5,5,20,5,5,10
