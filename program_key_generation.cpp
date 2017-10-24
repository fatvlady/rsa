#define DEBUG_MODE
#include "common.h"

int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; ++i) {
    generate_keys(1024, argv[i]);
  }
}
