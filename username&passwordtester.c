/*
Author: Amanda Lieng
Date updated: 7/25/20

Program Description: takes in usernames and passwords. Checks against stored usernames and passwords. 
If the usernames are valid, prompt for a password. If the password is valid, print the hello username message. 
If the username or password is typed incorrectly 3 times program quits. The password should stored in some form of encryption.

*/
#include <stdio.h>
#include <string.h>     // need to include string.h header file for strcmp()

int usernamecounter = 0;
int passwordcounter = 0;

int main(void)
{
    
    while (1) {

        //declare valid usernames and passwords in arrays 
        char user1[] = "panteater";
        char user2[] = "qv";
        char user3[] = "alien";
        
        char pass1[] = ("peter");
        char pass2[] = ("hellothere!");
        char pass3[] = ("space");
        
        
        //encrypt passwords with an ascii offset of 17 per character
        for(int n =0; n < strlen(pass1); n++) {
            pass1[n] = (pass1[n] + 17);  }
        
        for(int n =0; n < strlen(pass2); n++) {
            pass2[n] = (pass2[n] + 17);  }
        
        for(int n =0; n < strlen(pass3); n++) {
            pass3[n] = (pass3[n] + 17);  }
            
            
        //declare array variables for user inputted username and password
        //I chose to have the maximum input be 24 (BUF_SIZE-1) characters  
        //so I set BUF_SIZE = 25
        const int BUF_SIZE = 25;
        char usernameinput[BUF_SIZE];
        char passwordinput[BUF_SIZE];
        
        
        //prompt the user to enter a username and store it
        printf("%s", "Enter a username: ");
        scanf("%s", usernameinput);
        
        
        // initialize whichuser = 0, which acts as a flag to let us know which username has been entered
        int whichuser = 0; 
        
        
        // Compare the inputted usename with the stored usernames
        // use whichuser as a flag to specify which username has been inputted
        // if an invalid username is entered, whichuser = 0

        if (strcmp(usernameinput, user1) == 0) {
            whichuser = 1;  }

        else if (strcmp(usernameinput, user2) == 0) {
            whichuser = 2;  }

        else if (strcmp(usernameinput, user3) == 0) {
            whichuser = 3;  }  
        
        
        //check to see if a user has inputted a correct username
        //checks the usernamecounter to see if the usersname has been inputted incorrectly 3 times
        //if it has, the program prints a goodbye message and ends
        //if incorrect username prompt user to try again, usernamecounter +1 
        
        if (whichuser == 0) {
        
            if (usernamecounter == 2) {
                printf("You've entered the username incorrectly 3 times. Goodbye!");  
                return 0;  }
            else {
                printf("Incorrect username, please try again\n");
                usernamecounter ++;
                continue;  }
        }
                
                
        //while a correct username has been inputted check to see if an incorrect password 
        //has been inputted 3 times, if it has print a goodbye message and end the program
        while (whichuser != 0) {

            //prompt the user to enter a password and store it    
            printf("%s", "Enter a password: ");
            scanf("%s", passwordinput); 

            //encrypt the user inputted password with an ascii offset of 17 per character
            for (int i =0; i < strlen(passwordinput); i++) {
                passwordinput[i] = (passwordinput[i] + 17); }
                
                
            //test the encryted user inputted password with the encrypted stored password
            //if they match print out a hello username message
            //if the user names dont match, print an incorrect message, 
            //prompt user to try again and increment the passwordcounter +1
            
            if ((whichuser = 1) && (strcmp(passwordinput, pass1) == 0)) {
                printf("Hello %s! You have succesfully logged in :)\n", user1);
                return 0;}
            
            else if ((whichuser = 2) && (strcmp(passwordinput, pass2) == 0)) {
                printf("Hello %s! You have succesfully logged in :)\n", user2);  
                return 0;}
            
            else if ((whichuser = 3) && (strcmp(passwordinput, pass3) == 0)) {
                printf("Hello %s! You have succesfully logged in :)\n", user3); 
                return 0;}

            else  {
                if (passwordcounter == 2)  {
                    printf("You've entered the password incorrectly 3 times. Goodbye!");  
                    return 0;  }
                
                else {
                    printf("Incorrect password, please try again\n");  
                    passwordcounter++;  
                    continue;}
                }
            }
        }
    
}




