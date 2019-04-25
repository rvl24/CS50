# Omega Directive

## Questions

6.1. Selection sort is in Ω(n^2) because, even if the list starts sorted, on each 
     iteration the algorithm gets the next value along and compares it to every other 
     value in the unsorted portion, to make sure that none are smaller, so regardless 
     of order it takes Ω(n^2). 

6.2. Merge sort, similar to selection sort, goes through the same procedure 
     regardless of the starting state of the list--all the comparisons happen evey 
     time. 

6.3. Since strings are really arrays of characters, strlen is actually having to go 
     through an array one element at a time until it finds the "\n" at the end of the 
     string, so the amount of time it takes is directly proportional to the length 
     of the string. 

6.4. The length of Python built-ins like lists is stored sort of as part of the 
     structure itself, so len() just has to go get that pre-stored value rather than
     calculate it. 

6.5. There are a limited number of ASCII codes which correspond to uppercase letters;
     all isupper has to do is check whether the char being evaluated has any of those
     codes. So the lookup time is probably the total number of uppercase letters--26--
     regardless of the char entered. 

## Debrief

a. <https://www.geeksforgeeks.org/selection-sort/>,
   <https://www.youtube.com/watch?v=Ns7tGNbtvV4>
   <https://www.reddit.com/r/learnpython/comments/752zbp/why_is_the_complexity_of_lenlist_o1/>

b. 10,5,5,5,5
