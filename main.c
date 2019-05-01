/* EENG1003 Programming Assignment 1, Oliver Teiwsen
 * Text encryption/decryption using rotation cipher, and substitution cipher
 * 
 * work in progress
 *
 *
 * To Do:
 * - Update To Do list
 *
 *
 * - fix the no-key function decipher functions.
 * - clean up comments
 * - write this intro up nicer
 * - check rotation key on decipher, can't remember if I fixed it
 */

#include <stdio.h>

//function prototypes  return_type name(arguments);
void ciphRotate(void); 
void ciphSub(void);
void deciphRotKey(void);
void deciphRotNoKey(void);
void deciphSubKey(void);
//void deciphSubNoKey(void);
    
// sub and rotation cipher below, attempting a menu system etc now
int main(){
    //initialise main variables;
    //int i = 0;
    int progSelection1;
    int progSelection2;
    //int progSelection3;
    //char filename;
    //char message;
    //int rotKey;
    //char subKey;
    
    
    // Program User Menu Start
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
		  ciphRotate();
         
       }
       
       //IF SUBSTITUTION CIPHER IS SELECTED
       
       if(progSelection2 == 2){
          printf("\n*****\nSubstitution cipher message selected.\n");
		  ciphSub();
          
       }

       // once the above code is done, the program should skip the remaining code as progSelection is 1,  
       // maybe print from file to prove the cipher worked
    }
    
    //IF DECIPHER IS SELECTED
    
    if(progSelection1 == 2){// Continue Decipher Menu dialog
       printf("\n*****\nDecipher message selected.\n");
       while((progSelection2!=1)&&(progSelection2!=2)&&(progSelection2!=3)&&(progSelection2!=4)){
          printf("Enter an integer for one of the following options:\n  1: Rotation decipher with key\n  2: Rotation decipher without key\n  3: Substitution decipher with key\n  4: Substitution decipher without key\n");
          scanf("%d", &progSelection2);
          if((progSelection2 < 1)||(progSelection2 > 4)){
             printf("\n\nInvalid input, try again.\n");
          }
       }
       //****maybe do a case statement here to demonstrate how it is used
       
       //*************
       //IF ROTATION DECIPHER WITH KEY IS SELECTED
       //
       
       if(progSelection2 == 1){
          printf("\n*****\nRotation decipher with key selected.\n");
		  deciphRotKey();   // run rotation decipher
		  
       }
       //
       //IF ROTATION DECIPHER WITHOUT KEY IS SELECTED
       //
       if(progSelection2 == 2){
          printf("\n*****\nRotation decipher without key selected.\n");
		  deciphRotNoKey(); // run rotation decipher
		  
		  
       }
       
       //
       //IF SUBSTITUTION DECIPHER WITH KEY IS SELECTED
       //
       if(progSelection2 == 3){
           printf("\n*****\nSubstitution decipher with key selected.\n");
		  deciphSubKey();
		  
		  
       }
       
       //
       //IF SUBSTITUTION DECIPHER WITHOUT KEY IS SELECTED
       //
       if(progSelection2 == 4){
           printf("\n*****\nSubstitution decipher without key selected.\n");
		   //deciphSubNoKey();
       }	   

		         
    }
    
	
	printf("\n\nEND\n");
    
}


//function blocks
  
