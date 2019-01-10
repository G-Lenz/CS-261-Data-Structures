#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list) {
	// FIXME: you must write this
	list->size = 0;
	list->frontSentinel = malloc(sizeof(struct Link));
	list->backSentinel = malloc(sizeof(struct Link));
	list->frontSentinel->next = list->backSentinel;
	list->backSentinel->prev = list->frontSentinel;
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	struct Link *temp = malloc(sizeof(struct Link));
	temp->value = value;
	// FIXME: you must write this
	assert(link != 0);
	if (list->frontSentinel->next != list->backSentinel)
	{
				
		temp->next = link;
		temp->prev = link->prev;
		link->prev = temp;
		temp->prev->next = temp;
	}
	else
	{
		temp->next = list->backSentinel;
		temp->prev = list->frontSentinel;
		list->frontSentinel->next = temp;
		list->backSentinel->prev = temp;
	}
	

	
	

}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
	// FIXME: you must write this
	assert(link != 0);
	link->prev->next = link->next;
	link->next->prev = link->prev;
	free(link);
	
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	struct Link *temp = malloc(sizeof(struct Link));
	temp->value = value;

	if (list->frontSentinel->next != list->backSentinel)
	{
		addLinkBefore(list, list->frontSentinel->next, value);
	}
	else
	{
		addLinkBefore(list, list->backSentinel, value);
	}
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	struct Link *temp = malloc(sizeof(struct Link));
	temp->value = value;
	
	// FIXME: you must write this
	if (list->frontSentinel->next == list->backSentinel)
	{
		addLinkBefore(list, list->backSentinel, value);
		
	}
	else
	{
		addLinkBefore(list, list->backSentinel, value);
		
	}
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{
	// FIXME: you must write this
	return list->frontSentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{
	// FIXME: you must write this
	return list->backSentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(list->frontSentinel != 0);
	struct Link *temp = list->frontSentinel->next;
	list->frontSentinel->next = temp->next;
	temp->next->prev = list->frontSentinel;
	free(temp);
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
	// FIXME: you must write this
	struct Link *temp = list->backSentinel->prev;
    
	assert(list->frontSentinel != list->backSentinel);

	list->backSentinel->prev->prev->next = list->backSentinel;
	list->backSentinel->prev = list->backSentinel->prev->prev;

	free(temp);

	
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
	// FIXME: you must write this
	if (list->frontSentinel->next == list->backSentinel)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(!(linkedListIsEmpty(list)));
	struct Link *temp = list->frontSentinel->next;
	while (temp != list->backSentinel)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
	temp = 0;
	free(temp);
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	linkedListAddBack(list, value);
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	struct Link *temp = list->frontSentinel->next;

	if (linkedListIsEmpty(list))
	{
		return 0;
	}
    
	while (temp != list->backSentinel)
	{
		if (temp->value == value)
		{
			return 1;
		}
		temp = temp->next;
	}

	return 0;
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	assert(!(linkedListIsEmpty(list)));

	struct Link *temp = list->frontSentinel->next;

	while (temp != list->backSentinel)
	{
		if (temp->value == value)
		{
			removeLink(list, temp);
			return;
		}
		temp = temp->next;
	}
}
