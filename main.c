#include "stringbuilder.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void test_strcmp() {
    char *s1 = "Test";
    char *s2 = "test";
    char *s3 = "";
    char *s4 = "Tesb";
    char *s5 = "tes";
    char *s6 = "teste";

    printf("strcmp(%s, %s) == %d, expected %d\n", s1, s1, sb_strcmp(s1, s1), strcmp(s1, s1));
    printf("strcmp(%s, %s) == %d, expected %d\n", s1, s2, sb_strcmp(s1, s2), strcmp(s1, s2));
    printf("strcmp(%s, %s) == %d, expected %d\n", s1, s3, sb_strcmp(s1, s3), strcmp(s1, s3));
    printf("strcmp(%s, %s) == %d, expected %d\n", s1, s4, sb_strcmp(s1, s4), strcmp(s1, s4));
    printf("strcmp(%s, %s) == %d, expected %d\n", s2, s5, sb_strcmp(s2, s5), strcmp(s2, s5));
    printf("strcmp(%s, %s) == %d, expected %d\n", s2, s6, sb_strcmp(s2, s6), strcmp(s2, s6));
    printf("strcmp(%s, %s) == %d, expected %d\n", s3, s3, sb_strcmp(s3, s3), strcmp(s3, s3));

}
void test_strncmp() {
    char *s1 = "Test";
    char *s2 = "Testing";
    char *s3 = "abc";
    char *s4 = "abd";
    

    printf("strncmp(%s, %s) == %d, expected %d\n", s1, s1, sb_strncmp(s1, s1, 2), strncmp(s1, s1, 2));
    printf("strncmp(%s, %s) == %d, expected %d\n", s1, s1, sb_strncmp(s1, s1, 4), strncmp(s1, s1, 4));
    printf("strncmp(%s, %s) == %d, expected %d\n", s1, s1, sb_strncmp(s1, s1, 0), strncmp(s1, s1, 0));
    printf("strncmp(%s, %s) == %d, expected %d\n", s1, s1, sb_strncmp(s1, s1, 5), strncmp(s1, s1, 5));
    printf("strncmp(%s, %s) == %d, expected %d\n", s1, s1, sb_strncmp(s1, s1, 1), strncmp(s1, s1, 1));

    printf("strncmp(%s, %s) == %d, expected %d\n", s1, s2, sb_strncmp(s1, s2, 4), strncmp(s1, s2, 4));
    printf("strncmp(%s, %s) == %d, expected %d\n", s2, s1, sb_strncmp(s2, s1, 4), strncmp(s2, s1, 4));
    printf("strncmp(%s, %s) == %d, expected %d\n", s1, s2, sb_strncmp(s1, s2, 6), strncmp(s1, s2, 6));
    printf("strncmp(%s, %s) == %d, expected %d\n", s2, s1, sb_strncmp(s2, s1, 6), strncmp(s2, s1, 6));

    printf("strncmp(%s, %s) == %d, expected %d\n", s3, s4, sb_strncmp(s3, s4, 3), strncmp(s3, s4, 3));
    printf("strncmp(%s, %s) == %d, expected %d\n", s3, s4, sb_strncmp(s3, s4, 2), strncmp(s3, s4, 2));
    printf("strncmp(%s, %s) == %d, expected %d\n", s3, s4, sb_strncmp(s3, s4, 6), strncmp(s3, s4, 6));
}

void test_replace() {
    char s1[] = "Bye Bye People";
    const char *s2 = "World";
    const char *s3 = "Again";
    const char *s4 = "Sea";
    char s5[] = "Hello World";
    const char *s6 = "Bye";

    printf("%s\n", s1);
    printf("%s\n", sb_replace_str(s5, s2, s6));
}

int main() {
    //test_strcmp();
    //test_strncmp();

    test_replace();
    
    
    return 0;
}