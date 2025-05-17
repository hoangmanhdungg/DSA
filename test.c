#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc Học sinh
typedef struct Student {
    char id[10];
    char name[50];
    char classId[10];
    struct Student* next;
} Student;

// Định nghĩa cấu trúc Giáo viên
typedef struct Teacher {
    char id[10];
    char name[50];
    char classId[10];
    struct Teacher* next;
} Teacher;

// Định nghĩa cấu trúc Lớp học
typedef struct Class {
    char id[10];
    char name[50];
    struct Class* next;
} Class;

// Định nghĩa cấu trúc Biên lai
typedef struct Receipt {
    char id[10];
    char studentId[10];
    int month;
    int year;
    float amount;
    struct Receipt* next;
} Receipt;

// Định nghĩa cấu trúc quản lý
typedef struct {
    Student* students;
    Teacher* teachers;
    Class* classes;
    Receipt* receipts;
} Preschool;

// Khởi tạo hệ thống
void initPreschool(Preschool* ps) {
    ps->students = NULL;
    ps->teachers = NULL;
    ps->classes = NULL;
    ps->receipts = NULL;
}

// Tạo node mới
Student* createStudent(char* id, char* name, char* classId) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->id, id);
    strcpy(newStudent->name, name);
    strcpy(newStudent->classId, classId);
    newStudent->next = NULL;
    return newStudent;
}

Teacher* createTeacher(char* id, char* name, char* classId) {
    Teacher* newTeacher = (Teacher*)malloc(sizeof(Teacher));
    strcpy(newTeacher->id, id);
    strcpy(newTeacher->name, name);
    strcpy(newTeacher->classId, classId);
    newTeacher->next = NULL;
    return newTeacher;
}

Class* createClass(char* id, char* name) {
    Class* newClass = (Class*)malloc(sizeof(Class));
    strcpy(newClass->id, id);
    strcpy(newClass->name, name);
    newClass->next = NULL;
    return newClass;
}

Receipt* createReceipt(char* id, char* studentId, int month, int year, float amount) {
    Receipt* newReceipt = (Receipt*)malloc(sizeof(Receipt));
    strcpy(newReceipt->id, id);
    strcpy(newReceipt->studentId, studentId);
    newReceipt->month = month;
    newReceipt->year = year;
    newReceipt->amount = amount;
    newReceipt->next = NULL;
    return newReceipt;
}

// Thêm dữ liệu
void addStudent(Preschool* ps, char* id, char* name, char* classId) {
    Student* newStudent = createStudent(id, name, classId);
    newStudent->next = ps->students;
    ps->students = newStudent;
    printf("Them hoc sinh thanh cong!\n");
}

void addTeacher(Preschool* ps, char* id, char* name, char* classId) {
    Teacher* newTeacher = createTeacher(id, name, classId);
    newTeacher->next = ps->teachers;
    ps->teachers = newTeacher;
    printf("Them giao vien thanh cong!\n");
}

void addClass(Preschool* ps, char* id, char* name) {
    Class* newClass = createClass(id, name);
    newClass->next = ps->classes;
    ps->classes = newClass;
    printf("Them lop hoc thanh cong!\n");
}

void addReceipt(Preschool* ps, char* id, char* studentId, int month, int year, float amount) {
    Receipt* newReceipt = createReceipt(id, studentId, month, year, amount);
    newReceipt->next = ps->receipts;
    ps->receipts = newReceipt;
    printf("Them bien lai thanh cong!\n");
}

// Sửa dữ liệu
void editStudent(Preschool* ps, char* id, char* newName, char* newClassId) {
    Student* current = ps->students;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            strcpy(current->name, newName);
            strcpy(current->classId, newClassId);
            printf("Sua thong tin hoc sinh thanh cong!\n");
            return;
        }
        current = current->next;
    }
    printf("Khong tim thay hoc sinh voi ma so %s\n", id);
}

// Xóa dữ liệu
void deleteStudent(Preschool* ps, char* id) {
    Student* current = ps->students;
    Student* prev = NULL;

    while (current != NULL && strcmp(current->id, id) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Khong tim thay hoc sinh voi ma so %s\n", id);
        return;
    }

    if (prev == NULL) {
        ps->students = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Xoa hoc sinh thanh cong!\n");
}

// Tìm kiếm
void searchStudent(Preschool* ps, char* id) {
    Student* current = ps->students;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            printf("Ma HS: %s, Ho ten: %s, Lop: %s\n", 
                   current->id, current->name, current->classId);
            return;
        }
        current = current->next;
    }
    printf("Khong tim thay hoc sinh voi ma so %s\n", id);
}

// Thống kê
void statistics(Preschool* ps) {
    int studentCount = 0, teacherCount = 0, classCount = 0;
    float totalRevenue = 0;
    Student* s = ps->students;
    Teacher* t = ps->teachers;
    Class* c = ps->classes;
    Receipt* r = ps->receipts;

    while (s != NULL) { studentCount++; s = s->next; }
    while (t != NULL) { teacherCount++; t = t->next; }
    while (c != NULL) { classCount++; c = c->next; }
    while (r != NULL) { totalRevenue += r->amount; r = r->next; }

    printf("Tong so hoc sinh: %d\n", studentCount);
    printf("Tong so giao vien: %d\n", teacherCount);
    printf("Tong so lop hoc: %d\n", classCount);
    printf("Tong doanh thu hoc phi: %.2f\n", totalRevenue);
}

