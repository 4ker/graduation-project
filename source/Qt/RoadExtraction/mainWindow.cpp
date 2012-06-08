#include "mainWindow.h"
#include "ui_mainwindow.h"
#include <qfiledialog.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(tr("image/RoadExtraction.ico")));

    this->ui->tabWidget->setCurrentIndex(0);

    pathManager = new PathManager();
    logsManager = new LogsManager(this->ui->treeWidget_logs);
    imgDialog = new ImgDialog();
    proManager = new ProcessorManager(this->pathManager);

    pathChecked = false;
    queueInitated = false;
    queueStart = false;

    connect(this->proManager, SIGNAL(errorMsg(QString,int)), this, SLOT(handleStepError(QString,int)));
    connect(this->proManager, SIGNAL(progressUpdate(int,int)), this, SLOT(handleProgress(int,int)));
    connect(this->proManager, SIGNAL(processFinish(int)), this, SLOT(handleStepFinish(int)));
    connect(this->proManager, SIGNAL(progressUpdateAll(int)), this, SLOT(handleProgressAll(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pathManager;
    delete logsManager;
    delete proManager;
    if(NULL != imgDialog)
    {
        delete imgDialog;
    }
}

void MainWindow::updatePath(bool way)
{
    if(way)  //控件->变量
    {
        pathManager->setInputPath(ui->lineEdit_inputPath->text());
        pathManager->setWorkDir(ui->lineEdit_workDir->text());
        pathManager->setOutputDir(ui->lineEdit_outputDir->text());
        pathManager->setStepPath(ui->lineEdit_subPath1->text(), 1);
        pathManager->setStepPath(ui->lineEdit_subPath2->text(), 2);
        pathManager->setStepPath(ui->lineEdit_subPath3->text(), 3);
        pathManager->setStepPath(ui->lineEdit_subPath4->text(), 4);
        pathManager->setStepPath(ui->lineEdit_subPath5->text(), 5);
        pathManager->setStepPath(ui->lineEdit_subPath6->text(), 6);
        pathManager->setStepPath(ui->lineEdit_subPath7->text(), 7);
    }
    else     //变量->控件
    {
        ui->lineEdit_inputPath->setText(pathManager->getInputPath());
        ui->lineEdit_workDir->setText(pathManager->getWorkDir());
        ui->lineEdit_outputDir->setText(pathManager->getOutputDir());
        ui->lineEdit_subPath1->setText(pathManager->getStepPath(1));
        ui->lineEdit_subPath2->setText(pathManager->getStepPath(2));
        ui->lineEdit_subPath3->setText(pathManager->getStepPath(3));
        ui->lineEdit_subPath4->setText(pathManager->getStepPath(4));
        ui->lineEdit_subPath5->setText(pathManager->getStepPath(5));
        ui->lineEdit_subPath6->setText(pathManager->getStepPath(6));
        ui->lineEdit_subPath7->setText(pathManager->getStepPath(7));
    }
}

void MainWindow::on_pushButton_inputPath_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("选择要处理的SAR图像文件"),
                ui->lineEdit_inputPath->text().isEmpty()?QDir::currentPath():ui->lineEdit_inputPath->text(),
                tr("SAR图像文件(*.bmp *.jpg);;所有文件(*.*)"));
    if (!fileName.isEmpty())
    {
        fileName = QDir::toNativeSeparators(fileName);
        pathManager->setInputPath(fileName);
        ui->lineEdit_inputPath->setText(fileName);
    }

}

void MainWindow::on_pushButton_workDir_clicked()
{
    QString workDir = QFileDialog::getExistingDirectory(
                this,
                tr("选择工作目录"),
                ui->lineEdit_workDir->text().isEmpty()?QDir::currentPath():ui->lineEdit_workDir->text(),
                QFileDialog::ShowDirsOnly);
    if (!workDir.isEmpty())
    {
        workDir = QDir::toNativeSeparators(workDir);
        pathManager->setWorkDir(workDir);
        ui->lineEdit_workDir->setText(workDir);
    }
}

