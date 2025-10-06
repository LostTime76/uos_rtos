#include <uos/collections/linked_list.h>

static inline void _ll_append(Linked_Node* ref, Linked_Node* node);
static inline void _ll_prepend(Linked_Node* ref, Linked_Node* node);

void ll_init(Linked_List* list)
{
	list->items       = 0;
	list->head.parent = list;
	list->head.next   = list->head.prev = &list->head;
}

void ll_append(Linked_List* list, Linked_Node* node)
{
	_ll_append(list->head.prev, node);
}

void ll_prepend(Linked_List* list, Linked_Node* node)
{
	_ll_prepend(list->head.next, node);
}

void lln_init(Linked_Node* node, void* data)
{
	node->next   = nullptr;
	node->prev   = nullptr;
	node->parent = nullptr;
	node->data   = data;
}

void lln_remove(Linked_Node* node)
{
	node->parent->items--;
	node->parent     = nullptr;
	node->prev->next = node->next;
	node->next->prev = node->prev;
}

static inline void _ll_append(Linked_Node* ref, Linked_Node* node)
{
	node->next      = ref->next;
	node->prev      = ref;
	ref->next->prev = node;
	ref->next       = node;
	node->parent    = ref->parent;
	ref->parent->items++;
}

static inline void _ll_prepend(Linked_Node* ref, Linked_Node* node)
{
	node->next      = ref;
	node->prev      = ref->prev;
	ref->prev->next = node;
	ref->prev       = node;
	node->parent    = ref->parent;
	ref->parent->items++;
}