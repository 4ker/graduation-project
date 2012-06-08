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

//��־������
class LogsManager : public QObject
{
    Q_OBJECT

public:
    LogsManager(QTreeWidget* tree);
    ~LogsManager();

    void updatePathItem(PathManager* pathManager);  //����·��������־
    void addQueueMsg(QString msg);  //��Ӷ��д�����־

    bool saveLogs(QString path); //������־

signals:
    void clearTree();   //�����־��

private:
    QString getTime();  //��ȡ��ǰϵͳʱ��

private:
    QTreeWidget* tree;
    QTreeWidgetItem *envItem;
};

#endif // LOGSMANAGER_H
