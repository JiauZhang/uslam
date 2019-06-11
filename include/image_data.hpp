#ifndef __IMAGE_DATA__
#define __IMAGE_DATA__

#include <iostream>
#include <cstring>
#include <string>

//#include <opencv2/core/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp> 

#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>

namespace uslam {

template <typename Dtype>
class ImageData {
public:
	Dtype image;
	boost::mutex image_data_mutex;
	static ImageData& getInstance() {
		static ImageData singleton;
		return singleton;
	}

private:
	ImageData () {}
};

} // namespace uslam

#endif
