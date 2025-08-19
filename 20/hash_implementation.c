#include <stdio.h>
#include <time.h>
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

int compare_freqkv_count(const void *a, const void *b) {
  const FreqKV *akv = a;
  const FreqKV *bkv = b;
  return (int)bkv->value - (int)akv->value;
}
void log_elapsed_time(struct timespec begin, struct timespec end) {
  double a = (double)begin.tv_sec + begin.tv_nsec*1e-9;
  double b = (double)end.tv_sec + end.tv_nsec*1e-9;
  nob_log(NOB_INFO, "Elapsed time %lfsecs", b - a);
}

int main(int argc, char **argv) {
  const char *program = nob_shift_args(&argc, &argv);

  if (argc <= 0) {
    nob_log(NOB_ERROR, "No input is provided");
    nob_log(NOB_INFO, "Usage: %s <input.txt>", program);
    return 1;
  }
  const char *file_path = nob_shift_args(&argc, &argv);
  Nob_String_Builder buf = {0};
  if (!nob_read_entire_file(file_path, &buf)) return 1;
  nob_log(NOB_INFO, "Size of %s is %zu bytes", file_path, buf.count);

  Nob_String_View content = {
    .data = buf.items,
    .count = buf.count,
  };

  FreqKVs freq = {0};

  struct timespec begin = {0};
  int ret = clock_gettime(CLOCK_MONOTONIC, &begin);
  assert(ret == 0);
  size_t count = 0;
  for (; content.count > 0; count++) {
    content = nob_sv_trim_left(content);
    Nob_String_View token = nob_sv_chop_by_space(&content);
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

  struct timespec end = {0};
  ret = clock_gettime(CLOCK_MONOTONIC, &end);
  assert(ret == 0);

  log_elapsed_time(begin, end);
  nob_log(NOB_INFO, "%s contains, %zu tokens", file_path, count);
  qsort(freq.items, freq.count, sizeof(freq.items[0]), compare_freqkv_count);

  nob_log(NOB_INFO, "Top 10 tokens in %s", file_path);
  for (size_t i = 0; i < 10 && i < freq.count; ++i) {
    nob_log(NOB_INFO, " %zu: "SV_Fmt" => %zu", i, SV_Arg(freq.items[i].key), freq.items[i].value);
  }
  return 0;
}
