#include <stdio.h>
#define NOB_IMPLEMENTATION
#include "nob.h"

typedef struct {
  Nob_String_View key;
  size_t value;
} FreqKV;

typedef struct {
  FreqKV *items;
  size_t count;
  size_t capacity;
} FreqKVs;

FreqKV *find_key(FreqKVs haystack, Nob_String_View needle) {
  for (size_t i = 0; i < haystack.count; ++i) {
    nob_sv_eq(haystack.items[i].key, needle);
    if (nob_sv_eq(haystack.items[i].key, needle)) {
      return &haystack.items[i];
    }
  }
  return NULL;
}

int main(void) {
  const char *file_path = "t8.shakespeare.txt";
  Nob_String_Builder buf = {0};
  if (!nob_read_entire_file(file_path, &buf)) return 1;
  nob_log(NOB_INFO, "Size of %s is %zu bytes", file_path, buf.count);

  Nob_String_View content = {
    .data = buf.items,
    .count = buf.count,
  };

  FreqKVs freq = {0};

  size_t count = 0;
  for (; content.count > 0; count++) {
    content = nob_sv_trim_left(content);
    Nob_String_View token = nob_sv_chop_by_space(&content);
    //nob_log(NOB_INFO, " "SV_Fmt, SV_Arg(token));
    FreqKV *kv = find_key(freq, token);
    if (kv) {
      kv->value += 1;
    } else {
      FreqKV new_kv = {
        .key = token,
        .value = 1
      };
      nob_da_append(&freq, new_kv);
    }

  }
  nob_log(NOB_INFO, "%s contains, %zu tokens", file_path, count);
  return 0;
}
