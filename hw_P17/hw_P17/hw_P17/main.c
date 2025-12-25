#include <stdio.h>
#include <stdlib.h>

#define MAX 80

int main(void)
{
    FILE* fptr;
    char str[MAX];
    int bytes;

    fptr = fopen("output.txt", "r");

    if (fptr == NULL)
    {
        printf("檔案開啟失敗！\n");
        system("pause");
        return 1;
    }

    // 每次讀取最多 MAX-1 個字元，並在字串結尾加上 '\0'
    while ((bytes = fread(str, sizeof(char), MAX - 1, fptr)) > 0)
    {
        str[bytes] = '\0';              // 加上字串結尾符
        printf("%s", str);              // 直接印出（不加額外換行）
    }

    fclose(fptr);
    printf("\n\n檔案讀取完成！\n");
    system("pause");
    return 0;
}