#include "headerA3.h"

void saveTweetsToFile (tweet * tweetList)
{
    tweet *top = tweetList; // init head var
    char fn[150];
    FILE *fp; // init file pointer pointer var
    
    // Step 1: get name of the file
    printf("Enter the filename where you would like to store your tweets: "); // print out to console
    fgets(fn, 150, stdin);
    fn[strlen (fn) - 1] = '\0'; // get rid of newline

    // Step 2: open file and start writing to file
    fp = fopen(fn, "w+");

    // Step 3: parse through all tweet lists and save to file (csv)
    while (top != NULL){
        fprintf(fp,"%d,%s,%s\n", top->id, top->user, top->text); // separate cells by comma
        top = top->next; // move to next unit in link list
    }
    fclose(fp); // close csv
    printf("Output successful! \n"); // print out to console
}