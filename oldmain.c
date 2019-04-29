/* EENG1003 Programming Assignment 1, Oliver Teiwsen
 * Text encryption/decryption using rotation cipher, and substitution cipher
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
 *  in the file.n
 * 
 * - improve on substitution cipher
 *
 * -tidy up code into functions for rotational encryption/decryption,
 *  and substitution encryption/decryption
 *
 */

#include <stdio.h>
// sub and rotation cipher below, attempting a menu system etc now
int main(){
    
    //function prototypes  return_type name(arguments);
    int getRotKey(void);
    void rotCiph(int key);//rotational cipher function prototype
    void rotDeciphKey(int key);//rotational decipher with key function prototype
   // int rotDeciphNoKey(void);//rotational decipher without key function prototype
   // char getSubKey(void);
   // void subCiph(char key);//substitution cipher function prototype
   // void subDeciphKey(char key);//substitution decipher with key function prototype
   // char subDeciphNoKey(void);//substitution cipher function prototype
    
    
    //initialise main variables;
    //int i = 0;
    int progSelection1;
    int progSelection2;
    //int progSelection3;
    int rotKey;
    char subKey;
    
    
    while((progSelection1!=1)&&(progSelection1!=2)){
        printf("Enter an integer for one of the following options:\n  1: Cipher message\n  2: Decipher message\n");
        scanf("%d", &progSelection1);
        if((progSelection1!=1)&&(progSelection1!=2)){
            printf("\n\nInvalid input, try again.\n");
        }
        
    }
    
    
    if(progSelection1 == 1){// Cipher
       printf("\n*****\nCipher message selected.\n");
       while((progSelection2!=1)&&(progSelection2!=2)){
          printf("Enter an integer for one of the following options:\n  1: Rotation cipher with key\n  2: Substitution cipher with key\n");
          scanf("%d", &progSelection2);
          if((progSelection2!=1)&&(progSelection2!=2)){
             printf("\n\nInvalid input, try again.\n");
          }
       }
       if(progSelection2 == 1){
          rotKey = getRotKey();
          rotCiph(rotKey);
          
       }
       if(progSelection2 == 2){
           //subKey = getSubKey();
           //subCiph(subKey);
           //Call SubCiph Function, hopefully running its own while loop
           //does it need to return anything?
       }

       // once the above code is done, the program should skip the remaining code as progSelection is 1,  
       // maybe print from file to prove the cipher worked
    }
    
    if(progSelection1 == 2){// Decipher
       printf("\n*****\nDecipher message selected.\n");
       while((progSelection2!=1)&&(progSelection2!=2)&&(progSelection2!=3)&&(progSelection2!=4)){
          printf("Enter an integer for one of the following options:\n  1: Rotation decipher with key\n  2: Rotation decipher without key\n  3: Substitution decipher with key\n  4: Substitution decipher without key\n");
          scanf("%d", &progSelection2);
          if((progSelection2 < 1)||(progSelection2 > 4)){
             printf("\n\nInvalid input, try again.\n");
          }
       }
       //****do a case statement here to demonstrate how it is used
       if(progSelection2 == 1){
           //RotDeciphKey
       }
       if(progSelection2 == 2){
           //RotDeciphNoKey
       }
       if(progSelection2 == 3){
           //SubDeciphKey
       }
       if(progSelection2 == 4){
           //SubDeciphNoKey
       }
        
    }
    printf("\n\nEND\n");
    
}

/*void rotCiph(void){
    //1. get message to cipher (file I/O later) maybe first because getting a whole line is a pain
    //2. ask for key, or generate random key
    //3. cipher message, (file I/O later)
    //4. give confirmation, and key.
    
    char message[50];
    int key;
    //starting with direct input of message
    printf("Enter the message to be decrypted:\n");
    //scanf("%s", &message);
    //scanf("%[^\n]s", message); <-- doesn't work, maybe getline() or something?
    printf("Enter the desired integer key to be used as the cipher key (range 1-25):\n");
    scanf("%d", &key);
    
    int i; // indexing integer for scanning/printing the characters from Test_input2 file
    for (i = 0; i <= 50; i++){ // for loop scans and prints the letters of the file one at a time
      //letter = test[i]);
      
      if((message[i]>=65)&&(message[i]<=90)){// checks if the character read is an alphabet character in the A-Z range,
                                        // only adds 1 if it is, then moves onto printing.
      
         message[i] = message[i]+key; // this adds the value if key to the ascii value of each letter before printing.
                                                            
         if(message[i]>90){
            message[i] = message[i]-26;
         }                     
      }
      
      if((message[i]>=97)&&(message[i]<=122)){//same as above if statement, but for a-z range
         message[i] = message[i]-32;  // the commented-out code above was pushing letters in the a-z range to strange values,
         message[i] = message[i]+key; // these few lines first converts letters in the a-z range to A-Z, by subtracting 32 
                                // then adds the key before converting back to the a-z range by re-adding 32.
         if(message[i]>90){
            message[i] = message[i]-26;
         }
         message[i] = message[i]+32;
         
      }
      printf("%c", message[i]);
                 
  }
  return 0;
    
}
*/

