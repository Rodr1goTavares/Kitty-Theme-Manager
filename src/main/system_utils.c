#include <stdlib.h>

#include "system_utils.h"


void get_kitty_path(char* kitty_path_buffer, int size) {
    char* home = getenv("HOME");
    if (home == NULL) {
        printf("Failed to get home path\n");
        return;
    }
    snprintf(kitty_path_buffer, size, "%s/.config/kitty", home);
    kitty_path_buffer[size - 1] = '\0';
}
