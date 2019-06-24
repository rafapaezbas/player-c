#include "wavReader.h"
#include <iostream>

struct header{    
	char chunk_id[4];
	int chunk_size;
	char format[4];
	char subchunk1_id[4];
	int subchunk1_size;
	short int audio_format;
	short int num_channels;
	int sample_rate;            
	int byte_rate;
	short int block_align;
	short int bits_per_sample;
	char subchunk2_id[4];
	int subchunk2_size;
};

int durationInSeconds(std::string filePath){
	FILE* fp = fopen(filePath.c_str(), "rb");
	header info;
	if (fp) {
		//Read a file in memory direction of info struct, therefore knowing the size of every part of the header
		//it is posible to divide the information
		fread(&info, 1, sizeof(header), fp);
	}
	int numSamples = info.subchunk2_size / (info.num_channels * (info.bits_per_sample/8));
	int durationSeconds = numSamples / info.sample_rate;
	return durationSeconds * 1000;
}
