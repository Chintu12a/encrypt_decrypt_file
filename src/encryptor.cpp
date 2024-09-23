#include "bits/stdc++.h"
#include <fstream>
#include <thread>
#include <vector>

char xor_encrypt(char data, char key)
{
    std::cout << "pritning data is " << data << std::endl;
    return data ^ key;
}

void encrypt_chunk(const std::string &input_file, const std::string &output_file, char key, std::streampos start, std::streamsize length)
{
    std::ifstream infile(input_file, std::ios::binary);
    std::ofstream outfile(output_file, std::ios::binary | std::ios::in | std::ios::out);

    if (!infile || !outfile)
    {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    infile.seekg(start);
    outfile.seekp(start);

    std::vector<char> buffer(length);
    infile.read(buffer.data(), length);

    std::cout << "Before is " << std::endl;
    for (auto &byte : buffer)
    {
        std::cout << "byte is " << byte << std::endl;
        byte = xor_encrypt(byte, key);
    }

    outfile.write(buffer.data(), length);
}

void encrypt_file(const std::string &input_file, const std::string &output_file, char key, int num_threads)
{
    std::ifstream infile(input_file, std::ios::binary | std::ios::ate);
    std::streamsize file_size = infile.tellg();
    infile.close();
    std::cout << "The size of file size is " << file_size << std::endl;

    // Create output file of the same size
    std::ofstream outfile(output_file, std::ios::binary);
    outfile.seekp(file_size - 1);
    outfile.write("", 1);
    outfile.close();

    std::streamsize chunk_size = file_size / num_threads;
    std::cout << "The size of chunk size is " << chunk_size << std::endl;
    std::vector<std::thread> threads;

    for (int i = 0; i < num_threads; i++)
    {
        std::streampos start = i * chunk_size;
        std::cout << "The size of start* is " << start << std::endl;
        std::streamsize length = (i == num_threads - 1) ? (file_size - start) : chunk_size;
        std::cout << "the length is length " << length << std::endl;
        threads.emplace_back(encrypt_chunk, input_file, output_file, key, start, length);
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    std::cout << "Encryption complete. Output saved to: " << output_file << std::endl;
}
