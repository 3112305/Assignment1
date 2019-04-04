#include <stdio.h>

int main(){

  
  char test[14]; // initialise array of char variables, with the same number of
                 // elements as the amount of characters in the Test_input2 file
  
  int i; // indexing integer for scanning/printing the characters from Test_input2 file
    
   
  
  for (i = 0; i <= 14; i++){ // 
      scanf("%c", &test[i]);
      printf("%c", test[i]);
  }
  
  return 0;
}
