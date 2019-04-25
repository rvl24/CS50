# Like Magic

## Questions

4.1. BM. 

4.2. %PDF. 

4.3. Any file could start with any collection of bytes, if some human made it that 
     way. The magic number is an indication to whatever program is using the file as 
     to how to process it, but it doesn't promise that the rest of the file contains any 
     particular information. Magic numbers could also be omitted from a file which is,
     in fact, of a certain type. I think they're more a convention aimed at convenience 
     than a necessary thing. 

4.4. f0=11110000, and e0=11100000. Each of the possible JPEG values is 111XXXXX. The 
     bitwise AND checks each bit of one number against each bit of the other, and
     returns 0 if the bits either do not match or are both 0, and 1 if both are 1. 
     The last four bits can be any combination of 0s and 1s, so they are compared against
     0 so that the result is always 0. The first three bits must be 1s, so they must be 
     compared against 1s. The fourth bit must be a zero, and the only way to check this is
     to compare against 1 to see if 0 is the result. Thus f is used to check that the first 
     four bits are e, and then the last four bits are compared to 0 because they can be whatever. 

4.5. Zamyla's code just does 1 comparison, whereas the logical OR code has to compare the fourth
     byte to sixteen things, one at a time. I imagine that the latter requires greater time and memory, 
     because each of those sixteen values has to be stored, and then pulled out, compared against, and put back. 

4.6. See `magic.c`.

## Debrief

a. <https://www.rapidtables.com/convert/number/hex-to-ascii.html>

b. 1,1,5,15,20
