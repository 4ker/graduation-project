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

//���д��������
class ProcessorManager : public QObject
{
    Q_OBJECT

public:
    ProcessorManager(PathManager* pathManager);
    ~ProcessorManager();

    void setMaxProcessor(int n); //��������н�����Ŀ

    //��������
    void beginStep(int step); //��������
    void stopStep(int step);  //ֹͣ����

    //�������
    void beginProcess();    //��������
    void pauseProcess();    //��ͣ����
    void stopProcess();     //ֹͣ����

    QString getStepParam(int step);  //��ȡ�������
    QString getResultPath(int step); //��ȡ���·��
    bool getStepFinish(int step);    //��ȡ�����Ƿ����

    void setStepPriority(QThread::Priority priority, int step); //�������ȼ�
    void setStepParamAll();  //���������������
    void setStepParam(QString param, int step);//���õ����������

public slots:
    void progressUpdate_slot(int n);
    void processFinish_slot();
    void errorMsg_slot(QString msg);

signals:
    //����
    void progressUpdate(int data, int step);
    void processFinish(int step);
    void errorMsg(QString msg, int step);

    //����
    void progressUpdateAll(int n);
    void processFinishALL();

private:
    PathManager* pathManager;           //·��������ָ��
    StepProcessor* stepProcessor;       //���账����
    int maxProcessor;                   //����н�����
    QString stepParam[MAX_STEP];        //�������
    int progressAll;                    //�������н���
    int currentRunStep;                 //��ǰ���еĲ���
    QThread::Priority priority[MAX_STEP];   //�������ȼ�
    QString resultPath[MAX_STEP];           //����ļ�·��
    bool stepFinish[MAX_STEP];              //����������ɱ�־
};

#endif // PROCESSORMANAGER_H
