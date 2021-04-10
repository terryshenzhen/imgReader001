#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include<QImage>
#include<QImageReader>
#include<QFileInfo>
#include<QFile>
#include<QPixmap>
#include<QLabel>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QImage image;
    QImageReader imageReader;//图片读取器
    QString pmfilename;//文件路径


    QSize resizeImage(const QSize image, int w, int h);
    void showBMP_onLabel(QString bmpName, QSize Bmpsize, QLabel *disLabel);

private slots:
    void on_pushButtonStart_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
