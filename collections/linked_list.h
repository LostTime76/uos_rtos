#pragma once

#include <uos/base.h>

/*! Forward declaration for a linked list node */
typedef struct Linked_Node Linked_Node;

/*! Forward declaration for a linked list */
typedef struct Linked_List Linked_List;

/*!
 * @brief Linked node structure
 */
struct Linked_Node
{	
	/*! Pointer to the next node within the list */
	Linked_Node* next;
	
	/*! Pointer to the previous node within the list */
	Linked_Node* prev;
	
	/*! Pointer to the list that owns the node */
	Linked_List* parent;
	
	/*! Pointer to the data that the node tracks */
	void* data;
};

/*!
 * @brief Linked list structure
 */
struct Linked_List
{
	/*! Head node of the list */
	Linked_Node head;
	
	/*! Number of items within the list*/
	uint32_t items;
};

/*!
 * @brief Initializes a linked list
 *
 * @param list
 *        The list to initialize
 */
void ll_init(Linked_List* list);

/*!
 * @brief Appends a node to the end of a list
 *
 * @param list
 *        The list to append to
 *
 * @param node
 *        The node to append to the list
 */
void ll_append(Linked_List* list, Linked_Node* node);

/*!
 * @brief Prepends a node to the beginning of a list
 *
 * @param list
 *        The list to prepend to
 *
 * @param node
 *        The node to prepend to the list
 */
void ll_prepend(Linked_List* list, Linked_Node* node);

/*!
 * @brief Initializes a linked list node
 *
 * @param The linked list node to initialize
 *
 * @param data
 *        The pointer to the data that the node tracks
 */
void lln_init(Linked_Node* node, void* data);

/*!
 * @brief Removes a node from within its parent list
 *
 * @param node
 *        The node to remove from its parent list
 */
void lln_remove(Linked_Node* node);