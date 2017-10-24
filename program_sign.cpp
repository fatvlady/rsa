#include "common.h"

int main(int argc, char *argv[]) {
  if (argc < 5) {
    std::cerr << argv[0] << " KEY_PATH SOURCE_PATH DIST_PATH MODE" << std::endl;
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

  if (argv[4][0] == '0') {
    std::ofstream encryption(argv[3]);
    encryption << e << std::endl << m;
  } else if (argv[4][0] == '1') {
    message >> m;
    std::cout << ((e == m) ? "Valid" : "Invalid") << std::endl;
  }
}
