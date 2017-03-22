#include "Wav.h"
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::ios;

Wav::Wav()
{
	num_samples = 0;
}


Wav::~Wav()
{
	delete[] samples;
}


bool Wav::read(const char *fname)
{
	//initialise ifstream
	ifstream fin(fname, ios::binary);
	if (!fin)
		return 0;

	//load header
	if (!header.read(fin))
		return 0;

	num_samples = header.get_data_size() / header.get_bytes_per_sample();
	samples = new short int[num_samples];

	fin.read((char*)samples, num_samples * sizeof(short int));

	fin.close();

	return 1;
}


void Wav::save(const char *fname)
{
	ofstream fout(fname, ios::binary);
	if (!fout)
		return;

	//write header
	header.write(fout);

	//recalculate num_samples for saving data
	num_samples = header.get_data_size() / header.get_bytes_per_sample();

	//write rest of data
	for (unsigned int i = 0; i < num_samples; i++)
		fout.write((char*)&(samples[i]), sizeof(short int));

	fout.close();
}


void Wav::reverse()
{
	short int temp = 0;
	for (int i = 1; i < num_samples / 2; i++)
	{
		temp = samples[i];
		samples[i] = samples[num_samples - i];
		samples[num_samples - i] = temp;
	}
}


void Wav::repeat(int start, int end)
{
	int sampleRate = header.get_sample_rate();
	int tempStart = start * sampleRate;
	int tempEnd = end * sampleRate;

	for (int i = 1; i < num_samples; i++)
	{
		samples[i] = samples[tempStart++];
		
		if (tempStart >= tempEnd)
			tempStart = start * sampleRate;
	}
}


void Wav::split_and_concat()
{
	unsigned int *random = new unsigned int[num_samples];
	
	for (unsigned int i = 0; i < num_samples; i++)
		random[i] = rand() % num_samples;

	for (unsigned int i = 0; i < num_samples; i++)
		samples[i] = random[i];

	delete[] random;
}