
//
// get.c
//
// copyright (c) 2013 joseph werle <joseph.werle@gmail.com>
//

#include <stddef.h>
#include <string.h>
#include "get.h"

char *
sphia_get (sphia_t *sphia, const char *key) {
  size_t size = strlen(key) + 1;
  size_t vsize;
  char *value;
  int rc;

  rc = sp_get(sphia->db, key, size, (void *) &value, &vsize);
  if (1 == rc) {
    if ('\0' != value[vsize]) value[vsize] = '\0';
    return value;
  }

  return NULL;
}