void MainWindow::on_pushButton_outputDir_clicked()
{
    QString outputDir = QFileDialog::getExistingDirectory(
                this,
                tr("选择输出目录"),
                ui->lineEdit_outputDir->text().isEmpty()?QDir::currentPath():ui->lineEdit_outputDir->text(),
                QFileDialog::ShowDirsOnly);
    if (!outputDir.isEmpty())
    {
        outputDir = QDir::toNativeSeparators(outputDir);
        pathManager->setOutputDir(outputDir);
        ui->lineEdit_outputDir->setText(outputDir);
    }
}

void MainWindow::on_pushButton_subPath1_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("选择执行步骤1的程序文件"),
                ui->lineEdit_subPath1->text().isEmpty()?QDir::currentPath():ui->lineEdit_subPath1->text(),
                tr("可执行文件(*.exe);;所有文件(*.*)"));
    if (!fileName.isEmpty())
    {
        fileName = QDir::toNativeSeparators(fileName);
        pathManager->setStepPath(fileName, 1);
        ui->lineEdit_subPath1->setText(fileName);
    }
}

void MainWindow::on_pushButton_subPath2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("选择执行步骤2的程序文件"),
                ui->lineEdit_subPath2->text().isEmpty()?QDir::currentPath():ui->lineEdit_subPath2->text(),
                tr("可执行文件(*.exe);;所有文件(*.*)"));
    if (!fileName.isEmpty())
    {
        fileName = QDir::toNativeSeparators(fileName);
        pathManager->setStepPath(fileName, 2);
        ui->lineEdit_subPath2->setText(fileName);
    }
}

void MainWindow::on_pushButton_subPath3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("选择执行步骤3的程序文件"),
                ui->lineEdit_subPath3->text().isEmpty()?QDir::currentPath():ui->lineEdit_subPath3->text(),
                tr("可执行文件(*.exe);;所有文件(*.*)"));
    if (!fileName.isEmpty())
    {
        fileName = QDir::toNativeSeparators(fileName);
        pathManager->setStepPath(fileName, 3);
        ui->lineEdit_subPath3->setText(fileName);
    }
}

void MainWindow::on_pushButton_subPath4_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("选择执行步骤4的程序文件"),
                ui->lineEdit_subPath4->text().isEmpty()?QDir::currentPath():ui->lineEdit_subPath4->text(),
                tr("可执行文件(*.exe);;所有文件(*.*)"));
    if (!fileName.isEmpty())
    {
        fileName = QDir::toNativeSeparators(fileName);
        pathManager->setStepPath(fileName, 4);
        ui->lineEdit_subPath4->setText(fileName);
    }
}

void MainWindow::on_pushButton_subPath5_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("选择执行步骤5的程序文件"),
                ui->lineEdit_subPath5->text().isEmpty()?QDir::currentPath():ui->lineEdit_subPath5->text(),
                tr("可执行文件(*.exe);;所有文件(*.*)"));
    if (!fileName.isEmpty())
    {
        fileName = QDir::toNativeSeparators(fileName);
        pathManager->setStepPath(fileName, 5);
        ui->lineEdit_subPath5->setText(fileName);
    }
}

void MainWindow::on_pushButton_subPath6_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("选择执行步骤6的程序文件"),
                ui->lineEdit_subPath6->text().isEmpty()?QDir::currentPath():ui->lineEdit_subPath6->text(),
                tr("可执行文件(*.exe);;所有文件(*.*)"));
    if (!fileName.isEmpty())
    {
        fileName = QDir::toNativeSeparators(fileName);
        pathManager->setStepPath(fileName, 6);
        ui->lineEdit_subPath6->setText(fileName);
    }
}

void MainWindow::on_pushButton_subPath7_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("选择执行步骤7的程序文件"),
                ui->lineEdit_subPath7->text().isEmpty()?QDir::currentPath():ui->lineEdit_subPath7->text(),
                tr("可执行文件(*.exe);;所有文件(*.*)"));
    if (!fileName.isEmpty())
    {
        fileName = QDir::toNativeSeparators(fileName);
        pathManager->setStepPath(fileName, 7);
        ui->lineEdit_subPath7->setText(fileName);
    }
}

void MainWindow::on_pushButton_resetAll_clicked()
{
    pathManager->resetAll();
    this->updatePath(false);
}

void MainWindow::on_pushButton_loadSettings_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("加载路径配置文件"),
                QDir::currentPath(),
                tr("配置文件(*.ini);;所有文件(*.*)"));
    if (!fileName.isEmpty())
    {
        fileName = QDir::toNativeSeparators(fileName);
        pathManager->loadPathCfg(fileName);
        this->updatePath(false);
        this->logsManager->updatePathItem(this->pathManager);
    }
}

