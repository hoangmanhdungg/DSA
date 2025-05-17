#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"

Student *LinkedList = NULL;
int main()  {
    displayStudentList(LinkedList);
    Student HocSinh1;
    strcpy(HocSinh1.ID_Student, "HS001");
    strcpy(HocSinh1.Name, "Nguyen Van An");
    strcpy(HocSinh1.Date, "10/10/2018");
    strcpy(HocSinh1.Gender, "Nam");
    strcpy(HocSinh1.NameParent, "Nguyen Van Ba");
    strcpy(HocSinh1.PhoneParent, "090111222");
    strcpy(HocSinh1.Address, "123 Duong A, Q1");
    strcpy(HocSinh1.Class, "L01");
    Student HocSinh2;
    strcpy(HocSinh2.ID_Student, "HS002");
    strcpy(HocSinh2.Name, "Nguyen Van Tung");
    strcpy(HocSinh2.Date, "10/9/2018");
    strcpy(HocSinh2.Gender, "Nu");
    strcpy(HocSinh2.NameParent, "Nguyen Van Bai");
    strcpy(HocSinh2.PhoneParent, "090111222");
    strcpy(HocSinh2.Address, "123 Duong A, Q1");
    strcpy(HocSinh2.Class, "L01");
    Student *Node1;
    Student *Node2;
    Node1 = createStudentNode(HocSinh1);
    Node2 = createStudentNode(HocSinh2);
    addStudentToList(&LinkedList, Node1);
    addStudentToList(&LinkedList, Node2);
    findStudent(LinkedList, "Tung");
    displayStudentList(LinkedList);
    deleteStudentByID(&LinkedList, "HS001" );
    displayStudentList(LinkedList);
}
 