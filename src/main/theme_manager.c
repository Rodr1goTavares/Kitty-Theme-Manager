#include "theme_manager.h"
#include "system_utils.h"
#include <stdio.h>
#include <stdlib.h>

char* get_kitty_path();

int save_actual_preset(char* theme_name, char* destination_path) {
  char* copyAndRenamePresetCommand;
  char* kitty_path = get_kitty_path();
  sprintf(
    copyAndRenamePresetCommand,
    "cd %s && mkdir -p %s && cp ./kitty.conf %s/%s.conf",
    kitty_path,
    destination_path,
    destination_path,
    theme_name
  );
  return system(copyAndRenamePresetCommand);
}

int select_theme(char* theme_name, char* destination_path) {
  return 0;
}

int delete_theme(char* theme_name, char* destination_path) {
  return 0;
}