void MainWindow::on_pushButton_saveSettings_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(
                this,
                tr("保存路径配置到文件"),
                QDir::currentPath(),
                tr("配置文件(*.ini);;所有文件(*.*)"));
    if (!fileName.isEmpty())
    {
        fileName = QDir::toNativeSeparators(fileName);
        this->updatePath(true);
        pathManager->savePathCfg(fileName);
    }
}

void MainWindow::on_lineEdit_inputPath_textChanged(const QString &arg1)
{
    QFileInfo info(arg1);
    QPalette pal = ui->lineEdit_inputPath->palette();
    pal.setColor(QPalette::Text, info.exists()?QColor(0,0,0):QColor(255,0,0));
    ui->lineEdit_inputPath->setPalette(pal);
}

void MainWindow::on_lineEdit_subPath1_textChanged(const QString &arg1)
{
    QFileInfo info(arg1);
    QPalette pal = ui->lineEdit_subPath1->palette();
    pal.setColor(QPalette::Text, info.exists()?QColor(0,0,0):QColor(255,0,0));
    ui->lineEdit_subPath1->setPalette(pal);
}

void MainWindow::on_lineEdit_subPath2_textChanged(const QString &arg1)
{
    QFileInfo info(arg1);
    QPalette pal = ui->lineEdit_subPath2->palette();
    pal.setColor(QPalette::Text, info.exists()?QColor(0,0,0):QColor(255,0,0));
    ui->lineEdit_subPath2->setPalette(pal);
}

void MainWindow::on_lineEdit_subPath3_textChanged(const QString &arg1)
{
    QFileInfo info(arg1);
    QPalette pal = ui->lineEdit_subPath3->palette();
    pal.setColor(QPalette::Text, info.exists()?QColor(0,0,0):QColor(255,0,0));
    ui->lineEdit_subPath3->setPalette(pal);
}

void MainWindow::on_lineEdit_subPath4_textChanged(const QString &arg1)
{
    QFileInfo info(arg1);
    QPalette pal = ui->lineEdit_subPath4->palette();
    pal.setColor(QPalette::Text, info.exists()?QColor(0,0,0):QColor(255,0,0));
    ui->lineEdit_subPath4->setPalette(pal);
}

void MainWindow::on_lineEdit_subPath5_textChanged(const QString &arg1)
{
    QFileInfo info(arg1);
    QPalette pal = ui->lineEdit_subPath5->palette();
    pal.setColor(QPalette::Text, info.exists()?QColor(0,0,0):QColor(255,0,0));
    ui->lineEdit_subPath5->setPalette(pal);
}

void MainWindow::on_lineEdit_subPath6_textChanged(const QString &arg1)
{
    QFileInfo info(arg1);
    QPalette pal = ui->lineEdit_subPath6->palette();
    pal.setColor(QPalette::Text, info.exists()?QColor(0,0,0):QColor(255,0,0));
    ui->lineEdit_subPath6->setPalette(pal);
}

void MainWindow::on_lineEdit_subPath7_textChanged(const QString &arg1)
{
    QFileInfo info(arg1);
    QPalette pal = ui->lineEdit_subPath7->palette();
    pal.setColor(QPalette::Text, info.exists()?QColor(0,0,0):QColor(255,0,0));
    ui->lineEdit_subPath7->setPalette(pal);
}

void MainWindow::on_pushButton_saveLogs_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(
                this,
                tr("保存日志到文件"),
                QDir::currentPath(),
                tr("文本文件(*.txt);;所有文件(*.*)"));
    if (!fileName.isEmpty())
    {
        fileName = QDir::toNativeSeparators(fileName);
        if(!this->logsManager->saveLogs(fileName))
        {
            QMessageBox::information(this, tr("错误"), tr("保存日志失败!"));
            return;
        }
    }
}

void MainWindow::on_action_imgView_triggered()
{
    this->imgDialog->showNormal();
    this->imgDialog->setFocus();
}

void MainWindow::on_spinBox_maxProcessNum_valueChanged(int arg1)
{
    this->proManager->setMaxProcessor(arg1);
}

