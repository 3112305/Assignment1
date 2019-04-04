#include <stdio.h>

int main(){

  
  char test[41]; // initialise array of char variables, with the same number of
                 // elements as the amount of characters in the Test_input2 file
  
  int i; // indexing integer for scanning/printing the characters from Test_input2 file
  int key = 7;// variable for the key for rotation cypher.
  //int key = 19;//after pasting the key = 7 encrypted message into the Test_input2 file, this key = 19 decrypts it.
  
  int astest;//~~~~~for debugging a-z range
   
  
  for (i = 0; i <= 41; i++){ // for loop scans and prints the letters of the file one at a time
      scanf("%c", &test[i]);
      
      if((test[i]>=65)&&(test[i]<=90)){// checks if the character read is an alphabet character in the A-Z range,
                                        // only adds 1 if it is, then moves onto printing.
      
         test[i] = test[i]+key; // this adds the value if key to the ascii value of each letter before printing.
                                                            
         if(test[i]>90){
            test[i] = test[i]-26;
         }                     
      }
      
      if((test[i]>=97)&&(test[i]<=122)){//same as above if statement, but for a-z range
         test[i] = test[i]+key;
         if(test[i]>122){
            test[i] = test[i]-26;
         }   
      }
      astest = (int)test[i];
      printf("%c", test[i]);
      
      printf("%d", astest);//~~~~~for debugging a-z range
      
  }
  
  return 0;
}
