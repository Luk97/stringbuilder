#include "stringbuilder.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define N 256

int test_succeeded = 0;
int test_failed = 0;

void print_logs_str(const char *name, const char *expected, const char *result) {
    if (strcmp(expected, result) == 0) {
        printf("Test \"%s\" passed.\n", name);
        test_succeeded++;
    } else {
        printf("ERROR: In \"%s\" expected %s, but got %s\n", name, expected, result);
        test_failed++;
    }
}

void print_log_bool(const char *name, bool expected, bool result) {
    if (expected == result) {
        printf("Test \"%s\" passed.\n", name);
        test_succeeded++;
    } else {
        printf("ERROR: In \"%s\" expected %s, but got %s\n", name, expected ? "true" : "false", result ? "true" : "false");
        test_failed++;
    }
}

void print_log_int(const char *name, int expected, int result) {
    if (expected == result) {
        printf("Test \"%s\" passed.\n", name);
        test_succeeded++;
    } else {
        printf("ERROR: In \"%s\" expected %d, but got %d\n", name, expected, result);
        test_failed++;
    }
}

void test_isspace() {
    print_log_bool("sb_isspace(' ') == isspace(' ')", sb_isspace(' '), isspace(' '));
    print_log_bool("sb_isspace('a') == isspace('a')", sb_isspace('a'), isspace('a'));
    print_log_bool("sb_isspace('\\n') == isspace('\\n')", sb_isspace('\n'), isspace('\n'));
    print_log_bool("sb_isspace('\\r') == isspace('\\¶')", sb_isspace('\r'), isspace('\r'));
    print_log_bool("sb_isspace('\\f') == isspace('\\f')", sb_isspace('\f'), isspace('\f'));
    print_log_bool("sb_isspace('\\t') == isspace('\\t')", sb_isspace('\t'), isspace('\t'));
    print_log_bool("sb_isspace('\\v') == isspace('\\v')", sb_isspace('\v'), isspace('\v'));
}

void test_isdigit() {
    print_log_bool("sb_isdigit('0') == isdigit('0')", sb_isdigit('0'), isdigit('0'));
    print_log_bool("sb_isdigit('9') == isdigit('9')", sb_isdigit('9'), isdigit('9'));
    print_log_bool("sb_isdigit('a') == isdigit('a')", sb_isdigit('a'), isdigit('a'));
    print_log_bool("sb_isdigit(' ') == isdigit(' ')", sb_isdigit(' '), isdigit(' '));
}

void test_isletter() {
    print_log_bool("sb_isletter('a') == isletter('a')", sb_isletter('a'), isalpha('a'));
    print_log_bool("sb_isletter('z') == isletter('z')", sb_isletter('z'), isalpha('z'));
    print_log_bool("sb_isletter('A') == isletter('A')", sb_isletter('A'), isalpha('A'));
    print_log_bool("sb_isletter('Z') == isletter('Z')", sb_isletter('Z'), isalpha('Z'));
    print_log_bool("sb_isletter('5') == isletter('5')", sb_isletter('5'), isalpha('5'));
    print_log_bool("sb_isletter(' ') == isletter(' ')", sb_isletter(' '), isalpha(' '));
    print_log_bool("sb_isletter('\\n') == isletter('\\n')", sb_isletter('\n'), isalpha('\n'));
}

void test_islower() {
    print_log_bool("sb_islower('A') == islower('A')", sb_islower('A'), islower('A'));
    print_log_bool("sb_islower('Z') == islower('Z')", sb_islower('Z'), islower('Z'));
    print_log_bool("sb_islower('a') == islower('a')", sb_islower('a'), islower('a'));
    print_log_bool("sb_islower('z') == islower('z')", sb_islower('z'), islower('z'));
    print_log_bool("sb_islower('1') == islower('1')", sb_islower('1'), islower('1'));
    print_log_bool("sb_islower(' ') == islower(' ')", sb_islower(' '), islower(' '));
}

