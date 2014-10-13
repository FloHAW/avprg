#include "colorkeyerhsv.h"
#include <QDebug>
using namespace cv;


ColorKeyerHSV::ColorKeyerHSV()
    : hueUpperThreshold(340/2)
    , hueLowerThreshold(360/2)
    , saturationThreshold(120)
{
}

Mat ColorKeyerHSV::process(const Mat &input){
    // convert BGR -> HSV
    Mat hsvFrame;
    cvtColor(input, hsvFrame, CV_BGR2HSV);

    // initialize Mat object for output
    Mat output(input.rows, input.cols, CV_8UC3);


    // analyse pixel
    int numWhitePixels = 0;
    int sumx = 0;
    int sumy = 0;
    for(int x = 0; x < hsvFrame.cols; x++){
        for(int y = 0; y < hsvFrame.rows; y++){
            Vec3b hsvPixel = hsvFrame.at<Vec3b>(y,x);
            int hue = hsvPixel[0];
            int saturation = hsvPixel[1];

            // Maskierung und Schwerpunktsberechnung
            bool isWhite = false;
            if (saturation > saturationThreshold){
                if (hueLowerThreshold < hueUpperThreshold){
                    if (hue >= hueLowerThreshold && hue <= hueUpperThreshold){
                        isWhite = true;
                    }
                }
                else {
                    if (hue >= hueLowerThreshold || hue <= hueUpperThreshold){
                        isWhite = true;
                    }
                }
            }
            if (isWhite){
                output.at<Vec3b>(y,x) = Vec3b(255, 255, 255);
                sumx += x;
                sumy += y;
                numWhitePixels++;
            }
            else{
                output.at<Vec3b>(y,x) = Vec3b(0, 0, 0);
            }
        }
    }
    if (numWhitePixels > 0){
        Point center(sumx/numWhitePixels, sumy/numWhitePixels);
        drawCross(output, center, 5, Scalar(0, 255, 0));
    }
    return output;
}

void ColorKeyerHSV::drawCross(Mat& image, Point center, int length, Scalar color){
    if(center.x > 0 && center.y > 0){
        line(image, center-Point(0, length), center+Point(0,length), color, 1);
        line(image, center-Point(length, 0), center+Point(length, 0), color, 1);
    }
}

void ColorKeyerHSV::setHueLowerThreshold(int value){
    hueLowerThreshold = value/2;
    qDebug() << "hueLowerThreshold: " << value;
}
void ColorKeyerHSV::setHueUpperThreshold(int value){
    hueUpperThreshold = value/2;
    qDebug() << "hueUpperThreshold: " << value;
}
void ColorKeyerHSV::setSaturationThreshold(int value){
    saturationThreshold = value/2;
    qDebug() << "saturationThreshold: " << value;
}
