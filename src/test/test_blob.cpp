#include <iostream>

#include "blob.hpp"

using uslam::Blob;

void init_blob(Blob<int> &blob)
{
	int i = 0;
	int *data = blob.data();
	for (int c = 0; c < blob.channel(); c++) {
		for (int h = 0; h < blob.height(); h++) {
			for (int w = 0; w < blob.width(); w++) {
				*(data + blob.offset(c, h, w)) = i++;
			}
		}
	}	
}

void print_blob(Blob<int> &blob)
{
	int *data = blob.data();
	for (int c = 0; c < blob.channel(); c++) {
		for (int h = 0; h < blob.height(); h++) {
			for (int w = 0; w < blob.width(); w++) {
				std::cout << *(data + blob.offset(c, h, w)) << ' ';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}	
}

void print_shape(Blob<int> &blob)
{
	std::cout << "c: " << blob.channel()
			  << "h: " << blob.height()
			  << "w: " << blob.width()
			  << std::endl;
}

int main(int argc, char **argv)
{
	const int c = 2;
	const int h = 3;
	const int w = 4;
	std::vector<int> shape{2,3,4};
	Blob<int> blob1(shape);
	Blob<int> blob2(3,2,4);
	Blob<int> blob3(3,4);
	Blob<int> blob4(3);
	
	init_blob(blob1);
	init_blob(blob2);
	init_blob(blob3);
	init_blob(blob4);
	
	print_shape(blob1);
	print_blob(blob1);
	print_shape(blob2);
	print_blob(blob2);
	print_shape(blob3);
	print_blob(blob3);
	print_shape(blob4);
	print_blob(blob4);
	
	std::cout << "main exiting..." << std::endl;
	
	return 0;
}