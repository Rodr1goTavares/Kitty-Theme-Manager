#include "io_service.h"
#include "theme_manager.h"

int main(int argc, char** argv) {
  if (processInput(argv) != 0) printCommandHelp();
  return 0;
}
