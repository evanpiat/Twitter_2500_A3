#include "headerA3.h"

void countStopWords (tweet * tweetList)
{
    tweet *pointer = tweetList; // init pointer variable
    int loopCount; // init counter var
    int count; // tracks occurences of a tweet  
    char *tk = NULL; // init pointer for tk
    int words = 0; // counts stop words found
    int tweets  = 0; // counts number of tweets with stop words
    char *tweet = malloc(sizeof(char)*1); // init pointer for char
    
    // Step 1: create an array to store all stop words
    char stopWords[25][6] = {"a","an","and","are","as","at","be","by","for","from","has","he","in","is","it","its", "of","on","that","the","to","was","were","will","with"};
   
    // Step 2: create a while loop that parses all words and checks for occurences of stop words
    while (pointer != NULL){
        tweet = realloc(tweet, sizeof(char)*141); // realloc mem for tweet
        strcpy(tweet, pointer->text); // copy text of tweet
        tk = strtok(tweet, " "); // find first word of the tweet and store
        count = 0; // reset count
        
        // Step 3: compare each tk word stored to each stop word
        while (tk != NULL){
            // compare tk to words at each index and checking for occurance of stop words
            for(loopCount = 0; loopCount < 25; loopCount++){
                // checks if tk == stopword
                if (strcasecmp (tk, stopWords[loopCount]) == 0){
                    words++; // increase if found
                    count++; // increase if found
                }
            }  
            tk = strtok(NULL, " "); // null and move to next
        }
        
        // Step 4: incrementing number of tweets that contain a stopword
        if(count > 0){
            tweets++; // increase if contains
        }
        pointer = pointer->next; // move pointer to the next tweet in link list
    }
    free(tk); // free space for token
    free(tweet); // free space for tweet
    printf ("Across %d tweets, %d stop words were found \n", tweets, words); // print to console
    
}