void ciphRotate(void){
   // *****************
   // open key file
   // read key from file
   // close key file
   //
   // open message file
   // read message from file
   // 
   // cipher using key
   // print ciphered message
   // write message to message file
   // close message file
   
   int key;
   FILE *keyPointer = fopen("rotCiphKey.txt","r"); // open key file
   
   if (keyPointer != NULL){
       fscanf(keyPointer,"%d", &key); // read key file
       //fclose(keyPointer);
       printf("Key is %d\n", key);
   }else{
      printf("Key file empty or missing!\nMessage cipher failed.\n");
   }
   
   fclose(keyPointer); // close key file
   
   
   //READ TEXT FROM MESSAGE FILE
   
   char message[1000];
   //int letter;
   int i;
   
   FILE *messagePointer;
   messagePointer = fopen("rotationCipher.txt","r");
   if(messagePointer != NULL){
      printf("Message:\n");
      if( fgets (message, 1000, messagePointer)!=NULL ) {
      /* writing content to stdout */
         puts(message);
      }
   
   }else{
       printf("File empty or missing");
   }
   
   fclose(messagePointer);
   
   
   
   //CIPHER USING KEY
   
   for (i = 0; i < 1000; i++){ // for loop scans and prints the letters of the file one at a time
      
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
         if(message[i] == 126){
             i = 1000;
         }
     
   }   
   //end cipher
   printf("Ciphered message:\n");
   for(i=0;i<1000;i++){
       printf("%c", message[i]);
       if(message[i] == 126){
           i = 1000;
       }
       
   }
   printf("\n");
}

	
void ciphSub(void){
   // *****************
   // open key file
      
   
   
   // read key from file
   // close key file
   // open message file
   // read message from file
   // 
   // cipher using key
   // print ciphered message
   // write message to message file
   // close message file
   //
   // etc
   
   char key[26];
   FILE *keyPointer = fopen("subCiphKey.txt","r"); // open key file
   
   if (keyPointer != NULL){
      printf("Key:\n");
      if( fgets (key, 27, keyPointer)!=NULL ) {
      
         puts(key);
      }
       
   }else{
      printf("Key file empty or missing!\nMessage cipher failed.\n");
   }
   
   fclose(keyPointer); // close key file
   
   
   //READ TEXT FROM MESSAGE FILE
   
   char message[1000];
   //int letter;
   int i;
   
   FILE *messagePointer;
   messagePointer = fopen("substitutionCipher.txt","r");
   if(messagePointer != NULL){
      printf("Message:\n");
      if( fgets (message, 1000, messagePointer)!=NULL ) {
      /* writing content to stdout */
         puts(message);
      }
   
   }else{
       printf("File empty or missing");
   }
   
   fclose(messagePointer);
   
   
   
   //CIPHER USING KEY
   
  int k; // indexing integer for letter identification
  int x; // integer for substituting letters assigned in the key
  
  for (i = 0; i < 1000; i++){ // for loop scans letter from input file, then applies substiution
      
      if((message[i]>=97)&&(message[i]<=122)){//convert any lower case to upper case first to save fucking around with code.
         message[i] = message[i]-32;
      }
      
      if((message[i]>=65)&&(message[i]<=90)){// checks if the character read is an alphabet character in the A-Z range,
                                       // skips non-alphabet characters 
         for(k=65;k<=90;k++){
             if (message[i]==k){        
                x = k-65;
                //printf("%c",key[x]);
                message[i] = key[x];
             } 
         }
      }
      if((message[i]<65)||(message[i]>90)){ // prints non-alphabet characters
          printf("%c", message[i]);
      }
      if(message[i] == 126){
          i = 1000;
      }
                 
  }
  printf("Encrypted message:\n");
  for(i=0;i<1000;i++){
       printf("%c", message[i]);
       if(message[i] == 126){
           i = 1000;
           printf("\n");
       }
       
   }
   
   
}

void deciphRotKey(void){
   // *****************
   // open key file
   // read key from file
   // close key file
   // open message file
   // read message from file
   // decipher using key // fix -ve wrap-around
   // print deciphered message
   // write to file
   // close key file
   
   // etc
   
   int key;
   FILE *keyPointer = fopen("rotCiphKey.txt","r"); // open key file
   
   if (keyPointer != NULL){
       fscanf(keyPointer,"%d", &key); // read key file
       //fclose(keyPointer);
       printf("Key is %d\n", key);
   }else{
      printf("Key file empty or missing!\nMessage cipher failed.\n");
   }
   
   fclose(keyPointer); // close key file
   
   
   //READ TEXT FROM MESSAGE FILE
   
   char message[1000];
   //int letter;
   int i;
   
   FILE *messagePointer;
   messagePointer = fopen("rotationDecipher.txt","r");
   if(messagePointer != NULL){
      printf("Message:\n");
      if( fgets (message, 1000, messagePointer)!=NULL ) {
      /* writing content to stdout */
         puts(message);
      }
   
   }else{
       printf("File empty or missing");
   }
   
   fclose(messagePointer);
   
   
   
   //CIPHER USING KEY
   key = (26-key);
   for (i = 0; i < 1000; i++){ // for loop scans and prints the letters of the file one at a time
      
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
         if(message[i] == 126){
             i = 1000;
         }
     
   }   
   //end cipher
   printf("Deciphered message:\n");
   for(i=0;i<1000;i++){
       printf("%c", message[i]);
       if(message[i] == 126){
           i = 1000;
       }
       
   }
   printf("\n");
   
}

