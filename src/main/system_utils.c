#include "system_utils.h"

#include <stdio.h>
#include <stdlib.h>


char* get_home_path() {
  char* path = getenv("HOME");
  if (path == NULL) printf("Failed to get home path\n");
  return path;
}

char* get_kitty_path() {
  char* kitty_path;
  sprintf(kitty_path, "%s/.config/kitty", get_home_path());
  return kitty_path;
}
