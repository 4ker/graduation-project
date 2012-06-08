#ifndef PROCESSORMANAGER_H
#define PROCESSORMANAGER_H

#include <QObject>
#include <QString>
#include <QFileInfo>
#include <QDir>
#include <QThread>
#include "pathManager.h"
#include "stepProcessor.h"
#include "common.h"

//队列处理管理器
class ProcessorManager : public QObject
{
    Q_OBJECT

public:
    ProcessorManager(PathManager* pathManager);
    ~ProcessorManager();

    void setMaxProcessor(int n); //设置最大并行进程数目

    //单步控制
    void beginStep(int step); //启动进程
    void stopStep(int step);  //停止进程

    //总体控制
    void beginProcess();    //启动队列
    void pauseProcess();    //暂停队列
    void stopProcess();     //停止队列

    QString getStepParam(int step);  //获取命令参数
    QString getResultPath(int step); //获取结果路径
    bool getStepFinish(int step);    //获取进程是否完成

    void setStepPriority(QThread::Priority priority, int step); //设置优先级
    void setStepParamAll();  //配置所有命令参数
    void setStepParam(QString param, int step);//配置单步命令参数

public slots:
    void progressUpdate_slot(int n);
    void processFinish_slot();
    void errorMsg_slot(QString msg);

signals:
    //单步
    void progressUpdate(int data, int step);
    void processFinish(int step);
    void errorMsg(QString msg, int step);

    //总体
    void progressUpdateAll(int n);
    void processFinishALL();

private:
    PathManager* pathManager;           //路径管理器指针
    StepProcessor* stepProcessor;       //步骤处理器
    int maxProcessor;                   //最大并行进程数
    QString stepParam[MAX_STEP];        //命令参数
    int progressAll;                    //总体运行进度
    int currentRunStep;                 //当前运行的步骤
    QThread::Priority priority[MAX_STEP];   //进程优先级
    QString resultPath[MAX_STEP];           //结果文件路径
    bool stepFinish[MAX_STEP];              //步骤运行完成标志
};

#endif // PROCESSORMANAGER_H