void MainWindow::on_pushButton_queueInit_clicked()  //队列初始化
{
    //初始化步骤参数
    this->proManager->setStepParamAll();
    //step1
    if(this->ui->lineEdit_paramStep1->text().isEmpty())
    {
        this->ui->lineEdit_paramStep1->setText(this->proManager->getStepParam(1));
    }
    else
    {
        this->proManager->setStepParam(this->ui->lineEdit_paramStep1->text(), 1);
    }
    //step2
    if(this->ui->lineEdit_paramStep2->text().isEmpty())
    {
        this->ui->lineEdit_paramStep2->setText(this->proManager->getStepParam(2));
    }
    else
    {
        this->proManager->setStepParam(this->ui->lineEdit_paramStep2->text(), 2);
    }
    //step3
    if(this->ui->lineEdit_paramStep3->text().isEmpty())
    {
        this->ui->lineEdit_paramStep3->setText(this->proManager->getStepParam(3));
    }
    else
    {
        this->proManager->setStepParam(this->ui->lineEdit_paramStep3->text(), 3);
    }
    //step4
    if(this->ui->lineEdit_paramStep4->text().isEmpty())
    {
        this->ui->lineEdit_paramStep4->setText(this->proManager->getStepParam(4));
    }
    else
    {
        this->proManager->setStepParam(this->ui->lineEdit_paramStep4->text(), 4);
    }
    //step5
    if(this->ui->lineEdit_paramStep5->text().isEmpty())
    {
        this->ui->lineEdit_paramStep5->setText(this->proManager->getStepParam(5));
    }
    else
    {
        this->proManager->setStepParam(this->ui->lineEdit_paramStep5->text(), 5);
    }
    //step6
    if(this->ui->lineEdit_paramStep6->text().isEmpty())
    {
        this->ui->lineEdit_paramStep6->setText(this->proManager->getStepParam(6));
    }
    else
    {
        this->proManager->setStepParam(this->ui->lineEdit_paramStep6->text(), 6);
    }
    //step7
    if(this->ui->lineEdit_paramStep7->text().isEmpty())
    {
        this->ui->lineEdit_paramStep7->setText(this->proManager->getStepParam(7));
    }
    else
    {
        this->proManager->setStepParam(this->ui->lineEdit_paramStep7->text(), 7);
    }

    this->update();
    this->queueInitated = true;
}

void MainWindow::on_pushButton_step1_clicked() //step 1运行/停止
{
    if(this->ui->pushButton_step1->isChecked())  //运行
    {
        this->logsManager->addQueueMsg(tr("步骤1: 开始运行... 参数: ") + this->proManager->getStepParam(1));
        this->proManager->setStepPriority((QThread::Priority)(this->ui->comboBox_priorityStep1->currentIndex()+1), 1);
        this->proManager->beginStep(1);
    }
    else  //停止
    {
        this->proManager->stopStep(1);
    }
}


void MainWindow::on_pushButton_step2_clicked()
{
    if(this->ui->pushButton_step2->isChecked())  //运行
    {
        this->logsManager->addQueueMsg(tr("步骤2: 开始运行... 参数: ") + this->proManager->getStepParam(2));
        this->proManager->setStepPriority((QThread::Priority)(this->ui->comboBox_priorityStep2->currentIndex()+1), 2);
        this->proManager->beginStep(2);
    }
    else  //停止
    {
        this->proManager->stopStep(2);
    }
}

void MainWindow::on_pushButton_step3_clicked()
{
    if(this->ui->pushButton_step3->isChecked())  //运行
    {
        this->logsManager->addQueueMsg(tr("步骤3: 开始运行... 参数: ") + this->proManager->getStepParam(3));
        this->proManager->setStepPriority((QThread::Priority)(this->ui->comboBox_priorityStep3->currentIndex()+1), 3);
        this->proManager->beginStep(3);
    }
    else  //停止
    {
        this->proManager->stopStep(3);
    }
}

void MainWindow::on_pushButton_step4_clicked()
{
    if(this->ui->pushButton_step4->isChecked())  //运行
    {
        this->logsManager->addQueueMsg(tr("步骤4: 开始运行... 参数: ") + this->proManager->getStepParam(4));
        this->proManager->setStepPriority((QThread::Priority)(this->ui->comboBox_priorityStep4->currentIndex()+1), 4);
        this->proManager->beginStep(4);
    }
    else  //停止
    {
        this->proManager->stopStep(4);
    }
}

