#include "headerA3.h"

int main(void)
{
    tweet *tweetList = NULL;
    int option = 0; // Store
    
    while(option != 9)
    {

        printf("\n1. Create a new tweet\n");
        printf("2. Display tweets\n");
        printf("3. Search a tweet (by keyword)\n");
        printf("4. Find how many words are “stop words”\n");
        printf("5. Delete the nth tweet\n");
        printf("6. Save tweets to a file\n");
        printf("7. Load tweets from a file\n");
        printf("8. Sort the given linked list on userid.\n");
        printf("9. Exit\n\n");
        
        do{
            printf ("Choose a menu option: ");
            scanf ("%d", &option); // Scan valid int input
            getchar();
        }while ((option <= 0) || (option >= 10));
        
        if (option == 1){
            addNodeToList(&tweetList, createTweet(tweetList));
        }
        
        if (option == 2){
            displayTweets(tweetList);
        }
        
        if (option == 3){
            searchTweetsByKeyword(tweetList);
        }
        if(option == 4){
            countStopWords(tweetList);
        }
        if(option == 5){
            deleteTweet(&tweetList);
        }
        if (option == 6){
            saveTweetsToFile(tweetList);
        }
        if(option == 7){
            loadTweetsFromFile(&tweetList);
        }
        if(option == 8){
            sortID(&tweetList);
        }
    }
    
    // Function to erase memory of all tweets
    tweet *top = tweetList; // init the first index
    tweet *next; // init the next index for tweetlist

    // clear all space for tweets
    while (top != NULL){
        next = top->next; // go to next tweet
        free(top);
        top = next;
    }
    tweetList = NULL; // change the 1st head to NULL
    return 0;
}