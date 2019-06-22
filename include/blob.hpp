#ifndef __BLOB_H__
#define __BLOB_H__

#include "common.hpp"
#include "check.hpp"

namespace uslam {

// three dimension
/*
struct BlobShape {
	explicit BlobShape(const int channels, const int height, const int width);
	
	inline unsigned int size() { return 3; }
	int &shape(int index);
	
	int shape_[3];
};
*/	
template <typename Dtype>	
class Blob {
public:
	Blob(): data_(NULL), count_(0), capacity_(0) {}
	explicit Blob(vector<int> &shape);
	explicit Blob(int c, int h, int w);
	explicit Blob(int h, int w);
	explicit Blob(int w);
	
	void reshape(vector<int> &shape);
	inline vector<int> shape() { return shape_; }
	
	inline int width() { return shape(0); }
	inline int height() { return shape(1); }
	inline int channel() { return shape(2); }
	inline int num_axes() { return shape_.size(); }
	inline int count() { return count_; }
	
	int offset(int c, int h, int w);
	int offset(vector<int> &indices);
	inline int offset(int h, int w) { return offset(0, h, w); }
	inline int offset(int w) { return offset(0, 0, w); }
	
	Dtype *data() {
		CHECK(data_.get());
		return data_.get();
	}
	
	void push_back_2d(vector<Dtype> &point_2d);
	
private:
	int shape(int index);

	shared_ptr<Dtype> data_;
	//vector<Dtype> data_;
	//[2]: width, [1]: height, [0]: channel
	//[1]: width, [0]: height
	//[0]: width
	vector<int> shape_;
	int count_;
	// all memory
	int capacity_;
	// have used memory
	int size_;
};	
	
} // namespace uslam

#endif