void MainWindow::on_pushButton_step5_clicked()
{
    if(this->ui->pushButton_step5->isChecked())  //运行
    {
        this->logsManager->addQueueMsg(tr("步骤5: 开始运行... 参数: ") + this->proManager->getStepParam(5));
        this->proManager->setStepPriority((QThread::Priority)(this->ui->comboBox_priorityStep5->currentIndex()+1), 5);
        this->proManager->beginStep(5);
    }
    else  //停止
    {
        this->proManager->stopStep(5);
    }
}

void MainWindow::on_pushButton_step6_clicked()
{
    if(this->ui->pushButton_step6->isChecked())  //运行
    {
        this->logsManager->addQueueMsg(tr("步骤6: 开始运行... 参数: ") + this->proManager->getStepParam(6));
        this->proManager->setStepPriority((QThread::Priority)(this->ui->comboBox_priorityStep6->currentIndex()+1), 6);
        this->proManager->beginStep(6);
    }
    else  //停止
    {
        this->proManager->stopStep(6);
    }
}

void MainWindow::on_pushButton_step7_clicked()
{
    if(this->ui->pushButton_step7->isChecked())  //运行
    {
        this->logsManager->addQueueMsg(tr("步骤7: 开始运行... 参数: ") + this->proManager->getStepParam(7));
        this->proManager->setStepPriority((QThread::Priority)(this->ui->comboBox_priorityStep7->currentIndex()+1), 7);
        this->proManager->beginStep(7);
    }
    else  //停止
    {
        this->proManager->stopStep(7);
    }
}

void MainWindow::handleStepError(QString str, int step)
{
    QMessageBox::information(this, tr("步骤")+QString::number(step)+tr(": 进程运行错误! "), str);
}

void MainWindow::handleProgress(int n, int step)
{
    switch(step)
    {
    case 1: this->ui->progressBar_step1->setValue(n); break;
    case 2: this->ui->progressBar_step2->setValue(n); break;
    case 3: this->ui->progressBar_step3->setValue(n); break;
    case 4: this->ui->progressBar_step4->setValue(n); break;
    case 5: this->ui->progressBar_step5->setValue(n); break;
    case 6: this->ui->progressBar_step6->setValue(n); break;
    case 7: this->ui->progressBar_step7->setValue(n); break;
    }
}

void MainWindow::handleStepFinish(int step)
{
    switch(step)
    {
    case 1: this->ui->progressBar_step1->setValue(100);
        this->ui->pushButton_step1->setChecked(false);
        this->logsManager->addQueueMsg(tr("步骤1: 处理完成!"));
        if(queueStart)
        {
            if(this->proManager->getStepFinish(1))
            {
                this->ui->pushButton_step2->setChecked(true);
                this->on_pushButton_step2_clicked();
            }
        }
        break;
    case 2: this->ui->progressBar_step2->setValue(100);
        this->ui->pushButton_step2->setChecked(false);
        this->logsManager->addQueueMsg(tr("步骤2: 处理完成!"));
        if(queueStart)
        {
            if(this->proManager->getStepFinish(2))
            {
                this->ui->pushButton_step3->setChecked(true);
                this->on_pushButton_step3_clicked();
            }
        }

        break;
    case 3: this->ui->progressBar_step3->setValue(100);
        this->ui->pushButton_step3->setChecked(false);
        this->logsManager->addQueueMsg(tr("步骤3: 处理完成!"));
        if(queueStart)
        {
            if(this->proManager->getStepFinish(3))
            {
                this->ui->pushButton_step4->setChecked(true);
                this->on_pushButton_step4_clicked();
            }
        }

        break;
    case 4: this->ui->progressBar_step4->setValue(100);
        this->ui->pushButton_step4->setChecked(false);
        this->logsManager->addQueueMsg(tr("步骤4: 处理完成!"));
        if(queueStart)
        {
            if(this->proManager->getStepFinish(4))
            {
                this->ui->scrollArea_queue->verticalScrollBar()->setSliderPosition(
                            this->ui->scrollArea_queue->verticalScrollBar()->maximum());
                this->ui->pushButton_step5->setChecked(true);
                this->on_pushButton_step5_clicked();
            }
        }

        break;
    case 5: this->ui->progressBar_step5->setValue(100);
        this->ui->pushButton_step5->setChecked(false);
        this->logsManager->addQueueMsg(tr("步骤5: 处理完成!"));
        if(queueStart)
        {
            if(this->proManager->getStepFinish(5))
            {
                this->ui->pushButton_step6->setChecked(true);
                this->on_pushButton_step6_clicked();
            }
        }

        break;
    case 6: this->ui->progressBar_step6->setValue(100);
        this->ui->pushButton_step6->setChecked(false);
        this->logsManager->addQueueMsg(tr("步骤6: 处理完成!"));
        if(queueStart)
        {
            if(this->proManager->getStepFinish(6))
            {
                this->ui->pushButton_step7->setChecked(true);
                this->on_pushButton_step7_clicked();
            }
        }

        break;
    case 7: this->ui->progressBar_step7->setValue(100);
        this->ui->pushButton_step7->setChecked(false);
        this->logsManager->addQueueMsg(tr("步骤7: 处理完成!"));
        //全部完成提示
        this->ui->progressBar_all->setValue(100);
        QMessageBox::information(this, tr("提示"), tr("队列处理全部完成!"));
        this->logsManager->addQueueMsg(tr("全部步骤完成!"));
        break;
    }
}

