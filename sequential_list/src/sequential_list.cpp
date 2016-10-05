#include "sequential_list.h"

///Element functions

Element* element_create(int id, string info)
{
    Element* e = new Element;
    e->id = id;
    e->info = info;

    return e;
}

void element_print(Element* e)
{
    cout << "{ " << e->id << ", " << e->info << " }" << endl;
}

void element_destroy(Element* e)
{
    if (e != NULL){
        delete e;
    }
}

///List functions

List* list_create()
{
    List* list = new List;
    list->size = 0;

    return list;
}

void list_destroy(List* list)
{
    for (int i = 0; i < list->size; i++){
        element_destroy(list->data[i]);
    }
    delete list;
}

int list_insert_last(List* list, Element* e)
{
    list->data[list->size] = e;
    list->size++;
}

int list_remove_last(List* list)
{
    if (list->size == 0){
        return -1;
    }
    element_destroy(list->data[list->size-1]);
    list->data[list->size-1] ==  NULL;
    list->size--;
    return 0;
}

void list_print(List* list)
{
    for(int i = 0; i < list->size; i++){
        element_print(list->data[i]);
    }
    cout << endl << endl;
}

/**
*Return the position of the element
*/
int list_indexOf(List* list, int id)
{
    for (int i = 0; i < list->size; i++){
        if (list->data[i]->id == id){
            return i;
        }
    }
    return -1;
}


/**
*Return the element
*/
Element* list_getById(List* list, int id)
{
    int i = list_indexOf(list, id);
    if (i > 0){
        return list->data[i];
    }
    return NULL;
}

/**
*return -1, list full
*return -2, invalid position
*/
int list_insertAt(List* list, Element* e, int pos)
{
    if (list->size >= list->MAX){
        return -1;
    }
    if (pos > list->size || pos < 0){
        return -2;
    }
    for (int i = list->size-1; i >= pos; i--){
        list->data[i+1] = list->data[i];
    }
    list->data[pos] = e;
    list->size++;
    return 0;
}

int list_insertSorted(List* list, Element* e)
{
    int i;
    for (i = 0; (i < list->size) && (list->data[i]->id < e->id); i++);
    return list_insertAt(list, e, i);
}


/**
*return -1, list is empty
*return -2, invalid position
*/
int list_removeByIndex(List* list, int index)  //index == pos
{
    if (list->size == 0){
        return -1;
    }
    if (index >= list->size){
        return -2;
    }
    element_destroy(list->data[index]);
    list->data[index] == NULL;
    list->size--;
    for(int i = index; i <= list->size; i++){
        list->data[i] = list->data[i+1];
    }
    return 0;
}

int list_removeById(List* list, int id)
{
    int index = list_indexOf(list, id);
    return list_removeByIndex(list, index);
}
