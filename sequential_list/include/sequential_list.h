#ifndef SEQUENTIAL_LIST_H
#define SEQUENTIAL_LIST_H

#include <iostream>
#include <string>

using namespace std;

///Element

struct Element {
	int id;
	string info;
};

Element* element_create(int id, string info);
void element_print(Element* e);
void element_destroy(Element* e);

///List

struct List {
    static const int MAX = 10;
    int size;
    Element* data[MAX];
};

List* list_create();
void list_destroy(List* list);
int list_insert_last(List* list, Element* e);
int list_remove_last(List* list);
void list_print(List* list);
int list_indexOf(List* list, int id);
Element* list_getById(List* list, int id);
int list_insertAt(List* list, Element* e, int pos);
int list_insertSorted(List* list, Element* e);
int list_removeByIndex(List* list, int index);
int list_removeById(List* list, int id);

#endif // SEQUENTIAL_LIST_H
