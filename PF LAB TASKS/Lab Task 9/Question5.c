#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main(){

    char key[10],inp[50]; // This line here is setting the input for the key and the text 
    int textArr[55]; // This is where the ascii values of the text will be saved
    int keyArr[55]; // This is where the ascii values of the key will be saved
    int cipherArr[55]; // The result of the addition of both arrays
    char cipherText[51]; // array to store the final encrypted characters 

    int textLen = strlen(inp); // Length of the text
    int keyLen = strlen(key);   // Length of the key

    printf("Please enter the text you want top encrypt: ");
    scanf("%s", &inp); // Inputting the text

    printf("\n");

    printf("Please enter the key you want to encrypt the text with: ");
    scanf("%s", &key); // Inputting the key

    if (keyLen == 0) {
        printf("Error: Key cannot be empty.\n");
        return 1;
    }

    for (int i = 0; i < textLen; i++) {
        textArr[i] = (inp[i] - 'A' + 1); // Saving all the ascii values of the text to an array for addition later on 
    }

    for (int i = 0; i < textLen; i++) {
        keyArr[i] = (key[i % keyLen] - 'A' + 1);  // Saving all the ascii values of the key to an array for addition later on 
    }

    
    for (int i = 0; i < textLen; i++) {
        cipherArr[i] = (textArr[i] + keyArr[i]) % 26; // Calculate the cipher by adding ascii values of text and key
        if (cipherArr[i] == 0) cipherArr[i] = 26;
    }
        
    for (int i = 0; i < textLen; i++) {
        cipherText[i] = (char)(cipherArr[i] + 'A' - 1); // converting back to ascii values
    }

    cipherText[textLen] = '\0';  // Null-terminate the string

    printf("Encrypted text: %s\n", cipherText);


    return 0;
}