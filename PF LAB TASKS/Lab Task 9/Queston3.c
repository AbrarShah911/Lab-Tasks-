#include <stdio.h>
#include <string.h>

int main(){

    char userName[10];
    char password[10];
    char checkUser[10];
    char checkPass[10];

    printf("Please enter a Username under 10 characters: ");
    scanf("%s", &userName);

    printf("\n");

    printf("Please enter a Password under 10 characters: ");
    scanf("%s", &password);

    printf("Please enter the username: ");
    scanf("%s", &checkUser);

    printf("\n");

    printf("Please enter the password: ");
    scanf("%s", &checkPass);

    printf("\n");


    if(strcmp(userName,checkUser) != 0 && strcmp(password,checkPass)!= 0){
        printf("The username and password you have entered is not correct!");
    }else{
        printf("Access granted");
    }

    return 0;
}