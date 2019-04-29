/* EENG1003 Programming Assignment 1, Oliver Teiwsen
 * Text encryption/decryption using rotation cipher, and substitution cipher
 * 
 * work in progress
 *
 *
 * To Do:
 *
 * - fix the no-key function decipher functions.
 * - clean up comments
 * - write this intro up nicer
 * - check rotation key on decipher, can't remember if I fixed it
 */

#include <stdio.h>

//function prototypes  return_type name(arguments);
char fileRead(char);  // function for reading message, pass filename and return contents of file
int getRotKey(void);  // gets key from file rotRyphKey.txt
char rotateKey(char, int);// rotational function with key, pass message and key, return rotated message
char rotateNoKey(char);// rotational function without key, pass message, return rotated message, write key to stdout
char getSubKey(void); // gets key from file subCiphKey.txt, returns key
char substKey(char, char);//substitution function, pass message, key, return ciphered message
char substNoKey(char);//substitution cipher function prototype
void fileWrite(char, char); // function for file writing, pass message and write file, no returns
char printMessage(char); // reads message file and prints contents send filename, return message

    
// sub and rotation cipher below, attempting a menu system etc now
int main(){
    //initialise main variables;
    //int i = 0;
    int progSelection1;
    int progSelection2;
    //int progSelection3;
    char filename;
    char message;
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
       
       
       //IF ROTATION CIPHER IS SELECTED
                    
       if(progSelection2 == 1){
          printf("\n*****\nRotation cipher message selected.\n");
          filename = "rotationCipher.txt";//set filename
          message = fileRead(filename);// run fileRead function to read messagefrom file
          rotKey = getRotKey(); // then get rotation key from file // run function to get the rotation key
          message = rotateKey(message,rotKey); // then rotate message with key
          fileWrite(filename, message); // then write rotated message to file
          printMessage(filename) // open and print contents of file to confirm
       }
       
       //IF SUBSTITUTION CIPHER IS SELECTED
       
       if(progSelection2 == 2){
          printf("\n*****\nSubstitution cipher message selected.\n");
          filename = "substitutionCipher.txt";//set filename
          message = fileRead(filename);// run fileRead function to read messagefrom file
          subKey = getSubKey(); // then get substitution key from file
          message = substKey(message,subKey); // then substitute message with key
          fileWrite(filename, message); // then write substituted message to file
          printMessage(filename) // open and print contents of file to confirm
       }

       // once the above code is done, the program should skip the remaining code as progSelection is 1,  
       // maybe print from file to prove the cipher worked
    }
    
    //IF DECIPHER IS SELECTED
    
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
       
       //IF ROTATION DECIPHER WITH KEY IS SELECTED
       if(progSelection2 == 1){
           //RotDeciphKey
          
          printf("\n*****\nRotation decipher with key selected.\n");
          
          filename = "rotationDecipher.txt";//set filename
          message = fileRead(filename);// run fileRead function to read messagefrom file
          
          rotKey = getRotKey(); // then get rotation key from file // run function to get the rotation key
/////////////VVVVVVVVVV????????
          rotKey = (26 + rotKey)// FIX MINUS WRAPAROUND what do you do here to fix it?? 
          message = rotateKey(message,rotKey); // then rotate message with key
          
          fileWrite(filename, message); // then write rotated message to file
          printMessage(filename) // open and print contents of file to confirm
       
       }
       
       //IF ROTATION DECIPHER WITHOUT KEY IS SELECTED
       
       if(progSelection2 == 2){
          //RotDeciphNoKey
          printf("\n*****\nRotation decipher without key selected.\n");
          
          filename = "rotationDecipher.txt";//set filename
          
          message = fileRead(filename);// run fileRead function to read messagefrom file
          message = rotateNoKey(message); // then rotate message with key
          
          fileWrite(filename, message); // then write rotated message to file
          printMessage(filename) // open and print contents of file to confirm
       
       }
       
       //IF SUBSTITUTION DECIPHER WITH KEY IS SELECTED
       
       if(progSelection2 == 3){
          //SubDeciphKey
          printf("\n*****\nSubstitution decipher with key selected.\n");
          
          filename = "subtitutionDecipher.txt";//set filename
          
          message = fileRead(filename);// run fileRead function to read message from file
          subKey = getSubKey(); // then get sub key from file // run function to get the rotation key
          message = substKey(message,subKey); // then rotate message with key
          
          fileWrite(filename, message); // then write rotated message to file
          printMessage(filename) // open and print contents of file to confirm
       
       }
       if(progSelection2 == 4){
           //SubDeciphNoKey
          printf("\n*****\nSubstitution decipher without key selected.\n");
          
          filename = "subtitutionDecipher.txt";//set filename
          
          message = fileRead(filename);// run fileRead function to read message from file
          message = substNoKey(message); // then rotate message with key
          
          fileWrite(filename, message); // then write rotated message to file
          printMessage(filename) // open and print contents of file to confirm
       
       }
        
    }
    printf("\n\nEND\n");
    
}

