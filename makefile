A3: main.o createTweet.o addNodeToList.o displayTweets.o searchTweetsByKeyword.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o countStopWords.o sortID.o
	gcc -Wall -std=c99 main.o createTweet.o addNodeToList.o displayTweets.o searchTweetsByKeyword.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o countStopWords.o sortID.o -o A3

main.o: main.c headerA3.h
	gcc -Wall -std=c99 -c main.c

createTweet.o: createTweet.c headerA3.h
	gcc -Wall -std=c99 -c createTweet.c

addNodeToList.o: addNodeToList.c headerA3.h
	gcc -Wall -std=c99 -c addNodeToList.c

displayTweets.o: displayTweets.c headerA3.h
	gcc -Wall -std=c99 -c displayTweets.c	

searchTweetsByKeyword.o: searchTweetsByKeyword.c headerA3.h
	gcc -Wall -std=c99 -c searchTweetsByKeyword.c -D_GNU_SOURCE

saveTweetsToFile.o: saveTweetsToFile.c headerA3.h
	gcc -Wall -std=c99 -c saveTweetsToFile.c

loadTweetsFromFile.o: loadTweetsFromFile.c headerA3.h
	gcc -Wall -std=c99 -c loadTweetsFromFile.c

countStopWords.o: countStopWords.c headerA3.h
	gcc -Wall -std=c99 -c countStopWords.c -D_GNU_SOURCE

sortID.o: sortID.c headerA3.h
	gcc -Wall -std=c99 -c sortID.c

deleteTweet.o: deleteTweet.c headerA3.h
	gcc -Wall -std=c99 -c deleteTweet.c

clean: 
	rm *.o A3