#include <iostream>
#include "sequential_list.h"

using namespace std;

int main()
{
    List* list = list_create();
    list_insert_last(list, element_create(1, "mario"));
    list_insert_last(list, element_create(2, "link"));
    list_insert_last(list, element_create(3, "samus"));
    list_insert_last(list, element_create(4, "DK"));
    list_insert_last(list, element_create(5, "fox"));
    list_print(list);
    list_remove_last(list);
    list_print(list);
    list_remove_last(list);
    list_print(list);
    list_remove_last(list);

    int i = list_indexOf(list, 2);
    cout << i << endl;
    element_print(list_getById(list, 2));
    cout << endl;

    list_insertAt(list, element_create(1000, "Mew"), 0);
    list_print(list);

    list_removeByIndex(list, 0);
    list_print(list);
    list_removeById(list, 2);
    list_print(list);
    list_remove_last(list);
    list_remove_last(list);
    list_remove_last(list);
    list_print(list);

    list_insertSorted(list, element_create(3, "John Smith"));
    list_insertSorted(list, element_create(2, "Jonh doe"));
    list_insertSorted(list, element_create(5, "Rose"));
    list_insertSorted(list, element_create(1, "Doctor"));

    list_print(list);


    list_destroy(list);
    return 0;
}
