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
    printf("%s\n", s);

    int i = 5;
    int j = -3;
    add_beginning(list, &i, sizeof(int));
    add_beginning(list, &j, sizeof(int));
    printf("%s\n", get_string(list, int_formatter));

    return 0;
}