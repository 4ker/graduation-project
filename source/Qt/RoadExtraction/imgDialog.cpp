#include "imgDialog.h"
#include "ui_imgdialog.h"

ImgDialog::ImgDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImgDialog)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(tr("image/RoadExtraction.ico")));
    this->setWindowFlags(Qt::Dialog | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    this->path = path;
    this->ui->label_pixmap->installEventFilter(this);
}

ImgDialog::~ImgDialog()
{
    delete ui;
}


void ImgDialog::on_horizontalSlider_valueChanged(int value)
{
    if(value%5) return;
    this->dispRate = value;
    this->ui->spinBox->setValue(value);
    if(!this->pix.isNull())
    {
        QSize size(width*dispRate/100, height*dispRate/100);
        this->ui->label_pixmap->setPixmap(this->pix.scaled(size, Qt::KeepAspectRatio));
    }
}

void ImgDialog::on_spinBox_valueChanged(int arg1)
{
    if(arg1%5) return;
    this->dispRate = arg1;
    this->ui->horizontalSlider->setValue(arg1);
    if(!this->pix.isNull())
    {
        QSize size(width*dispRate/100, height*dispRate/100);
        this->ui->label_pixmap->setPixmap(this->pix.scaled(size, Qt::KeepAspectRatio));
    }
}

void ImgDialog::on_pushButton_original_clicked()
{
    this->ui->horizontalSlider->setValue(100);
}

void ImgDialog::on_pushButton_fit_clicked()
{
    if(this->pix.isNull())
    {
        return;
    }
    this->dispRate = this->getFitDispRate();
    this->ui->horizontalSlider->setValue(this->dispRate);
    this->ui->spinBox->setValue(this->dispRate);
    QSize size(width*dispRate/100, height*dispRate/100);
    this->ui->label_pixmap->setPixmap(this->pix.scaled(size, Qt::KeepAspectRatio));
    this->setGeometry(this->geometry().x(),this->geometry().y(),
                      this->ui->label_pixmap->pixmap()->width() + 42,
                      this->ui->label_pixmap->pixmap()->height() + 76);
    this->update();
}

int ImgDialog::getFitDispRate()
{
    if(this->pix.isNull())
    {
        return 100;
    }

    int dialogW = this->ui->scrollArea->geometry().width();
    int dialogH = this->ui->scrollArea->geometry().height();
    if(dialogW > this->width && dialogH > this->height)
    {
        return 100;
    }
    else
    {
        int ans = (int)(MIN(dialogW/(double)width, dialogH/(double)height)*100);
        return ans - ans%5;
    }
}

void ImgDialog::on_label_pixmap_customContextMenuRequested(const QPoint &pos)
{
    QMenu *popMenu = new QMenu(this);
    popMenu->addAction(ui->action_Open);
    popMenu->addAction(ui->action_save);
    popMenu->addSeparator();
    popMenu->addAction(ui->action_fit);
    popMenu->addAction(ui->action_original);
    popMenu->exec(QCursor::pos());
}

void ImgDialog::on_action_Open_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("打开图片文件"),
                path.isEmpty()?QDir::currentPath():path,
                tr("所有支持的文件(*.dat *.bmp *.jpg *.jpeg *.gif *.png);;图片数据文件(*.dat);;图片文件(*.bmp *.jpg *.jpeg *.gif *.png);;所有文件(*.*)"));
    if (!fileName.isEmpty())
    {
        fileName = QDir::toNativeSeparators(fileName);
        this->openImage(fileName);
    }
}
void ImgDialog::openImage(QString imgPath)
{
    this->path = imgPath;
    QFileInfo info(this->path);
    if(!info.exists())
    {
        return;
    }
    if("dat" != info.suffix())
    {
        this->pix.load(path);
        if(pix.isNull())
        {
            QMessageBox::information(this, tr("错误"), tr("打开图片文件失败!"));
            this->setWindowTitle(tr("查看图片"));
            this->ui->label_size->setText("");
            return;
        }
        this->width = pix.width();
        this->height = pix.height();
    }
    else //读取.dat图片数据
    {
        if(!readDataFile(path))
        {
            QMessageBox::information(this, tr("错误"), tr("读取图片数据文件失败!"));
            this->setWindowTitle(tr("查看图片"));
            this->ui->label_size->setText("");
            return;
        }
        this->width = pix.width();
        this->height = pix.height();
    }

    this->setWindowTitle(tr("查看图片: ")+this->path);
    this->ui->label_size->setText(tr("尺寸: ")+QString::number(width)+" * "+QString::number(height));
    this->showNormal();
    this->on_pushButton_fit_clicked();
}

