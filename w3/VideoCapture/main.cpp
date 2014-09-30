#include <opencv2/opencv.hpp>
#include <QDebug>
using namespace cv;


int main(int argc, char *argv[])
{
    VideoCapture videoCapture;      // initialisiert Objekt

    // ACHTUNG: Pfad bitte anpassen!
    std::string videoFilePath = "C:/Users/Andreas/Dropbox/Micro-dance_2_.avi";

    // Videodatei öffnen
    // videoCapture.open(videoFilePath);
    // Alternativ: Kamera öffnen; Device 0
     videoCapture.open(0);

    while(true){
        Mat videoFrame;
        if (false == videoCapture.grab()){
            qDebug() << "grab() failed";
            break;
        }
        if (false == videoCapture.retrieve(videoFrame, 0)){
            qDebug() << "retrieve() failed";
            break;
        }

        imshow("Video", videoFrame);
        waitKey(30);
    }
    return 0;
}
