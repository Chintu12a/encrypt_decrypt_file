#pragma once
#include <string>

void decrypt_file(const std::string& input_file, const std::string& output_file, char key, int num_threads);
