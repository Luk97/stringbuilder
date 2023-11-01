#ifndef STRINGBUILDER_H_
#define STRINGBUILDER_H_

#include <stddef.h>
#include <stdbool.h>


// Returns true if c is a space or lineformat character.
bool sb_isspace(char c);
// Returns true if c is a digit 0..9.
bool sb_isdigit(char c);
// Returns true if c is a letter a..z or A..Z.
bool sb_isletter(char c);
// Returns true if c is a lowercase letter a..z.
bool sb_islower(char c);
// Returns true if c is an uppercase letter A..Z.
bool sb_isupper(char c);

/*
INFO:       Calculates the length of a string.
RETURN:     Returns the number of characters in str.
            Returns 0 if the string is empty or no string was provided.
WARNING:    str needs to contain a null byte, otherwise the functions gets stuck.
*/
size_t sb_strlen(const char *str);

/*
INFO:       Combines two strings together. Dst becomes the start of the combined string.
RETURN:     Returns a pointer to the start of dst, which is now modified as the combined strings.
            Returns NULL if either dst or src were not provided.
WARNING:    Dst gets modfied. It needs to provide enough memory to store the characters of both strings.
            sb_strncat might be not null-terminated, if src is equal or larger than n bytes.
*/
char *sb_strcat(char *dst, const char *src);
char *sb_strncat(char *dst, const char *src, size_t n);

/*
INFO:       Copies the bytes on one string into another string.
RETURN:     Returns a pointer to the copied string.
            Returns NULL if either dst or src were not provided.
WARNING:    Dst gets modified. It needs to provide enough memory to store the characters of both strings.
            sn_strncpy might be not null-terminated, if src is equal or larger than n bytes.
*/
char *sb_strcpy(char *dst, const char *src);
char *sb_strncpy(char *dst, const char *src, size_t n);

/*
INFO:       Compares two string lexicographically.
RETURN:     Returns 0 if the strings are lexicographically the same, a negative number if s1 is smaller
            and a positive number if s1 is larger than s2.
WARNING:    If both strings are not null-terminated, the functions will get stuck.
*/
int sb_strcmp(const char *s1, const char *s2);
int sb_strncmp(const char *s1, const char *s2, size_t n);

/*
INFO:       Making a string all lowercase or all uppercase.
RETURN:     Returns a pointer to the beginning of the string, that got passed to the function.
WARNING:    If s is allocated from the heap, sb_strcpy(s, stringliteral) should be called
            before passing it to this functions.
*/
char *sb_upper(char *s);
char *sb_lower(char *s);

/*
INFO:       Trims either left whitespaces, right whitespaces or both off a string.
RETURN:     Returns a pointer to the beginning of the modified string s.
WARNING:    trim and trimright put a zero byte at the end to trim off the outer part of the string.
*/
char *sb_trim(char *s);
char *sb_trimleft(char *s);
char *sb_trimright(char *s);

char *sb_find(char *s, const char *substr);
char *sb_findchar(char *s, char c);

size_t sb_count(char *s, const char *substr);
size_t sb_countchar(char *s, char c);

char *sb_replace(char *string, const char *old_substring, const char *new_substring);
char *sb_replace_char(char *string, char old_char, char new_char);

// TODO: think about overall syntax: sb_findstr or sb_find_str or sb_findStr ??? and about param names
// TODO: Testing, split, remove, substring, replace, shuffle

#endif // STRINGBUILDER_H_