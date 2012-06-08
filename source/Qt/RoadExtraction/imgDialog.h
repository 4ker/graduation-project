#ifndef IMGDIALOG_H
#define IMGDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QDir>
#include <QFileInfo>
#include <QPainter>
#include <QPixmap>
#include <QImage>
#include <QMenu>
#include <QMessageBox>
#include <QCloseEvent>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QPoint>
#include "common.h"

namespace Ui {
class ImgDialog;
}

class ImgDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ImgDialog(QWidget *parent = 0);
    ~ImgDialog();

    void openImage(QString imgPath);

private slots:
    void on_horizontalSlider_valueChanged(int value);
    void on_spinBox_valueChanged(int arg1);
    void on_pushButton_original_clicked();
    void on_pushButton_fit_clicked();

    void on_label_pixmap_customContextMenuRequested(const QPoint &pos);
    void on_action_Open_triggered();
    void on_action_save_triggered();
    void on_action_fit_triggered();
    void on_action_original_triggered();

private:
    void closeEvent(QCloseEvent *event);
    bool eventFilter(QObject *target, QEvent *event); //SrcollArea事件过滤器
    int getFitDispRate();
    bool readDataFile(QString filePath);

    //窗口拖动
    void mouseMoveEvent(QMouseEvent*event);
    void mousePressEvent(QMouseEvent*event);
    void mouseReleaseEvent(QMouseEvent*event);
    QPoint dragPosition;

private:
    Ui::ImgDialog *ui;
    QString path;
    QPixmap pix;

    int width;
    int height;
    int dispRate;  //显示比例: dispRate/100
};

#endif // IMGDIALOG_H
