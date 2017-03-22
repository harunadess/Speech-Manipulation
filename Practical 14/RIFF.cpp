#include "RIFF.h"

short int RIFF::get_bytes_per_sample() const
{
	return bytes_per_sample;
}


unsigned int RIFF::get_data_size() const
{
	return data_size;
}

int RIFF::get_sample_rate() const
{
	return sample_rate;
}


bool RIFF::read(ifstream& fin)
{
	fin.read((char*)riff_id, 4);
	//return if this is not RIFF format sound file
	if (riff_id[0] != 'R' || riff_id[1] != 'I' || riff_id[2] != 'F' || riff_id[3] != 'F')
		return 0;

	fin.read((char*)&file_size, sizeof(int));
	fin.read((char*)&wave_id, 4 * sizeof(char));
	fin.read((char*)&format, 4 * sizeof(char));
	fin.read((char*)&format_len, sizeof(unsigned int));
	fin.read((char*)&format_tag, sizeof(short int));
	fin.read((char*)&num_channels, sizeof(short int));
	fin.read((char*)&sample_rate, sizeof(int));
	fin.read((char*)&bytes_per_sec, sizeof(int));
	fin.read((char*)&bytes_per_sample, sizeof(short int));
	fin.read((char*)&bits_per_sample, sizeof(short int));
	fin.read((char*)&data, 4 * sizeof(char));
	fin.read((char*)&data_size, sizeof(unsigned int));

	return true;
}


void RIFF::write(ofstream &fout)
{
	//char is probably one byte, but to be safe used sizeof()
	fout.write((char*)riff_id, 4 * sizeof(char));
	fout.write((char*)&file_size, sizeof(int));
	fout.write((char*)&wave_id, 4 * sizeof(char));
	fout.write((char*)&format, 4 * sizeof(char));
	fout.write((char*)&format_len, sizeof(unsigned int));
	fout.write((char*)&format_tag, sizeof(short int));
	fout.write((char*)&num_channels, sizeof(short int));
	fout.write((char*)&sample_rate, sizeof(int));
	fout.write((char*)&bytes_per_sec, sizeof(int));
	fout.write((char*)&bytes_per_sample, sizeof(short int));
	fout.write((char*)&bits_per_sample, sizeof(short int));
	fout.write((char*)&data, 4 * sizeof(char));
	fout.write((char*)&data_size, sizeof(unsigned int));
}