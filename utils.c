#include "utils.h"

// Hàm này dùng để xóa dữ liệu trong buffer
void clearStdinBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Hàm này dùng để chuyển hết về chữ thường
char* stringLowerCopy(const char* str)  {
    size_t size  = strlen(str);
    char *lowerStr = (char*)malloc(size + 1);
    for(size_t i = 0; i <= size; i++)  {
        char oriChar = str[i];
        char convertChar = oriChar;
        if(oriChar >= 'A' && oriChar <= 'Z')    {
            convertChar = oriChar + 32;
        }
        lowerStr[i] = convertChar;
    }
    return lowerStr;
}

