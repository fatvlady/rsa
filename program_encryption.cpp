#include "common.h"

int main(int argc, char *argv[]) {
  if (argc < 4) {
    std::cerr << argv[0] << "KEY_PATH SOURCE_PATH DIST_PATH" << std::endl;
    return -1;
  }

  std::fstream key(argv[1]);
  cpp_int n, private_key;
  key >> n;
  key >> private_key;
  
  std::fstream message(argv[2]);
  cpp_int m;
  message >> m;
  auto e = crypt(m, n, private_key);

  std::ofstream encryption(argv[3]);
  encryption << e;
}
