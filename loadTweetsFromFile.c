#include "headerA3.h"

void loadTweetsFromFile (tweet ** tweetList){
    FILE *pointer; // init file pointer
    char storeRow[150]; // init row for csv file
    char *tk; // token for while loop
    char fn[150]; // init filename char


    // Step 1: get file name from user input
    printf("Enter a filename to load from: ");
    fgets(fn, 150, stdin); // fgets for name user in
    fn[strlen(fn)-1] = '\0'; // rem newline from the fgets
    pointer = fopen (fn, "r"); // open file

    // Step 2: message if error opening file || not able to open
    if(pointer == NULL){
        printf("Can't open file.\n"); // print error 
        return;
    }
    // Step 3: if able to open then do this
    else
    {
        // Step 4: parse through whole tweet list and save each field to csv file
        while(fgets(storeRow,150,pointer) != NULL)
        {
            tweet * nextTweet; // make new tweet
            nextTweet = malloc(sizeof(tweet)); // mem allocate

            // get user id
            tk = strtok(storeRow, ",");
            nextTweet->id = atoi(tk); // copy to list usign atoi 

            // get username
            tk = strtok(NULL, ",");
            strcpy(nextTweet->user, tk); // copy to list

            // get tweet text
            tk = strtok(NULL, "");
            // in case of comma
            if (tk[strlen (tk)-2] == ','){
                tk[strlen (tk)-2] = '\0';
            }
            else{
                tk[strlen(tk)-1] = '\0';
            }
            strcpy(nextTweet->text, tk); // copy all text to list
            nextTweet->next = NULL;

            //// CHANGE THIS TO ALL BE DONE IN FUNCTION
            addNodeToList (tweetList, nextTweet); // Add to the list

        }
    }
    fclose(pointer); // close
    printf("Output successful! \n"); // print to console
}