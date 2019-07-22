/*
    JTSK-320112
    a6-p3.c
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <stdio.h>
#include "queue.h"

int main()
{
	Queue line;
	Item temp;
	char ch;

	initialize_queue(&line);

	while (((ch = getchar()) != EOF))
	{
		switch (ch)	{
			case 'a':
				printf("add int: ");
				scanf("%d", &temp);
				if (!queue_is_full(&line))
				{
					printf("Putting %d into queue\n", temp);
					enqueue(temp, &line);
				}
				else
					puts("Queue is full");
				break;

			case 'd':
				if (queue_is_empty(&line))
					puts("Nothing to delete!");
				else
				{
					dequeue(&temp, &line);
					printf("Removing %d from queue\n", temp);
				}
				break;
            case 'q':
                puts("Bye.");
                return 0;
                //quit the program
                break;
            case 'p':
                //to print
                printq(&line);
                break;
			default:
				printf("%d items in queue\n", queue_item_count(&line));
				printf("Type a to add, d to delete, p to print");
				printf(", q to quit:\n");
				//extend default sentences
		}
	}
	empty_queue(&line);
	return 0;
}
