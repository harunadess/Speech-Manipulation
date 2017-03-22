#include "Wav.h"

#include <iostream>

#define FILENAME_LEN 100

int main()
{
	char *file_name = new char[FILENAME_LEN];

	std::cout << "provide wav file name: " << std::flush;
	std::cin >> file_name;

	//file path processing BS
	char *path = "C:\\Users\\Jordan\\Documents\\Uni\\2nd Year\\CSC2040 - Data Structures, Algorithms and Programming Languages\\Practicals\\Practical 14\\Practical 14\\Practical 14\\";
	std::string full_path = path;
	full_path += file_name;

	const char *c_path = full_path.c_str();

	//create & load wav
	Wav wav;
	if (wav.read(c_path))
		std::cout << "success!" << std::endl;
	else
		std::cout << "error reading file" << std::endl;

	//Reverse and save
	std::string new_full_path = path;
	new_full_path += std::string("reverse_")+ file_name;
	const char *new_c_path = new_full_path.c_str();
	wav.reverse();
	wav.save(new_c_path);
	std::cout << "reversed file saved to:\n" << new_c_path << std::endl;


	//Split and concat
	/*std::string new_full_path = path;
	new_full_path += std::string("random_") + file_name;
	const char *new_c_path = new_full_path.c_str();
	wav.split_and_concat();
	wav.save(new_c_path);
	std::cout << "split and concatenated file saved to:\n" << new_c_path << std::endl;*/

	//Repeat
	/*std::string new_full_path = path;
	new_full_path += std::string("repeat_") + file_name;
	const char *new_c_path = new_full_path.c_str();
	int start = 3;
	int end = 4;
	wav.repeat(start, end);
	wav.save(new_c_path);
	std::cout << "repeat sample saved to: \n" << new_c_path << std::endl;*/

	return 0;
}