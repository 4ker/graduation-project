#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Qpalette>
#include <QFileInfo>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QScrollbar>
#include "pathManager.h"
#include "logsManager.h"
#include "imgDialog.h"
#include "processorManager.h"
#include "common.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void mouseMoveEvent(QMouseEvent*event);
    void mousePressEvent(QMouseEvent*event);
    void mouseReleaseEvent(QMouseEvent*event);
    QPoint dragPosition;

private slots:
    void handleStepError(QString str, int step);
    void handleProgress(int n, int step);
    void handleStepFinish(int step);
    void handleProgressAll(int n);

private slots:
    void on_pushButton_inputPath_clicked();
    void on_pushButton_workDir_clicked();
    void on_pushButton_outputDir_clicked();

    void on_pushButton_subPath1_clicked();
    void on_pushButton_subPath2_clicked();
    void on_pushButton_subPath3_clicked();
    void on_pushButton_subPath4_clicked();
    void on_pushButton_subPath5_clicked();
    void on_pushButton_subPath6_clicked();
    void on_pushButton_subPath7_clicked();

    void on_pushButton_resetAll_clicked();
    void on_pushButton_loadSettings_clicked();
    void on_pushButton_saveSettings_clicked(); 
    void on_lineEdit_inputPath_textChanged(const QString &arg1);

    void on_lineEdit_subPath1_textChanged(const QString &arg1);
    void on_lineEdit_subPath2_textChanged(const QString &arg1);
    void on_lineEdit_subPath3_textChanged(const QString &arg1);
    void on_lineEdit_subPath4_textChanged(const QString &arg1);
    void on_lineEdit_subPath5_textChanged(const QString &arg1);
    void on_lineEdit_subPath6_textChanged(const QString &arg1);
    void on_lineEdit_subPath7_textChanged(const QString &arg1);

    void on_pushButton_saveLogs_clicked();
    void on_action_imgView_triggered();
    void on_spinBox_maxProcessNum_valueChanged(int arg1);
    void on_pushButton_queueInit_clicked();

    void on_pushButton_viewStep1_clicked();
    void on_pushButton_viewStep2_clicked();
    void on_pushButton_viewStep4_clicked();
    void on_pushButton_viewStep3_clicked();
    void on_pushButton_viewStep6_clicked();
    void on_pushButton_viewStep5_clicked();
    void on_pushButton_viewStep7_clicked();

    void on_pushButton_step1_clicked();
    void on_pushButton_step2_clicked();
    void on_pushButton_step3_clicked();
    void on_pushButton_step4_clicked();
    void on_pushButton_step5_clicked();
    void on_pushButton_step6_clicked();
    void on_pushButton_step7_clicked();

    void on_pushButton_queueStart_clicked();
    void on_action_loadCfg_triggered();
    void on_action_saveCfg_triggered();
    void on_action_quit_triggered();

    void on_action_inputImage_triggered();
    void on_action_workDir_triggered();
    void on_action_outputDir_triggered();
    void on_action_queue_triggered();
    void on_action_logs_triggered();

public:
    PathManager* pathManager;  //·�����ù�����
    void updatePath(bool way); //���¿ؼ�(·������ҳ) way==true:�ؼ�->����  way==false:����->�ؼ�
    Ui::MainWindow *ui;
    LogsManager* logsManager;  //��־������
    ImgDialog* imgDialog;      //ͼƬ�鿴��
    ProcessorManager* proManager; //���д��������

    bool pathChecked;         //·�������Ƿ��Ѿ����
    bool queueInitated;       //�����Ƿ��Ѿ���ʼ��
    bool queueStart;          //�Ƿ��Ƕ��л��Զ�����
};

#endif // MAINWINDOW_H
