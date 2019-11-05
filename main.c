#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "list_tests.h"

// Roslyn Parker
// 31 Oct. 2019
// CIS-3050

typedef struct thing thing;
typedef struct Node Node;
typedef struct LinkedList LinkedList;

struct thing {
    char* name;
    int x;
};

void print_thing(thing item)
{
    printf("thing: name = %s, x = %d \n", item.name, item.x);
}

int main()
{ /**
    thing thingOne;
    thingOne.name = "Thing one";
    thingOne.x = 1;

    thing thingTwo = {"Thing two", 2};

    thing* p3 = (thing*) malloc(sizeof(thing));
    p3->name = "Thing three";
    (*p3).x = 3;

    print_thing(thingOne);
    print_thing(thingTwo);
    print_thing(*p3);

    free(p3);
    */

    LinkedList* list = create_list();
    char* s = get_string(list, int_formatter);
    printf("%s size: %d\n", s, list_size(list));
    int c = 4;
    add_end(list, &c, sizeof(int));
    printf("%s size: %d\n", get_string(list, int_formatter), list_size(list));

    int i = 5;
    int j = -3;
    add_beginning(list, &i, sizeof(int));
    add_beginning(list, &j, sizeof(int));
    printf("%s size: %d\n", get_string(list, int_formatter), list_size(list));

    int a = 7;
    int b = 2;
    add_end(list, &a, sizeof(int));
    add_end(list, &b, sizeof(int));
    printf("%s size: %d\n", get_string(list, int_formatter), list_size(list));

    int k = 20;
    int l = 14;
    add_n(list, -1, &k, sizeof(int));
    add_n(list, 10, &l, sizeof(int));
    printf("%s size: %d\n", get_string(list, int_formatter), list_size(list));

    remove_first(list);
    remove_last(list);
    printf("%s size: %d\n", get_string(list, int_formatter), list_size(list));

    remove_n(list, 2);
    printf("%s size: %d\n", get_string(list, int_formatter), list_size(list));

    int* getFirst = get_first(list);
    int* getLast = get_last(list);
    int* getN = get_n(list, 2);
    printf("getFirst: %d \ngetLast: %d \ngetN: %d\n", *getFirst, *getLast, *getN);

    LinkedList* empty_list = create_list();
    int* e_getFirst = get_first(empty_list);
    int* e_getLast = get_last(empty_list);
    int* e_getN = get_n(empty_list, 2);
    printf("getFirst: %d \ngetLast: %d \ngetN: %d\n", *e_getFirst, *e_getLast, *e_getN);
    all_list_tests();

    return 0;
}
