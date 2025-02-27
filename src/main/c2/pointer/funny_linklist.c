#include <cstddef>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef OFFSET1
#define offset(T, d) ({ \
    T t; \
    (void *)(&t.d) - (void *)(&t); \
})
#else
#define start(addr, T, d) ((T *)(((void *)addr) - offset(T, d)))
#define offset(T, d) ((size_t)(&(((T *)(0))->d)))
#endif

enum DataType {
    A_type,
    B_type,
    C_type,
    MAX_type
};

typedef struct Link {
    enum DataType type;
    struct Link *next;
} Link;

struct A {
    int a;
    char b;
    double c;
    Link l;
};

struct B {
    int x, y;
    Link l;
};

struct C {
    int a;
    Link l;
    double b;
};

struct D {
    char c;
    Link l;
    const char *s;
    int t;
};

Link *getDataA() {
    struct A *a = (struct A *)malloc(sizeof(struct A));
    a->a = 3;
    a->l.next = NULL;
    a->l.type = A_type;
    return &(a->l);
}


void output_A(Link *p) {
    struct A *a = start(p, struct A, l);
    printf("struct A: a = %d, b = %c\n", a->a, a->b);
    return;
}

Link *(*getData[MAX_type])() = {
    getDataA, getDataB, getDataC
};

void (*output[MAX_type])(Link *) = {
    output_A, output_B, output_C
};

int main() {
    printf("offset(A, a) = %lu\n", offset(struct A, a));
    printf("offset(A, b) = %lu\n", offset(struct A, b));
    printf("offset(A, c) = %lu\n", offset(struct A, c));
    struct A a;
    printf("&a = %p\n", &a);
    printf("start(&a.a, A, a) = %p\n", start(&a.a, struct A, a));
    printf("start(&a.b, A, b) = %p\n", start(&a.b, struct A, b));
    printf("start(&a.c, A, c) = %p\n", start(&a.c, struct A, c));
    #define MAX_OP 10
    Link head, *p = &head;
    for (int i = 0; i < MAX_OP; i++) {
        //switch (rand() % 3) {
        //    case 0: p->next = getDataA(); break;
        //    case 1: p->next = getDataB(); break;
        //    case 2: p->next = getDataC(); break;
        //    case 3: break;
        //}
        p->next = getData[rand() % MAX_type]();
        p = p->next;
    }
    for (p = head.next; p; p = p->next) {
        //switch (p->type) {
        //    case A_type: output_A(p); break;
        //    case B_type: output_B(p); break;
        //    case C_type: output_C(p); break;
        //    case D_type: break;
        //    default: break;
        //}
        output[p->type](p);
    }
    return 0;
}
