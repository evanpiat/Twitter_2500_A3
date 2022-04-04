#include "headerA3.h"

void displayTweets(tweet * tweetList){
    tweet *pointer = tweetList; // init pointer variable
    
    // Step 1: parse list and print out contents of each field
    while(pointer != NULL){
        printf("\n %d: Created by %s: %s", pointer->id, pointer->user, pointer->text);
        pointer = pointer->next; // set pointer to next tweet in list
    }
}