// CrossWordHelperV01.c: An app to help you solve crosswords
// For 1920-CS211 - Lab 3+4
// By:  Michael McGloin
// When: 15 Feb 2020
// Why:  Beat my friends at scrabble
// More: Contact M.MCGLOIN2@nuigalway.ie

/* This program was designed to help solve crosswords. It takes an input string, clue, and stores it in an array
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

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORDLENGTH 200   //The max word length we will allow
#define MAXMATCHENTRIES 32768   // The largest number of matches we will allow
int Match(char Guess[], char clue[]);

int searchClue(FILE *file, char *clue);
char wordlist[MAXMATCHENTRIES][MAXWORDLENGTH];
//start Main
int main(void){
    FILE* file;
    char FileName[30];
    char clue[35];
    int i;
    strcpy(FileName, "BigDictionary.txt");

    file=fopen(FileName, "r");
    if (file == NULL){
        printf("File did not open");
        exit(EXIT_FAILURE);
    }
      else{
        printf("File opened Successfully! \n");
      }

    printf("\n %40s"," Crossword");
    printf("\n---------------------------------------------------\n");
    printf("This is CrossWordHelperV01.2 - written for CS211 Lab 3+4\n");
    printf("To enter a crossword string, use ? to represent an unknown letter\n");
    printf("This will then be matched against a dictionary word. \n");
    printf("This version will match words regardless of capitalisation, match words of the same length and letters\n");

    printf("Enter a crossword string: ");
    scanf("%s", clue);
    int wordcnt=searchClue(file, clue);

    for( i=0;i<wordcnt;i++)
        printf("\n%s matches %s\n",wordlist[i],clue);

    fclose(file);
    return(0);
}



int Match(char *Guess, char *clue)

{
    unsigned int i;
    unsigned int lengthOfWord = strlen(Guess)-1;

    if (lengthOfWord != strlen(clue))
        return(0);

    for(i=0; i<lengthOfWord; i++){
        int asciiGuess = Guess[i];
        int asciiClue = clue[i];
        int asciiClueCapital = clue[i]+32;

        if (!(asciiClue==asciiGuess) && !(asciiClueCapital==asciiGuess) && !(clue[i]==63)){
                return(0);
            }
        }
    return(1);

  }



/*             Declaration of searchClue() Function                                                  */

int searchClue(FILE *file, char *clue)
{
    rewind(file);
    char word[MAXWORDLENGTH];
    char longestWord[MAXWORDLENGTH];
    int wordCounter = 0;
    int longestWordLength =0;
    int wordlistcount=0;


    //read line
    while(fgets(word,MAXWORDLENGTH,file)&& (wordlistcount<MAXMATCHENTRIES)){


        int wordlength=strlen(word);
        if(wordlength>longestWordLength){
            longestWordLength=wordlength;
            strcpy(longestWord, word);
        }

        if(Match(word, clue)){
            word[strlen(word)-1]='\0';
            strcpy(wordlist[wordlistcount],word);
            wordlistcount++;

        }
        wordCounter++;

    }

    longestWord[longestWordLength-1] = '\0'; //wanted to remove \n from longest word
    printf("\nNumber of Words is %d\n",wordCounter);
    printf("Longest Word is %s and is %d letters long\n",longestWord,longestWordLength-1);//Subtract one for overcounting a \n
    rewind(file);

    return(wordlistcount);
}



