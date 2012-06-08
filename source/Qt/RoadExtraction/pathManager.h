#ifndef PATHMANAGER_H
#define PATHMANAGER_H

#include <QObject>
#include <QSettings>
#include <QString>
#include "common.h"

//PathManager ·�����ù�����
class PathManager : public QObject
{
    Q_OBJECT

public:
    PathManager();
    ~PathManager();

public:
    void loadPathCfg(QString path);  //��������
    void savePathCfg(QString path);  //��������

    void setInputPath(QString path); //��������ͼƬ·��
    void setWorkDir(QString path);   //���ù���·��
    void setOutputDir(QString path); //�������·��
    void setStepPath(QString path, int step);   //���ò����ӳ���·��
    void resetAll();                            //��������·��

    QString getInputPath();         //��ȡ����ͼƬ·��
    QString getWorkDir();           //��ȡ����·��
    QString getOutputDir();         //��ȡ���·��
    QString getStepPath(int step);  //��ȡ�����ӳ���·��

private:
    QString inputPath;
    QString workDir;
    QString outputDir;
    QString stepPath[MAX_STEP];
};




#endif // PATHMANAGER_H