void test_isupper() {
    print_log_bool("sb_isupper('A') == isupper('A')", sb_isupper('A'), isupper('A'));
    print_log_bool("sb_isupper('Z') == isupper('Z')", sb_isupper('Z'), isupper('Z'));
    print_log_bool("sb_isupper('a') == isupper('a')", sb_isupper('a'), isupper('a'));
    print_log_bool("sb_isupper('z') == isupper('z')", sb_isupper('z'), isupper('z'));
    print_log_bool("sb_isupper('1') == isupper('1')", sb_isupper('1'), isupper('1'));
    print_log_bool("sb_isupper(' ') == isupper(' ')", sb_isupper(' '), isupper(' '));
}

void test_strlen() {
    const char *s1 = "Hello";
    const char *s2 = "";
    const char *s3 = "\n";
    print_log_int("sb_strlen(\"Hello\") == strlen(\"Hello\")", sb_strlen(s1), strlen(s1));
    print_log_int("sb_strlen(\"\") == strlen(\"\")", sb_strlen(s2), strlen(s2));
    print_log_int("sb_strlen(\"\") == strlen(\"\")", sb_strlen(s2), strlen(s2));
    print_log_int("sb_strlen(\"\\n\") == strlen(\"\\n\")", sb_strlen(s3), strlen(s3));
}

void test_strcat() {
    char s1[N] = "Hello";
    char s2[N] = "World";
    print_logs_str("sb_strcat(\"Hello\", \"World\") == strcat(\"Hello\", \"World\")", sb_strcat(s1, s2), strcat(s1, s2));
    char s3[N] = "";
    char s4[N] = "Hello World";
    print_logs_str("sb_strcat(\"\", \"Hello World\") == strcat(\"\", \"Hello World\")", sb_strcat(s3, s4), strcat(s3, s4));
    char s5[N] = "Hello World";
    char s6[N] = "";
    print_logs_str("sb_strcat(\"Hello World\", \"\") == strcat(\"Hello World\", \"\")", sb_strcat(s5, s6), strcat(s5, s6));

    char s7[N] = "Hello";
    char s8[N] = "Sea";
    print_logs_str("sb_strcat(\"Hello\", \"Sea\") == strcat(\"Hello\", \"Sea\")", sb_strcat(s7, s8), strcat(s7, s8));
    char s9[N] = "Moin";
    char s10[N] = "World";
    print_logs_str("sb_strcat(\"Moin\", \"World\") == strcat(\"Moin\", \"World\")", sb_strcat(s9, s10), strcat(s9, s10));
}

void test_strncat() {
    char s1[N] = "Hello";
    char s2[N] = "World";
    print_logs_str("sb_strncat(\"Hello\", \"World\", 3) == strncat(\"Hello\", \"World\", 3)", sb_strncat(s1, s2, 3), strncat(s1, s2, 3));
    char s3[N] = "Hello";
    char s4[N] = "World";
    print_logs_str("sb_strncat(\"Hello\", \"World\", 10) == strncat(\"Hello\", \"World\", 10)", sb_strncat(s3, s4, 10), strncat(s3, s4, 10));
    char s5[N] = "Hello";
    char s6[N] = "World";
    print_logs_str("sb_strncat(\"Hello\", \"World\", 0) == strncat(\"Hello\", \"World\", 0)", sb_strncat(s5, s6, 0), strncat(s5, s6, 0));
}


int main() {

    test_isspace();
    test_isdigit();
    test_isletter();
    test_islower();
    test_isupper();
    test_strlen();
    test_strcat();
    test_strncat();

    // TODO:
    /*
    sb_strcpy()
    sb_strncpy()
    sb_strcmp()
    sb_strncmp()
    sb_upper()
    sb_lower()
    sb_trim()
    sb_trim_left()
    sb_trim_right()
    sb_find()
    sb_findchar()
    sb_count()
    sb_countchar()
    sb_replace()
    sb_replacechar()
    
    */

    printf("%d tests executed. %d passed and %d failed.\n", test_succeeded + test_failed, test_succeeded, test_failed);

    return 0;
}