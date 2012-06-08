#ifndef LOGSMANAGER_H
#define LOGSMANAGER_H

#include <QObject>
#include <QString>
#include <QTreeWidget>
#include <QDateTime>
#include <QDir>
#include <QSysInfo>
#include <QDesktopWidget>
#include <QApplication>
#include <QHeaderView>
#include <QFileDialog>
#include <QTreeWidgetItemIterator>
#include <QFile>
#include <QIcon>
#include <QTextStream>
#include "pathManager.h"

//日志管理器
class LogsManager : public QObject
{
    Q_OBJECT

public:
    LogsManager(QTreeWidget* tree);
    ~LogsManager();

    void updatePathItem(PathManager* pathManager);  //更新路径配置日志
    void addQueueMsg(QString msg);  //添加队列处理日志

    bool saveLogs(QString path); //保存日志

signals:
    void clearTree();   //清空日志树

private:
    QString getTime();  //获取当前系统时间

private:
    QTreeWidget* tree;
    QTreeWidgetItem *envItem;
};

#endif // LOGSMANAGER_H
