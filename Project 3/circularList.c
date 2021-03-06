#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	// FIXME: you must write this
	list->sentinel = malloc(sizeof(struct Link));
	list->sentinel->next = list->sentinel;
	list->sentinel->prev = list->sentinel;
	list->size = 0;

}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this
	struct Link *newLink = malloc(sizeof(struct Link));

	newLink->value = value;
	newLink->next = NULL;
	newLink->prev = NULL;

	return newLink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	struct Link *newLink = createLink(value);

	assert(link != NULL);
	newLink->prev = link;
	newLink->next = link->next;
	link->next = newLink;
	newLink->next->prev = newLink;
	list->size++;
	

	

	// FIXME: you must write this
	

	
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXME: you must write this
	assert((link != NULL));
	assert(list != NULL);
	if (list->sentinel->next == list->sentinel)
	{
		return;
	}
	
	struct Link *temp = link;

	temp->next->prev = temp->prev;
	temp->prev->next = temp->next;

	free(temp);
	list->size--;


}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	// FIXME: you must write this
	struct Link* temp = list->sentinel->next;

	while (list->size > 0)
	{   
		temp = temp->next;
		free(temp->prev);
		list->size--;

	}
	free(list->sentinel);
	free(list);
	
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	assert(list != 0);
	addLinkAfter(list, list->sentinel, value);

}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	assert(list != 0);
	addLinkAfter(list, list->sentinel->prev, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list->sentinel->next != list->sentinel);
	assert(list != 0);
	return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list->sentinel->next != list->sentinel);
	assert(list != 0);
	return list->sentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
	removeLink(list, list->sentinel->next);


}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
	removeLink(list, list->sentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this
	if (list->sentinel->next == list->sentinel)
	{
		return 1;
	}
	return 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	// FIXME: you must write this
	assert(!(circularListIsEmpty(list)));
	struct Link *temp = list->sentinel->next;
	for (int i = 0; i < list->size; i++)
	{
		printf("%.2f ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this
	assert(!(circularListIsEmpty(list)));
	struct Link *tempFront = list->sentinel->next;
        struct Link *tempBack = list->sentinel->prev;
        TYPE tempValue = tempFront->value;
	for (int i = 0; i < list->size/2; i++)
	{
		tempFront->value = tempBack->value;
                tempBack->value = tempValue;
                tempFront = tempFront->next;
                tempBack = tempBack->prev;
                tempValue = tempFront->value;
	}
}
