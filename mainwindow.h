#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlabel.h"
//#include "qlistwidget.h"
#include <QMainWindow>
#include <QMouseEvent>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <QFileDialog>
#include <QDir>
#include <QFileInfoList>
#include <QStringList>
#include <QPointer>
#include "real.h"
#include "realtopred.h"
#include "predtoreal.h"
#include "playground.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;



private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();
   // void on_listWidget_itemClicked(QListWidgetItem *item);


    void on_pushButton_21_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_37_clicked();

private:
    Ui::MainWindow *ui;
    cv::Mat originalImage;  // Store the original image

    cv::Mat mask2;  // Store the original image
    cv::Mat mask1;  // Store the original image
    cv::Mat mask3;  // Store the original image

    cv::Mat modifiedImage;  // Store the modified image with points
    cv::Mat blendedImage;  // Store the modified image with points
    cv::Mat blendedImage2;  // Store the modified image with points
    cv::Point2f point1;       // Store the position of the first point
    cv::Point2f point2;       // Store the position of the second point
    cv::Point2f point3;       // Store the position of the third point
    cv::Point2f point4;       // Store the position of the fourth point
    QPoint initialMousePos; // Store the initial mouse click position
    QString selectedFolderPath;
    QString selectedFolderPath2;
    QStringList imageFileList;
    QLabel *movingRatioLabel;
    QLabel *inscore;
    QLabel *rotatingRatioLabel;
    QLabel *zoomingRatioLabel;
    QLabel *imgscorelable;
    QPointer<real> controlWindow;
    QPointer<realtopred> controlWindoww;
    QPointer<predtoreal> controlWindowww;
    QPointer<playground> controlWindowwww;



    QString imageName;


    // For the second image and points
    cv::Mat originalImage2; // Store the original image for label_2
    cv::Mat modifiedImage2; // Store the modified image with points for label_2
    cv::Point2f point1_2;      // Store the position of the first point for label_2
    cv::Point2f point2_2;      // Store the position of the second point for label_2
    cv::Point2f point3_2;      // Store the position of the third point for label_2
    cv::Point2f point4_2;      // Store the position of the fourth point for label_2
    cv::Point2f pointC2;      // Store the position of the fourth point for label_2
    cv::Point2f pointC;      // Store the position of the fourth point for label_2
    cv::Point2f centerr;

    void zoomInOnPoint(const cv::Mat& originalImage, cv::Point selectedPoint, double zoomFactor, QLabel* label);
    void updatePointPosition(cv::Point2f& point, const QPointF &offset);
    void calculateCenter(const cv::Point& p1, const cv::Point& p2, const cv::Point& p3, const cv::Point& p4, cv::Point2f &center);
    void sss();
    void calculateCenterr(const cv::Point& p1, const cv::Point& p2, const cv::Point& p3, const cv::Point& p4, cv::Point2f& center);
    void drawImageWithPoints();
    void drawImageWithPoints2(); // Function to draw the image with updated points for label_2
    cv::Mat calculatePerspectiveMatrix2();
    std::pair<cv::Mat, cv::Mat> calculatePerspectiveMatrix();

    std::pair<double, double> calculate_ioa_iou(const cv::Mat& image1, const cv::Mat& image2);
    void applyPerspectiveTransformation(const cv::Mat& image1, const cv::Mat& image2);
    double calculate_ioa(const cv::Mat& binary_mask1, const cv::Mat& binary_mask2);

    void applyPerspectiveTransformation2(const cv::Mat& image1, const cv::Mat& image2);
    double calculate_iou(const cv::Mat& binary_mask1, const cv::Mat& binary_mask2);
    void on_horizontalSlider_sliderMoved(int position);
    void loadPointsFromTextFile(const QString &folderPath);
    void loadscoreImage(int position);


    void updateSliderSize();
    void readPointValues(QTextStream &stream, const QRegularExpression &pattern, double &x, double &y);
    void on_horizontalSlider_sliderPressed();
    void on_horizontalSlider_sliderReleased();
    void updatePointsAndRedraw();
    void onEnterKeyPressed();
    bool isMouseHeldOnPoint = false;
    bool modifyPointsOnButtonClick = false;
    bool Click = false;
     bool flag = false;
    bool Cl = false;
    bool p1_2 = false;
    bool p2_2 = false;
    bool p3_2 = false;
    bool p4_2 = false;
    bool pc = false;
    bool z = false;
     bool pc1 = false;
    bool p1 = false;
    bool p2 = false;
    bool p3 = false;
    bool p4 = false;
    bool lock = false;
    bool modifyPointsRotationDirection = true;
    bool rl = false;
    double accumulatedRotationAngle = 0.0;
    double rectangle = 0.0;
    double accumulatedRotationAnglecopy = 0.0;
    double rectanglecopy = 0.0;
    double movingratio = 2;
    double rotatingratio = 0.2;
    double zoomratio = 2.0;

    double score =0;
    double imgscore = 0;

    double rectratio = 0.2;
    double point1x;
    double point1y;
    double point2x;
    double point2y;
    double point3x;
    double point4x;
    double point3y;
    double point4y;
    double point1_2x;
    double point1_2y;
    double point2_2y;
    double point2_2x;
    double point3_2y;
    double point3_2x;
    double point4_2y;
    double point4_2x;
    int previousSliderPosition;
    void loadAndDisplayImage(int position);
    bool sliderMovingAllowed;

};

#endif // MAINWINDOW_H