//function blocks

char fileRead(char filename){  // function for reading message, pass filename and return contents of file
   char message;
   int i = 0;
   
   FILE *messagePointer = fopen(filename,"r");
   
   while (!feof(messagePointer))
       fscanf(messagePointer,"%c", &message[i]);
       i++
   }
   
   fclose(messagePointer);
   
   return message;


}

int getRotKey(void){  // gets key from file rotRyphKey.txt
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

char rotateKey(char message, int key){// rotational function with key, pass message and key, return rotated message
   for (i = 0; i<=1000; i++){
      printf("%c", message[i]); 
   }
   printf("\n\n");
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
      }
   }   
}


char rotateNoKey(char message){...}// rotational function without key, pass message, return rotated message, write key to stdout
 // can use statistical analysis and ask user if it looks right,
 // bash at it with statistical keys until its right

char getSubKey(void){// gets key from file subCiphKey.txt, returns key
   char key;
   FILE *keyPointer = fopen("subCiphKey.txt","r");
   
   while (!feof(keypointer))
       fscanf(keyPointer,"%c", &key[i]);
       i++;
   }
   fclose(keyPointer);
   
   return key;
}

char substKey(char message, char key){//substitution function, pass message, key, return ciphered message
   //******messy subst key at bottom
   //
   // tidy it up and put it here
   //
   //
   // key array for substitution, if program finds an A, it will subst it with the [0] element of this array, B will become [1] element, and so on
  //              'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
  //char key[26] = {'k', 'e', 'i', 'D', 'u', 't', 'v', 'h', 'p', 's', 'n', 'c', 'f', 'a', 'm', 'w', 'g', 'd', 'S', 'T', 'x', 'y', 'b', 'r', 'o', 'l'};
  //char test[216]; // initialise array of char variables, with the same number of
                 // elements as the amount of characters in the Test_input2 file
  
  //have message and subst key at this point in char message and char key
  
  //most common words and letters
  char comWords[100] = {'the', 'be', 'to', 'of', 'and', 'a', 'in', 'that', 'have', 'I', 'it', 'for', 'not', 'on', 'with', 'he', 'as', 'you', 'do', 'at', 'this', 'but', 'his', 'by', 'from', 'they', 'we', 'say', 'her', 'she', 'or', 'an', 'will', 'my', 'one', 'all', 'would', 'there', 'their', 'what', 'so', 'up', 'out', 'if', 'about', 'who', 'get', 'which', 'go', 'me', 'when', 'make', 'can', 'like', 'time', 'no', 'just', 'him', 'know', 'take', 'people', 'into', 'year', 'your', 'good', 'some', 'could', 'them', 'see', 'other', 'than', 'then', 'now', 'look', 'only', 'come', 'its', 'over', 'think', 'also', 'back', 'after', 'use', 'two', 'how', 'our', 'work', 'first', 'well', 'way', 'even', 'new', 'want', 'because', 'any', 'these', 'give', 'day', 'most', 'us'};
  char comLetters[26] = {'e', 't', 'a', 'o', 'i', 'n', 's', 'h', 'r', 'd', 'l', 'c', 'u', 'm', 'w', 'f', 'g', 'y', 'p', 'b', 'v', 'k', 'j', 'x', 'q', 'z'};
  char countLetter[27];
  
  
  // count repeated letters(only) for message[i] ---> i = 0 to end
  // if letter is a, index a etc, print most common to check
  
  
  for(i=0, i<1000,i++){  // scan through each letter of the message
     while(j=0; j<=25; j++){ // check each letter against the list of common letters
         
        if(message[i]==comLetter[j]){
            countLetter[j] = countletter[j] + 1; counts how many times each letter appears
        }

     }
     if(message[i] == 32){ // 32 is ASCII space
         countLetter[26] = countLetter[26] + 1; // count spaces
     }
   
  
  }
  
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

char substNoKey(char message){//substitution cipher function prototype

   //most common words and letters
   char comWords[100] = {'the', 'be', 'to', 'of', 'and', 'a', 'in', 'that', 'have', 'I', 'it', 'for', 'not', 'on', 'with', 'he', 'as', 'you', 'do', 'at', 'this', 'but', 'his', 'by', 'from', 'they', 'we', 'say', 'her', 'she', 'or', 'an', 'will', 'my', 'one', 'all', 'would', 'there', 'their', 'what', 'so', 'up', 'out', 'if', 'about', 'who', 'get', 'which', 'go', 'me', 'when', 'make', 'can', 'like', 'time', 'no', 'just', 'him', 'know', 'take', 'people', 'into', 'year', 'your', 'good', 'some', 'could', 'them', 'see', 'other', 'than', 'then', 'now', 'look', 'only', 'come', 'its', 'over', 'think', 'also', 'back', 'after', 'use', 'two', 'how', 'our', 'work', 'first', 'well', 'way', 'even', 'new', 'want', 'because', 'any', 'these', 'give', 'day', 'most', 'us'};
   char comLetters[26] = {'e', 't', 'a', 'o', 'i', 'n', 's', 'h', 'r', 'd', 'l', 'c', 'u', 'm', 'w', 'f', 'g', 'y', 'p', 'b', 'v', 'k', 'j', 'x', 'q', 'z'}; 
   char countLetter[27];
  
  
  // count repeated letters(only) for message[i] ---> i = 0 to end
  // if letter is a, index a etc, print most common to check
  
  
   for(i=0, i<1000,i++){  // scan through each letter of the message
      while(j=0; j<=25; j++){ // check each letter against the list of common letters
         
         if(message[i]==comLetter[j]){
            countLetter[j] = countletter[j] + 1; counts how many times each letter appears
         }

      }
      if(message[i] == 32){ // 32 is ASCII space
          countLetter[26] = countLetter[26] + 1; // count spaces
      }
   
      printf("do i need to print anything here?\n");// print results, word count (ie space count + 1)
      
   }
   
   
   //*****do same for common words with pointers
   

   // using the letter count and the comLetters[] function 
   // now write a key into a file, and try decode.
   
   
   /////////technically this is a statistical analysis done

}

void fileWrite(char filename, char message){// function for file writing, pass me
   FILE *messagePointer = fopen(filename,"w");
   
   if (messagePointer != NULL){
       fprintf(messagePointer,"%s", message);
       fclose(messagePointer);
   }else{
      printf("Message file empty or missing!\n");
   }
   
}



//
char printMessage(char filename){
    
   char message;
   int i = 0;
   
   FILE *messagePointer = fopen(filename,"r");
   
   while (!feof(messagePointer))
       fscanf(messagePointer,"%c", &message[i]);
       printf("c", message[i]);
       i++;
       
   }
   
   fclose(messagePointer);
   
   printf("\n\n does this look right?\n");


    
}    


 





