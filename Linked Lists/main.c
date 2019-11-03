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
    int size_l = list_size(list);
    printf("%s size: %d\n", s, size_l);

    int i = 5;
    int j = -3;
    int k = 4;
    int l = 0;
    add_beginning(list, &i, sizeof(int));
    add_beginning(list, &j, sizeof(int));
    add_end(list, &k, sizeof(int));
    add_n(list, 0, &l, sizeof(int));
    add_n(list, 7, &l, sizeof(int));

    int size = list_size(list);

    printf("%s size: %d\n", get_string(list, int_formatter), size);

    all_list_tests();
    return 0;
}
