

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
    myBigObject* objsvsv = gc_malloc(vm, sizeof(myBigObject));
    gc_free(vm, objsvsv);
    myBigObject* obsbs = gc_malloc(vm, sizeof(myBigObject));
    gc_free(vm, obsbs);
    myBigObject* obsvsvs = gc_malloc(vm, sizeof(myBigObject));
    gc_free(vm, obsvsvs);
    myBigObject* obsvsvsvs = gc_malloc(vm, sizeof(myBigObject));
    gc_free(vm, obsvsvsvs);
    myBigObject* obshf = gc_malloc(vm, sizeof(myBigObject));
    gc_free(vm, obshf);
    myBigObject* obsdhdft = gc_malloc(vm, sizeof(myBigObject));
    gc_free(vm, obsdhdft);
    myBigObject* obsddht = gc_malloc(vm, sizeof(myBigObject));
    myBigObject* obsdtykt = gc_malloc(vm, sizeof(myBigObject));
    myBigObject* obsdtygfkht = gc_malloc(vm, sizeof(myBigObject));
    myBigObject* obsdgtrhtygfkht = gc_malloc(vm, sizeof(myBigObject));
    myBigObject* obddsdgtrhtygfkht = gc_malloc(vm, sizeof(myBigObject));

    gc_stop(vm);
}