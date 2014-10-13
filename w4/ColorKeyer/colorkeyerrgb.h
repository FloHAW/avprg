#ifndef COLORKEYERRGB_H
#define COLORKEYERRGB_H

#include "videoprocessor.h"

class ColorKeyerRGB : public VideoProcessor
{
public:
    ColorKeyerRGB();
    void startProcessing(const VideoFormat& format){}
    cv::Mat process(const cv::Mat&source);
private:
};

#endif // COLORKEYERRGB_H
