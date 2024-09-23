#include "bits/stdc++.h"
#include "decryptor.hpp"
#include "encryptor.hpp"
#include "thread"

int main(int argc, char *argv[])
{
    if (argc != 6)
    {
        std::cerr << "Usage: " << argv[0] << " <encrypt|decrypt> <input_file> <output_file> <key> <num_threads>\n";
        return 1;
    }

    std::string mode = argv[1];
    std::string input_file = argv[2];
    std::string output_file = argv[3];
    char key = argv[4][0];
    std::cout<<"jey is "<<key<<std::endl;
    int num_threads = std::stoi(argv[5]);

    if (mode == "encrypt")
    {
        encrypt_file(input_file, output_file, key, num_threads);
    }
    else if (mode == "decrypt")
    {
        decrypt_file(input_file, output_file, key, num_threads);
    }
    else
    {
        std::cerr << "Unknown mode: " << mode << "\n";
        return 1;
    }

    return 0;
}
