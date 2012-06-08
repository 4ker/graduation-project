#include "logsManager.h"

LogsManager::LogsManager(QTreeWidget *tree)
{
    this->tree = tree;
    connect(this, SIGNAL(clearTree()), this->tree, SLOT(clear()));
    emit clearTree();

    this->tree->setColumnCount(1);
    QHeaderView *pHeader = this->tree->header();
    pHeader->setResizeMode( QHeaderView::ResizeToContents );
    pHeader->setStretchLastSection( false );

    this->envItem = new QTreeWidgetItem(this->tree, QStringList(QString(tr("运行环境"))));

    QTreeWidgetItem *version = new QTreeWidgetItem(this->envItem, QStringList(QString(getTime()+tr("程序版本: 1.0.0.0"))));
    version->setIcon(0, QIcon("image/infomation.bmp"));
    QTreeWidgetItem *runPath = new QTreeWidgetItem(this->envItem, QStringList(getTime()+tr("运行路径: ")+QDir::toNativeSeparators(QDir::currentPath())));
    runPath->setIcon(0, QIcon("image/infomation.bmp"));

    QString opSystm;
#ifdef Q_WS_WIN
    switch(QSysInfo::WindowsVersion)
    {
    case QSysInfo::WV_NT: opSystm = "Windows NT (version 4.0)"; break;
    case QSysInfo::WV_2000: opSystm = "Windows 2000 (version 5.0)"; break;
    case QSysInfo::WV_XP: opSystm = "Windows XP (version 5.1)"; break;
    case QSysInfo::WV_2003: opSystm = "Windows 2003 (version 5.2)"; break;
    case QSysInfo::WV_VISTA: opSystm = "Windows VISTA (version 6.0)"; break;
    case QSysInfo::WV_WINDOWS7: opSystm = "Windows 7 (version 6.1)"; break;
    }
#endif

#ifdef Q_WS_MAC
    opSystm = "Mac OS X";
#endif

#ifdef Q_WS_LINUX
    opSystm = "Linux";
#endif
    QTreeWidgetItem *os = new QTreeWidgetItem(this->envItem, QStringList(QString(getTime()+tr("操作系统: ")+opSystm)));
    os->setIcon(0, QIcon("image/infomation.bmp"));

    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect screenRect = desktopWidget->screenGeometry();
    QString screenSize = QString::number(screenRect.width())+" * "+QString::number(screenRect.height());
    QTreeWidgetItem *screen = new QTreeWidgetItem(this->envItem, QStringList(QString(getTime()+tr("显示设备分辨率: ")+screenSize)));
    screen->setIcon(0, QIcon("image/infomation.bmp"));

    this->envItem->addChild(version);
    this->envItem->addChild(runPath);
    this->envItem->addChild(os);
    this->envItem->addChild(screen);
    this->envItem->setSizeHint(0, QSize(0,18));
    this->tree->expandAll();
}

LogsManager::~LogsManager()
{
    delete this->envItem;
}

QString LogsManager::getTime()
{
    QString dateTime = QDateTime(QDateTime::currentDateTime()).toString(tr("yyyy-MM-dd hh:mm:ss"));
    return "["+dateTime+"] ";
}

void LogsManager::updatePathItem(PathManager *pathManager)
{
    QTreeWidgetItem *pathItems = new QTreeWidgetItem();
    pathItems->setText(0, tr("路径配置"));
    QTreeWidgetItem *inputItem = new QTreeWidgetItem(pathItems, QStringList(getTime()+tr("输入图像: ")+pathManager->getInputPath()));
    QTreeWidgetItem *workDirItem = new QTreeWidgetItem(pathItems, QStringList(getTime()+tr("工作目录: ")+pathManager->getWorkDir()));
    QTreeWidgetItem *outDirItem = new QTreeWidgetItem(pathItems, QStringList(getTime()+tr("输出目录: ")+pathManager->getOutputDir()));
    inputItem->setIcon(0, QIcon("image/infomation.bmp"));
    workDirItem->setIcon(0, QIcon("image/infomation.bmp"));
    outDirItem->setIcon(0, QIcon("image/infomation.bmp"));
    pathItems->addChild(inputItem);
    pathItems->addChild(workDirItem);
    pathItems->addChild(outDirItem);
    for(int i = 0; i < MAX_STEP; i++)
    {
        QTreeWidgetItem *stepItem =
                new QTreeWidgetItem(pathItems, QStringList(getTime()+tr("步骤")+QString::number(i+1) +
                                   tr(" 程序路径: ") + pathManager->getStepPath(i+1)));
        stepItem->setIcon(0, QIcon("image/infomation.bmp"));
        pathItems->addChild(stepItem);
    }
    pathItems->setSizeHint(0, QSize(0,18));
    this->tree->addTopLevelItem(pathItems);
    this->tree->expandAll();
}

void LogsManager::addQueueMsg(QString msg)
{
    QTreeWidgetItem *topItem;
    topItem = this->tree->topLevelItem(this->tree->topLevelItemCount() - 1);
    QTreeWidgetItem *msgItem;
    if(tr("队列处理") != topItem->text(0)) //需要创建queueItems
    {
        QTreeWidgetItem *queueItems = new QTreeWidgetItem();
        queueItems->setText(0, tr("队列处理"));
        msgItem = new QTreeWidgetItem(queueItems, QStringList(getTime()+msg));
        msgItem->setIcon(0, QIcon("image/infomation.bmp"));
        queueItems->addChild(msgItem);
        queueItems->setSizeHint(0, QSize(0,18));
        this->tree->addTopLevelItem(queueItems);
    }
    else
    {
        msgItem = new QTreeWidgetItem(topItem, QStringList(getTime() + msg));
        msgItem->setIcon(0, QIcon("image/infomation.bmp"));
        topItem->addChild(msgItem);
    }
    this->tree->expandAll();
}

bool LogsManager::saveLogs(QString path)
{
    QString str;
    QFile file(path);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        return false;
    }
    QTextStream out(&file);
    QTreeWidgetItemIterator itemIterator(this->tree);
    while(*itemIterator)
    {
        if((*itemIterator)->childCount() > 0)
        {
            str = (*itemIterator)->text(0) + ":";
        }
        else
        {
            str = "    " + (*itemIterator)->text(0);
        }
        out << str << "\n";
        ++itemIterator;
    }
    file.flush();
    file.close();

    return true;
}
