#include "stringbuilder.h"
#include <stdio.h>

bool sb_isspace(char c) {
    return c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v';
}

bool sb_isdigit(char c) {
    return c >= '0' && c <= '9';
}

bool sb_isletter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool sb_islower(char c) {
    return c >= 'a' && c <= 'z';
}

bool sb_isupper(char c) {
    return c >= 'A' && c <= 'Z';
}

size_t sb_strlen(const char *str) {
    int len = 0;
    while(str[len]) {
        len++;
    }
    return len;
}

char *sb_strcat(char *dst, const char *src) {
    size_t dst_len = sb_strlen(dst);
    size_t i;
    for (i = 0; src[i] != '\0'; ++i) {
        dst[dst_len + i] = src[i]; 
    }
    dst[dst_len + i + 1] = '\0';

    return dst;
}

char *sb_strncat(char *dst, const char *src, size_t n) {
    size_t dst_len = sb_strlen(dst);
    size_t i;
    for (i = 0; i < n && i != '\0'; ++i) {
        dst[dst_len+i] = src[i];
    }
    for (; i < n; ++i) {
        dst[dst_len+i] = '\0';
    }
    return dst;
}

char *sb_strcpy(char *dst, const char *src) {   
    size_t i;
    for (i = 0; src[i] != '\0'; ++i) {
        dst[i] = src[i];
    }
    dst[i+1] = '\0';

    return dst;
}

char *sb_strncpy(char *dst, const char *src, size_t n) {
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; ++i) {
        dst[i] = src[i];
    }
    for (; i < n; ++i) {
        dst[i] = '\0';
    }

    return dst;
}



int sb_strcmp(const char *s1, const char *s2) {
    size_t i;
    for (i = 0; s1[i] != '\0' || s2[i] != '\0'; ++i) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }

    return s1[i] - s2[i];
}

int sb_strncmp(const char *s1, const char *s2, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        if (s1[i] == '\0' || s2[i] == '\0' || s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}

char *sb_upper(char *s) {
    for (size_t i = 0; i < sb_strlen(s); ++i) {
        if (sb_islower(s[i])) {
            s[i] -= 32;
        }
    }

    return s;
}

char *sb_lower(char *s) {
    for (size_t i = 0; i < sb_strlen(s); ++i) {
        if (sb_isupper(s[i])) {
            s[i] += 32;
        }
    }

    return s;
}

char *sb_trim(char *s) {
    return sb_trimleft(sb_trimright(s));
}

char *sb_trimleft(char *s) {
    char *trim = s;
    while (sb_isspace(*trim)) {
        trim++;
    }

    size_t i;
    for (i = 0; i < sb_strlen(trim); ++i) {
        s[i] = trim[i];
    }
    s[i] = '\0';
    return s;
}

char *sb_trimright(char *s) {
    char *trim = s + sb_strlen(s) - 1;
    while (sb_isspace(*trim)) {
        trim--;
    }
    *(trim+1) = '\0';
    return s;
}
char *sb_find(char *s, const char *substr) {
    char *search = s;

    while (*search != '\0') {
        if (*search == *substr) {
            if (sb_strncmp(search, substr, sb_strlen(substr)) == 0) {
                return search;
            }
        }
        search++;
    }
    return NULL;
}

char *sb_findchar(char *s, char c) {
    char *search = s;
    while (*search != '\0') {
        if (*search == c) return search;
        search++;
    }
    return NULL;
}

size_t sb_count(char *s, const char *substr) {
    char *search = s;
    size_t count = 0;
    
    while (*search != '\0') {
        if (*search == *substr) {
            if (sb_strncmp(search, substr, sb_strlen(substr)) == 0) {
                count++;
            }
        }
        search++;
    }
    return count;
}


size_t sb_countchar(char *s, char c) {
    char *search = s;
    size_t count = 0;
    while (*search != '\0') {
        if (*search == c) count++;
        search++;
    }
    return count;
}

char *sb_replace(char *string, const char *old_substring, const char *new_substring) {
    char *s = string;
    size_t old_string_len = sb_strlen(old_substring);
    size_t new_string_len = sb_strlen(new_substring);

    while (*s != '\0') {
        if (sb_strncmp(s, old_substring, old_string_len) == 0) {

            if (old_string_len == new_string_len) {
                for (size_t i = 0; i < new_string_len; ++i) {
                    *s = new_substring[i];
                    s++;
                }

            } else if (old_string_len > new_string_len) {
                for (size_t i = 0; i < new_string_len; ++i) {
                    *s = new_substring[i];
                    s++;
                }
                size_t size_diff = old_string_len - new_string_len;
                for (size_t i = 0; i < sb_strlen(s) - size_diff; ++i) {
                    *s = s[i+size_diff];
                    s++;
                }
                for (size_t i = 0; i < size_diff; ++i) {
                    s[i] = '\0';
                }

            } else if (old_string_len < new_string_len) {
                //size_t size_diff = old_string_len - new_string_len;
                for (size_t i = 0; i < old_string_len; ++i) {
                    *s = new_substring[i];
                    s++;
                }
                // TODO: shift all char to the right to make room for extra new_substr chars
            }
        }
        s++;
    }
    return string;
}

char *sb_replace_char(char *string, char old_char, char new_char) {
    char *s = string;
    while (*s != '\0') {
        if (*s == old_char) *s = new_char;
        s++;
    }
    return string;
}