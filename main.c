#include <stdio.h>

int main(){

  
  char test[14]; // initialise array of char variables, with the same number of
                 // elements as the amount of characters in the Test_input2 file
  
  int i; // indexing integer for scanning/printing the characters from Test_input2 file
    
   
  
  for (i = 0; i <= 14; i++){ // for loop scans and prints the letters of the file one at a time
      scanf("%c", &test[i]);
      test[i] = test[i]+1; // this adds 1 to the ascii value of each letter before printing.
                           // the number 1 would be used as the key of a rotation cypher,
                           // and could be replaced with a variable eg... int cypherKey = 1;
                           // An if statement could be used to check whether the character read is
                           // in the bounds of A-Z, a-z and not add any ascii value if it is a space
                           // or any other non alphabet character.
      printf("%c", test[i]);
  }
  
  return 0;
}
