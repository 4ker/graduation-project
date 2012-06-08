#ifndef STEPPROCESSOR_H
#define STEPPROCESSOR_H

#include <QObject>
#include <QString>
#include <QFileInfo>
#include <QProcess>
#include <QThread>
#include <QStringList>

typedef enum {
    NotStarted,
    Starting,  //启动中，尚未invoke程序
    Running,
    Stop,
    Finish
} RunStatus;       //处理器运行状态


//StepProcessor 单个步骤处理器
class StepProcessor : public QObject
{
    Q_OBJECT

public:
    StepProcessor();
    ~StepProcessor();

    void setEnv(QString path, QString result,
                QString param, QThread::Priority prio); //设置进程运行环境

    RunStatus getStatus();  //获取进程状态
    int getProgress();      //获取进程进度
    QString getResultPath();//获取结果路径

    bool startProcess();    //启动进程
    void stopProcess();     //停止进程

public slots:
    void readFromStdOut();  //读取标准输出stdout
    void readFromStdErr();  //读取标准错误stderr
    void processError(QProcess::ProcessError error);        //进程错误
    void processStop(int exitCode,
                     QProcess::ExitStatus exitStatus);      //进程停止
    void statusChanged(QProcess::ProcessState newState);    //进程状态改变

signals:
    void progressUpdate(int data); //进度更新
    void processFinish();          //处理完成
    void errorMsg(QString msg);    //运行错误

private:
    QProcess *myProcess;  //进程指针
    QString programPath;  //程序路径
    QString paramLine;    //程序参数
    RunStatus status;     //运行状态
    int progress;         //处理进度 0-100
    QThread::Priority priority; //进程优先级
    QString resultPath;   //处理结果路径(文件/目录)
};

#endif // STEPPROCESSOR_H
