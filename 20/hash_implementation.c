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

FreqKV *find_key() {
  for (size_t i = 0; i < ) {

  }
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

  for (int i = 0; i < 1000 && content.count > 0; i++) {
    content = nob_sv_trim_left(content);
    Nob_String_View token = nob_sv_chop_by_space(&content);
    nob_log(NOB_INFO, " "SV_Fmt, SV_Arg(token));
  }
  return 0;
}
