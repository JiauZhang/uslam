#include<opencv2/opencv.hpp>

using namespace cv;

int main(){
    Mat img =imread("selfdriving.jpg");
    imshow("image",img);
    waitKey();
    return 0;
}