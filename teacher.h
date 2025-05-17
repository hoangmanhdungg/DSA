#ifndef TEACHER_H
#define TEACHER_H

#include <stdio.h>
#include <define.h>

typedef struct Teacher  {
    char ID_Teacher[MAX_ID];
    char Name[MAX_NAME];
    char Date[MAX_DATE];
    char Gender[10];
    int Phone[MAX_PHONE];
    char Address[MAX_ADDRESS];
    char Class[MAX_ID];
    struct Teacher *next;
}   Teacher;

#endif 