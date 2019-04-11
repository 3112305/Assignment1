/* EENG1003 Programming Assignment 1, Oliver Teiwsen
 * Text encryption/decryption using rotation cypher, and substitution cypher
 * 
 * work in progress, a lot of these lines of code will be put into
 * seperate functions to make the program flow easier to read.
 *
 * currently can read a line of text with a known amount of characters from a
 * file through the run command, and add an integer value from a hard coded key
 *
 * To Do:
 * -implement ability for -ve value rotation keys, ie. reverse rotation
 * -implement ability for large value keys, converting them back within range
 *  of 0 to 26
 * -implement proper file i/o, including reading to end of file rather than
 *  having to specify the length of the array to be the amount of characters
 *  in the file.
 * 
 * -implement substitution cypher, which directly maps one letter to another 
 *  rather than adding ascii values
 * -tidy up code into functions for rotational encryption/decryption,
 *  and substitution encryption/decryption
 *
 */

#include <stdio.h>
// original rotation cypher code at bottom, trying sub cypher now

int main(){

  char key[26] = {'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A'};
  char test[27]; // initialise array of char variables, with the same number of
                 // elements as the amount of characters in the Test_input2 file
  
  int i; // indexing integer for scanning/printing the characters from Test_input2 file
  int k; // indexing integer for key increments
  int x;
  //new key will be an array of 26 letters, need to turn test[i] into the key[i],
  //maybe with a 27 case switch statement?? probably easier ways...
  
  //int key = 19;// variable for the key for rotation cypher.
  //int key = 19;//after pasting the key = 7 encrypted message into the Test_input2 file, this key = 19 decrypts it.
  
  
  for (i = 0; i <= 27; i++){ // for loop scans and prints the letters of the file one at a time
      scanf("%c", &test[i]);
      
      
      if((test[i]>=97)&&(test[i]<=122)){//convert any lower case to upper case first to save fucking around with code.
         test[i] = test[i]-32;
      }
      
      if((test[i]>=65)&&(test[i]<=90)){// checks if the character read is an alphabet character in the A-Z range,
                                       // skips non-alphabet characters 
         for(k=65;k<=90;k++){
             if (test[i]==k){        // this should check through the alphabet to find what letter is in test[i]
                x = (int)k;
                x = x-65;
                
 //falling down here//k=k-65;           // then it redefines k to be in the range of the key array
                
             //    test[i] = key[k]; // then it reassignes the letter to its key letter.
                printf("%c",key[x]);
             } 
             
         }
//         printf(".");
      }
      
      
      printf("%c", test[i]);
                 
  }
  
  return 0;
}




/*
int main(){

  
  char test[738]; // initialise array of char variables, with the same number of
                 // elements as the amount of characters in the Test_input2 file
  
  int i; // indexing integer for scanning/printing the characters from Test_input2 file
  int key = 19;// variable for the key for rotation cypher.
  //int key = 19;//after pasting the key = 7 encrypted message into the Test_input2 file, this key = 19 decrypts it.
  
  
  for (i = 0; i <= 738; i++){ // for loop scans and prints the letters of the file one at a time
      scanf("%c", &test[i]);
      
      if((test[i]>=65)&&(test[i]<=90)){// checks if the character read is an alphabet character in the A-Z range,
                                        // only adds 1 if it is, then moves onto printing.
      
         test[i] = test[i]+key; // this adds the value if key to the ascii value of each letter before printing.
                                                            
         if(test[i]>90){
            test[i] = test[i]-26;
         }                     
      }
      
      if((test[i]>=97)&&(test[i]<=122)){//same as above if statement, but for a-z range
         //test[i] = test[i]+key;
         //if(test[i]>122){
         //   test[i] = test[i]-26; 
         //}
         test[i] = test[i]-32;  // the commented-out code above was pushing letters in the a-z range to strange values,
         test[i] = test[i]+key; // these few lines first converts letters in the a-z range to A-Z, by subtracting 32 
                                // then adds the key before converting back to the a-z range by re-adding 32.
         if(test[i]>90){
            test[i] = test[i]-26;
         }
         test[i] = test[i]+32;
         
      }
      printf("%c", test[i]);
                 
  }
  
  return 0;
}
*/
