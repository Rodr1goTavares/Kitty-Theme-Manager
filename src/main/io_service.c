#include "io_service.h"
#include "theme_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int save_actual_preset(char *theme_name, char *destination_path);
int select_theme(char* theme_name, char* theme_folder_path);

int processInput(char** argv) {
  if (argv[1] == NULL) return 1;
  if (strncmp(argv[1], "--save", 6) == 0 || strncmp(argv[1], "-s", 2) == 0) {
    printf("Save option selected !\n");
    return argv[2] == NULL ? 1 : save_actual_preset(argv[2], "./ktheme");
  }
  if (strncmp(argv[1], "--select", 8) == 0 || strncmp(argv[1], "-s", 2) == 0) {
    char input;
    printf("\n\nChanging the theme will overwrite your current kitty.conf (save it using 'ktm --save'). Do you want to proceed? (y/n): ");
    scanf(" %c", &input);
    if (input == 'y' || input == 'Y') return argv[2] == NULL ? 1 : select_theme(argv[2], "./ktheme");
    printf("[ Theme selection canceled ]\n");
    return;
  }
  return 1;
}

void printCommandHelp() {
  printf(
    "Basic commands: \n\n\t--save <name> or -s <name>  |  Save current kitty.conf file as a theme (Default destination folder: $HOME/.config/kitty/kthemes)\n\n\t--select <name>  |  Select theme <name>.conf located in $HOME/.config/kitty/kthemes)\n\n"
  );
}