// Hiển thị danh sách
void displayStudents(Preschool* ps) {
    Student* current = ps->students;
    if (current == NULL) {
        printf("Danh sach hoc sinh rong!\n");
        return;
    }
    printf("\nDanh sach hoc sinh:\n");
    while (current != NULL) {
        printf("Ma HS: %s, Ho ten: %s, Lop: %s\n", 
               current->id, current->name, current->classId);
        current = current->next;
    }
}

// Giải phóng bộ nhớ
void freePreschool(Preschool* ps) {
    Student* s = ps->students;
    while (s != NULL) {
        Student* temp = s;
        s = s->next;
        free(temp);
    }
    Teacher* t = ps->teachers;
    while (t != NULL) {
        Teacher* temp = t;
        t = t->next;
        free

(temp);
    }
    Class* c = ps->classes;
    while (c != NULL) {
        Class* temp = c;
        c = c->next;
        free(temp);
    }
    Receipt* r = ps->receipts;
    while (r != NULL) {
        Receipt* temp = r;
        r = r->next;
        free(temp);
    }
}

// Menu chương trình
void menu() {
    printf("\n=== QUAN LY TRUONG MAM NON ===\n");
    printf("1. Them hoc sinh\n");
    printf("2. Them giao vien\n");
    printf("3. Them lop hoc\n");
    printf("4. Them bien lai hoc phi\n");
    printf("5. Sua thong tin hoc sinh\n");
    printf("6. Xoa hoc sinh\n");
    printf("7. Tim kiem hoc sinh\n");
    printf("8. Thong ke\n");
    printf("9. Hien thi danh sach hoc sinh\n");
    printf("0. Thoat\n");
    printf("Chon chuc nang: ");
}

int main() {
    Preschool ps;
    initPreschool(&ps);
    int choice;
    char id[10], name[50], classId[10], studentId[10];
    int month, year;
    float amount;

    do {
        menu();
        scanf("%d", &choice);
        getchar(); // Xóa ký tự newline

        switch (choice) {
            case 1: // Thêm học sinh
                printf("Nhap ma HS: ");
                fgets(id, 10, stdin);
                id[strcspn(id, "\n")] = 0;
                printf("Nhap ho ten: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Nhap ma lop: ");
                fgets(classId, 10, stdin);
                classId[strcspn(classId, "\n")] = 0;
                addStudent(&ps, id, name, classId);
                break;

            case 2: // Thêm giáo viên
                printf("Nhap ma GV: ");
                fgets(id, 10, stdin);
                id[strcspn(id, "\n")] = 0;
                printf("Nhap ho ten: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Nhap ma lop: ");
                fgets(classId, 10, stdin);
                classId[strcspn(classId, "\n")] = 0;
                addTeacher(&ps, id, name, classId);
                break;

            case 3: // Thêm lớp học
                printf("Nhap ma lop: ");
                fgets(id, 10, stdin);
                id[strcspn(id, "\n")] = 0;
                printf("Nhap ten lop: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0;
                addClass(&ps, id, name);
                break;

            case 4: // Thêm biên lai
                printf("Nhap ma bien lai: ");
                fgets(id, 10, stdin);
                id[strcspn(id, "\n")] = 0;
                printf("Nhap ma HS: ");
                fgets(studentId, 10, stdin);
                studentId[strcspn(studentId, "\n")] = 0;
                printf("Nhap thang: ");
                scanf("%d", &month);
                printf("Nhap nam: ");
                scanf("%d", &year);
                printf("Nhap so tien: ");
                scanf("%f", &amount);
                addReceipt(&ps, id, studentId, month, year, amount);
                break;

            case 5: // Sửa học sinh
                printf("Nhap ma HS can sua: ");
                fgets(id, 10, stdin);
                id[strcspn(id, "\n")] = 0;
                printf("Nhap ho ten moi: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Nhap ma lop moi: ");
                fgets(classId, 10, stdin);
                classId[strcspn(classId, "\n")] = 0;
                editStudent(&ps, id, name, classId);
                break;

            case 6: // Xóa học sinh
                printf("Nhap ma HS can xoa: ");
                fgets(id, 10, stdin);
                id[strcspn(id, "\n")] = 0;
                deleteStudent(&ps, id);
                break;

            case 7: // Tìm kiếm học sinh
                printf("Nhap ma HS can tim: ");
                fgets(id, 10, stdin);
                id[strcspn(id, "\n")] = 0;
                searchStudent(&ps, id);
                break;

            case 8: // Thống kê
                statistics(&ps);
                break;

            case 9: // Hiển thị danh sách học sinh
                displayStudents(&ps);
                break;

            case 0: // Thoát
                printf("Tam biet!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);

    freePreschool(&ps);
    return 0;
}