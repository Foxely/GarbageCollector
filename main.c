

#include "garbage.h"

struct myBigObject
{
    int a;
    char b;
    struct myBigObject* next;
};

typedef struct myBigObject myBigObject;

int main(int ac, char** av)
{
    gc_t* vm = my_gc_new();
    myBigObject* obj = gc_malloc(vm, sizeof(myBigObject));
    obj->a = 10;
    printf("%d\n", obj->a);
    obj->next = gc_malloc(vm, sizeof(myBigObject));
    gc_stop(vm);
}