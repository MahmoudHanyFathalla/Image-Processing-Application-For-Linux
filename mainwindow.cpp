#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QDebug>
#include <cmath>
#include <QImage>
#include <QPixmap>
#include <QTimer>
#include "real.h"
#include <QPointer>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    try {


                ui->setupUi(this);
                //setFixedSize(1360, 695);
                QWidget window;
                window.showMaximized();
                ui->listWidget->setFocusPolicy(Qt::NoFocus);
                ui->horizontalSlider->setFocusPolicy(Qt::NoFocus);

                ui->pushButton->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_2->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_3->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_4->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_5->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_6->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_7->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_8->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_9->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_10->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_11->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_12->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_13->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_14->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_15->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_16->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_17->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_18->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_19->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_20->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_21->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_22->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_23->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_24->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_25->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_26->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_27->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_28->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_29->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_30->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_31->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_32->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_33->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_34->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_35->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_36->setFocusPolicy(Qt::NoFocus);
                ui->pushButton_37->setFocusPolicy(Qt::NoFocus);

                // Load the first image using OpenCV
                cv::Mat image2 = cv::imread("GT.jpg");

                // Load the second image using OpenCV
             //  cv::Mat image2 = cv::imread("C:\\Users\\hp\\Desktop\\KoraState\\Qt\\opencvfull\\untitled\\GT.jpg");
              //  cv::Mat image2 = cv::imread("C:\\Users\\hp\\Desktop\\KoraState\\Qt\\opencvfull\\untitled\\GT.jpg");
                // cv::Mat image2 = cv::imread((":/GT.jpg").toStdString());
                //cv::Mat image2 = cv::imread("GT.jpg");
               // cv::Mat image2 = cv::imread(":/GT.jpg");


                if ( !image2.empty()) {

                   // cv::cvtColor(image1, image1, cv::COLOR_BGR2RGB);
                    cv::cvtColor(image2, image2, cv::COLOR_BGR2RGB);

                    // Get the size of the first QLabel (label)
                    QSize labelSize1 = ui->label->size();
                    QSize labelSize2 = ui->label_2->size();  // Add this line to get the size of label_2

                    // Resize the first image to fit the first QLabel while maintaining the aspect ratio
                   // cv::resize(image1, image1, cv::Size(labelSize1.width(), labelSize1.height()));
                    cv::resize(image2, image2, cv::Size(labelSize2.width(), labelSize2.height()));
                    qDebug() << "Image 1 Dimensions: " << labelSize1.width() << "x" << labelSize1.height(); // (521 * 261) but real is (1280 * 720)
                    qDebug() << "Image 2 Dimensions: " << labelSize2.width() << "x" << labelSize2.height(); // (511 * 261) but real is (1600 * 1066)
                    // image 1 ratio is (0.40703125 * 0.3625)
                    // image 2 ratio is (0.319375   * 0.2448405253)
                    // rect/2
                    // 0.4990234375 x  0.3826979472
                    // Store the original image
                   // originalImage = image1.clone();
                    originalImage2 = image2.clone();  // Add this line to store the original image for label_2

                    // Store a copy of the original image in the modified image
                  //  modifiedImage = originalImage.clone();
                    modifiedImage2 = originalImage2.clone();  // Add this line for label_2

                    // Initialize the positions of the points
                    point1x = 150;
                    point1y = 80;
                    point2x = 330;
                    point2y = 80;
                    point3x = 100;
                    point3y = 150;
                    point4x = 380;
                    point4y = 150;

                    point1_2x = 150+61;
                    point1_2y = 80+16;
                    point2_2x = 150+61;
                    point2_2y = 180-16;
                    point3_2x = 350-51;
                    point3_2y = 80+16;
                    point4_2x = 350-51;
                    point4_2y = 180-16;



                    point1 = cv::Point(point1x, point1y);
                    point2 = cv::Point(point2x, point2y);
                    point3 = cv::Point(point3x, point3y);
                    point4 = cv::Point(point4x, point4y);

                    // Initialize the positions of the points for label_2
                    point1_2 = cv::Point(point1_2x, point1_2y);
                    point2_2 = cv::Point(point2_2x, point2_2y);
                    point3_2 = cv::Point(point3_2x, point3_2y);
                    point4_2 = cv::Point(point4_2x, point4_2y);
                    pointC2 = cv::Point(0, 0);
                    pointC = cv::Point(0, 0);

                    calculateCenter(point1_2, point2_2, point3_2, point4_2, pointC2);
                    calculateCenter(point1, point2, point3, point4, pointC);

                     qDebug() << "Center 1: (" << pointC.x << ", " << pointC.y << ")";
                    // Print or use the result
                    qDebug() << "Center: (" << pointC2.x << ", " << pointC2.y << ")";
                    // Draw circles at each point on the images
                 //   drawImageWithPoints();
                    drawImageWithPoints2();  // Add this line to draw points on label_2
                } else {
                    qDebug() << "Error: Unable to load the images.";
                }

                // Enable mouse tracking for the QLabels to receive mouse move events
                ui->label->setMouseTracking(true);
                ui->label_2->setMouseTracking(true);  // Add this line
              //  applyPerspectiveTransformation(image1, image2);
                movingRatioLabel = ui->label_19;
                imgscorelable = ui->label_32;
                movingRatioLabel->setText(QString("%1").arg(movingratio));



                zoomingRatioLabel = ui->label_28;
                zoomingRatioLabel->setText(QString("%1").arg(zoomratio));

                inscore = ui->label_30;





                rotatingRatioLabel = ui->label_20;
                rotatingRatioLabel->setText(QString("%1").arg(rotatingratio));
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }

}
// Function to update the points and redraw the image