void deciphRotNoKey(void){
   //*****************
   // open message file
   // read message from file
   // attempt statistical ananlysis of letters
   // try key using analysis and first few common letters and user confirmation
   // if it doesn't work - brute force
   // write message to file
   // close message file
   // print key
   
   int key; //still uses a key when to apply decipher
   
   //READ TEXT FROM MESSAGE FILE
   
   char message[1000];
   int i;
   int j;
   int k = 0;
   char commonLetter;
   
   FILE *messagePointer;
   messagePointer = fopen("rotationDecipher.txt","r");
   if(messagePointer != NULL){
      printf("Message:\n");
      if(fgets(message, 1000, messagePointer)!=NULL) {
         puts(message);
      }
   
   }else{
       printf("File empty or missing");
   }
   
   fclose(messagePointer);
   
   //
   // Do statistical analysis on message
   //
   
   char comLetter[26] = {'E', 'T', 'A', 'O', 'I', 'N', 'S', 'H', 'R', 'D', 'L', 'C', 'U', 'M', 'W', 'F', 'G', 'Y', 'P', 'B', 'V', 'K', 'J', 'X', 'Q', 'Z'}; 
   int countLetter[27] = {0};
   // count repeated letters(only) for message[i] ---> i = 0 to end
  // if letter is a, index a etc, print most common to check
   for(i=0;i<1000;i++){
	   
	   for(j=0;j<=25;j++){
		  if(message[i]==comLetter[j]){
			 countLetter[j]++;
		 }

	   
	   }
	   if(message[i]== 126){
		  i = 1000;	   
	   }
	}
	for(j=0;j<=25;j++){
	   if(k<countLetter[j]){
		  k = countLetter[j];
		   
	   }
	//k is highest count figure	
	}

	for(j=0;j<=25;j++){
	   if(countLetter[j] == k){
		  commonLetter = comLetter[j];
		   
	   }//common letter is known
		
	}
	printf("%c happened most\n", commonLetter);
  
   if(commonLetter<=69){
      key = 69-commonLetter;     
   }
   if(commonLetter>69){
      key = (69-commonLetter+26); //fixes -ve rotation problem
       
   }
   printf("Key: %d\n", key);
   
   //END OF STATISTICAL ANALYSIS
   
   
   //CIPHER USING KEY
   //do it with first 5 most common letters, print all and ask user if any look good
   //give real key
   //DO CIPHER!!!!
   int attempt;
   int correct;
   
   for(attempt=1;attempt<=5;attempt++){
      for (i = 0; i < 1000; i++){ // for loop scans and prints the letters of the file one at a time
      
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
         if(message[i] == 126){
             i = 1000;
         }
     
     
   }
   printf("Attempt %d: ", attempt);
   for(i=0;i<30;i++){
       printf("%c", message[i]);
             
   }
   
   
   //update key 'E', 'T', 'A', 'O', 'I'
   // it starts referenced to E 
   if(commonLetter == 79){
       key = key-6; // make it next letter
       
   }
   if(commonLetter == 65){
       key = key + 14; // make it next letter
       
   }
   if(commonLetter == 84){
       key = key - 19; // make it next letter
       
   }
   if(commonLetter == 69){
       key = key + 15;// make it next letter
       
   }
   //end update key
   

  }
  
  printf("which looks good?\n");
   //end cipher
   
   printf("\n");
   
   
   }
   
  // printf("\n");


void deciphSubKey(void){
   // *****************
   // open key file
   // read key from file
   // close key file
   // open message file
   // read message from file
   // decipher using key
   // print deciphered message
   // write to file
   // close message file
   
   // etc
   
   char key[26];
   FILE *keyPointer = fopen("subCiphKey.txt","r"); // open key file
   
   if (keyPointer != NULL){
      printf("Key:\n");
      if( fgets (key, 27, keyPointer)!=NULL ) {
      
         puts(key);
      }
       
   }else{
      printf("Key file empty or missing!\nMessage cipher failed.\n");
   }
   
   fclose(keyPointer); // close key file
   
   
   //READ TEXT FROM MESSAGE FILE
   
   char message[1000];
   //int letter;
   int i;
   
   FILE *messagePointer;
   messagePointer = fopen("substitutionDecipher.txt","r");
   if(messagePointer != NULL){
      printf("Message:\n");
      if( fgets (message, 1000, messagePointer)!=NULL ) {
      /* writing content to stdout */
         puts(message);
      }
   
   }else{
       printf("File empty or missing");
   }
   
   fclose(messagePointer);
   
   
   
   //CIPHER USING KEY
   
  int k; // indexing integer for letter identification
  int x; // integer for substituting letters assigned in the key
  
  for (i = 0; i < 1000; i++){ // for loop scans letter from input file, then applies substiution
      
      if((message[i]>=97)&&(message[i]<=122)){//convert any lower case to upper case first to save fucking around with code.
         message[i] = message[i]-32;
      }
      
      if((message[i]>=65)&&(message[i]<=90)){// checks if the character read is an alphabet character in the A-Z range,
                                       // skips non-alphabet characters 
         for(k=65;k<=90;k++){
             if (message[i]==k){        
                x = k-65;
                message[i] = key[x];
                //printf("%c",key[x]);
             } 
         }
      }
      
                 
  }
  printf("Decrypted message:\n");
  for(i=0;i<1000;i++){
       printf("%c", message[i]);
       if(message[i] == 126){
           i = 1000;
           printf("\n");
       }
       
   }
}

void deciphSubNoKey(void){
   // *****************
   // open message file
   // read message from file
   // attempt statistical analysis
   // ask user for confirmation
   // maybe implement easy way for user to change letters in key
   // implement reset message to original (just read file again)
   // print deciphered message
   // write deciphered message to file
   // print key
   // etc
   
   
   
   
}


 /*
 int waitForUser(void){ // return number of times fuction has been called with static int
   
   
 }
 */





   //change key
   /*if(commonLetter<=69){ //69 = F
      key = 69-commonLetter;     
   }
   if(commonLetter>69){
      key = (69-commonLetter+26); 
       
   }
   printf("Key: %d\n", key);
   */
   
   
   



/*
void deciphSubNoKey(void){
   // *****************
   // open message file
   // read message from file
   // attempt statistical analysis
   // ask user for confirmation
   // maybe implement easy way for user to change letters in key
   // implement reset message to original (just read file again)
   // print deciphered message
   // write deciphered message to file
   // print key
   // etc
   
}
*/



 /*
 int waitForUser(void){ // return number of times fuction has been called with static int
   
   
 }
 */




