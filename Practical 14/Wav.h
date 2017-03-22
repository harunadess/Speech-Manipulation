#ifndef WAV_H
#define WAV_H

#include "RIFF.h"

class Wav
{
public:
	Wav();
	~Wav();

	bool read(const char *fname);
	void save(const char *fname);

	//reverse sample
	void reverse();

	//repeat sample
	void repeat(int start, int end);

	//split sample into segments & reconcatenate
	void split_and_concat();

private:
	//The WAV header
	RIFF header;
	//The WAV data
	unsigned int num_samples;
	short int *samples;
};

#endif // !WAV_H