// Mouse press event handler
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    try{

            // Check if the left mouse button is pressed
            if (event->button() == Qt::LeftButton) {
                // Store the initial position of the mouse click
                initialMousePos = event->pos();
                qDebug() << "m Position: " <<initialMousePos;

                // Check if the event occurred within the QLabel for label_2
                if (ui->label_2->geometry().contains(initialMousePos)) {
                    isMouseHeldOnPoint = true;
                }
            }
            int distance1_2 = (initialMousePos - QPoint(point1_2.x + 562, point1_2.y)).manhattanLength();
            int distance2_2 = (initialMousePos - QPoint(point2_2.x + 562, point2_2.y)).manhattanLength();
            int distance3_2 = (initialMousePos - QPoint(point3_2.x + 562, point3_2.y)).manhattanLength();
            int distance4_2 = (initialMousePos - QPoint(point4_2.x + 562, point4_2.y)).manhattanLength();

            calculateCenter(point1_2, point2_2, point3_2, point4_2, pointC2);
            int distancec = (initialMousePos - QPoint(pointC2.x + 562, pointC2.y)).manhattanLength();
            int minDistance_2 = std::min({distance1_2, distance2_2, distance3_2, distance4_2,distancec});

            int distance1 = (initialMousePos - QPoint(point1.x + 10, point1.y)).manhattanLength();
            int distance2 = (initialMousePos - QPoint(point2.x + 10, point2.y)).manhattanLength();
            int distance3 = (initialMousePos - QPoint(point3.x + 10, point3.y)).manhattanLength();
            int distance4 = (initialMousePos - QPoint(point4.x + 10, point4.y)).manhattanLength();
            calculateCenter(point1, point2, point3, point4, pointC);
            int distancec1 = (initialMousePos - QPoint(pointC.x + 10, pointC.y)).manhattanLength();
            int minDistance = std::min({distance1, distance2, distance3, distance4, distancec1});

            if (minDistance_2 < 15) {
                p1_2 = minDistance_2 == distance1_2;
                p2_2 = minDistance_2 == distance2_2;
                p3_2 = minDistance_2 == distance3_2;
                p4_2 = minDistance_2 == distance4_2;
                pc = minDistance_2 == distancec;

                if (p1_2 || p2_2 || p3_2 || p4_2 || pc) {
                    p1_2 ? (p2_2 = p3_2 = p4_2 = pc = false) : (p1_2 = false);
                    p2_2 ? (p1_2 = p3_2 = p4_2 = pc = false) : (p2_2 = false);
                    p3_2 ? (p1_2 = p2_2 = p4_2 = pc = false) : (p3_2 = false);
                    p4_2 ? (p1_2 = p2_2 = p3_2 = pc = false) : (p4_2 = false);
                    pc   ? (p1_2 = p2_2 = p3_2 = p4_2 = false) : (pc = false);
                }
            } else {
                p1_2 = p2_2 = p3_2 = p4_2 = pc = false;
            }
            if (minDistance < 15) {
                p1 = minDistance == distance1;
                p2 = minDistance == distance2;
                p3 = minDistance == distance3;
                p4 = minDistance == distance4;
                pc1 = minDistance == distancec1;


                if (p1 || p2 || p3 || p4 ||pc1) {
                    p1 ? (p2 = p3 = p4 = pc1 = false) : (p1 = false);
                    p2 ? (p1 = p3 = p4 = pc1 = false) : (p2 = false);
                    p3 ? (p1 = p2 = p4 = pc1 = false) : (p3 = false);
                    p4 ? (p1 = p2 = p3 = pc1 = false) : (p4 = false);
                    pc1 ? (p1 = p2 = p3 = p4 = false) : (pc1 = false);


                }
            } else {
                p1 = p2 = p3 = p4 = pc1 = false;
            }
           drawImageWithPoints2();
           drawImageWithPoints();

    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    try{

            // Check if the pressed key is the up arrow key
            if (p1_2 || p2_2 || p3_2 || p4_2 || pc) {
                qDebug() << "m Position:ererrrrrrrrr ";

                double yOffset = 0;
                double xOffset = 0;

                if (event->key() == Qt::Key_Up) {
                    yOffset = -movingratio;
                } else if (event->key() == Qt::Key_Down) {
                    yOffset = movingratio;
                } else if (event->key() == Qt::Key_Left) {
                    xOffset = -movingratio;
                } else if (event->key() == Qt::Key_Right) {
                    xOffset = movingratio;
                }

                if (p1_2) {
                    point1_2.y += yOffset;
                    point3_2.y += yOffset;
                    point1_2.x += xOffset;
                    point2_2.x += xOffset;
                } else if (p2_2) {
                    point2_2.y += yOffset;
                    point4_2.y += yOffset;
                    point2_2.x += xOffset;
                    point1_2.x += xOffset;
                } else if (p3_2) {
                    point3_2.y += yOffset;
                    point1_2.y += yOffset;
                    point3_2.x += xOffset;
                    point4_2.x += xOffset;
                } else if (p4_2) {
                    point4_2.y += yOffset;
                    point2_2.y += yOffset;
                    point4_2.x += xOffset;
                    point3_2.x += xOffset;
                } else if (pc) {
                    point1_2.y += yOffset;
                    point2_2.y += yOffset;
                    point3_2.y += yOffset;
                    point4_2.y += yOffset;
                    point4_2.x += xOffset;
                    point3_2.x += xOffset;
                    point1_2.x += xOffset;
                    point2_2.x += xOffset;
                }

                calculateCenter(point1_2, point2_2, point3_2, point4_2, pointC2);
                drawImageWithPoints2();
                applyPerspectiveTransformation(originalImage, originalImage2);
            }
            if (p1 || p2 || p3 || p4 || pc1) {
                qDebug() << "m Position:ererrrrrrrrr ";

                double yOffset = 0;
                double xOffset = 0;

                if (event->key() == Qt::Key_Up) {
                    yOffset = -movingratio;
                } else if (event->key() == Qt::Key_Down) {
                    yOffset = movingratio;
                } else if (event->key() == Qt::Key_Left) {
                    xOffset = -movingratio;
                } else if (event->key() == Qt::Key_Right) {
                    xOffset = movingratio;
                }

                if (p1) {
                    point1.y += yOffset;
                    point2.y += yOffset;
                    if(lock){
                       point1.x += xOffset;
                       point2.x -= xOffset;
                    }
                    else if (lock == false){
                         point1.x += xOffset;
                    }

                } else if (p2) {
                    point2.y += yOffset;
                    point1.y += yOffset;
                    if(lock){
                        point1.x -= xOffset;
                        point2.x += xOffset;
                    }
                    else if (lock == false){
                        point2.x += xOffset;
                    }

                } else if (p3) {
                    point3.y += yOffset;
                    point4.y += yOffset;
                    if(lock){
                        point3.x += xOffset;
                        point4.x -= xOffset;
                    }
                    else if (lock == false){
                        point3.x += xOffset;
                    }

                } else if (p4) {
                    point4.y += yOffset;
                    point3.y += yOffset;
                    if(lock){
                        point4.x += xOffset;
                        point3.x -= xOffset;
                    }
                    else if (lock == false){
                        point4.x += xOffset;
                    }

                } else if (pc1) {
                    point1.y += yOffset;
                    point2.y += yOffset;
                    point3.y += yOffset;
                    point4.y += yOffset;
                    point4.x += xOffset;
                    point3.x += xOffset;
                    point1.x += xOffset;
                    point2.x += xOffset;
                }

                calculateCenter(point1, point2, point3, point4, pointC);
                drawImageWithPoints();
                applyPerspectiveTransformation(originalImage, originalImage2);
            }
            qDebug() << "Exception caught: " << point1_2.x;
            qDebug() << "Exception caught: " << point1_2.y;
            if (event->key() == Qt::Key_D) {
                // Call the function to move to the next image
                on_pushButton_24_clicked();
            }
            if (event->key() == Qt::Key_A) {
                // Call the function to move to the next image
                on_pushButton_25_clicked();
            }
            if (event->key() == Qt::Key_N) {
                // Call the function to move to the next image
                on_pushButton_17_clicked();
            }
            if (event->key() == Qt::Key_V) {
                // Call the function to move to the next image
                on_pushButton_18_clicked();
            }
            if (event->key() == Qt::Key_P) {
                // Call the function to move to the next image
                on_pushButton_29_clicked();
            }
            if (event->key() == Qt::Key_I) {
                // Call the function to move to the next image
                on_pushButton_30_clicked();
            }
            if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
                // Call the function to handle Enter key press
                onEnterKeyPressed();
            }
            if (event->key() == Qt::Key_L) {
                // Call the function to move to the next image
                lock =! lock;
                qDebug() << "t: " << lock;
                if(lock == false){
                  ui->label_25->setText("LOCK IS : OFF");
                }
                else if (lock == true){
                    ui->label_25->setText("LOCK IS : ON");
                }
            }
            if (event->key() == Qt::Key_Plus) {
                // Call the function to move to the next image
                on_pushButton_22_clicked();
            }
            if (event->key() == Qt::Key_Minus) {
                // Call the function to move to the next image
                on_pushButton_23_clicked();
            }

            if (event->key() == Qt::Key_Z) {
                z =! z;
                // Check if a point is selected for zooming
                if(z==true){
                            ui->label_26->setText("ZOOM IS : ON");
                            if (p1 || p2 || p3 || p4 || pc1) {
                                // Define zoom level (e.g., 2x)
                               // const double zoomFactor = 2.0;

                                // Determine the center of the zooming region
                                cv::Point zoomCenter;
                                if (p1)
                                    zoomCenter = point1;
                                else if (p2)
                                    zoomCenter = point2;
                                else if (p3)
                                    zoomCenter = point3;
                                else if (p4)
                                    zoomCenter = point4;
                                else if (p4)
                                    zoomCenter = point4;
                                else if (pc1)
                                    zoomCenter = pointC;

                                // Zoom in on the selected point
                                zoomInOnPoint(modifiedImage, zoomCenter, zoomratio, ui->label);
                            }
                }else if(z == false)
                {
                    ui->label_26->setText("ZOOM IS : OFF");
                    drawImageWithPoints();
                }
            }

            // Call the base class implementation
            QMainWindow::keyPressEvent(event);


    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}
void MainWindow::zoomInOnPoint(const cv::Mat& originalImage, cv::Point selectedPoint, double zoomFactor, QLabel* label)
{
    // Calculate ROI dimensions
    int roiWidth = originalImage.cols / zoomFactor;
    int roiHeight = originalImage.rows / zoomFactor;

    // Calculate ROI coordinates
    int roiX = std::max(0, selectedPoint.x - roiWidth / 2);
    int roiY = std::max(0, selectedPoint.y - roiHeight / 2);

    // Ensure ROI does not exceed image boundaries
    roiX = std::min(roiX, originalImage.cols - roiWidth);
    roiY = std::min(roiY, originalImage.rows - roiHeight);

    // Create ROI
    cv::Rect roiRect(roiX, roiY, roiWidth, roiHeight);
    cv::Mat zoomedRegion = originalImage(roiRect);

    // Resize the zoomed region to the original size
    cv::resize(zoomedRegion, zoomedRegion, originalImage.size());
    //cv::circle(zoomedRegion, cv::Point(zoomedRegion.cols / 2, zoomedRegion.rows / 2), 20, cv::Scalar(0, 255, 0), 2);
    // Display the zoomed image
    QImage zoomedImg = QImage(zoomedRegion.data, zoomedRegion.cols, zoomedRegion.rows, zoomedRegion.step, QImage::Format_RGB888);
    label->setPixmap(QPixmap::fromImage(zoomedImg));
}
void MainWindow::onEnterKeyPressed()
{
    // Call the function to handle Enter key press
    // You can replace the function name and add your logic here
    // For example, you can call on_pushButton_28_clicked() or any other function
    // based on your requirements.
    on_pushButton_28_clicked();
}


