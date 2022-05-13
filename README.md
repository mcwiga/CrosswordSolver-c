# CrosswordSolver-c
A crossword solver

This program was designed to help solve crosswords. It takes an input string, clue, and stores it in an array
It will then check this array against some Dictionary and check for matches within that dictionary.

It will match words based firstly on length of the word before then considering whether individual characters
match up. It will match these characters regardless of capitalization and the charcter ? is used to denote
any possible character.

Functions included in this are :
        - searchClue() which takes a pointer to File and an array clue. It then iterates line by line through our file
        stores the number of lines, the length and value of the longest word, and iterates through the Match() function
        reporting any matches to our clue.
        
        - Match() takes 2 arrays, Guess[] and clue[] as input. It then checks character by character the clue we entered
        against all the elements of our Guess[] array. If at any point the characters dont match, both as
        lower and upper case character and the character in clue is not a question mark we discount this
        word as being a possible match.
