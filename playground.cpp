#include "playground.h"
#include "opencv2/core/mat.hpp"
#include "ui_playground.h"

playground::playground(const cv::Mat &image, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::playground)
{
    ui->setupUi(this);
    QImage qimage(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);

    // Set the QImage to the existing QLabel in your UI
    ui->label->setPixmap(QPixmap::fromImage(qimage));

    // Ensure the image resizes with the label
    ui->label->setScaledContents(true);

    // Center-align the image within the label
    ui->label->setAlignment(Qt::AlignCenter);
    initialLabelSize = ui->label->size();

    // Install an event filter to detect resize events
    installEventFilter(this);
}
void playground::updateImageeee(const cv::Mat &image)
{
    QImage qimage(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);

    // Set the new image to the label
    ui->label->setPixmap(QPixmap::fromImage(qimage));

    // Ensure the image resizes with the label
    ui->label->setScaledContents(true);

    // Center-align the image within the label
    ui->label->setAlignment(Qt::AlignCenter);

}
bool playground::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::Resize) {
        // If a resize event occurs, update the label size
        QSize newSize = size();
        int newWidth = qMax(initialLabelSize.width(), newSize.width());
        int newHeight = qMax(initialLabelSize.height(), newSize.height());
        ui->label->resize(newWidth, newHeight);
    }
    return QObject::eventFilter(obj, event);
}

playground::~playground()
{
    delete ui;
}
