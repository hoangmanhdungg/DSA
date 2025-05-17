#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
#include "utils.h"

// Hàm tạo Node để thêm vào danh sách
Student* createStudentNode(Student dataStudent)    {
    Student *newNode = (Student*)malloc(sizeof(Student));
    strcpy(newNode->ID_Student, dataStudent.ID_Student);
    strcpy(newNode->Name, dataStudent.Name);
    strcpy(newNode->Date, dataStudent.Date);
    strcpy(newNode->Gender, dataStudent.Gender);
    strcpy(newNode->Address, dataStudent.Address);
    strcpy(newNode->NameParent, dataStudent.NameParent);
    strcpy(newNode->PhoneParent, dataStudent.PhoneParent);
    strcpy(newNode->Class, dataStudent.Class);
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm Node vào danh sách
void addStudentToList(Student **LinkedListStudent, Student *newNode) {
    newNode->next = *LinkedListStudent;
    *LinkedListStudent = newNode;
}

// Hàm hiển thị danh sách
void displayStudentList(Student *LinkedList)    {
    Student *ptr = LinkedList;
    int count = 0;
    printf("\n--- DANH SACH HOC SINH ---\n");
    if(ptr == NULL) {
        printf("Danh sach hoc sinh rong.\n");
        printf("--------------------------\n");
    }
    else{
        printf("%-5s %-10s %-25s %-10s\n", "STT", "Ma HS", "Ho Ten", "Lop");
        printf("----------------------------------------------------\n");
        while(ptr != NULL)  {
            printf("%-5d %-10s %-25s %-10s\n", count, ptr->ID_Student, ptr->Name, ptr->Class);
            ptr = ptr->next; 
        }
        printf("----------------------------------------------------\n");
        printf("Tong so hoc sinh: %d\n", count);
        printf("----------------------------------------------------\n");
    }
    
}

// Hàm tím kiếm nút 
int findStudent(Student *LinkedList, const char* nameQuery)   {
    Student *ptr = LinkedList;
    int count = 0;
    int foundCount = 0;
    printf("\n---------KET QUA TIM KIEM---------\n");
    if(LinkedList == NULL)  {
        printf("Danh sach rong.\n");
        printf("----------------------------------");
        return 0;
    }
    if(nameQuery == NULL || strlen(nameQuery) == 0)   {
        printf("Vui long nhap ten hoc sinh can tim.\n");
        printf("-----------------------------------------\n");
        return 0;
    }
    char *lowerNameQuery = stringLowerCopy(nameQuery);
    printf("%-5s %-10s %-25s %-10s\n", "STT", "Ma HS", "Ho Ten", "Ma Lop");
    printf("----------------------------------------------------\n");
    while (ptr != NULL) {
        count++;
        char *lowerPtrName = stringLowerCopy(ptr->Name); 
        if (lowerPtrName != NULL) {
            if (strstr(lowerPtrName, lowerNameQuery) != NULL) {
                foundCount++;
                printf("%-5d %-10s %-25s %-10s\n",foundCount, ptr->ID_Student, ptr->Name, ptr->Class);
            }
            free(lowerPtrName);
        }
        ptr = ptr->next;
    }
    free(lowerNameQuery);
    if (foundCount == 0) {
        printf("Khong tim thay hoc sinh nao co ten chua '%s'.\n", nameQuery);
    }
    printf("----------------------------------------------------\n");
    printf("Tim thay %d hoc sinh.\n", foundCount);
    printf("-----------------------------------------\n");
    return foundCount; 
}
