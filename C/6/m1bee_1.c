#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main() 
{
    //_itoa
    printf_s("_itoa\n");
    int a = 32147;
    char array[50];
    _itoa(a, array, 2);   //2 means binary
    printf("%s\n", array);

    _itoa(a, array, 10);   //10 means decimal
    printf("%s\n\n", array);

    //_ltoa
    printf_s("_ltoa\n");
    _ltoa(a, array, 16);   
    printf("%s\n\n", array);

    //_gcvt
    printf_s("_gcvt\n");
    _gcvt(24.68, 5, array);
    printf_s("%s\n\n", array);

    //atoi
    printf_s("atoi\n");
    const char* Str = "652.23brrt";
    int Num = 0;
    Num = atoi(Str);
    printf("%d\n\n", Num);
   
    //atol
    printf_s("atol\n");
    long int num = 0;
    num = atol(Str);
    printf_s("%1d\n\n", num);

    //strtol
    printf_s("strtol\n");
    char str[30] = "2098 text";
    char* ptr;
    long ret;
    ret = strtol(str, &ptr, 10);
    printf_s("%1d\n\n", ret);

    //strtod
    printf_s("strtod\n");
    char str2[30] = "2098.652 text";
    char* ptr2;
    double ret2;
    ret2 = strtod(str2, &ptr2);
    printf_s("%1f\n\n\n", ret2);

    //strlen
    printf_s("strlen\n");
    char text[6] = "hello";
    printf_s("%1d\n\n", strlen(text));

    //strcmp
    //0	if both strings are equal
    //-1 if the ASCII value of the first line is less than second
    //1 if the ASCII value of the first line is greater than second
    printf_s("strcmp\n");
    char line1[] = "abcGGd", line2[] = "abCd", line3[] = "abcd";
    int result;

    // comparing strings line1 and line2
    result = strcmp(line1, line2);
    printf_s("strcmp(line1, line2) = %d\n", result);

    // comparing strings line1 and line3                             
    result = strcmp(line1, line3);
    printf_s("strcmp(line1, line3) = %d\n\n", result);

    //strncmp and strcpy
    printf_s("strncmp and strcpy\n");
    char string1[20];
    char string2[20];
    int res;

    //Assigning the value to the string str1
    strcpy(string1, "hello");

    //Assigning the value to the string str2
    strcpy(string2, "helLO WORLD");

    //This will compare the first 5 characters
    res = strncmp(string1, string2, 5);

    if (res > 0) {
        printf_s("ASCII value of string1 is greater than string2");
    }
    else if (res < 0) {
        printf_s("ASCII value ofstring1 is less than string2");
    }
    else {
        printf_s("Both the strings are equal");
    }

    //strncpy
    printf_s("\n\nstrncpy\n");
    char src[40];
    char dest[40];
    memset(dest, '\0', sizeof(dest));
    strcpy(src, "Welcome to this part");
    strncpy(dest, src, 15);
    printf_s("Final copied string : %s\n\n", dest);

    //strcat
    printf_s("strcat\n");
    strcpy(src, "This is source");
    strcpy(dest, "This is destination");
    strcat(dest, src);
    printf_s("Final destination string : |%s|\n\n", dest);

    //srncat
    printf_s("strncat\n");
    strcpy(src, "This is source");
    strcpy(dest, "This is destination");
    strncat(dest, src, 4);
    printf_s("Final destination string : |%s|\n", dest);
    return 0;
}

    