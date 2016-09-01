#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int a;
    int b;
} mystruct;

int fun_alloc(mystruct **allocint) {
    *allocint = (mystruct *) malloc (sizeof(mystruct));
    (*allocint)->a = 10;
    (*allocint)->b = 20;
     return 0;
}

int fun_alloc2(mystruct *mySt) {
    mySt->a = 30;
    mySt->b = 40;
    return 0;
}

void set_callback(void(*foo)(mystruct*)) {
    mystruct mySt;
    mySt.a = 50;
    mySt.b = 60;
    foo(&mySt);
}