void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    try{
                // Check if the left mouse button is pressed
                if (event->buttons() == Qt::LeftButton) {
                    // Get the current position of the mouse
                    QPoint currentMousePos = event->pos();

                    // Calculate the distance between each point and the initial mouse click position for label
                    int distance1 = (currentMousePos - QPoint(point1.x + 10, point1.y)).manhattanLength();
                    int distance2 = (currentMousePos - QPoint(point2.x + 10, point2.y)).manhattanLength();
                    int distance3 = (currentMousePos - QPoint(point3.x + 10, point3.y)).manhattanLength();
                    int distance4 = (currentMousePos - QPoint(point4.x + 10, point4.y)).manhattanLength();


                    int distanceC2 = (currentMousePos - QPoint(pointC2.x + 562, pointC2.y)).manhattanLength();
                    int distanceC12 = (currentMousePos - QPoint(pointC.x + 10, pointC.y)).manhattanLength();

                    // Determine the minimum distance among the points for label
                    int minDistance = std::min({distance1, distance2, distance3, distance4});

                    // Determine the minimum distance among the points for label_2
                    //int minDistance_2 = std::min({distance1_2, distance2_2, distance3_2, distance4_2});
                    int minDistance_3 = std::min({distanceC2});
                    int minDistance_4 = std::min({distanceC12});

                    // Check if the initial mouse click was close to any point (within a threshold, e.g., 15 pixels) for label
                    if (minDistance < 15) {
                        // Calculate the offset between the current mouse position and the initial mouse click position
                        QPoint offset(currentMousePos.x() - initialMousePos.x(), 0);  // Only horizontal movement

                        // Update the position of the appropriate point based on the offset for label
                        if (minDistance == distance1) {
                            if(lock){
                                updatePointPosition(point1, offset);
                                updatePointPosition(point2, -offset);
                            }
                            else if (lock == false){
                                updatePointPosition(point1, offset);
                            }
                        } else if (minDistance == distance2) {
                            if(lock){
                                updatePointPosition(point1, -offset);
                                updatePointPosition(point2, offset);
                            }
                            else if (lock == false){
                                updatePointPosition(point2, offset);
                            }
                        } else if (minDistance == distance3) {
                            if(lock){
                                updatePointPosition(point3, offset);
                                updatePointPosition(point4, -offset);
                            }
                            else if (lock == false){
                                updatePointPosition(point3, offset);
                            }
                        } else if (minDistance == distance4) {
                            if(lock){
                                updatePointPosition(point4, offset);
                                updatePointPosition(point3, -offset);
                            }
                            else if (lock == false){
                                updatePointPosition(point4, offset);
                            }
                        }
                        calculateCenter(point1, point2, point3, point4, pointC);
                       // updatePointPosition(point4, offset);
                        // Redraw the image with updated points for label
                        drawImageWithPoints();
                        applyPerspectiveTransformation(originalImage, originalImage2);
                    }

                    if (minDistance_3 < 15) {
                        // Calculate the offset between the current mouse position and the initial mouse click position for label_2
                        QPoint offset_2 = currentMousePos - initialMousePos;

                        // Update the position of the appropriate point based on the offset for label_2
                            updatePointPosition(point1_2, offset_2);
                            updatePointPosition(point2_2, offset_2);
                            updatePointPosition(point3_2, offset_2);
                            updatePointPosition(point4_2, offset_2);
                            updatePointPosition(pointC2, offset_2);
                        // Redraw the image with updated points for label_2
                        drawImageWithPoints2();
                        applyPerspectiveTransformation(originalImage, originalImage2);
                    }
                    if (minDistance_4 < 15) {
                        // Calculate the offset between the current mouse position and the initial mouse click position for label_2
                        QPoint offset_5 = currentMousePos - initialMousePos;

                        // Update the position of the appropriate point based on the offset for label_2
                        updatePointPosition(point1, offset_5);
                        updatePointPosition(point2, offset_5);
                        updatePointPosition(point3, offset_5);
                        updatePointPosition(point4, offset_5);
                        updatePointPosition(pointC, offset_5);
                        // Redraw the image with updated points for label_2
                        drawImageWithPoints();
                        applyPerspectiveTransformation(originalImage, originalImage2);
                    }

                    // Update the initial mouse position for the next move event
                    initialMousePos = currentMousePos;
                } else {
                    isMouseHeldOnPoint = false;  // Reset the flag if the mouse button is released
                }


        }catch (const std::exception &ex) {
            qDebug() << "Exception caught: " << ex.what();
            // You can add further actions in case of an exception, such as showing an error message
        }
}


// Function to update the position of a point based on mouse movement
void MainWindow::updatePointPosition(cv::Point2f& point, const QPointF &offset)
{
    // Update the position of the point based on the offset
    point.x += static_cast<float>(offset.x());
    point.y += static_cast<float>(offset.y());

    // Print the current position of the point
    qDebug() << "Point Position: " << point.x << ", " << point.y;

}


