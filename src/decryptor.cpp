#include "decryptor.hpp"
#include "encryptor.hpp"

void decrypt_file(const std::string& input_file, const std::string& output_file, char key, int num_threads) {
    encrypt_file(input_file, output_file, key, num_threads);  // XOR encryption is symmetric
}
