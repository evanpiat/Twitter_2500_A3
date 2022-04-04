#include "headerA3.h"

void sortID (tweet ** head) {
    int userID;
    char username[51];
    tweet *cn = *head;
    tweet *next = *head;
    char tweetText[141];

    // Step 1: checks value of the current index of link list for NULL
    while(cn != NULL){
        next = cn->next;

        // Step 2: checks value of the next index if NULL
        while(next!=NULL)
        {
            if(cn->id > next->id){
                // Step 3: swaps the second field (username) using string copy
                strcpy(username, cn->user);
                strcpy(cn->user, next->user);
                strcpy(next->user, username);

                // Step 4: swaps the third field (tweetText) using string copy
                strcpy(tweetText, cn->text);
                strcpy(cn->text, next->text);
                strcpy(next->text, tweetText);
                
                // Step 5: swaps the first field (userID) using bubble sort
                userID = cn->id;
                cn->id = next->id;
                next->id = userID;
            }
            next = next->next; // moves to next
        }
        cn = cn->next; // moves to next 
    }
}