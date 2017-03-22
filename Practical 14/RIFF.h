#ifndef RIFF_H
#define RIFF_H
#include <fstream>
using std::ifstream;
using std::ofstream;

class RIFF
{
public:
	bool read(ifstream &fin);
	void write(ofstream &fout);

	short int get_bytes_per_sample() const;
	unsigned int get_data_size() const;
	int get_sample_rate() const;

private:
	//RIFF header parameters
	char riff_id[4]; //RIFF file ID - must contain RIFF
	int file_size;	
	char wave_id[4]; //WAVE ID
	char format[4]; //format chunk marker, include null
	unsigned int format_len;
	short int format_tag;
	short int num_channels; //number of channels: 1-mono, 2-stereo
	int sample_rate; //sampling rate
	int bytes_per_sec;
	short int bytes_per_sample; //2 bytes per sampel i.e. each sample is short int
	short int bits_per_sample;
	char data[4]; //data chunk marker
	unsigned int data_size; //size of data (in bytes)
};

#endif // !RIFF_H
