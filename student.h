#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include "define.h"


typedef struct Student  {
    char ID_Student[MAX_ID];
    char Name[MAX_NAME];
    char Date[MAX_DATE];
    char Gender[10];
    char NameParent[MAX_NAME];
    char PhoneParent[MAX_PHONE];
    char Address[MAX_ADDRESS];
    char Class[MAX_ID];
    struct Student *next;
}   Student;

Student* createStudentNode(Student dataStudent);  
void addStudentToList(Student **LinkedListStudent, Student *newNode);
void displayStudentList(Student *LinkedList);
int findStudent(Student *LinkedList, const char* nameQuery);

#endif 
