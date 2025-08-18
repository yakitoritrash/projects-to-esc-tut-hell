#include <stdio.h>
#define NOB_IMPLEMENTATION
#include "nob.h"

int main(void) {
  const char *file_path = "t8.shakespeare.txt";
  Nob_String_Builder buf = {0};
  if (!nob_read_entire_file(file_path, &buf)) return 1;
  nob_log(NOB_INFO, "Size of %s is %zu bytes", file_path, buf.count);

  Nob_String_View content = {
    .data = buf.items,
    .count = buf.count,
  };

  for (int i = 0; i < 100 && content.count > 0; i++) {
    Nob_String_View token = nob_sv_chop_by_delim(&content, ' ');
    nob_log(NOB_INFO, " "SV_Fmt, SV_Arg(token));
  }
  return 0;
}
