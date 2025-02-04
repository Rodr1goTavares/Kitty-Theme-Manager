#include <stdio.h>
#include <stdlib.h>

#include "theme_manager.h"
#include "system_utils.h"


int save_actual_preset(char* theme_name, char* destination_path) {
    char kitty_path_buffer[255];
    get_kitty_path(kitty_path_buffer, sizeof(kitty_path_buffer));

    int command_size = snprintf(NULL, 0,
        "cd %s && mkdir -p %s && cp ./kitty.conf %s/%s.conf",
        kitty_path_buffer, destination_path, destination_path, theme_name
    ) + 1; // +1 for '\0'

    char* copyAndRenamePresetCommand = malloc(command_size);
    if (!copyAndRenamePresetCommand) {
        perror("Error to alloc memory of a command");
        return -1;
    }

    snprintf(copyAndRenamePresetCommand, command_size,
        "cd %s && mkdir -p %s && cp ./kitty.conf %s/%s.conf",
        kitty_path_buffer, destination_path, destination_path, theme_name
    );

    int result = system(copyAndRenamePresetCommand);

    free(copyAndRenamePresetCommand);

    return result;
}

int select_theme(char* theme_name, char* theme_folder_path) {
    char kitty_path_buffer[255];
    get_kitty_path(kitty_path_buffer, sizeof(kitty_path_buffer));

    int command_size = snprintf(NULL, 0,
        "cd %s && rm -f kitty.conf && cp %s/%s.conf kitty.conf",
        kitty_path_buffer, theme_folder_path, theme_name
    ) + 1; // +1 for '\0'

    char* selectionThemeCommand = malloc(command_size);
    if (!selectionThemeCommand) {
        perror("Erro ao alocar memória para o comando");
        return -1;
    }

    snprintf(selectionThemeCommand, command_size,
        "cd %s && rm -f kitty.conf && cp %s/%s.conf kitty.conf",
        kitty_path_buffer, theme_folder_path, theme_name
    );

    int result = system(selectionThemeCommand);

    free(selectionThemeCommand);

    return result;
}