void MainWindow::on_pushButton_viewStep1_clicked()
{
    this->imgDialog->openImage(this->proManager->getResultPath(1));
}

void MainWindow::on_pushButton_viewStep2_clicked()
{
    this->imgDialog->openImage(this->proManager->getResultPath(2));
}

void MainWindow::on_pushButton_viewStep3_clicked()
{
    this->imgDialog->openImage(this->proManager->getResultPath(3));
}

void MainWindow::on_pushButton_viewStep4_clicked()
{
    this->imgDialog->openImage(this->proManager->getResultPath(4));
}

void MainWindow::on_pushButton_viewStep5_clicked()
{
    this->imgDialog->openImage(this->proManager->getResultPath(5));
}

void MainWindow::on_pushButton_viewStep6_clicked()
{
    this->imgDialog->openImage(this->proManager->getResultPath(6));
}

void MainWindow::on_pushButton_viewStep7_clicked()
{
    this->imgDialog->openImage(this->proManager->getResultPath(7));
}

void MainWindow::handleProgressAll(int n)
{
    this->ui->progressBar_all->setValue(n);
}

void MainWindow::on_pushButton_queueStart_clicked()  //全部开始
{
    if(!this->queueInitated)
    {
        QMessageBox::information(this, tr("提示"), tr("队列尚未初始化!"));
        return;
    }
    this->queueStart  = true;
    this->ui->pushButton_step1->setChecked(true);
    on_pushButton_step1_clicked();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragPosition = QPoint(-1, -1);
        event->accept();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() &Qt::LeftButton)
    {
        if (dragPosition != QPoint(-1, -1))
            move(event->globalPos() - dragPosition);
        event->accept();
    }
}

void MainWindow::on_action_loadCfg_triggered()
{
    this->ui->tabWidget->setCurrentIndex(0);
    on_pushButton_loadSettings_clicked();
}

void MainWindow::on_action_saveCfg_triggered()
{
    this->ui->tabWidget->setCurrentIndex(0);
    on_pushButton_saveSettings_clicked();
}

void MainWindow::on_action_quit_triggered()  //退出
{
    this->close();
    //判断队列处理状态
}

void MainWindow::on_action_inputImage_triggered()
{
    this->imgDialog->openImage(this->pathManager->getInputPath());
}

void MainWindow::on_action_workDir_triggered()
{
    QDesktopServices::openUrl(QUrl("file:///"+QDir::fromNativeSeparators(this->pathManager->getWorkDir()), QUrl::TolerantMode));
}

void MainWindow::on_action_outputDir_triggered()
{
    QDesktopServices::openUrl(QUrl("file:///"+QDir::fromNativeSeparators(this->pathManager->getOutputDir()), QUrl::TolerantMode));
}

void MainWindow::on_action_queue_triggered()
{
    this->ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_action_logs_triggered()
{
    this->ui->tabWidget->setCurrentIndex(2);
}
