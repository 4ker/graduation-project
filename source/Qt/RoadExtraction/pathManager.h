#ifndef PATHMANAGER_H
#define PATHMANAGER_H

#include <QObject>
#include <QSettings>
#include <QString>
#include "common.h"

//PathManager 路径配置管理器
class PathManager : public QObject
{
    Q_OBJECT

public:
    PathManager();
    ~PathManager();

public:
    void loadPathCfg(QString path);  //加载配置
    void savePathCfg(QString path);  //保存配置

    void setInputPath(QString path); //设置输入图片路径
    void setWorkDir(QString path);   //设置工作路径
    void setOutputDir(QString path); //设置输出路径
    void setStepPath(QString path, int step);   //设置步骤子程序路径
    void resetAll();                            //重置所有路径

    QString getInputPath();         //获取输入图片路径
    QString getWorkDir();           //获取工作路径
    QString getOutputDir();         //获取输出路径
    QString getStepPath(int step);  //获取步骤子程序路径

private:
    QString inputPath;
    QString workDir;
    QString outputDir;
    QString stepPath[MAX_STEP];
};




#endif // PATHMANAGER_H
