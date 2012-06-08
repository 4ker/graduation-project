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
    Starting,  //�����У���δinvoke����
    Running,
    Stop,
    Finish
} RunStatus;       //����������״̬


//StepProcessor �������账����
class StepProcessor : public QObject
{
    Q_OBJECT

public:
    StepProcessor();
    ~StepProcessor();

    void setEnv(QString path, QString result,
                QString param, QThread::Priority prio); //���ý������л���

    RunStatus getStatus();  //��ȡ����״̬
    int getProgress();      //��ȡ���̽���
    QString getResultPath();//��ȡ���·��

    bool startProcess();    //��������
    void stopProcess();     //ֹͣ����

public slots:
    void readFromStdOut();  //��ȡ��׼���stdout
    void readFromStdErr();  //��ȡ��׼����stderr
    void processError(QProcess::ProcessError error);        //���̴���
    void processStop(int exitCode,
                     QProcess::ExitStatus exitStatus);      //����ֹͣ
    void statusChanged(QProcess::ProcessState newState);    //����״̬�ı�

signals:
    void progressUpdate(int data); //���ȸ���
    void processFinish();          //�������
    void errorMsg(QString msg);    //���д���

private:
    QProcess *myProcess;  //����ָ��
    QString programPath;  //����·��
    QString paramLine;    //�������
    RunStatus status;     //����״̬
    int progress;         //������� 0-100
    QThread::Priority priority; //�������ȼ�
    QString resultPath;   //������·��(�ļ�/Ŀ¼)
};

#endif // STEPPROCESSOR_H
