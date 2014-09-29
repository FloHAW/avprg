win32 {
    INCLUDEPATH += $$(OPENCV3_DIR)\..\..\include
    LIBS += -L$$(OPENCV3_DIR)\lib
    Release:LIBS +=  -lopencv_ts300 -lopencv_world300
    Debug:LIBS +=  -lopencv_ts300d -lopencv_world300d
}
macx {
    INCLUDEPATH += /usr/local/include
    LIBS += -L/usr/local/lib
    LIBS +=  -lopencv_core -lopencv_highgui -lopencv_imgproc
}
linux* {
    QT_CONFIG -= no-pkg-config
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}
