// game.cpp
// Hangman game illustrates string library functions, 
// character arrays, arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Prototype. we'll define this below.
int processGuess(char* word, const char* targetWord, char guess);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s
const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn", 
                          "science", "engineer"};

const int numWords = 10;

int main()
{
  srand(time(0));
  char guess;
  bool wordGuessed = false;
  int numTurns = 10;
  

  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];

  // More initialization code as needed
  char word[80];  // a blank array to use to build up the answer
                  // It should be initialized with *'s and then
                  //  change them to the actual letters when the 
                  //  user guesses the letter
  //initialize the array to * and ' '
  for (int i = 0; i< strlen(targetWord) ; i++)
  {
    word[i] = '*';
    for (int i = strlen(targetWord) + 1; i<81; i++)
    {
      word[i] = ' ';
    }
  }
 
  
  // guessing loop
  while (wordGuessed == false)
  {
   cout << "Current word: " << word << endl;
   cout << numTurns << " remain... Enter a letter to guess: " << endl; 
   cin >> guess; 
   if (processGuess(word, targetWord, guess) == 0)
   {
     numTurns--;
   }
   
    
   //check if word has been guessed
   if ((strcmp(targetWord, word)) == 0 )
   {
     cout << "The word was: "<< targetWord << ". You win!" << endl;
     wordGuessed == true;
     break;
   }
    //check if out of numTurns 
   if (numTurns < 1)
   {
     cout << "Too many turns...You lose!" << endl;
     break;
   }

  }
  return 0;
}

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char* word, const char* targetWord, char guess)
{
    int count = 0;
    for (int i = 0; i < strlen(targetWord); i++)
    {
      if (targetWord[i] == guess)
      {
        word[i]= targetWord[i];
        count++;
      }
    }
    return count;
}