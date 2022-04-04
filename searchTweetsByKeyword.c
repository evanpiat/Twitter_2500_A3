#include "headerA3.h"

int searchTweetsByKeyword(tweet * tweetList){
    tweet *pointer = tweetList; // init pointer to parse
    int total = 0; // init counter
    char keyword[150]; // init user inputed keyword
    char *test; // init pointer for checking

    // Step 1: get keyword from user input
    do{
        printf("Enter a keyword to search: ");
        fgets(keyword, 150, stdin); // gets user input within max char limit
    }
    while (strlen(keyword) > 141); // make sure within restraints
    keyword[strlen(keyword) - 1] = '\0'; // deletes newline to prevent scan problem


    // Step 2: find tweets that include keyword
    while (pointer != NULL){
        test = NULL; // set the test pointer to null
        test = strcasestr(pointer->text, keyword); // search through text with strcasestr (regardless of upper/lowercase)

        // Step 3: print to console if word is found in tweet text
        if (test != NULL){
            printf("Match found for '%s': %s wrote: '%s'\n", keyword, pointer->user, pointer->text);
            total++;
        }
        pointer = pointer->next; // move to next index in list
    }
    return total; // return when done
}