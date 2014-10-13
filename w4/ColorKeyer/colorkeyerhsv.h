#ifndef COLORKEYERHSV_H
#define COLORKEYERHSV_H

#include "videoprocessor.h"

class ColorKeyerHSV : public VideoProcessor
{
public:
    ColorKeyerHSV();
    void startProcessing(const VideoFormat& format){}
    cv::Mat process(const cv::Mat&source);
    void setHueUpperThreshold(int);
    void setHueLowerThreshold(int);
    void setSaturationThreshold(int);

private:
    int hueUpperThreshold;
    int hueLowerThreshold;
    int saturationThreshold;
    void drawCross(cv::Mat& mat, cv::Point center, int length, cv::Scalar color);
};

#endif // COLORKEYERHSV_H
