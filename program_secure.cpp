#include "common.h"
int main(int argc, char *argv[]) {
  if (argc < 6) {
    std::cerr << argv[0] << " K PUBLIC_KEY PRIVATE_KEY SOURCE_PATH DIST_PATH MODE" << std::endl;
    return -1;
  }
  std::fstream data(argv[1]);
  cpp_int k;
  data >> k;

  std::fstream a_public_file(argv[2]);
  cpp_int a_n, a_public, a_private;
  a_public_file >> a_n >> a_public;

  std::fstream a_private_file(argv[3]);
  a_private_file >> a_n >> a_private;


  cpp_int b_n, b_public, b_private;
  std::fstream b_public_file(argv[4]);
  b_public_file >> b_n >> b_public;

  std::fstream b_private_file(argv[5]);
  b_private_file >> b_n >> b_private;

  auto s = crypt(k, a_n, a_private);
  auto s1 = crypt(s, b_n, b_public);
  auto k1 = crypt(k, b_n, b_public);

  auto second_k = crypt(k1, b_n, b_private);
  auto second_s = crypt(s1, b_n, b_private);
  
  std::cout << (second_k == crypt(second_s, a_n, a_public)) << std::endl;
}
