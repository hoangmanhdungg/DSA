#ifndef CLASS_H
#define CLASS_H

#include <stdio.h>
#include <define.h>

typedef struct Class  {
    char ID_Class[MAX_ID];
    char NameTeacher[MAX_NAME];
    struct Class *next;
}   Class;

#endif CLASS_H
