#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------------------------------------------------------------------
 * String: dynamic struct similar to std::string
 * ---------------------------------------------------------------------
 * - data: char buffer, always null-terminated
 * - length: number of "useful" characters (not counting the '\0')
 * - capacity: allocated size of the buffer
 *
 * ------------------------------------------------------------------- */
typedef struct {
  char *data;
  size_t length;
  size_t capacity;
} String;

/* ---------------------------- create / destroy ---------------------------- */

static inline String string_create(void) {
  String s;
  s.capacity = 16;
  s.length = 0;
  s.data = (char *)malloc(s.capacity);
  s.data[0] = '\0';
  return s;
}

static inline String string_from_cstr(const char *cstr) {
  size_t len = strlen(cstr);
  String s;
  s.capacity = len + 1;
  s.length = len;
  s.data = (char *)malloc(s.capacity);
  memcpy(s.data, cstr, len + 1);
  return s;
}

static inline void string_free(String *s) {
  free(s->data);
  s->data = NULL;
  s->length = 0;
  s->capacity = 0;
}

/* -------------------------------- growth -------------------------------- */

static inline void string_reserve(String *s, size_t new_cap) {
  if (new_cap <= s->capacity)
    return;
  char *new_data = (char *)realloc(s->data, new_cap);
  if (!new_data) {
    fprintf(stderr, "string_reserve: allocation failed\n");
    exit(EXIT_FAILURE);
  }
  s->data = new_data;
  s->capacity = new_cap;
}

static inline void string_push_back(String *s, char c) {
  if (s->length + 1 >= s->capacity) {
    string_reserve(s, s->capacity * 2);
  }
  s->data[s->length] = c;
  s->length += 1;
  s->data[s->length] = '\0';
}

static inline void string_append_cstr(String *s, const char *cstr) {
  size_t add_len = strlen(cstr);
  if (s->length + add_len + 1 > s->capacity) {
    size_t new_cap = s->capacity * 2;
    while (new_cap < s->length + add_len + 1)
      new_cap *= 2;
    string_reserve(s, new_cap);
  }
  memcpy(s->data + s->length, cstr, add_len + 1);
  s->length += add_len;
}

static inline void string_clear(String *s) {
  s->length = 0;
  s->data[0] = '\0';
}

/* --------------------------------- access --------------------------------- */

static inline char string_at(const String *s, size_t idx) {
  if (idx >= s->length) {
    fprintf(stderr, "string_at: index out of bounds\n");
    exit(EXIT_FAILURE);
  }
  return s->data[idx];
}

static inline const char *string_cstr(const String *s) { return s->data; }

/* ---------------------- forward iteration (begin/end) ----------------------
 */
/* usage: for (char *it = string_begin(&s); it != string_end(&s); ++it) */

static inline char *string_begin(String *s) { return s->data; }
static inline char *string_end(String *s) { return s->data + s->length; }

/* --------------------- reverse iteration (rbegin/rend) ---------------------
 */

static inline char *string_rbegin(String *s) {
  return (s->length == 0) ? s->data - 1 : s->data + s->length - 1;
}
static inline char *string_rend(String *s) { return s->data - 1; }

/* ------------------------------ reading stdin ------------------------------
 */
/* Reads a full line from stdin (no fixed size, grows as needed).
 * Returns 1 if something was read, 0 on EOF with nothing read. */

static inline int string_read_line(String *s) {
  string_clear(s);
  int c;
  int got_any = 0;
  while ((c = fgetc(stdin)) != EOF) {
    got_any = 1;
    if (c == '\n')
      break;
    string_push_back(s, (char)c);
  }
  return got_any;
}

#endif /* MYSTRING_H */
