#include <stdio.h>

int main(){

  
  char test[41]; // initialise array of char variables, with the same number of
                 // elements as the amount of characters in the Test_input2 file
  
  int i; // indexing integer for scanning/printing the characters from Test_input2 file
    
   
  
  for (i = 0; i <= 41; i++){ // for loop scans and prints the letters of the file one at a time
      scanf("%c", &test[i]);
      
      if((test[i]>=65)&&(test[i]<=90)){// checks if the character read is an alphabet character,
                                        // only adds 1 if it is, then moves onto printing.
      
         test[i] = test[i]+7; // this adds 7 to the ascii value of each letter before printing.
                              // the number 7 would be used as the key of a rotation cypher,
                              // and could be replaced with a variable eg... int cypherKey = 1;
                              
         if(test[i]>90){
            test[i] = test[i]-26;
         }                     
      }
      
      if((test[i]>=97)&&(test[i]<=122)){//same as above if statement, but for A-Z range
         test[i] = test[i]+7;
         
         if(test[i]>122){
            test[i] = test[i]-26;
         }   
      }

      printf("%c", test[i]);
  }
  
  return 0;
}