// Function to draw the image with updated points and display it
void MainWindow::drawImageWithPoints()
{
    try{

            // Reset the modified image to the original image
            modifiedImage = originalImage.clone();

            // Draw circles at each point on the image
            cv::circle(modifiedImage, point1, 10, cv::Scalar(255, 0, 0), 1); // Blue outline
            cv::circle(modifiedImage, point2, 10, cv::Scalar(255, 0, 0), 1);
            cv::circle(modifiedImage, point3, 10, cv::Scalar(255, 0, 0), 1);
            cv::circle(modifiedImage, point4, 10, cv::Scalar(255, 0, 0), 1);
            cv::circle(modifiedImage, pointC, 10, cv::Scalar(0, 255, 255), 1);



            // Draw a line between point1 and point2
            cv::line(modifiedImage, point1, point2, cv::Scalar(200, 200, 0), 1);
            cv::line(modifiedImage, point1, point3, cv::Scalar(200, 200, 0), 1);
            cv::line(modifiedImage, point2, point4, cv::Scalar(200, 200, 0), 1);
            cv::line(modifiedImage, point4, point3, cv::Scalar(200, 200, 0), 1);

            if(p1)
            {
                cv::circle(modifiedImage, point1, 13, cv::Scalar(0, 0, 255), 1);
            }
            if(p2)
            {
                cv::circle(modifiedImage, point2, 13, cv::Scalar(0, 0, 255), 1);
            }
            if(p3)
            {
                cv::circle(modifiedImage, point3, 13, cv::Scalar(0, 0, 255), 1);
            }
            if(p4)
            {
                cv::circle(modifiedImage, point4, 13, cv::Scalar(0, 0, 255), 1);
            }
            if(pc1)
            {
                cv::circle(modifiedImage, pointC, 13, cv::Scalar(0, 0, 255), 2);
            }


            // Convert BGR to RGB for OpenCV images
            cv::cvtColor(modifiedImage, modifiedImage, cv::COLOR_BGR2RGB);

            // Convert OpenCV Mat to QImage for the modified image
            QImage modifiedImg = QImage(modifiedImage.data, modifiedImage.cols, modifiedImage.rows, modifiedImage.step, QImage::Format_RGB888);

            // Display the modified image in the QLabel
            cv::Point zoomCente;
            if (p1 && z == true){
                zoomCente = point1;
                ui->label->setPixmap(QPixmap::fromImage(modifiedImg));
                zoomInOnPoint(modifiedImage, zoomCente, zoomratio, ui->label);

            } else if (p2 && z == true){
                zoomCente = point2;
                ui->label->setPixmap(QPixmap::fromImage(modifiedImg));
                zoomInOnPoint(modifiedImage, zoomCente, zoomratio, ui->label);
            }else if (p3 && z == true){
                zoomCente = point3;
                ui->label->setPixmap(QPixmap::fromImage(modifiedImg));
                zoomInOnPoint(modifiedImage, zoomCente, zoomratio, ui->label);
            }else if (p4 && z == true){
                zoomCente = point4;
                ui->label->setPixmap(QPixmap::fromImage(modifiedImg));
                zoomInOnPoint(modifiedImage, zoomCente, zoomratio, ui->label);
            }else if (pc1 && z == true){
                zoomCente = pointC;
                ui->label->setPixmap(QPixmap::fromImage(modifiedImg));
                zoomInOnPoint(modifiedImage, zoomCente, zoomratio, ui->label);
            }else{
                ui->label->setPixmap(QPixmap::fromImage(modifiedImg));
            }

            if (!controlWindow || controlWindow.isNull()) {
                // If not, create a new instance

            } else {
                // If already open, just bring it to front
                on_pushButton_34_clicked();
            }


        //    sss();


            //on_pushButton_34_clicked();
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}
void MainWindow::sss()
{
    double ioa = calculate_ioa(mask1/255,mask2/255);
    qDebug() << "IOA: " << ioa;
    double iou = calculate_iou(mask1/255,mask2/255);
    qDebug() << "IOu: " << iou;

    double s = ((0.65*ioa + 0.35*iou) * 100) ;
    qDebug() << "score: " << s;
    score = s;

    imgscorelable->setText(QString(" %1").arg(score));
    if (score < 85) {
        imgscorelable->setStyleSheet("background-color: red;");
    } else if (score < 90 && score >= 85) {
        imgscorelable->setStyleSheet("background-color: orange;");
    } else if (score >= 90) {
        imgscorelable->setStyleSheet("background-color: green;");
    }
}
// Function to draw the image with updated points and display it for label_2
void MainWindow::drawImageWithPoints2()
{

    try{
                // Reset the modified image to the original image for label_2
                modifiedImage2 = originalImage2.clone();

                // Draw circles at each point on the image for label_2
                cv::circle(modifiedImage2, point1_2, 10, cv::Scalar(255, 0, 0), 1);
                cv::circle(modifiedImage2, point2_2, 10, cv::Scalar(255, 0, 0), 1);
                cv::circle(modifiedImage2, point3_2, 10, cv::Scalar(255, 0, 0), 1);
                cv::circle(modifiedImage2, point4_2, 10, cv::Scalar(255, 0, 0), 1);
                cv::circle(modifiedImage2, pointC2, 10, cv::Scalar(0, 255, 255), 2);

                // Draw a line between point1_2 and point2_2
                cv::line(modifiedImage2, point1_2, point2_2, cv::Scalar(200, 200, 0), 1);
                cv::line(modifiedImage2, point1_2, point3_2, cv::Scalar(200, 200, 0), 1);
                cv::line(modifiedImage2, point2_2, point4_2, cv::Scalar(200, 200, 0), 1);
                cv::line(modifiedImage2, point4_2, point3_2, cv::Scalar(200, 200, 0), 1);
                if(p1_2)
                {
                    cv::circle(modifiedImage2, point1_2, 13, cv::Scalar(0, 0, 255), 1);
                }
                if(p2_2)
                {
                    cv::circle(modifiedImage2, point2_2, 13, cv::Scalar(0, 0, 255), 1);
                }
                if(p3_2)
                {
                    cv::circle(modifiedImage2, point3_2, 13, cv::Scalar(0, 0, 255), 1);
                }
                if(p4_2)
                {
                    cv::circle(modifiedImage2, point4_2, 13, cv::Scalar(0, 0, 255), 1);
                }
                if(pc)
                {
                    cv::circle(modifiedImage2, pointC2, 13, cv::Scalar(0, 0, 255), 2);
                }
                // Convert BGR to RGB for OpenCV images
                cv::cvtColor(modifiedImage2, modifiedImage2, cv::COLOR_BGR2RGB);

                // Convert OpenCV Mat to QImage for the modified image for label_2
                QImage modifiedImg2 = QImage(modifiedImage2.data, modifiedImage2.cols, modifiedImage2.rows, modifiedImage2.step, QImage::Format_RGB888);

                // Display the modified image in the QLabel for label_2
                ui->label_2->setPixmap(QPixmap::fromImage(modifiedImg2));

                if (!controlWindowwww || controlWindowwww.isNull()) {
                    // If not, create a new instance

                } else {
                    // If already open, just bring it to front
                    on_pushButton_35_clicked();
                }

              //  sss();



      }catch (const std::exception &ex) {
          qDebug() << "Exception caught: " << ex.what();
          // You can add further actions in case of an exception, such as showing an error message
      }
}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::calculateCenter(const cv::Point& p1, const cv::Point& p2, const cv::Point& p3, const cv::Point& p4, cv::Point2f& center) {
    try{
            center.x = (p1.x + p2.x + p3.x + p4.x) / 4;
            center.y = (p1.y + p2.y + p3.y + p4.y) / 4;

    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}

void MainWindow::calculateCenterr(const cv::Point& p1, const cv::Point& p2, const cv::Point& p3, const cv::Point& p4, cv::Point2f& center) {
    try{
        center.x = (p1.x + p2.x + p3.x + p4.x) / 4;
        center.y = (p1.y + p2.y + p3.y + p4.y) / 4;

    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}






void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    // Update the displayed image based on the slider value
    loadAndDisplayImage(position);
}
void MainWindow::loadAndDisplayImage(int position)
{
    try{

                if (position >= 0 && position < imageFileList.size()) {
                    QString imageName = imageFileList[position];
                    QString imagePath = selectedFolderPath + QDir::separator() + imageName;

                    cv::Mat image = cv::imread(imagePath.toStdString());

                    if (!image.empty()) {
                        QSize labelSize1 = ui->label->size();

                        cv::resize(image, image, cv::Size(labelSize1.width(), labelSize1.height()));

                        originalImage = image.clone();
                        modifiedImage = originalImage.clone();
                        ui->label_21->setText(QString("%1/%2").arg(position + 1).arg(imageFileList.size()));
                        ui->label_22->setText(imageName);



                        // Update the imageName variable
                        this->imageName = imageName;
                        qDebug() << "image: " << imageName;
                        qDebug() << "load image: " << imagePath;
                        accumulatedRotationAngle = 0;
                        updatePointsAndRedraw();
                        loadPointsFromTextFile(selectedFolderPath);
                             loadscoreImage(position);
                    } else {
                        this->imageName = imageName;
                        qDebug() << "Failed to load image: " << imagePath;
                        loadPointsFromTextFile(selectedFolderPath);
                    }
                }
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::loadscoreImage(int position)
{
    try{

        if (position >= 0 && position < imageFileList.size()) {
            QString imageName = imageFileList[position];
            imageName.replace(".jpg", ".png", Qt::CaseInsensitive);
            QString imagePath = selectedFolderPath2 + QDir::separator() + imageName;
            qDebug() << "imageee: " << imagePath;

            mask1 = cv::imread(imagePath.toStdString());


            if (!mask1.empty()) {
                QSize labelSize1 = ui->label->size();

                cv::cvtColor(mask1, mask1, cv::COLOR_BGR2GRAY);
                cv::threshold(mask1, mask1, 0, 255, cv::THRESH_BINARY);
                cv::resize(mask1, mask1, cv::Size(labelSize1.width(), labelSize1.height()));
                sss();
                imgscore=score;
                if (imgscore < 85) {
                    inscore->setStyleSheet("background-color: red;");
                } else if (imgscore < 90 && imgscore >= 85) {
                    inscore->setStyleSheet("background-color: orange;");
                } else if (imgscore >= 90) {
                    inscore->setStyleSheet("background-color: green;");
                }
                 inscore->setText(QString("%1").arg(imgscore));

                QImage mask = QImage(mask1.data, mask1.cols, mask1.rows, mask1.step, QImage::Format_Grayscale8);

                // Display the modified image in the QLabel for label_2
             //   ui->label_2->setPixmap(QPixmap::fromImage(mask));

                //originalImage = image.clone();
              //  modifiedImage = originalImage.clone();
              //  ui->label_21->setText(QString("%1/%2").arg(position + 1).arg(imageFileList.size()));
               // ui->label_22->setText(imageName);

               qDebug() << "imfsfdsfsdfsdfsdfsdfage: ";

                // Update the imageName variable
              //  this->imageName = imageName;
                //qDebug() << "image: " << imageName;
                //qDebug() << "load image: " << imagePath;
                //accumulatedRotationAngle = 0;
                //updatePointsAndRedraw();
                //loadPointsFromTextFile(selectedFolderPath);
            } else {
                this->imageName = imageName;
                qDebug() << "Faileddddd to load image: " << imagePath;
               // loadPointsFromTextFile(selectedFolderPath);
            }
        }
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}






// Open folder button click
void MainWindow::on_pushButton_19_clicked() // open folder
{
    try{
                    // Open a folder dialog to select a directory
                    QString folderPath = QFileDialog::getExistingDirectory(this, tr("Select Folder"), QDir::homePath());

                    if (!folderPath.isEmpty()) {
                        // Change the working directory to the selected folder
                        QDir::setCurrent(folderPath);

                        // Check if the "imgs" subfolder exists
                        QDir imgsFolder("imgs");
                        if (imgsFolder.exists()) {
                            // Clear the listWidget before adding new items
                  //          ui->listWidget->clear();
                           imageFileList.clear();  // Clear the imageFileList

                            // Set the directory to the "imgs" subfolder
                            QDir directory("imgs");

                            // Filter JPG files
                            QStringList filters;
                            filters << "*.jpg"<< "*.png";;
                            directory.setNameFilters(filters);

                            // Get the list of JPG files in the directory
                            QFileInfoList fileList = directory.entryInfoList();

                            // Add each JPG file name to the listWidget and imageFileList
                            foreach (const QFileInfo &fileInfo, fileList) {
                               // ui->listWidget->addItem(fileInfo.fileName());
                                imageFileList.append(fileInfo.fileName());
                            }

                            // Set the maximum value of the slider based on the number of images
                            ui->horizontalSlider->setMaximum(imageFileList.size() - 1);

                            // Update the slider based on its size
                            selectedFolderPath = folderPath + QDir::separator() + "imgs";
                            selectedFolderPath2 = folderPath + QDir::separator() + "GT";
                            loadAndDisplayImage(0);
                            loadscoreImage(0);
                            updateSliderSize();

                            // Load points from the text file corresponding to the selected image
                           // loadPointsFromTextFile(selectedFolderPath);
                        } else {
                            qDebug() << "The 'imgs' subfolder does not exist in the selected folder.";
                        }
                    }

    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}






void MainWindow::loadPointsFromTextFile(const QString &folderPath)
{

                // Assuming imageName is the name of the currently selected image
                QDir parentDir(folderPath);
                parentDir.cdUp();
                QString textFilePath = parentDir.absolutePath() + QDir::separator() + "sol" + QDir::separator() + imageName + ".txt";

                QFile textFile(textFilePath);
                if (textFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    QTextStream stream(&textFile);

                    // Define a regular expression pattern to match integer values in the format (x, y)
                    QRegularExpression integerPattern("\\((-?\\d+), (-?\\d+)\\)");

                    // Read and set values for Trapezoidal points
                    stream.readLine(); // Skip "Trapezoidal points:"
                    readPointValues(stream, integerPattern, point1x, point1y);
                    readPointValues(stream, integerPattern, point2x, point2y);
                    readPointValues(stream, integerPattern, point3x, point3y);
                    readPointValues(stream, integerPattern, point4x, point4y);

                    // Read and set values for Rectangle points
                    stream.readLine(); // Skip "Rectangle points:"
                    readPointValues(stream, integerPattern, point1_2x, point1_2y);
                    readPointValues(stream, integerPattern, point2_2x, point2_2y);
                    readPointValues(stream, integerPattern, point3_2x, point3_2y);
                    readPointValues(stream, integerPattern, point4_2x, point4_2y);

                    stream.readLine(); // Skip "Rotation:"
                    QString rotationLine = stream.readLine().trimmed();

                    stream.readLine(); // Skip "Rotation:"
                 //   QString s = stream.readLine().trimmed();
                   // score = s.toDouble();
                   // qDebug() << "score is " << score;



                    accumulatedRotationAngle = rotationLine.toDouble();
                    rectangle = 0.0;
                    accumulatedRotationAnglecopy = accumulatedRotationAngle;


                    imgscorelable->setText(QString(" %1").arg(score));
                    if (score < 85) {
                        imgscorelable->setStyleSheet("background-color: red;");
                    } else if (score < 90 && score >= 85) {
                        imgscorelable->setStyleSheet("background-color: orange;");
                    } else if (score >= 90) {
                        imgscorelable->setStyleSheet("background-color: green;");
                    }

                    // Print or use the result



                    point1x *= 0.40703125;
                    point1y *= 0.3625;
                    point2x *= 0.40703125;
                    point2y *= 0.3625;
                    point3x *= 0.40703125;
                    point3y *= 0.3625;
                    point4x *= 0.40703125;
                    point4y *= 0.3625;

                    point1_2x *= 0.4990234375;
                    point1_2y *= 0.3826979472;
                    point2_2x *= 0.4990234375;
                    point2_2y *= 0.3826979472;
                    point3_2x *= 0.4990234375;
                    point3_2y *= 0.3826979472;
                    point4_2x *= 0.4990234375;
                    point4_2y *= 0.3826979472;

                    qDebug() << "Rotation Angle: " << accumulatedRotationAngle;
                    qDebug() << " x:" << point1_2x;

                    point1 = cv::Point2f(point1x, point1y);
                    point2 = cv::Point2f(point2x, point2y);
                    point3 = cv::Point2f(point3x, point3y);
                    point4 = cv::Point2f(point4x, point4y);

                    qDebug() << "Point 1: x =" << point1.x << ", y =" << point1.y;
                    qDebug() << "Point 2: x =" << point2.x << ", y =" << point2.y;
                    qDebug() << "Point 3: x =" << point3.x << ", y =" << point3.y;
                    qDebug() << "Point 4: x =" << point4.x << ", y =" << point4.y;

                    // Initialize the positions of the points for label_2
                    point1_2 = cv::Point2f(point1_2x, point1_2y);
                    point2_2 = cv::Point2f(point2_2x, point2_2y);
                    point3_2 = cv::Point2f(point3_2x, point3_2y);
                    point4_2 = cv::Point2f(point4_2x, point4_2y);

                    qDebug() << "Point 1: x =" << point1_2.x << ", y =" << point1_2.y;
                    qDebug() << "Point 2: x =" << point2_2.x << ", y =" << point2_2.y;
                    qDebug() << "Point 3: x =" << point3_2.x << ", y =" << point3_2.y;
                    qDebug() << "Point 4: x =" << point4_2.x << ", y =" << point4_2.y;

                    // Close the file
                    textFile.close();
                } else {
                    qDebug() << "Failed to open the text file: " << textFilePath;
                    point1x = 150;
                    point1y = 80;
                    point2x = 330;
                    point2y = 80;
                    point3x = 100;
                    point3y = 150;
                    point4x = 380;
                    point4y = 150;

                    point1_2x = 150+61;
                    point1_2y = 80+16;
                    point2_2x = 150+61;
                    point2_2y = 180-16;
                    point3_2x = 350-51;
                    point3_2y = 80+16;
                    point4_2x = 350-51;
                    point4_2y = 180-16;



                    point1 = cv::Point(point1x, point1y);
                    point2 = cv::Point(point2x, point2y);
                    point3 = cv::Point(point3x, point3y);
                    point4 = cv::Point(point4x, point4y);

                    // Initialize the positions of the points for label_2
                    point1_2 = cv::Point(point1_2x, point1_2y);
                    point2_2 = cv::Point(point2_2x, point2_2y);
                    point3_2 = cv::Point(point3_2x, point3_2y);
                    point4_2 = cv::Point(point4_2x, point4_2y);
                    pointC2 = cv::Point(0, 0);
                    pointC = cv::Point(0, 0);
                    accumulatedRotationAngle = 0.0;
                    rectangle = 0.0;
                    calculateCenter(point1_2, point2_2, point3_2, point4_2, pointC2);
                    calculateCenter(point1, point2, point3, point4, pointC);

                    qDebug() << "Center 1: (" << pointC.x << ", " << pointC.y << ")";
                    // Print or use the result
                    qDebug() << "Center: (" << pointC2.x << ", " << pointC2.y << ")";
                    // Draw circles at each point on the images
                    //   drawImageWithPoints();
                    drawImageWithPoints2();  // Add this line to draw points on label_2
                     drawImageWithPoints();  // Add this line to draw points on label_2

                }
}


void MainWindow::readPointValues(QTextStream &stream, const QRegularExpression &pattern, double &x, double &y)
{
    QString line = stream.readLine();
    QRegularExpressionMatch match = pattern.match(line);
    if (match.hasMatch()) {
        x = match.captured(1).toDouble();
        y = match.captured(2).toDouble();

       qDebug() << "P values - x:" << x << "y:" << y;
    } else {
        qDebug() << "Failed to match values in line: " << line;
    }
}
void MainWindow::updatePointsAndRedraw()
{
    // Initialize or reset the points as needed

    loadPointsFromTextFile(selectedFolderPath);
    qDebug() << "fileerrrr " << &point1_2.x;

    calculateCenter(point1_2, point2_2, point3_2, point4_2, pointC2);
    calculateCenter(point1, point2, point3, point4, pointC);
    // Redraw the image with updated points for label_2
    drawImageWithPoints();
    drawImageWithPoints2();

    // Apply perspective transformation with the updated image
    applyPerspectiveTransformation(originalImage, originalImage2);
}

void MainWindow::updateSliderSize()
{
    // Update the slider based on its width
    int availableSpace = ui->horizontalSlider->width();

    // Calculate the maximum value of the slider based on the available space
    int maxSliderValue = imageFileList.size() - 1;
    int sliderValue = static_cast<int>((static_cast<double>(maxSliderValue) / availableSpace) * ui->horizontalSlider->width());

    // Save the current slider value before updating
    int currentSliderValue = ui->horizontalSlider->value();

    // Disconnect the sliderMoved signal temporarily
    disconnect(ui->horizontalSlider, &QSlider::sliderMoved, this, &MainWindow::on_horizontalSlider_sliderMoved);

    // Set the single step size to zero to prevent handle movement on click
    ui->horizontalSlider->setSingleStep(0);
    ui->horizontalSlider->setSliderPosition(sliderValue);

    // Reset the single step size
    ui->horizontalSlider->setSingleStep(1);

    // Reconnect the sliderMoved signal
    connect(ui->horizontalSlider, &QSlider::sliderMoved, this, &MainWindow::on_horizontalSlider_sliderMoved);

    // Reset the slider to its previous position to prevent movement when clicking on the line
    ui->horizontalSlider->setValue(currentSliderValue);

}
void MainWindow::on_horizontalSlider_sliderPressed()
{
    // Handle slider pressed event
    disconnect(ui->horizontalSlider, &QSlider::sliderMoved, this, &MainWindow::on_horizontalSlider_sliderMoved);
    previousSliderPosition = ui->horizontalSlider->value();
    // For example, you can add code here to pause automatic slider updates

}

void MainWindow::on_horizontalSlider_sliderReleased()
{
    connect(ui->horizontalSlider, &QSlider::sliderMoved, this, &MainWindow::on_horizontalSlider_sliderMoved);

    // Update the displayed image based on the current slider value

    loadAndDisplayImage(ui->horizontalSlider->value());


    // For example, you can add code here to resume automatic slider updates
}













std::pair<cv::Mat, cv::Mat> MainWindow::calculatePerspectiveMatrix()
{
    // Define source and destination points
    cv::Point2f destPoints[4] = {point1, point2, point3, point4};
    cv::Point2f srcPoints[4] = {point1_2, point3_2, point2_2, point4_2};

    if (modifyPointsOnButtonClick) {
        accumulatedRotationAngle += rotatingratio;
    }
    if (Click) {
        accumulatedRotationAngle -= rotatingratio;
    }
    if (rl) {
        rectangle -= rectratio;
    }
    if (Cl) {
        rectangle += rectratio;
    }

    qDebug() << "modifyPointsOnButtonClick is now: " << modifyPointsOnButtonClick;

    cv::Point2f centerr(0,0);

   // qDebug() << "modifyPoi is now: " ;
    //for (int i = 0; i < 4; ++i) {
     //   centerr += srcPoints[i];
   // }
   // centerr /= 4.0;
    calculateCenterr(point1, point2, point3, point4, centerr);
    // Rotate all points around the center by accumulatedRotationAngle degrees
    qDebug() << " now: " << accumulatedRotationAngle;
    double angleInRadians = accumulatedRotationAngle * CV_PI / 180.0;
    qDebug() << "center x :" << centerr.x;
    qDebug() << "center y: " << centerr.y;
   // drawImageWithPoints();
    for (int i = 0; i < 4; ++i) {
        cv::Point2f temp = destPoints[i] - centerr;
        destPoints[i].x = temp.x * cos(angleInRadians) - temp.y * sin(angleInRadians) + centerr.x;
        destPoints[i].y = temp.x * sin(angleInRadians) + temp.y * cos(angleInRadians) + centerr.y;
    }
    cv::Point2f centerrr(0,0);
    calculateCenterr(point1_2, point2_2, point3_2, point4_2, centerrr);
    double a = rectangle * CV_PI / 180.0;
    qDebug() << "center x :" << centerrr.x;
    qDebug() << "center y: " << centerrr.y;
    // drawImageWithPoints();
    for (int i = 0; i < 4; ++i) {
        cv::Point2f tempo = srcPoints[i] - centerrr;
        srcPoints[i].x = tempo.x * cos(a) - tempo.y * sin(a) + centerrr.x;
        srcPoints[i].y = tempo.x * sin(a) + tempo.y * cos(a) + centerrr.y;
    }

    // Calculate the forward perspective transformation matrix
    cv::Mat forwardPerspectiveMatrix = cv::getPerspectiveTransform(srcPoints, destPoints);

    // Calculate the inverse perspective transformation matrix
    cv::Mat inversePerspectiveMatrix = cv::getPerspectiveTransform(destPoints, srcPoints);

    return std::make_pair(forwardPerspectiveMatrix, inversePerspectiveMatrix);
}

void MainWindow::applyPerspectiveTransformation(const cv::Mat& image1, const cv::Mat& image2)
{
    // Calculate the perspective transformation matrices
    auto perspectiveMatrices = calculatePerspectiveMatrix();
    cv::Mat forwardPerspectiveMatrix = perspectiveMatrices.first;
    cv::Mat inversePerspectiveMatrix = perspectiveMatrices.second;

    // Create a copy of the original images for label_3 and label_4
    cv::Mat transformedImage2_forward = image2.clone();
    cv::Mat transformedImage2_inverse = image1.clone();

    // Apply forward perspective transformation to image2 using image1.size() as the output size
    cv::warpPerspective(image2, transformedImage2_forward, forwardPerspectiveMatrix, image1.size());

    // Apply inverse perspective transformation to image1 using image1.size() as the output size
    cv::warpPerspective(image1, transformedImage2_inverse, inversePerspectiveMatrix, image2.size());

    mask2 =  transformedImage2_forward.clone();
   // mask3 =  transformedImage2_inverse.clone();
    cv::cvtColor(mask2, mask2, cv::COLOR_BGR2GRAY);
   // cv::cvtColor(mask3, mask3, cv::COLOR_BGR2GRAY);
    //cv::threshold(mask2,mask2, 90, 255, cv::THRESH_BINARY);



    QImage mask = QImage(mask2.data, mask2.cols, mask2.rows, mask2.step, QImage::Format_Grayscale8);

    // Display the modified image in the QLabel for label_2
  //  ui->label->setPixmap(QPixmap::fromImage(mask));


    // Blend the two forward and inverse transformed images using equal weights
     blendedImage = 0.5 * image1 + 0.5 * transformedImage2_forward; //  hta5od dy : image1
     blendedImage2 = 0.5 * image2 + 0.5 * transformedImage2_inverse;
    // Convert BGR to RGB for OpenCV images
    cv::cvtColor(blendedImage, blendedImage, cv::COLOR_BGR2RGB);
    cv::cvtColor(blendedImage2, blendedImage2, cv::COLOR_BGR2RGB);

    // Convert OpenCV Mat to QImage for the blended image
    QImage blendedImg = QImage(blendedImage.data, blendedImage.cols, blendedImage.rows, blendedImage.step, QImage::Format_RGB888);
    QImage blendedImg2 = QImage(blendedImage2.data, blendedImage2.cols, blendedImage2.rows, blendedImage2.step, QImage::Format_RGB888);

    // Display the blended image in QLabel for label_3
    ui->label_3->setPixmap(QPixmap::fromImage(blendedImg));
    ui->label_4->setPixmap(QPixmap::fromImage(blendedImg2));

    //cv::cvtColor(image1, image1, cv::COLOR_BGR2GRAY);

    if (!controlWindoww || controlWindoww.isNull()) {
        // If not, create a new instance

    } else {
        // If already open, just bring it to front
        on_pushButton_36_clicked();
    }
    if (!controlWindowww || controlWindowww.isNull()) {
        // If not, create a new instance

    } else {
        // If already open, just bring it to front
        on_pushButton_37_clicked();
    }

    sss();

}



double MainWindow::calculate_ioa(const cv::Mat& binary_mask1, const cv::Mat& binary_mask2) {
    cv::Mat intersection;
    cv::bitwise_and(binary_mask1, binary_mask2, intersection);
    qDebug() << "Iy: " ;

    double ioa = static_cast<double>(cv::countNonZero(intersection)) / static_cast<double>(cv::countNonZero(binary_mask2));
    return ioa;
}

double MainWindow::calculate_iou(const cv::Mat& binary_mask1, const cv::Mat& binary_mask2) {
    cv::Mat intersection, union_mask;
    cv::bitwise_and(binary_mask1, binary_mask2, intersection);
    cv::bitwise_or(binary_mask1, binary_mask2, union_mask);
    qDebug() << "A: " ;

    double iou = static_cast<double>(cv::countNonZero(intersection)) / static_cast<double>(cv::countNonZero(union_mask));
    return iou;
}







std::pair<double, double> MainWindow::calculate_ioa_iou(const cv::Mat& image1, const cv::Mat& image2) {
    // Convert image1 to binary mask
   // cv::Mat binary_mask1;
   // cv::cvtColor(image1, image1, cv::COLOR_BGR2GRAY); // Convert to grayscale
   // cv::threshold(binary_mask1, binary_mask1, 128, 255, cv::THRESH_BINARY); // Threshold to create binary mask

    // Convert image2 to binary mask
   // cv::Mat binary_mask2;
   // cv::cvtColor(image2, image2, cv::COLOR_BGR2GRAY); // Convert to grayscale
   // cv::threshold(binary_mask2, binary_mask2, 128, 255, cv::THRESH_BINARY); // Threshold to create binary mask

    qDebug() << "IOjhjhjhjhA: " ;
    // Calculate IOA and IOU
    double ioa = calculate_ioa(image1/255, image2/255);
    double iou = calculate_iou(image1/255, image2/255);

    qDebug() << "IOA: " << ioa;
    qDebug() << "IOU: " << iou;

    return std::make_pair(ioa, iou);
}






void MainWindow::on_pushButton_clicked()
{
    try{
        point1_2.y -= movingratio;
        point3_2.y -= movingratio;
        calculateCenter(point1_2, point2_2, point3_2, point4_2, pointC2);
        // Redraw the image with the updated points for label_2
        drawImageWithPoints2();
        applyPerspectiveTransformation(originalImage, originalImage2);
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    try{
        point1_2.y += movingratio;
        point3_2.y += movingratio;
        calculateCenter(point1_2, point2_2, point3_2, point4_2, pointC2);
        drawImageWithPoints2();
        applyPerspectiveTransformation(originalImage, originalImage2);
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    try{
            point2_2.y -= movingratio;
            point4_2.y -= movingratio;
            calculateCenter(point1_2, point2_2, point3_2, point4_2, pointC2);

            // Redraw the image with the updated points for label_2
            drawImageWithPoints2();
            applyPerspectiveTransformation(originalImage, originalImage2);

    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_4_clicked()
{

    try{
            point2_2.y += movingratio;
            point4_2.y += movingratio;
            calculateCenter(point1_2, point2_2, point3_2, point4_2, pointC2);

            // Redraw the image with the updated points for label_2
            drawImageWithPoints2();
            applyPerspectiveTransformation(originalImage, originalImage2);
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }

}


void MainWindow::on_pushButton_5_clicked()
{
    try{
    point1_2.x += movingratio;
    point2_2.x += movingratio;
    calculateCenter(point1_2, point2_2, point3_2, point4_2, pointC2);

    // Redraw the image with the updated points for label_2
    drawImageWithPoints2();
    applyPerspectiveTransformation(originalImage, originalImage2);

    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }

}


void MainWindow::on_pushButton_6_clicked()
{
    try{
    point1_2.x -= movingratio;
    point2_2.x -= movingratio;
    calculateCenter(point1_2, point2_2, point3_2, point4_2, pointC2);


    // Redraw the image with the updated points for label_2
    drawImageWithPoints2();
    applyPerspectiveTransformation(originalImage, originalImage2);
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }

}


void MainWindow::on_pushButton_7_clicked()
{
    try{
    point3_2.x -= movingratio;
    point4_2.x -= movingratio;
    calculateCenter(point1_2, point2_2, point3_2, point4_2, pointC2);


    // Redraw the image with the updated points for label_2
    drawImageWithPoints2();
    applyPerspectiveTransformation(originalImage, originalImage2);
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }

}


void MainWindow::on_pushButton_8_clicked()
{
    try{
    point3_2.x += movingratio;
    point4_2.x += movingratio;
   calculateCenter(point1_2, point2_2, point3_2, point4_2, pointC2);


    // Redraw the image with the updated points for label_2
    drawImageWithPoints2();
    applyPerspectiveTransformation(originalImage, originalImage2);
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    try{
    point1_2.y -= movingratio;
    point2_2.y -= movingratio;
    point3_2.y -= movingratio;
    point4_2.y -= movingratio;
    calculateCenter(point1_2, point2_2, point3_2, point4_2, pointC2);


    // Redraw the image with the updated points for label_2
    drawImageWithPoints2();
    applyPerspectiveTransformation(originalImage, originalImage2);
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    try{
    point1_2.y += movingratio;
    point2_2.y += movingratio;
    point3_2.y += movingratio;
    point4_2.y += movingratio;
    calculateCenter(point1_2, point2_2, point3_2, point4_2, pointC2);


    // Redraw the image with the updated points for label_2
    drawImageWithPoints2();
    applyPerspectiveTransformation(originalImage, originalImage2);
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_12_clicked()
{
    try{
    point1_2.x -= movingratio;
    point2_2.x -= movingratio;
    point3_2.x -= movingratio;
    point4_2.x -= movingratio;
    calculateCenter(point1_2, point2_2, point3_2, point4_2, pointC2);


    // Redraw the image with the updated points for label_2
    drawImageWithPoints2();
    applyPerspectiveTransformation(originalImage, originalImage2);
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_11_clicked()
{
    try{
    point1_2.x += movingratio;
    point2_2.x += movingratio;
    point3_2.x += movingratio;
    point4_2.x += movingratio;
   calculateCenter(point1_2, point2_2, point3_2, point4_2, pointC2);


    // Redraw the image with the updated points for label_2
    drawImageWithPoints2();
    applyPerspectiveTransformation(originalImage, originalImage2);
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_13_clicked()
{
    try{
    point1.y -= movingratio;
    point2.y -= movingratio;

    // Redraw the image with the updated points for label_2
    calculateCenter(point1, point2, point3, point4, pointC);

    drawImageWithPoints();
    applyPerspectiveTransformation(originalImage, originalImage2);
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_14_clicked()
{
    try{
    point1.y += movingratio;
    point2.y += movingratio;

    // Redraw the image with the updated points for label_2
    calculateCenter(point1, point2, point3, point4, pointC);
    drawImageWithPoints();
    applyPerspectiveTransformation(originalImage, originalImage2);
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_15_clicked()
{
    try{
    point3.y -= movingratio;
    point4.y -= movingratio;

    // Redraw the image with the updated points for label_2
    calculateCenter(point1, point2, point3, point4, pointC);
    drawImageWithPoints();
    applyPerspectiveTransformation(originalImage, originalImage2);
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_16_clicked()
{
    try{
    point3.y += movingratio;
    point4.y += movingratio;

    // Redraw the image with the updated points for label_2
    calculateCenter(point1, point2, point3, point4, pointC);
    drawImageWithPoints();
    applyPerspectiveTransformation(originalImage, originalImage2);
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_17_clicked()
{
    try{
    // Toggle the modification state when the button is clicked
    modifyPointsOnButtonClick = true;
    qDebug() << "modifyPointsOnButtonClick is now: " << modifyPointsOnButtonClick;

    // Update the perspective transformation
    applyPerspectiveTransformation(originalImage, originalImage2);
    modifyPointsOnButtonClick = false;
    sss();
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}



void MainWindow::on_pushButton_18_clicked()
{
    try{
    Click = true;
    qDebug() << "modifyPointsOnButtonClick is now: " << modifyPointsOnButtonClick;

    // Update the perspective transformation
    applyPerspectiveTransformation(originalImage, originalImage2);
    Click = false;
    sss();
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}














void MainWindow::on_pushButton_21_clicked()
{
    try{
    rotatingratio += 0.2;
    qDebug() << "Failed to load image: " << rotatingratio;
    rotatingRatioLabel->setText(QString("%1").arg(rotatingratio));
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_20_clicked()
{
    try{
    if(rotatingratio <= 0.2){
        rotatingratio =0.2;
        qDebug() << " image: " << rotatingratio;
        rotatingRatioLabel->setText(QString("%1").arg(rotatingratio));
    }
    else if(rotatingratio > 0.2)
      rotatingratio -=0.2;
      qDebug() << "Failed to load image: " << rotatingratio;
      rotatingRatioLabel->setText(QString("%1").arg(rotatingratio));
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_22_clicked()
{
    try{
    movingratio += 0.2;
    movingRatioLabel->setText(QString("%1").arg(movingratio));
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_23_clicked()
{
    try{
    if(movingratio <= 0.2){
        movingratio =0.2;
        qDebug() << " image: " << movingratio;
        movingRatioLabel->setText(QString("%1").arg(movingratio));
    }
    else
        movingratio -=0.2;
        qDebug() << "Failed to load image: " << movingratio;
        movingRatioLabel->setText(QString("%1").arg(movingratio));
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }

}


void MainWindow::on_pushButton_24_clicked()
{
    try{
    // Get the current slider position
        if(flag==false)
        {
                        if (point1 != cv::Point2f(point1x, point1y) ||
                            point2 != cv::Point2f(point2x, point2y) ||
                            point3 != cv::Point2f(point3x, point3y) ||
                            point4 != cv::Point2f(point4x, point4y) ||
                            point1_2 != cv::Point2f(point1_2x, point1_2y) ||
                            point2_2 != cv::Point2f(point2_2x, point2_2y) ||
                            point3_2 != cv::Point2f(point3_2x, point3_2y) ||
                            point4_2 != cv::Point2f(point4_2x, point4_2y) ||
                            accumulatedRotationAnglecopy != accumulatedRotationAngle ||
                            rectangle != 0){
                            // Points for either label_1 or label_2 have changed
                            QMessageBox::StandardButton reply;
                            reply = QMessageBox::question(this, "Message", "You didn't save. Do you want to move now?",
                                                          QMessageBox::Yes|QMessageBox::No);
                            if (reply == QMessageBox::Yes) {
                                int currentPosition = ui->horizontalSlider->value();

                                // Increment the slider position to move to the next image
                                int newPosition = currentPosition + 1;

                                // Ensure the new position is within the valid range
                                if (newPosition < ui->horizontalSlider->maximum()+1) {
                                    // Set the new slider position
                                    ui->horizontalSlider->setValue(newPosition);

                                    // Update the displayed image based on the new slider position
                                    loadAndDisplayImage(newPosition);
                                    loadscoreImage(newPosition);
                                    flag=false;
                                }
                            } else {
                                flag = true;
                            }
                            }
                            else{
                                int currentPosition = ui->horizontalSlider->value();

                                // Increment the slider position to move to the next image
                                int newPosition = currentPosition + 1;

                                // Ensure the new position is within the valid range
                                if (newPosition < ui->horizontalSlider->maximum()+1) {
                                    // Set the new slider position
                                    ui->horizontalSlider->setValue(newPosition);

                                    // Update the displayed image based on the new slider position
                                    loadAndDisplayImage(newPosition);
                                    loadscoreImage(newPosition);
                                    flag=false;
                                }}


        }
        else{
            int currentPosition = ui->horizontalSlider->value();

            // Increment the slider position to move to the next image
            int newPosition = currentPosition + 1;

            // Ensure the new position is within the valid range
            if (newPosition < ui->horizontalSlider->maximum()+1) {
                // Set the new slider position
                ui->horizontalSlider->setValue(newPosition);

                // Update the displayed image based on the new slider position
                loadAndDisplayImage(newPosition);
                loadscoreImage(newPosition);
                flag=false;
            }

        }
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_25_clicked()
{
    try{

        if(flag==false)
        {
            if (point1 != cv::Point2f(point1x, point1y) ||
                point2 != cv::Point2f(point2x, point2y) ||
                point3 != cv::Point2f(point3x, point3y) ||
                point4 != cv::Point2f(point4x, point4y) ||
                point1_2 != cv::Point2f(point1_2x, point1_2y) ||
                point2_2 != cv::Point2f(point2_2x, point2_2y) ||
                point3_2 != cv::Point2f(point3_2x, point3_2y) ||
                point4_2 != cv::Point2f(point4_2x, point4_2y) ||
                accumulatedRotationAnglecopy != accumulatedRotationAngle ||
                rectangle != 0){
                // Points for either label_1 or label_2 have changed

                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Message", "You didn't save. Do you want to move now?",
                                              QMessageBox::Yes|QMessageBox::No);
                if (reply == QMessageBox::Yes) {

                    int currentPosition = ui->horizontalSlider->value();

                    // Decrement the slider position to move to the previous image
                    int newPosition = currentPosition - 1;

                    // Ensure the new position is within the valid range
                    if (newPosition >= ui->horizontalSlider->minimum()) {
                        // Set the new slider position
                        ui->horizontalSlider->setValue(newPosition);

                        // Update the displayed image based on the new slider position
                        loadAndDisplayImage(newPosition);
                        loadscoreImage(newPosition);
                        flag=false;
                    }


                } else {
                   flag = true;
                }
                }
            else{
                int currentPosition = ui->horizontalSlider->value();

                // Decrement the slider position to move to the previous image
                int newPosition = currentPosition - 1;

                // Ensure the new position is within the valid range
                if (newPosition >= ui->horizontalSlider->minimum()) {
                    // Set the new slider position
                    ui->horizontalSlider->setValue(newPosition);

                    // Update the displayed image based on the new slider position
                    loadAndDisplayImage(newPosition);
                    loadscoreImage(newPosition);
                    flag=false;
                }


            }

        }
        else{
                    // Get the current slider position
                    int currentPosition = ui->horizontalSlider->value();

                    // Decrement the slider position to move to the previous image
                    int newPosition = currentPosition - 1;

                    // Ensure the new position is within the valid range
                    if (newPosition >= ui->horizontalSlider->minimum()) {
                        // Set the new slider position
                        ui->horizontalSlider->setValue(newPosition);

                        // Update the displayed image based on the new slider position
                        loadAndDisplayImage(newPosition);
                         loadscoreImage(newPosition);
                        flag=false;
                    }
        }
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_27_clicked()
{
    try{
    // Get the current slider position
    int currentPosition = ui->horizontalSlider->value();

    // Increment the slider position by 10 to move to the next 10 images
    int newPosition = currentPosition + 10;

    // Ensure the new position is within the valid range
    if (newPosition <= ui->horizontalSlider->maximum()+1) {
        // Set the new slider position
        ui->horizontalSlider->setValue(newPosition);

        // Update the displayed image based on the new slider position
        loadAndDisplayImage(newPosition);
         loadscoreImage(newPosition);
    }
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_26_clicked()
{
    try{
    // Get the current slider position
    int currentPosition = ui->horizontalSlider->value();

    // Decrement the slider position by 10 to move to the previous 10 images
    int newPosition = currentPosition - 10;

    // Ensure the new position is within the valid range
    if (newPosition >= ui->horizontalSlider->minimum()) {
        // Set the new slider position
        ui->horizontalSlider->setValue(newPosition);

        // Update the displayed image based on the new slider position
        loadAndDisplayImage(newPosition);
        loadscoreImage(newPosition);
    }
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }

}


void MainWindow::on_pushButton_28_clicked()
{
    try{
    if (imageName.isEmpty()) {
        qDebug() << "No image selected.";
        return;
    }

    // Get the parent directory of the "lolo" folder
    QDir parentDir(selectedFolderPath);
    parentDir.cdUp(); // Move up one level

    // Construct the output file path
    QString outputFolderPath = parentDir.absolutePath() + QDir::separator() + "output";
    QDir outputFolder(outputFolderPath);
    if (!outputFolder.exists()) {
        outputFolder.mkpath(".");
    }

    QString outputFilePath = outputFolderPath + QDir::separator() + imageName + ".txt";

    QFile outputFile(outputFilePath);
    if (outputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // Write points positions to the file (modify this part based on your data structure)
        QTextStream stream(&outputFile);

        point1.x /= 0.40703125;
        point1.y /= 0.3625;
        point2.x /= 0.40703125;
        point2.y /= 0.3625;
        point3.x /= 0.40703125;
        point3.y /= 0.3625;
        point4.x /= 0.40703125;
        point4.y /= 0.3625;

        point1_2.x /= 0.4990234375;
        point1_2.y /= 0.3826979472;
        point2_2.x /= 0.4990234375;
        point2_2.y /= 0.3826979472;
        point3_2.x /= 0.4990234375;
        point3_2.y /= 0.3826979472;
        point4_2.x /= 0.4990234375;
        point4_2.y /= 0.3826979472;

        stream << "Trapezoidal points: \n";
        stream << "Point 1: (" << point1.x << ", " << point1.y << ")\n";
        stream << "Point 2: (" << point2.x << ", " << point2.y << ")\n";
        stream << "Point 3: (" << point3.x << ", " << point3.y << ")\n";
        stream << "Point 4: (" << point4.x << ", " << point4.y << ")\n";

        stream << "Rectangle points: \n";
        stream << "Point 1_2: (" << point1_2.x << ", " << point1_2.y << ")\n";
        stream << "Point 2_2: (" << point2_2.x << ", " << point2_2.y << ")\n";
        stream << "Point 3_2: (" << point3_2.x << ", " << point3_2.y << ")\n";
        stream << "Point 4_2: (" << point4_2.x << ", " << point4_2.y << ")\n";
        // ... add more points if needed
        stream << "Rotation Angle: \n";
        stream << accumulatedRotationAngle << "\n";

        stream << "Rect Rotation Angle: \n";
        stream << rectangle << "\n";

        stream << "Image score was: \n";
        stream << imgscore << "\n";

        stream << "His score is: \n" ;
        stream << score;


        outputFile.close();
        qDebug() << "Points saved to: " << outputFilePath;
        ui->label_23->setText("Saved successfully");
        point1.x *= 0.40703125;
        point1.y *= 0.3625;
        point2.x *= 0.40703125;
        point2.y *= 0.3625;
        point3.x *= 0.40703125;
        point3.y *= 0.3625;
        point4.x *= 0.40703125;
        point4.y *= 0.3625;

        point1_2.x *= 0.4990234375;
        point1_2.y *= 0.3826979472;
        point2_2.x *= 0.4990234375;
        point2_2.y *= 0.3826979472;
        point3_2.x *= 0.4990234375;
        point3_2.y *= 0.3826979472;
        point4_2.x *= 0.4990234375;
        point4_2.y *= 0.3826979472;
           flag=true;
        // Create a QTimer to hide the message after 3 seconds
        QTimer::singleShot(2000, this, [this]() {
            //ui->label_23->clear();  // Clear the text after 3 seconds
            ui->label_23->setText("Keep Going!");

        });
    } else {
        qDebug() << "Failed to create or open the output file: " << outputFilePath;
    }
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}

void MainWindow::on_pushButton_30_clicked()
{
    try{
        // Toggle the modification state when the button is clicked
        rl = true;
        qDebug() << "modifyPointsOnButtonClick is now: " << rl;

        // Update the perspective transformation
        applyPerspectiveTransformation(originalImage, originalImage2);
        rl = false;
        sss();
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_29_clicked()
{
    try{
        Cl = true;
        qDebug() << "modifyPointsOnButtonClick is now: " << Cl;

        // Update the perspective transformation
        applyPerspectiveTransformation(originalImage, originalImage2);
        Cl = false;
        sss();
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}


void MainWindow::on_pushButton_31_clicked()
{
    try{
       loadPointsFromTextFile(selectedFolderPath);
        //accumulatedRotationAngle = 0.0;
        //rectangle = 0.0;
        calculateCenter(point1, point2, point3, point4, pointC);
        calculateCenter(point1_2, point2_2, point3_2, point4_2, pointC2);
        applyPerspectiveTransformation(originalImage, originalImage2);
        drawImageWithPoints2();  // Add this line to draw points on label_2
        drawImageWithPoints();  // Add this line to draw points on label_2
    }catch (const std::exception &ex) {
        qDebug() << "Exception caught: " << ex.what();
        // You can add further actions in case of an exception, such as showing an error message
    }
}



void MainWindow::on_pushButton_33_clicked()
{
    zoomratio += 0.5;
    zoomingRatioLabel->setText(QString("%1").arg(zoomratio));
    drawImageWithPoints();
}


void MainWindow::on_pushButton_32_clicked()
{

    if(zoomratio <= 1){
        movingratio =1;
        zoomingRatioLabel->setText(QString("%1").arg(zoomratio));
    }
    else
        zoomratio -=0.5;
        zoomingRatioLabel->setText(QString("%1").arg(zoomratio));

drawImageWithPoints();
}


void MainWindow::on_pushButton_34_clicked()
{
    // Check if the window is already open
    if (!controlWindow || controlWindow.isNull()) {
        // If not, create a new instance
        controlWindow = new real(modifiedImage, this);
        controlWindow->setAttribute(Qt::WA_DeleteOnClose); // Optional: Delete window on close
         controlWindow->setFocusPolicy(Qt::NoFocus);
        controlWindow->show();
    } else {
        // If already open, just bring it to front
        //controlWindow->activateWindow();
        controlWindow->updateImage(modifiedImage);
    }

    controlWindow->updateImage(modifiedImage);
}

void MainWindow::on_pushButton_35_clicked()
{
    if (!controlWindowwww || controlWindowwww.isNull()) {
        // If not, create a new instance
        controlWindowwww = new playground(modifiedImage2, this);
        controlWindowwww->setAttribute(Qt::WA_DeleteOnClose); // Optional: Delete window on close
        controlWindowwww->setFocusPolicy(Qt::NoFocus);
        controlWindowwww->show();
    } else {
        // If already open, just bring it to front
        //controlWindow->activateWindow();
        controlWindowwww->updateImageeee(modifiedImage2);
    }

    controlWindowwww->updateImageeee(modifiedImage2);

}


void MainWindow::on_pushButton_36_clicked()
{
    if (!controlWindoww || controlWindoww.isNull()) {
        // If not, create a new instance
        controlWindoww = new realtopred(blendedImage, this);
        controlWindoww->setAttribute(Qt::WA_DeleteOnClose); // Optional: Delete window on close
        controlWindoww->setFocusPolicy(Qt::NoFocus);
        controlWindoww->show();
    } else {
        // If already open, just bring it to front
        //controlWindow->activateWindow();
        controlWindoww->updateImagee(blendedImage);
    }

    controlWindoww->updateImagee(blendedImage);

}


void MainWindow::on_pushButton_37_clicked()
{
    if (!controlWindowww || controlWindowww.isNull()) {
        // If not, create a new instance
        controlWindowww = new predtoreal(blendedImage2, this);
        controlWindowww->setAttribute(Qt::WA_DeleteOnClose); // Optional: Delete window on close
        controlWindowww->setFocusPolicy(Qt::NoFocus);
        controlWindowww->show();
    } else {
        // If already open, just bring it to front
        //controlWindow->activateWindow();
        controlWindowww->updateImageee(blendedImage2);
    }

    controlWindowww->updateImageee(blendedImage2);

    /*

    std::pair<double, double> ioa_iou = calculate_ioa_iou(mask1, mask2);
    double ioa = ioa_iou.first;
    double iou = ioa_iou.second;

    qDebug() << "IOA: " << ioa;
    qDebug() << "IOU: " << iou;
*/
    //calculate_iou(mask1/255,mask2/255);
    /*
    cv::Mat mask1_resized, mask2_resized;
    cv::resize(mask1, mask1_resized, mask2.size());
    cv::resize(mask2, mask2_resized, mask1.size());

   cv::threshold(mask1, mask1, 128, 255, cv::THRESH_BINARY);
    cv::threshold(mask2, mask2, 128, 255, cv::THRESH_BINARY);


    double ioaa = calculate_ioa(mask1,mask2);
    //double iou = ioa_iou.second;

    qDebug() << "IOA: " << ioaa;
    //qDebug() << "IOU: " << iou;
*/

   // cv::Mat mask1_resized, mask2_resized;
  //  cv::resize(mask2, mask2, mask1.size());
   // cv::resize(mask2, mask2_resized, mask1.size());

//cv::threshold(mask1, mask1, 128, 255, cv::THRESH_BINARY);

    // Calculate IOA

}

