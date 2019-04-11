/* EENG1003 Programming Assignment 1, Oliver Teiwsen
 * Text encryption/decryption using rotation cypher, and substitution cypher
 * ddd
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
 * - improve on substitution cypher
 *
 * -tidy up code into functions for rotational encryption/decryption,
 *  and substitution encryption/decryption
 *
 */

#include <stdio.h>
// sub and rotation cypher below, attempting a menu system etc now
int main(){
    
    //initialise main variables;
    int i = 0;
    int progSelection1;
    int progSelection2;
    //int progSelection3;
    
    
    while((progSelection1!=1)&&(progSelection1!=2)){
        printf("Enter an integer for one of the following options:\n  1: Cypher message\n  2: Decypher message\n");
        scanf("%d", &progSelection1);
        if((progSelection1!=1)&&(progSelection1!=2)){
            printf("\n\nInvalid input, try again.\n");
        }
    }
    
    if(progSelection1 == 1){// Cypher
       printf("\n*****\nCypher message selected.\n");
       while((progSelection2!=1)&&(progSelection2!=2)){
          printf("Enter an integer for one of the following options:\n  1: Rotation cypher with key\n  2: Substitution cypher with key\n");
          scanf("%d", &progSelection2);
          if((progSelection2!=1)&&(progSelection2!=2)){
             printf("\n\nInvalid input, try again.\n");
          }
       }

        
        
    }
    
    if(progSelection1 == 2){// Decypher
       printf("\n*****\nDecypher message selected.\n");
       while((progSelection2!=1)&&(progSelection2!=2)&&(progSelection2!=3)&&(progSelection2!=4)){
          printf("Enter an integer for one of the following options:\n  1: Rotation decypher with key\n  2: Rotation decypher without key\n  3: Rotation decypher with key\n  4: Rotation decypher without key\n");
          scanf("%d", &progSelection2);
          if((progSelection2!=1)&&(progSelection2!=2)){
             printf("\n\nInvalid input, try again.\n");
          }
       } 
        
    }
    printf("\n\nEND\n");
    
  /*  
    start:do{
        printf("Enter an integer for one of the following options:\n  1: Cypher\n  2: Decypher\n");
        scanf("%d", &progSelection);
        if((progSelection!=1)||(progSelection!=2)){
            goto start;
        }
        i++;
    }*/
    

}




// original rotation cypher code at bottom, trying sub cypher now
/*

int main(){
  // key array for substitution, if program finds an A, it will subst it with the [0] element of this array, B will become [1] element, and so on
  //              'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
  char key[26] = {'k', 'e', 'i', 'D', 'u', 't', 'v', 'h', 'p', 's', 'n', 'c', 'f', 'a', 'm', 'w', 'g', 'd', 'S', 'T', 'x', 'y', 'b', 'r', 'o', 'l'};
  char test[216]; // initialise array of char variables, with the same number of
                 // elements as the amount of characters in the Test_input2 file
  
  int i; // indexing integer for scanning/printing the characters from Test_input2 file
  int k; // indexing integer for letter identification
  int x; // integer for substituting letters assigned in the key
  
  for (i = 0; i <= 216; i++){ // for loop scans letter from input file, then applies substiution
      scanf("%c", &test[i]);

      if((test[i]>=97)&&(test[i]<=122)){//convert any lower case to upper case first to save fucking around with code.
         test[i] = test[i]-32;
      }
      
      if((test[i]>=65)&&(test[i]<=90)){// checks if the character read is an alphabet character in the A-Z range,
                                       // skips non-alphabet characters 
         for(k=65;k<=90;k++){
             if (test[i]==k){        
                x = k-65;
                printf("%c",key[x]);
             } 
         }
      }
      if((test[i]<65)||(test[i]>90)){ // prints non-alphabet characters
          printf("%c", test[i]);
      } 
      
      
      //printf("%c", test[i]);  
                 
  }
  
  return 0;
}

*/


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