void ImgDialog::on_action_save_triggered()
{
    if(this->pix.isNull())
    {
        return;
    }
    QString fileName = QFileDialog::getSaveFileName(
                this,
                tr("图片另存为..."),
                path.isEmpty()?QDir::currentPath():path,
                tr("图片文件(*.bmp *.jpg *.jpeg *.gif *.png);;所有文件(*.*)"));
    if (!fileName.isEmpty())
    {
        fileName = QDir::toNativeSeparators(fileName);
        if(!this->pix.save(fileName))
        {
            QMessageBox::information(this, tr("错误"), tr("保存图片失败!"));
        }
    }
}

void ImgDialog::on_action_fit_triggered()
{
    this->on_pushButton_fit_clicked();
}

void ImgDialog::on_action_original_triggered()
{
    this->on_pushButton_original_clicked();
}

bool ImgDialog::readDataFile(QString filePath)
{
    FILE* file = NULL;
    fopen_s(&file, filePath.toLatin1().data(), "rb");
    if (NULL == file)
    {
        return false;
    }
    char mark[5] = {'\0'};
    unsigned imgW;
    unsigned imgH;
    fread(mark, sizeof(char), 4, file);
    if(0 == strcmp(mark, "ImgB") || 0 == strcmp(mark, "ImgA"))
    {
        fread(&imgW, sizeof(unsigned), 1, file);
        fread(&imgH, sizeof(unsigned), 1, file);
    }
    else if((((0 == strcmp(mark, "ImgC") || 0 == strcmp(mark, "ImgE")) ||
              (0 == strcmp(mark, "ImgD") || 0 == strcmp(mark, "ImgL")))) ||
               0 == strcmp(mark, "ImgS"))
    {
        fseek(file, sizeof(unsigned), SEEK_CUR);
        fread(&imgW, sizeof(unsigned), 1, file);
        fread(&imgH, sizeof(unsigned), 1, file);
        fseek(file, 40, SEEK_SET); //跳到数据开始处
    }
    else
    {
        fclose(file);
        return false;
    }

    imgW = (int)imgW;
    imgH = (int)imgH;
    if(imgW <= 0 || imgH <= 0)
    {
        fclose(file);
        return false;
    }
    //读取图像数据
    uchar *data = new uchar[imgW*imgH]();
    fread(data, sizeof(uchar), imgW*imgH, file);
    QImage image((const uchar*)data, imgW, imgH, sizeof(uchar)*imgW, QImage::Format_Indexed8);
    QVector<QRgb> colorTable;    //灰度调色板
    for(int k = 0; k < 256; k++)
    {
        colorTable.push_back(qRgb(k, k, k));
    }
    QVector<QRgb> colorBW;       //二值调色板
    colorBW.push_back(qRgb(0, 0, 0));
    colorBW.push_back(qRgb(255, 255, 255));
    QVector<QRgb> colorDire;     //方向图调色板
    colorDire.push_back(qRgb(0, 0, 0));
    colorDire.push_back(qRgb(255, 255, 255));
    colorDire.push_back(qRgb(255, 0, 0));
    colorDire.push_back(qRgb(0, 255, 0));
    colorDire.push_back(qRgb(0, 0, 255));
    if(0 == strcmp(mark, "ImgB") || 0 == strcmp(mark, "ImgC"))
    {
        image.setColorTable(colorTable);
    }
    else if(0 == strcmp(mark, "ImgD"))
    {
        image.setColorTable(colorDire);
    }
    else
    {
        image.setColorTable(colorBW);
    }
    this->pix = QPixmap::fromImage(image);
    delete []data;
    fclose(file);
    return true;
}

void ImgDialog::closeEvent(QCloseEvent *event)
{
    this->hide();
}


bool ImgDialog::eventFilter(QObject * target, QEvent * event)
{
    if(this->ui->label_pixmap == target)
    {
        if(event->type() == QEvent::Wheel)
        {
            QWheelEvent *wEvent = (QWheelEvent*)event;
            int numDegrees = wEvent->delta() / 8;
            int numSteps = numDegrees / 10;

            if (wEvent->orientation() == Qt::Vertical)
            {
                this->ui->horizontalSlider->setValue(this->ui->horizontalSlider->value()+numSteps);
                return true;
            }
        }
    }
    return false;
}

void ImgDialog::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragPosition = QPoint(-1, -1);
        event->accept();
    }
}

void ImgDialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void ImgDialog::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() &Qt::LeftButton)
    {
        if (dragPosition != QPoint(-1, -1))
            move(event->globalPos() - dragPosition);
        event->accept();
    }
}
