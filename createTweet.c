#include "headerA3.h"

tweet * createTweet(tweet * tweetList){
    tweet * newTweet; // creates a new tweet (linked list)
    newTweet = malloc(sizeof(tweet)); // allocatign mem for new tweet

    char name[52]; // create var for username
    char tweetText[142]; // create var for users tweet

    // Step 1: Get user input and assign to the username
    do{
        printf("Enter a username: ");
        fgets(name, 60, stdin); // get user input
    }
    while(strlen(name)>=52); // scanf only scans names less that max char (51)
    
    name[strlen(name)-1] = '\0'; // subtracts newline
    strcpy(newTweet->user, name); // sets new tweet name to user input (assigning in linked list)


    // Step 2: Get user text and assign to the new tweet
    do{
        printf("Enter the user's tweet: ");
        fgets(tweetText, 146, stdin); // get user input for tweet

    }while(strlen(tweetText)>=142); // scan only if less than max char for tweet (141)
    tweetText[strlen(tweetText)-1] = '\0'; // subtracts newline
    strcpy(newTweet->text, tweetText); // sets user input to tweet in newTweet list

    // Step 3: Get user ID from ascii values of username and tweet
    int total = 0; // tracks all assci values
    int count;

    for(count = 0; count < strlen(name); count++){
        total += name[count];
    }

    for(count = 0; count < strlen(tweetText); count++){
        total = total + ((rand()%999) + 1);
    }
    printf("Your computer generated userid is = %d \n", total); // console print to test
    newTweet->id = total; // assigns total value of ascii calc to the ID

    // Step 4: create next instance in tweet list
    newTweet->next = '\0'; // create next index in newtweet list
    
    return newTweet;
}