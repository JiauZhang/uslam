#include <climits>

#include "blob.hpp"
#include "common.hpp"

namespace uslam {
/*
BlobShape::BlobShape(const int channels, const int height, const int width)
{
	shape_[0] = channels;
	shape_[1] = height;
	shape_[2] = width;
}

int &BlobShape::shape(int index)
{
	try {
		if (index > -3 && index < 3) {
			if (index >= 0)
				return shape_[index];
			else if (index < 0)
				return shape_[3+index];
		} else {
			throw -1;
		}
	} catch (...) {
		std::cout << "invalid BlobShape [index]" << std::endl;
		exit(1);
	}
}
*/
template <typename Dtype>
Blob<Dtype>::Blob(vector<int> &shape): capacity_(0)
{
	reshape(shape);
}	

template <typename Dtype>
Blob<Dtype>::Blob(int c, int h, int w): capacity_(0)
{
	std::vector<int> shape{c, h, w};
	reshape(shape);
}

template <typename Dtype>
Blob<Dtype>::Blob(int h, int w): capacity_(0)
{
	std::vector<int> shape{1, h, w};
	reshape(shape);
}

template <typename Dtype>
Blob<Dtype>::Blob(int w): capacity_(0)
{
	std::vector<int> shape{1, 1, w};
	reshape(shape);
}

template <typename Dtype>
int Blob<Dtype>::shape(int index)
{	
	CHECK_LT(index, 3);
	CHECK_GE(index, -3);
	if (index >= num_axes() || index < -num_axes())
		return 1;
	else if (index >= 0)
		return shape_[num_axes() - 1 - index];
	else if (index < 0)
		return shape_[num_axes() + index];
}

template <typename Dtype>
void Blob<Dtype>::reshape(vector<int> &shape)
{
	CHECK_LE(shape.size(), 3);
	
	count_ = 1;
	shape_.resize(shape.size());
	
	for (int i = 0; i < shape.size(); i++) {
		
		CHECK_GE(shape[i], 0);		
		if (count_ != 0) {			
			CHECK_LE(shape[i], INT_MAX / count_);
		}
		
		count_ *= shape[i];
		shape_[i] = shape[i];
	}
	
	if (count_ > capacity_) {
		capacity_ = count_;
		//data_.reset(new char[count_ * sizeof(Dtype)]);
		data_.reset(new Dtype[count_]);
		//data_.resize();
	}
}

template <typename Dtype>
int Blob<Dtype>::offset(int c, int h, int w)
{
	CHECK_GT(channel(), 0);
	CHECK_LT(c, channel());
	CHECK_GT(height(), 0);
	CHECK_LT(h, height());
	CHECK_GT(width(), 0);
	CHECK_LT(w, width());
	// c * height() * width() + h * width() + w
	return (c * height() + h) * width() + w;
}

template <typename Dtype>
int Blob<Dtype>::offset(vector<int> &indices)
{
	CHECK_LE(indices.size(), num_axes());
	int offset = 0;
	for (int i = 0; i < num_axes(); i++) {
		offset *= shape(i);
		if (indices.size() > i) {
			CHECK_GE(indices[i], 0);
			CHECK_LT(indices[i], shape(i));
			offset += indices[i];
		}
	}
	
	return offset;
}

template <typename Dtype>
void Blob<Dtype>::push_back_2d(vector<Dtype> &point_2d)
{
	if () {
		
	} else {
		
	}
}

INSTANTIATE_CLASS(Blob);
	
} // namespace uslam