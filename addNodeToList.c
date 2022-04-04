#include "headerA3.h"

void addNodeToList(tweet**tweetList,tweet * node){
    tweet *pointer = *tweetList;
    if (*tweetList == NULL){
        *tweetList = node;
    }
    else if(tweetList != NULL){
        while (pointer->next != NULL){
            pointer = pointer->next;
        }
        pointer->next = node;
    }  
}