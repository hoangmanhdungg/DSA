#ifndef RECEIPT_H
#define RECEIPT_H

#include <stdio.h>
#include <define.h>

typedef struct Receipt  {
    char ID_Receipt[MAX_ID];
    char ID_Student[MAX_ID];
    char Date[MAX_DATE];
    double Amount;
    int Month;
    int Year;
    char Status[MAX_STATUS];
    struct Receipt *next;
}   Class;

#endif CLASS_H
