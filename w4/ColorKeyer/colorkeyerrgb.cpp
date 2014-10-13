#include "colorkeyerrgb.h"

using namespace cv;


const Vec3b REFERENCE_COLOR(54, 39, 97);	// BGR
const int THRESHOLD = 16;

ColorKeyerRGB::ColorKeyerRGB()
{
}

Mat ColorKeyerRGB::process(const Mat &input){
    Mat output(input.rows, input.cols, CV_8UC1);
    for(int x = 0; x < input.cols; x++){
        for(int y = 0; y < input.rows; y++){
            Vec3b inputPixel = input.at<Vec3b>(y,x);

            double distance = norm(inputPixel, REFERENCE_COLOR);


            uchar outputPixel = 0;
            if (distance < THRESHOLD){
                outputPixel = 255;
            }
            output.at<uchar>(y,x) = outputPixel;
        }
    }
    return output;
}

