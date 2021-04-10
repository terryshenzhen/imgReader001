#include "widget.h"
#include "ui_widget.h"
#include "widget.h"
#include<QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);



}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButtonStart_clicked()
{

//   int m_nWidth= 200;
//   int m_nHeight =200;
   QSize size(500,500);


    pmfilename = "img/aaa.bmp";
   //pmfilename = "./img/aaa.bmp";


        QFileInfo finfo(pmfilename);

    if(finfo.exists())
    {
        qDebug()<<"exists";
    }

    showBMP_onLabel(pmfilename,size, ui->label_img);

    qDebug()<<"aaa";
}


void Widget::showBMP_onLabel(QString bmpName, QSize Bmpsize, QLabel *disLabel)
{
    imageReader.setFileName(bmpName);


    if (imageReader.canRead())
    {
        //QSize size = resizeImage(imageReader.size(),m_nWidth,m_nHeight);
        imageReader.setScaledSize(Bmpsize);

        QImage image = imageReader.read();


        QPixmap pixmap = QPixmap::fromImage(image.scaled(Bmpsize,Qt::KeepAspectRatio));
        disLabel->setPixmap(pixmap);

    }
}

QSize Widget::resizeImage(const QSize image,int w,int h)
{
    double width,height;

    double setWidth = (double)w;
    double setHeight = (double)h;

    double imageWidth = (double)image.width();
    double imageHeight = (double)image.height();

    if(setWidth/imageWidth<=setHeight/imageHeight){
        width=imageWidth*(setWidth/imageWidth);
        height=imageHeight*(setWidth/imageWidth);
    }else{
        width=imageWidth*(setHeight/imageHeight);
        height=imageHeight*(setHeight/imageHeight);
    }

    return QSize((int)width,(int)height);
}

