#include <stdio.h>

int main(){

  
  char test[14]; // initialise array of char variables, with the same number of
                 // elements as the amount of characters in the Test_input2 file
  
  int i; // indexing integer for scanning/printing the characters from Test_input2 file
    
   
  
  for (i = 0; i <= 14; i++){ // for loop scans and prints the letters of the file one at a time
      scanf("%c", &test[i]);
      
      if(((test[i]>=65)&&(test[i]<=90))||((test[i]>=97)&&(test[i]<=122))){// checks if the character read is an alphabet character,
                                                                          // only adds 1 if it is, then moves onto printing.
      
          test[i] = test[i]+1; // this adds 1 to the ascii value of each letter before printing.
                               // the number 1 would be used as the key of a rotation cypher,
                               // and could be replaced with a variable eg... int cypherKey = 1;
                               // The next step would be to make it so that if any letter is used
                               // that gets pushed out of the a-z,A-Z boundary (eg z+1 = ???),
                               // that letter should wrap back around to the start of the alphabet.
      }

      printf("%c", test[i]);
  }
  
  return 0;
}