int getRotKey(void){
   int key;
   FILE *keyPointer = fopen("rotCiphKey.txt","r");
   
   if (keyPointer != NULL){
       fscanf(keyPointer,"%d", &key);
       fclose(keyPointer);
   }else{
      printf("Key file empty or missing!\nMessage cipher failed.\n");
   }
   
   return key;
}



void rotCiph(int key){
   //takes no argument but reads cipher key from rotCiphKey.txt ***make this***
   //then ciphers text contained in rotationCipher.txt
   // might not need to return anything, if it doesn't maybe just change to
   // int subCiph (void) or void subCyph(void)
   char message[1000];
   int i;
   for (i = 0; i == 1000; i++){
      message[i] = "~";
   }
   i = 0;
   char name = 
    
   FILE *cipher = fopen("rotationCipher.txt", "r");
   while (!feof(cipher)){
      fscanf(cipher, "%c", &message[i]);
      i++;        
   }
   i = 0;
   fclose(cipher);
   
   for (i = 0; i <= 1000; i++){ // for loop scans and prints the letters of the file one at a time
      if(message[i]!=126){
         if((message[i]>=65)&&(message[i]<=90)){// checks if the character read is an alphabet character in the A-Z range,
            message[i] = message[i]+key; // this adds the value if key to the ascii value of each letter before printing.
         
            if(message[i]>90){
               message[i] = message[i]-26;
            }                     
         }
      
         if((message[i]>=97)&&(message[i]<=122)){//same as above if statement, but for a-z range
            message[i] = message[i]-32;  // the commented-out code above was pushing letters in the a-z range to strange values,
            message[i] = message[i]+key; // these few lines first converts letters in the a-z range to A-Z, by subtracting 32 
                                // then adds the key before converting back to the a-z range by re-adding 32.
            if(message[i]>90){
              message[i] = message[i]-26;
            }
            message[i] = message[i]+32;
         
         }
         printf("%c", message[i]);
                 
      }
   }
   
   while(i<=1000){
      printf("%c", message[i]);
      i++;
   }
   
   FILE *ciphered = fopen("rotationCipher.txt", "w");
   fprintf(ciphered,"%s",message);
   fclose(ciphered);
}


void rotDeciphKey(int key){
   //takes no argument but reads cipher key from rotCiphKey.txt ***make this***
   //then ciphers text contained in rotationCipher.txt
   // might not need to return anything, if it doesn't maybe just change to
   // int subCiph (void) or void subCyph(void)
   char message[1000];
   int i;
   for (i = 0; i == 1000; i++){
      message[i] = "~";
   }
   i = 0;
    
   FILE *decipher = fopen("rotationDecipher.txt", "r");
   while (!feof(decipher)){
      fscanf(decipher, "%c", &message[i]);
      i++;        
   }
   i = 0;
   fclose(decipher);
   key = (26 - key); // easy way to reuse the rotcyph code again without editing much
   //****************do key-26 or whatever it is (key + 26?)
   for (i = 0; i <= 1000; i++){ // for loop scans and prints the letters of the file one at a time
      if(message[i]!=126){
         if((message[i]>=65)&&(message[i]<=90)){// checks if the character read is an alphabet character in the A-Z range,
            message[i] = message[i]+key; // this adds the value if key to the ascii value of each letter before printing.
         
            if(message[i]>90){
               message[i] = message[i]-26;
            }                     
         }
      
         if((message[i]>=97)&&(message[i]<=122)){//same as above if statement, but for a-z range
            message[i] = message[i]-32;  // the commented-out code above was pushing letters in the a-z range to strange values,
            message[i] = message[i]+key; // these few lines first converts letters in the a-z range to A-Z, by subtracting 32 
                                // then adds the key before converting back to the a-z range by re-adding 32.
            if(message[i]>90){
              message[i] = message[i]-26;
            }
            message[i] = message[i]+32;
         
         }
         printf("%c", message[i]);
                 
      }
   }
   
   while(i<=1000){
      printf("%c", message[i]);
      i++;
   }
   
   FILE *deciphered = fopen("rotationDecipher.txt", "w");
   fprintf(deciphered,"%s",message);
   fclose(deciphered);
}

/*
int rotDeciphNoKey(void){
   //takes no argument, helps user decipher text contained in
   //rotationDecipher.txt, then overwrites the text in the same file??
   //then returns the key as an integer

}

void subCiph(char key){
   //takes no argument but reads cipher key from subCiphKey.txt ***make this***
   //then ciphers text contained in substitutionCipher.txt
   // might not need to return anything, if it doesn't maybe just change to
   // int subCiph (void) or void subCyph(void)
   // maybe returning keys would help in describing how functions work
    
}

void subDeciphKey(char key){
   // takes no argument, reads key from subDeciphKey.txt
   // then deciphers text contained in substitutionDecipher.txt

}

char subDeciphNoKey(void){
   // takes no argument, helps user to perform substitution decipher
   // on the text contained in substitutionDecipher.txt then overwrites
   // the text in the file.
   // then returns the decryption key as a char
    
}

*/

// original rotation cipher code at bottom, trying sub cipher now

int main(){

  
  char test[738]; // initialise array of char variables, with the same number of
                 // elements as the amount of characters in the Test_input2 file
  
  int i; // indexing integer for scanning/printing the characters from Test_input2 file
  int key = 19;// variable for the key for rotation cipher.
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

