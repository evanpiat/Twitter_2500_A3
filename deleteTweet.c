#include "headerA3.h"

void deleteTweet(tweet **tweetList){
    tweet *pointer = * tweetList; // innit pointer and 
    tweet *previous = * tweetList; // stores and moves prev tweetList index of list
    int check = 1; // init check position in list var
    int userIn; // init user input var
    int totalTweets = 0; // init var to store total tweets

    // Step 1: Check tweet; go to the last index of the tweet list 
    while(pointer != NULL){
        totalTweets++; // if not null increase amount of total tweets
        pointer = pointer->next; //  move pointer to next index
    }
    pointer = *tweetList; // save location of last tweet
    printf("Currently there are %d tweets.\n\n", totalTweets); // print out to console

    // Step 2: Check if more than one tweet is created
    if(totalTweets > 0){
        // - get user input for which tweet to remove
        do{
            printf ("Which tweet do you wish to delete - enter a value between 1 and %d: ", totalTweets); // out print to console
            scanf ("%d", &userIn); // get input
        }while((userIn<1)||(userIn>totalTweets)); // restrictions for scan for user in
        getchar(); // makes sure no new line is taken for input

        // Step 3: if the 1st index in the list is the one to be deleted
        if(userIn == 1 && tweetList != NULL){
            *tweetList = pointer->next; // move the 1st index in list to next
            printf("\nTweet %d deleted. There are now %d tweets left. \n", pointer->id, totalTweets - 1); // print out to console
            free(pointer); // free space of old head
            return;
        }

        // Step 4: find requested tweet for delete and get previous
        while(check != userIn && pointer != NULL){
            check++; // increase check
            previous = pointer;
            pointer = pointer->next; // move to next
        }

        // Step 5: remove tweet from the linked list
        previous->next = pointer->next;
        printf("\nTweet %d deleted. There are now %d tweets left.\n", pointer->id, totalTweets-1); // outprint ot console
        free (pointer); // free mem of pointer
    }
}