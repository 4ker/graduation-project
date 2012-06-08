/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue May 8 17:53:58 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_loadCfg;
    QAction *action_saveCfg;
    QAction *action_quit;
    QAction *action_inputImage;
    QAction *action_workDir;
    QAction *action_outputDir;
    QAction *action_queue;
    QAction *action_logs;
    QAction *action_imgView;
    QAction *action_netCfg;
    QAction *action_langCfg;
    QAction *action_onlineHelp;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_settings;
    QGroupBox *groupBox_sysPath;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_inputPath;
    QLineEdit *lineEdit_inputPath;
    QPushButton *pushButton_inputPath;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_workDir;
    QLineEdit *lineEdit_workDir;
    QPushButton *pushButton_workDir;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label__outputDir;
    QLineEdit *lineEdit_outputDir;
    QPushButton *pushButton_outputDir;
    QGroupBox *groupBox_subPath;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_subPath1;
    QLineEdit *lineEdit_subPath1;
    QPushButton *pushButton_subPath1;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_subPath2;
    QLineEdit *lineEdit_subPath2;
    QPushButton *pushButton_subPath2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_subPath3;
    QLineEdit *lineEdit_subPath3;
    QPushButton *pushButton_subPath3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_subPath4;
    QLineEdit *lineEdit_subPath4;
    QPushButton *pushButton_subPath4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_subPath5;
    QLineEdit *lineEdit_subPath5;
    QPushButton *pushButton_subPath5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_subPath6;
    QLineEdit *lineEdit_subPath6;
    QPushButton *pushButton_subPath6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_subPath7;
    QLineEdit *lineEdit_subPath7;
    QPushButton *pushButton_subPath7;
    QPushButton *pushButton_loadSettings;
    QPushButton *pushButton_saveSettings;
    QPushButton *pushButton_resetAll;
    QLabel *label_settingsOp;
    QWidget *tab_queue;
    QScrollArea *scrollArea_queue;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *groupBox_step1;
    QProgressBar *progressBar_step1;
    QLabel *label_paramStep1;
    QLineEdit *lineEdit_paramStep1;
    QLabel *label_priorityStep1;
    QComboBox *comboBox_priorityStep1;
    QPushButton *pushButton_step1;
    QPushButton *pushButton_viewStep1;
    QGroupBox *groupBox_step2;
    QLabel *label_paramStep2;
    QLabel *label_priorityStep2;
    QPushButton *pushButton_step2;
    QProgressBar *progressBar_step2;
    QLineEdit *lineEdit_paramStep2;
    QComboBox *comboBox_priorityStep2;
    QPushButton *pushButton_viewStep2;
    QGroupBox *groupBox_step3;
    QLabel *label_paramStep3;
    QLabel *label_priorityStep3;
    QPushButton *pushButton_step3;
    QProgressBar *progressBar_step3;
    QLineEdit *lineEdit_paramStep3;
    QComboBox *comboBox_priorityStep3;
    QPushButton *pushButton_viewStep3;
    QGroupBox *groupBox_step4;
    QLabel *label_paramStep4;
    QLabel *label_priorityStep4;
    QPushButton *pushButton_step4;
    QProgressBar *progressBar_step4;
    QLineEdit *lineEdit_paramStep4;
    QComboBox *comboBox_priorityStep4;
    QPushButton *pushButton_viewStep4;
    QGroupBox *groupBox_step5;
    QLabel *label_paramStep5;
    QLabel *label_priorityStep5;
    QPushButton *pushButton_step5;
    QProgressBar *progressBar_step5;
    QLineEdit *lineEdit_paramStep5;
    QComboBox *comboBox_priorityStep5;
    QPushButton *pushButton_viewStep5;
    QGroupBox *groupBox_step6;
    QLabel *label_paramStep6;
    QLabel *label_priorityStep6;
    QPushButton *pushButton_step6;
    QProgressBar *progressBar_step6;
    QLineEdit *lineEdit_paramStep6;
    QComboBox *comboBox_priorityStep6;
    QPushButton *pushButton_viewStep6;
    QGroupBox *groupBox_step7;
    QLabel *label_paramStep7;
    QLabel *label_priorityStep7;
    QPushButton *pushButton_step7;
    QProgressBar *progressBar_step7;
    QLineEdit *lineEdit_paramStep7;
    QComboBox *comboBox_priorityStep7;
    QPushButton *pushButton_viewStep7;
    QLabel *label_progessAll;
    QProgressBar *progressBar_all;
    QLabel *label_queueOp;
    QPushButton *pushButton_queueStart;
    QPushButton *pushButton_queueStop;
    QLabel *label_maxProcessNum;
    QSpinBox *spinBox_maxProcessNum;
    QPushButton *pushButton_queueInit;
    QWidget *tab_logs;
    QTreeWidget *treeWidget_logs;
    QLabel *label_logsOp;
    QPushButton *pushButton_saveLogs;
    QMenuBar *menuBar;
    QMenu *menu_file;
    QMenu *menu_view;
    QMenu *menu_openDir;
    QMenu *menu_tool;
    QMenu *menu_option;
    QMenu *menu;
    QMenu *menu_help;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(483, 521);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(483, 521));
        MainWindow->setMaximumSize(QSize(483, 521));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../RoadExtraction-build-desktop-Qt_4_8_0_for_Desktop_-_MSVC2010__Qt_SDK____/image/RoadExtraction.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_loadCfg = new QAction(MainWindow);
        action_loadCfg->setObjectName(QString::fromUtf8("action_loadCfg"));
        action_saveCfg = new QAction(MainWindow);
        action_saveCfg->setObjectName(QString::fromUtf8("action_saveCfg"));
        action_quit = new QAction(MainWindow);
        action_quit->setObjectName(QString::fromUtf8("action_quit"));
        action_inputImage = new QAction(MainWindow);
        action_inputImage->setObjectName(QString::fromUtf8("action_inputImage"));
        action_workDir = new QAction(MainWindow);
        action_workDir->setObjectName(QString::fromUtf8("action_workDir"));
        action_outputDir = new QAction(MainWindow);
        action_outputDir->setObjectName(QString::fromUtf8("action_outputDir"));
        action_queue = new QAction(MainWindow);
        action_queue->setObjectName(QString::fromUtf8("action_queue"));
        action_logs = new QAction(MainWindow);
        action_logs->setObjectName(QString::fromUtf8("action_logs"));
        action_imgView = new QAction(MainWindow);
        action_imgView->setObjectName(QString::fromUtf8("action_imgView"));
        action_netCfg = new QAction(MainWindow);
        action_netCfg->setObjectName(QString::fromUtf8("action_netCfg"));
        action_langCfg = new QAction(MainWindow);
        action_langCfg->setObjectName(QString::fromUtf8("action_langCfg"));
        action_onlineHelp = new QAction(MainWindow);
        action_onlineHelp->setObjectName(QString::fromUtf8("action_onlineHelp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 461, 481));
        tabWidget->setUsesScrollButtons(true);
        tab_settings = new QWidget();
        tab_settings->setObjectName(QString::fromUtf8("tab_settings"));
        groupBox_sysPath = new QGroupBox(tab_settings);
        groupBox_sysPath->setObjectName(QString::fromUtf8("groupBox_sysPath"));
        groupBox_sysPath->setGeometry(QRect(10, 10, 431, 131));
        verticalLayoutWidget = new QWidget(groupBox_sysPath);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 411, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_inputPath = new QLabel(verticalLayoutWidget);
        label_inputPath->setObjectName(QString::fromUtf8("label_inputPath"));

        horizontalLayout->addWidget(label_inputPath);

        lineEdit_inputPath = new QLineEdit(verticalLayoutWidget);
        lineEdit_inputPath->setObjectName(QString::fromUtf8("lineEdit_inputPath"));

        horizontalLayout->addWidget(lineEdit_inputPath);

        pushButton_inputPath = new QPushButton(verticalLayoutWidget);
        pushButton_inputPath->setObjectName(QString::fromUtf8("pushButton_inputPath"));
        pushButton_inputPath->setMaximumSize(QSize(35, 23));

        horizontalLayout->addWidget(pushButton_inputPath);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_workDir = new QLabel(verticalLayoutWidget);
        label_workDir->setObjectName(QString::fromUtf8("label_workDir"));

        horizontalLayout_2->addWidget(label_workDir);

        lineEdit_workDir = new QLineEdit(verticalLayoutWidget);
        lineEdit_workDir->setObjectName(QString::fromUtf8("lineEdit_workDir"));

        horizontalLayout_2->addWidget(lineEdit_workDir);

        pushButton_workDir = new QPushButton(verticalLayoutWidget);
        pushButton_workDir->setObjectName(QString::fromUtf8("pushButton_workDir"));
        pushButton_workDir->setMaximumSize(QSize(35, 23));

        horizontalLayout_2->addWidget(pushButton_workDir);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label__outputDir = new QLabel(verticalLayoutWidget);
        label__outputDir->setObjectName(QString::fromUtf8("label__outputDir"));

        horizontalLayout_3->addWidget(label__outputDir);

        lineEdit_outputDir = new QLineEdit(verticalLayoutWidget);
        lineEdit_outputDir->setObjectName(QString::fromUtf8("lineEdit_outputDir"));

        horizontalLayout_3->addWidget(lineEdit_outputDir);

        pushButton_outputDir = new QPushButton(verticalLayoutWidget);
        pushButton_outputDir->setObjectName(QString::fromUtf8("pushButton_outputDir"));
        pushButton_outputDir->setMaximumSize(QSize(35, 23));

        horizontalLayout_3->addWidget(pushButton_outputDir);


        verticalLayout->addLayout(horizontalLayout_3);

        groupBox_subPath = new QGroupBox(tab_settings);
        groupBox_subPath->setObjectName(QString::fromUtf8("groupBox_subPath"));
        groupBox_subPath->setGeometry(QRect(10, 160, 431, 261));
        verticalLayoutWidget_2 = new QWidget(groupBox_subPath);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 411, 231));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_subPath1 = new QLabel(verticalLayoutWidget_2);
        label_subPath1->setObjectName(QString::fromUtf8("label_subPath1"));

        horizontalLayout_4->addWidget(label_subPath1);

        lineEdit_subPath1 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_subPath1->setObjectName(QString::fromUtf8("lineEdit_subPath1"));

        horizontalLayout_4->addWidget(lineEdit_subPath1);

        pushButton_subPath1 = new QPushButton(verticalLayoutWidget_2);
        pushButton_subPath1->setObjectName(QString::fromUtf8("pushButton_subPath1"));
        pushButton_subPath1->setMinimumSize(QSize(0, 0));
        pushButton_subPath1->setMaximumSize(QSize(35, 23));

        horizontalLayout_4->addWidget(pushButton_subPath1);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_subPath2 = new QLabel(verticalLayoutWidget_2);
        label_subPath2->setObjectName(QString::fromUtf8("label_subPath2"));

        horizontalLayout_8->addWidget(label_subPath2);

        lineEdit_subPath2 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_subPath2->setObjectName(QString::fromUtf8("lineEdit_subPath2"));

        horizontalLayout_8->addWidget(lineEdit_subPath2);

        pushButton_subPath2 = new QPushButton(verticalLayoutWidget_2);
        pushButton_subPath2->setObjectName(QString::fromUtf8("pushButton_subPath2"));
        pushButton_subPath2->setMinimumSize(QSize(0, 0));
        pushButton_subPath2->setMaximumSize(QSize(35, 23));

        horizontalLayout_8->addWidget(pushButton_subPath2);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_subPath3 = new QLabel(verticalLayoutWidget_2);
        label_subPath3->setObjectName(QString::fromUtf8("label_subPath3"));

        horizontalLayout_7->addWidget(label_subPath3);

        lineEdit_subPath3 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_subPath3->setObjectName(QString::fromUtf8("lineEdit_subPath3"));

        horizontalLayout_7->addWidget(lineEdit_subPath3);

        pushButton_subPath3 = new QPushButton(verticalLayoutWidget_2);
        pushButton_subPath3->setObjectName(QString::fromUtf8("pushButton_subPath3"));
        pushButton_subPath3->setMinimumSize(QSize(0, 0));
        pushButton_subPath3->setMaximumSize(QSize(35, 23));

        horizontalLayout_7->addWidget(pushButton_subPath3);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_subPath4 = new QLabel(verticalLayoutWidget_2);
        label_subPath4->setObjectName(QString::fromUtf8("label_subPath4"));

        horizontalLayout_5->addWidget(label_subPath4);

        lineEdit_subPath4 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_subPath4->setObjectName(QString::fromUtf8("lineEdit_subPath4"));

        horizontalLayout_5->addWidget(lineEdit_subPath4);

        pushButton_subPath4 = new QPushButton(verticalLayoutWidget_2);
        pushButton_subPath4->setObjectName(QString::fromUtf8("pushButton_subPath4"));
        pushButton_subPath4->setMinimumSize(QSize(0, 0));
        pushButton_subPath4->setMaximumSize(QSize(35, 23));

        horizontalLayout_5->addWidget(pushButton_subPath4);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_subPath5 = new QLabel(verticalLayoutWidget_2);
        label_subPath5->setObjectName(QString::fromUtf8("label_subPath5"));

        horizontalLayout_6->addWidget(label_subPath5);

        lineEdit_subPath5 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_subPath5->setObjectName(QString::fromUtf8("lineEdit_subPath5"));

        horizontalLayout_6->addWidget(lineEdit_subPath5);

        pushButton_subPath5 = new QPushButton(verticalLayoutWidget_2);
        pushButton_subPath5->setObjectName(QString::fromUtf8("pushButton_subPath5"));
        pushButton_subPath5->setMinimumSize(QSize(0, 0));
        pushButton_subPath5->setMaximumSize(QSize(35, 23));

        horizontalLayout_6->addWidget(pushButton_subPath5);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_subPath6 = new QLabel(verticalLayoutWidget_2);
        label_subPath6->setObjectName(QString::fromUtf8("label_subPath6"));

        horizontalLayout_9->addWidget(label_subPath6);

        lineEdit_subPath6 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_subPath6->setObjectName(QString::fromUtf8("lineEdit_subPath6"));

        horizontalLayout_9->addWidget(lineEdit_subPath6);

        pushButton_subPath6 = new QPushButton(verticalLayoutWidget_2);
        pushButton_subPath6->setObjectName(QString::fromUtf8("pushButton_subPath6"));
        pushButton_subPath6->setMinimumSize(QSize(0, 0));
        pushButton_subPath6->setMaximumSize(QSize(35, 23));

        horizontalLayout_9->addWidget(pushButton_subPath6);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_subPath7 = new QLabel(verticalLayoutWidget_2);
        label_subPath7->setObjectName(QString::fromUtf8("label_subPath7"));

        horizontalLayout_10->addWidget(label_subPath7);

        lineEdit_subPath7 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_subPath7->setObjectName(QString::fromUtf8("lineEdit_subPath7"));

        horizontalLayout_10->addWidget(lineEdit_subPath7);

        pushButton_subPath7 = new QPushButton(verticalLayoutWidget_2);
        pushButton_subPath7->setObjectName(QString::fromUtf8("pushButton_subPath7"));
        pushButton_subPath7->setMinimumSize(QSize(0, 0));
        pushButton_subPath7->setMaximumSize(QSize(35, 23));

        horizontalLayout_10->addWidget(pushButton_subPath7);


        verticalLayout_2->addLayout(horizontalLayout_10);

        pushButton_loadSettings = new QPushButton(tab_settings);
        pushButton_loadSettings->setObjectName(QString::fromUtf8("pushButton_loadSettings"));
        pushButton_loadSettings->setGeometry(QRect(270, 430, 75, 23));
        pushButton_saveSettings = new QPushButton(tab_settings);
        pushButton_saveSettings->setObjectName(QString::fromUtf8("pushButton_saveSettings"));
        pushButton_saveSettings->setGeometry(QRect(350, 430, 91, 23));
        pushButton_resetAll = new QPushButton(tab_settings);
        pushButton_resetAll->setObjectName(QString::fromUtf8("pushButton_resetAll"));
        pushButton_resetAll->setGeometry(QRect(10, 430, 61, 23));
        label_settingsOp = new QLabel(tab_settings);
        label_settingsOp->setObjectName(QString::fromUtf8("label_settingsOp"));
        label_settingsOp->setGeometry(QRect(190, 432, 81, 20));
        tabWidget->addTab(tab_settings, QString());
        tab_queue = new QWidget();
        tab_queue->setObjectName(QString::fromUtf8("tab_queue"));
        scrollArea_queue = new QScrollArea(tab_queue);
        scrollArea_queue->setObjectName(QString::fromUtf8("scrollArea_queue"));
        scrollArea_queue->setGeometry(QRect(10, 10, 441, 381));
        scrollArea_queue->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_queue->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_queue->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -237, 422, 629));
        groupBox_step1 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_step1->setObjectName(QString::fromUtf8("groupBox_step1"));
        groupBox_step1->setGeometry(QRect(10, 10, 401, 81));
        groupBox_step1->setStyleSheet(QString::fromUtf8(""));
        progressBar_step1 = new QProgressBar(groupBox_step1);
        progressBar_step1->setObjectName(QString::fromUtf8("progressBar_step1"));
        progressBar_step1->setGeometry(QRect(47, 20, 181, 23));
        progressBar_step1->setValue(0);
        label_paramStep1 = new QLabel(groupBox_step1);
        label_paramStep1->setObjectName(QString::fromUtf8("label_paramStep1"));
        label_paramStep1->setGeometry(QRect(10, 50, 54, 20));
        lineEdit_paramStep1 = new QLineEdit(groupBox_step1);
        lineEdit_paramStep1->setObjectName(QString::fromUtf8("lineEdit_paramStep1"));
        lineEdit_paramStep1->setGeometry(QRect(70, 50, 251, 20));
        label_priorityStep1 = new QLabel(groupBox_step1);
        label_priorityStep1->setObjectName(QString::fromUtf8("label_priorityStep1"));
        label_priorityStep1->setGeometry(QRect(250, 21, 71, 20));
        comboBox_priorityStep1 = new QComboBox(groupBox_step1);
        comboBox_priorityStep1->setObjectName(QString::fromUtf8("comboBox_priorityStep1"));
        comboBox_priorityStep1->setGeometry(QRect(320, 20, 69, 22));
        pushButton_step1 = new QPushButton(groupBox_step1);
        pushButton_step1->setObjectName(QString::fromUtf8("pushButton_step1"));
        pushButton_step1->setGeometry(QRect(10, 20, 31, 23));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("image/on.ico"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8("image/off.ico"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_step1->setIcon(icon1);
        pushButton_step1->setCheckable(true);
        pushButton_viewStep1 = new QPushButton(groupBox_step1);
        pushButton_viewStep1->setObjectName(QString::fromUtf8("pushButton_viewStep1"));
        pushButton_viewStep1->setGeometry(QRect(330, 50, 61, 23));
        groupBox_step2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_step2->setObjectName(QString::fromUtf8("groupBox_step2"));
        groupBox_step2->setGeometry(QRect(10, 100, 401, 81));
        groupBox_step2->setStyleSheet(QString::fromUtf8(""));
        label_paramStep2 = new QLabel(groupBox_step2);
        label_paramStep2->setObjectName(QString::fromUtf8("label_paramStep2"));
        label_paramStep2->setGeometry(QRect(10, 50, 54, 20));
        label_priorityStep2 = new QLabel(groupBox_step2);
        label_priorityStep2->setObjectName(QString::fromUtf8("label_priorityStep2"));
        label_priorityStep2->setGeometry(QRect(250, 20, 71, 20));
        pushButton_step2 = new QPushButton(groupBox_step2);
        pushButton_step2->setObjectName(QString::fromUtf8("pushButton_step2"));
        pushButton_step2->setGeometry(QRect(10, 20, 31, 23));
        pushButton_step2->setIcon(icon1);
        pushButton_step2->setCheckable(true);
        progressBar_step2 = new QProgressBar(groupBox_step2);
        progressBar_step2->setObjectName(QString::fromUtf8("progressBar_step2"));
        progressBar_step2->setGeometry(QRect(47, 19, 181, 23));
        progressBar_step2->setValue(0);
        lineEdit_paramStep2 = new QLineEdit(groupBox_step2);
        lineEdit_paramStep2->setObjectName(QString::fromUtf8("lineEdit_paramStep2"));
        lineEdit_paramStep2->setGeometry(QRect(70, 49, 251, 20));
        comboBox_priorityStep2 = new QComboBox(groupBox_step2);
        comboBox_priorityStep2->setObjectName(QString::fromUtf8("comboBox_priorityStep2"));
        comboBox_priorityStep2->setGeometry(QRect(320, 19, 69, 22));
        pushButton_viewStep2 = new QPushButton(groupBox_step2);
        pushButton_viewStep2->setObjectName(QString::fromUtf8("pushButton_viewStep2"));
        pushButton_viewStep2->setGeometry(QRect(330, 50, 61, 23));
        groupBox_step3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_step3->setObjectName(QString::fromUtf8("groupBox_step3"));
        groupBox_step3->setGeometry(QRect(10, 190, 401, 81));
        groupBox_step3->setStyleSheet(QString::fromUtf8(""));
        label_paramStep3 = new QLabel(groupBox_step3);
        label_paramStep3->setObjectName(QString::fromUtf8("label_paramStep3"));
        label_paramStep3->setGeometry(QRect(10, 50, 54, 20));
        label_priorityStep3 = new QLabel(groupBox_step3);
        label_priorityStep3->setObjectName(QString::fromUtf8("label_priorityStep3"));
        label_priorityStep3->setGeometry(QRect(250, 21, 71, 20));
        pushButton_step3 = new QPushButton(groupBox_step3);
        pushButton_step3->setObjectName(QString::fromUtf8("pushButton_step3"));
        pushButton_step3->setGeometry(QRect(10, 20, 31, 23));
        pushButton_step3->setIcon(icon1);
        pushButton_step3->setCheckable(true);
        progressBar_step3 = new QProgressBar(groupBox_step3);
        progressBar_step3->setObjectName(QString::fromUtf8("progressBar_step3"));
        progressBar_step3->setGeometry(QRect(47, 20, 181, 23));
        progressBar_step3->setValue(0);
        lineEdit_paramStep3 = new QLineEdit(groupBox_step3);
        lineEdit_paramStep3->setObjectName(QString::fromUtf8("lineEdit_paramStep3"));
        lineEdit_paramStep3->setGeometry(QRect(70, 50, 251, 20));
        comboBox_priorityStep3 = new QComboBox(groupBox_step3);
        comboBox_priorityStep3->setObjectName(QString::fromUtf8("comboBox_priorityStep3"));
        comboBox_priorityStep3->setGeometry(QRect(320, 20, 69, 22));
        pushButton_viewStep3 = new QPushButton(groupBox_step3);
        pushButton_viewStep3->setObjectName(QString::fromUtf8("pushButton_viewStep3"));
        pushButton_viewStep3->setGeometry(QRect(330, 50, 61, 23));
        groupBox_step4 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_step4->setObjectName(QString::fromUtf8("groupBox_step4"));
        groupBox_step4->setGeometry(QRect(10, 280, 401, 81));
        groupBox_step4->setStyleSheet(QString::fromUtf8(""));
        label_paramStep4 = new QLabel(groupBox_step4);
        label_paramStep4->setObjectName(QString::fromUtf8("label_paramStep4"));
        label_paramStep4->setGeometry(QRect(10, 51, 54, 20));
        label_priorityStep4 = new QLabel(groupBox_step4);
        label_priorityStep4->setObjectName(QString::fromUtf8("label_priorityStep4"));
        label_priorityStep4->setGeometry(QRect(250, 20, 71, 20));
        pushButton_step4 = new QPushButton(groupBox_step4);
        pushButton_step4->setObjectName(QString::fromUtf8("pushButton_step4"));
        pushButton_step4->setGeometry(QRect(10, 20, 31, 23));
        pushButton_step4->setIcon(icon1);
        pushButton_step4->setCheckable(true);
        progressBar_step4 = new QProgressBar(groupBox_step4);
        progressBar_step4->setObjectName(QString::fromUtf8("progressBar_step4"));
        progressBar_step4->setGeometry(QRect(47, 20, 181, 23));
        progressBar_step4->setValue(0);
        lineEdit_paramStep4 = new QLineEdit(groupBox_step4);
        lineEdit_paramStep4->setObjectName(QString::fromUtf8("lineEdit_paramStep4"));
        lineEdit_paramStep4->setGeometry(QRect(70, 50, 251, 20));
        comboBox_priorityStep4 = new QComboBox(groupBox_step4);
        comboBox_priorityStep4->setObjectName(QString::fromUtf8("comboBox_priorityStep4"));
        comboBox_priorityStep4->setGeometry(QRect(320, 20, 69, 22));
        pushButton_viewStep4 = new QPushButton(groupBox_step4);
        pushButton_viewStep4->setObjectName(QString::fromUtf8("pushButton_viewStep4"));
        pushButton_viewStep4->setGeometry(QRect(330, 50, 61, 23));
        groupBox_step5 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_step5->setObjectName(QString::fromUtf8("groupBox_step5"));
        groupBox_step5->setGeometry(QRect(10, 370, 401, 81));
        groupBox_step5->setStyleSheet(QString::fromUtf8(""));
        label_paramStep5 = new QLabel(groupBox_step5);
        label_paramStep5->setObjectName(QString::fromUtf8("label_paramStep5"));
        label_paramStep5->setGeometry(QRect(10, 51, 54, 20));
        label_priorityStep5 = new QLabel(groupBox_step5);
        label_priorityStep5->setObjectName(QString::fromUtf8("label_priorityStep5"));
        label_priorityStep5->setGeometry(QRect(250, 20, 71, 20));
        pushButton_step5 = new QPushButton(groupBox_step5);
        pushButton_step5->setObjectName(QString::fromUtf8("pushButton_step5"));
        pushButton_step5->setGeometry(QRect(10, 20, 31, 23));
        pushButton_step5->setIcon(icon1);
        pushButton_step5->setCheckable(true);
        progressBar_step5 = new QProgressBar(groupBox_step5);
        progressBar_step5->setObjectName(QString::fromUtf8("progressBar_step5"));
        progressBar_step5->setGeometry(QRect(47, 20, 181, 23));
        progressBar_step5->setValue(0);
        lineEdit_paramStep5 = new QLineEdit(groupBox_step5);
        lineEdit_paramStep5->setObjectName(QString::fromUtf8("lineEdit_paramStep5"));
        lineEdit_paramStep5->setGeometry(QRect(70, 50, 251, 20));
        comboBox_priorityStep5 = new QComboBox(groupBox_step5);
        comboBox_priorityStep5->setObjectName(QString::fromUtf8("comboBox_priorityStep5"));
        comboBox_priorityStep5->setGeometry(QRect(320, 20, 69, 22));
        pushButton_viewStep5 = new QPushButton(groupBox_step5);
        pushButton_viewStep5->setObjectName(QString::fromUtf8("pushButton_viewStep5"));
        pushButton_viewStep5->setGeometry(QRect(330, 50, 61, 23));
        groupBox_step6 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_step6->setObjectName(QString::fromUtf8("groupBox_step6"));
        groupBox_step6->setGeometry(QRect(10, 460, 401, 81));
        groupBox_step6->setStyleSheet(QString::fromUtf8(""));
        label_paramStep6 = new QLabel(groupBox_step6);
        label_paramStep6->setObjectName(QString::fromUtf8("label_paramStep6"));
        label_paramStep6->setGeometry(QRect(10, 50, 54, 20));
        label_priorityStep6 = new QLabel(groupBox_step6);
        label_priorityStep6->setObjectName(QString::fromUtf8("label_priorityStep6"));
        label_priorityStep6->setGeometry(QRect(250, 21, 71, 20));
        pushButton_step6 = new QPushButton(groupBox_step6);
        pushButton_step6->setObjectName(QString::fromUtf8("pushButton_step6"));
        pushButton_step6->setGeometry(QRect(10, 20, 31, 23));
        pushButton_step6->setIcon(icon1);
        pushButton_step6->setCheckable(true);
        progressBar_step6 = new QProgressBar(groupBox_step6);
        progressBar_step6->setObjectName(QString::fromUtf8("progressBar_step6"));
        progressBar_step6->setGeometry(QRect(47, 20, 181, 23));
        progressBar_step6->setValue(0);
        lineEdit_paramStep6 = new QLineEdit(groupBox_step6);
        lineEdit_paramStep6->setObjectName(QString::fromUtf8("lineEdit_paramStep6"));
        lineEdit_paramStep6->setGeometry(QRect(70, 50, 251, 20));
        comboBox_priorityStep6 = new QComboBox(groupBox_step6);
        comboBox_priorityStep6->setObjectName(QString::fromUtf8("comboBox_priorityStep6"));
        comboBox_priorityStep6->setGeometry(QRect(320, 20, 69, 22));
        pushButton_viewStep6 = new QPushButton(groupBox_step6);
        pushButton_viewStep6->setObjectName(QString::fromUtf8("pushButton_viewStep6"));
        pushButton_viewStep6->setGeometry(QRect(330, 50, 61, 23));
        groupBox_step7 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_step7->setObjectName(QString::fromUtf8("groupBox_step7"));
        groupBox_step7->setGeometry(QRect(10, 550, 401, 71));
        groupBox_step7->setStyleSheet(QString::fromUtf8(""));
        label_paramStep7 = new QLabel(groupBox_step7);
        label_paramStep7->setObjectName(QString::fromUtf8("label_paramStep7"));
        label_paramStep7->setGeometry(QRect(10, 50, 54, 20));
        label_priorityStep7 = new QLabel(groupBox_step7);
        label_priorityStep7->setObjectName(QString::fromUtf8("label_priorityStep7"));
        label_priorityStep7->setGeometry(QRect(250, 20, 71, 20));
        pushButton_step7 = new QPushButton(groupBox_step7);
        pushButton_step7->setObjectName(QString::fromUtf8("pushButton_step7"));
        pushButton_step7->setGeometry(QRect(10, 20, 31, 23));
        pushButton_step7->setIcon(icon1);
        pushButton_step7->setCheckable(true);
        progressBar_step7 = new QProgressBar(groupBox_step7);
        progressBar_step7->setObjectName(QString::fromUtf8("progressBar_step7"));
        progressBar_step7->setGeometry(QRect(47, 19, 181, 23));
        progressBar_step7->setValue(0);
        lineEdit_paramStep7 = new QLineEdit(groupBox_step7);
        lineEdit_paramStep7->setObjectName(QString::fromUtf8("lineEdit_paramStep7"));
        lineEdit_paramStep7->setGeometry(QRect(70, 49, 251, 20));
        comboBox_priorityStep7 = new QComboBox(groupBox_step7);
        comboBox_priorityStep7->setObjectName(QString::fromUtf8("comboBox_priorityStep7"));
        comboBox_priorityStep7->setGeometry(QRect(320, 19, 69, 22));
        pushButton_viewStep7 = new QPushButton(groupBox_step7);
        pushButton_viewStep7->setObjectName(QString::fromUtf8("pushButton_viewStep7"));
        pushButton_viewStep7->setGeometry(QRect(330, 50, 61, 21));
        scrollArea_queue->setWidget(scrollAreaWidgetContents);
        label_progessAll = new QLabel(tab_queue);
        label_progessAll->setObjectName(QString::fromUtf8("label_progessAll"));
        label_progessAll->setGeometry(QRect(10, 402, 54, 20));
        progressBar_all = new QProgressBar(tab_queue);
        progressBar_all->setObjectName(QString::fromUtf8("progressBar_all"));
        progressBar_all->setGeometry(QRect(70, 400, 381, 23));
        progressBar_all->setValue(0);
        label_queueOp = new QLabel(tab_queue);
        label_queueOp->setObjectName(QString::fromUtf8("label_queueOp"));
        label_queueOp->setGeometry(QRect(200, 431, 54, 20));
        pushButton_queueStart = new QPushButton(tab_queue);
        pushButton_queueStart->setObjectName(QString::fromUtf8("pushButton_queueStart"));
        pushButton_queueStart->setGeometry(QRect(320, 430, 61, 23));
        pushButton_queueStop = new QPushButton(tab_queue);
        pushButton_queueStop->setObjectName(QString::fromUtf8("pushButton_queueStop"));
        pushButton_queueStop->setGeometry(QRect(384, 430, 61, 23));
        label_maxProcessNum = new QLabel(tab_queue);
        label_maxProcessNum->setObjectName(QString::fromUtf8("label_maxProcessNum"));
        label_maxProcessNum->setGeometry(QRect(10, 431, 101, 20));
        spinBox_maxProcessNum = new QSpinBox(tab_queue);
        spinBox_maxProcessNum->setObjectName(QString::fromUtf8("spinBox_maxProcessNum"));
        spinBox_maxProcessNum->setGeometry(QRect(120, 430, 41, 22));
        spinBox_maxProcessNum->setMinimum(1);
        spinBox_maxProcessNum->setMaximum(10);
        pushButton_queueInit = new QPushButton(tab_queue);
        pushButton_queueInit->setObjectName(QString::fromUtf8("pushButton_queueInit"));
        pushButton_queueInit->setGeometry(QRect(260, 430, 51, 23));
        tabWidget->addTab(tab_queue, QString());
        tab_logs = new QWidget();
        tab_logs->setObjectName(QString::fromUtf8("tab_logs"));
        treeWidget_logs = new QTreeWidget(tab_logs);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget_logs);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget_logs);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget_logs);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        treeWidget_logs->setObjectName(QString::fromUtf8("treeWidget_logs"));
        treeWidget_logs->setGeometry(QRect(10, 10, 431, 411));
        treeWidget_logs->setIndentation(10);
        treeWidget_logs->header()->setVisible(false);
        treeWidget_logs->header()->setStretchLastSection(false);
        label_logsOp = new QLabel(tab_logs);
        label_logsOp->setObjectName(QString::fromUtf8("label_logsOp"));
        label_logsOp->setGeometry(QRect(310, 432, 61, 20));
        pushButton_saveLogs = new QPushButton(tab_logs);
        pushButton_saveLogs->setObjectName(QString::fromUtf8("pushButton_saveLogs"));
        pushButton_saveLogs->setGeometry(QRect(370, 430, 75, 23));
        tabWidget->addTab(tab_logs, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 483, 19));
        menu_file = new QMenu(menuBar);
        menu_file->setObjectName(QString::fromUtf8("menu_file"));
        menu_view = new QMenu(menuBar);
        menu_view->setObjectName(QString::fromUtf8("menu_view"));
        menu_openDir = new QMenu(menu_view);
        menu_openDir->setObjectName(QString::fromUtf8("menu_openDir"));
        menu_tool = new QMenu(menuBar);
        menu_tool->setObjectName(QString::fromUtf8("menu_tool"));
        menu_option = new QMenu(menuBar);
        menu_option->setObjectName(QString::fromUtf8("menu_option"));
        menu = new QMenu(menu_option);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_help = new QMenu(menuBar);
        menu_help->setObjectName(QString::fromUtf8("menu_help"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu_file->menuAction());
        menuBar->addAction(menu_view->menuAction());
        menuBar->addAction(menu_tool->menuAction());
        menuBar->addAction(menu_option->menuAction());
        menuBar->addAction(menu_help->menuAction());
        menu_file->addSeparator();
        menu_file->addAction(action_loadCfg);
        menu_file->addAction(action_saveCfg);
        menu_file->addSeparator();
        menu_file->addAction(action_quit);
        menu_view->addAction(action_inputImage);
        menu_view->addSeparator();
        menu_view->addAction(menu_openDir->menuAction());
        menu_view->addSeparator();
        menu_view->addAction(action_queue);
        menu_view->addAction(action_logs);
        menu_openDir->addAction(action_workDir);
        menu_openDir->addAction(action_outputDir);
        menu_tool->addAction(action_imgView);
        menu_option->addAction(action_netCfg);
        menu_option->addAction(menu->menuAction());
        menu->addAction(action_langCfg);
        menu_help->addAction(action_onlineHelp);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        comboBox_priorityStep1->setCurrentIndex(2);
        comboBox_priorityStep2->setCurrentIndex(2);
        comboBox_priorityStep3->setCurrentIndex(2);
        comboBox_priorityStep4->setCurrentIndex(2);
        comboBox_priorityStep5->setCurrentIndex(2);
        comboBox_priorityStep6->setCurrentIndex(2);
        comboBox_priorityStep7->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SAR\345\233\276\345\203\217\351\201\223\350\267\257\346\217\220\345\217\226\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        action_loadCfg->setText(QApplication::translate("MainWindow", "\345\212\240\350\275\275\350\267\257\345\276\204\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        action_saveCfg->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\350\267\257\345\276\204\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        action_quit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&Q)", 0, QApplication::UnicodeUTF8));
        action_inputImage->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\345\233\276\345\203\217", 0, QApplication::UnicodeUTF8));
        action_workDir->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\345\267\245\344\275\234\347\233\256\345\275\225", 0, QApplication::UnicodeUTF8));
        action_outputDir->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\345\233\276\345\203\217\347\233\256\345\275\225", 0, QApplication::UnicodeUTF8));
        action_queue->setText(QApplication::translate("MainWindow", "\351\230\237\345\210\227\350\277\233\345\272\246", 0, QApplication::UnicodeUTF8));
        action_logs->setText(QApplication::translate("MainWindow", "\346\227\245\345\277\227\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        action_imgView->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\346\237\245\347\234\213\345\231\250", 0, QApplication::UnicodeUTF8));
        action_netCfg->setText(QApplication::translate("MainWindow", "\347\275\221\347\273\234\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        action_langCfg->setText(QApplication::translate("MainWindow", "\347\256\200\344\275\223\344\270\255\346\226\207(Chinese simplified)", 0, QApplication::UnicodeUTF8));
        action_onlineHelp->setText(QApplication::translate("MainWindow", "\345\234\250\347\272\277\345\270\256\345\212\251", 0, QApplication::UnicodeUTF8));
        groupBox_sysPath->setTitle(QApplication::translate("MainWindow", "\347\263\273\347\273\237\350\267\257\345\276\204\350\256\276\347\275\256:", 0, QApplication::UnicodeUTF8));
        label_inputPath->setText(QApplication::translate("MainWindow", "  \350\276\223\345\205\245\345\233\276\345\203\217:  ", 0, QApplication::UnicodeUTF8));
        pushButton_inputPath->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        label_workDir->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\345\267\245\344\275\234\347\233\256\345\275\225:", 0, QApplication::UnicodeUTF8));
        pushButton_workDir->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        label__outputDir->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\345\233\276\345\203\217\347\233\256\345\275\225:", 0, QApplication::UnicodeUTF8));
        pushButton_outputDir->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        groupBox_subPath->setTitle(QApplication::translate("MainWindow", "\345\255\220\347\250\213\345\272\217\350\267\257\345\276\204\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_subPath1->setText(QApplication::translate("MainWindow", "\346\255\245\351\252\2441.\345\233\276\345\203\217\350\257\273\345\205\245: ", 0, QApplication::UnicodeUTF8));
        pushButton_subPath1->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        label_subPath2->setText(QApplication::translate("MainWindow", "\346\255\245\351\252\2442.\345\210\206\345\235\227\345\210\207\345\211\262: ", 0, QApplication::UnicodeUTF8));
        pushButton_subPath2->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        label_subPath3->setText(QApplication::translate("MainWindow", "\346\255\245\351\252\2443.\350\276\271\347\274\230\346\217\220\345\217\226: ", 0, QApplication::UnicodeUTF8));
        pushButton_subPath3->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        label_subPath4->setText(QApplication::translate("MainWindow", "\346\255\245\351\252\2444.Hough\345\217\230\346\215\242:", 0, QApplication::UnicodeUTF8));
        pushButton_subPath4->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        label_subPath5->setText(QApplication::translate("MainWindow", "\346\255\245\351\252\2445.\351\201\223\350\267\257\346\213\237\345\220\210: ", 0, QApplication::UnicodeUTF8));
        pushButton_subPath5->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        label_subPath6->setText(QApplication::translate("MainWindow", "\346\255\245\351\252\2446.\345\210\206\345\235\227\345\220\210\345\271\266: ", 0, QApplication::UnicodeUTF8));
        pushButton_subPath6->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        label_subPath7->setText(QApplication::translate("MainWindow", "\346\255\245\351\252\2447.\346\240\207\346\263\250\345\216\237\345\233\276: ", 0, QApplication::UnicodeUTF8));
        pushButton_subPath7->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        pushButton_loadSettings->setText(QApplication::translate("MainWindow", "\345\212\240\350\275\275\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButton_saveSettings->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\345\275\223\345\211\215\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButton_resetAll->setText(QApplication::translate("MainWindow", "\345\205\250\351\203\250\351\207\215\347\275\256", 0, QApplication::UnicodeUTF8));
        label_settingsOp->setText(QApplication::translate("MainWindow", "\350\267\257\345\276\204\351\205\215\347\275\256\346\223\215\344\275\234:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_settings), QApplication::translate("MainWindow", "\350\267\257\345\276\204\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        groupBox_step1->setTitle(QApplication::translate("MainWindow", "\346\255\245\351\252\2441.\345\233\276\345\203\217\350\257\273\345\205\245", 0, QApplication::UnicodeUTF8));
        label_paramStep1->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\345\221\275\344\273\244:", 0, QApplication::UnicodeUTF8));
        label_priorityStep1->setText(QApplication::translate("MainWindow", "\350\277\233\347\250\213\344\274\230\345\205\210\347\272\247:", 0, QApplication::UnicodeUTF8));
        comboBox_priorityStep1->clear();
        comboBox_priorityStep1->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\253\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\253\230\344\272\216\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\275\216\344\272\216\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\275\216", 0, QApplication::UnicodeUTF8)
        );
        pushButton_step1->setText(QString());
        pushButton_viewStep1->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        groupBox_step2->setTitle(QApplication::translate("MainWindow", "\346\255\245\351\252\2442.\345\210\206\345\235\227\345\210\207\345\211\262", 0, QApplication::UnicodeUTF8));
        label_paramStep2->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\345\221\275\344\273\244:", 0, QApplication::UnicodeUTF8));
        label_priorityStep2->setText(QApplication::translate("MainWindow", "\350\277\233\347\250\213\344\274\230\345\205\210\347\272\247:", 0, QApplication::UnicodeUTF8));
        pushButton_step2->setText(QString());
        comboBox_priorityStep2->clear();
        comboBox_priorityStep2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\253\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\253\230\344\272\216\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\275\216\344\272\216\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\275\216", 0, QApplication::UnicodeUTF8)
        );
        pushButton_viewStep2->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        groupBox_step3->setTitle(QApplication::translate("MainWindow", "\346\255\245\351\252\2443.\350\276\271\347\274\230\346\217\220\345\217\226", 0, QApplication::UnicodeUTF8));
        label_paramStep3->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\345\221\275\344\273\244:", 0, QApplication::UnicodeUTF8));
        label_priorityStep3->setText(QApplication::translate("MainWindow", "\350\277\233\347\250\213\344\274\230\345\205\210\347\272\247:", 0, QApplication::UnicodeUTF8));
        pushButton_step3->setText(QString());
        comboBox_priorityStep3->clear();
        comboBox_priorityStep3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\253\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\253\230\344\272\216\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\275\216\344\272\216\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\275\216", 0, QApplication::UnicodeUTF8)
        );
        pushButton_viewStep3->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        groupBox_step4->setTitle(QApplication::translate("MainWindow", "\346\255\245\351\252\2444.Hough\345\217\230\346\215\242", 0, QApplication::UnicodeUTF8));
        label_paramStep4->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\345\221\275\344\273\244:", 0, QApplication::UnicodeUTF8));
        label_priorityStep4->setText(QApplication::translate("MainWindow", "\350\277\233\347\250\213\344\274\230\345\205\210\347\272\247:", 0, QApplication::UnicodeUTF8));
        pushButton_step4->setText(QString());
        comboBox_priorityStep4->clear();
        comboBox_priorityStep4->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\253\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\253\230\344\272\216\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\275\216\344\272\216\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\275\216", 0, QApplication::UnicodeUTF8)
        );
        pushButton_viewStep4->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        groupBox_step5->setTitle(QApplication::translate("MainWindow", "\346\255\245\351\252\2445.\351\201\223\350\267\257\346\213\237\345\220\210", 0, QApplication::UnicodeUTF8));
        label_paramStep5->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\345\221\275\344\273\244:", 0, QApplication::UnicodeUTF8));
        label_priorityStep5->setText(QApplication::translate("MainWindow", "\350\277\233\347\250\213\344\274\230\345\205\210\347\272\247:", 0, QApplication::UnicodeUTF8));
        pushButton_step5->setText(QString());
        comboBox_priorityStep5->clear();
        comboBox_priorityStep5->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\253\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\253\230\344\272\216\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\275\216\344\272\216\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\275\216", 0, QApplication::UnicodeUTF8)
        );
        pushButton_viewStep5->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        groupBox_step6->setTitle(QApplication::translate("MainWindow", "\346\255\245\351\252\2446.\345\210\206\345\235\227\345\220\210\345\271\266", 0, QApplication::UnicodeUTF8));
        label_paramStep6->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\345\221\275\344\273\244:", 0, QApplication::UnicodeUTF8));
        label_priorityStep6->setText(QApplication::translate("MainWindow", "\350\277\233\347\250\213\344\274\230\345\205\210\347\272\247:", 0, QApplication::UnicodeUTF8));
        pushButton_step6->setText(QString());
        comboBox_priorityStep6->clear();
        comboBox_priorityStep6->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\253\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\253\230\344\272\216\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\275\216\344\272\216\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\275\216", 0, QApplication::UnicodeUTF8)
        );
        pushButton_viewStep6->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        groupBox_step7->setTitle(QApplication::translate("MainWindow", "\346\255\245\351\252\2447.\346\240\207\346\263\250\345\216\237\345\233\276", 0, QApplication::UnicodeUTF8));
        label_paramStep7->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\345\221\275\344\273\244:", 0, QApplication::UnicodeUTF8));
        label_priorityStep7->setText(QApplication::translate("MainWindow", "\350\277\233\347\250\213\344\274\230\345\205\210\347\272\247:", 0, QApplication::UnicodeUTF8));
        pushButton_step7->setText(QString());
        comboBox_priorityStep7->clear();
        comboBox_priorityStep7->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\253\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\253\230\344\272\216\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\275\216\344\272\216\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\275\216", 0, QApplication::UnicodeUTF8)
        );
        pushButton_viewStep7->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        label_progessAll->setText(QApplication::translate("MainWindow", "\346\200\273\344\275\223\350\277\233\345\272\246:", 0, QApplication::UnicodeUTF8));
        progressBar_all->setFormat(QApplication::translate("MainWindow", "%p%", 0, QApplication::UnicodeUTF8));
        label_queueOp->setText(QApplication::translate("MainWindow", "\351\230\237\345\210\227\346\223\215\344\275\234:", 0, QApplication::UnicodeUTF8));
        pushButton_queueStart->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        pushButton_queueStop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
        label_maxProcessNum->setText(QApplication::translate("MainWindow", "\346\234\200\345\244\247\345\271\266\350\241\214\350\277\233\347\250\213\346\225\260:", 0, QApplication::UnicodeUTF8));
        pushButton_queueInit->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_queue), QApplication::translate("MainWindow", "\345\244\204\347\220\206\351\230\237\345\210\227", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_logs->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "2012.05.04", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = treeWidget_logs->isSortingEnabled();
        treeWidget_logs->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget_logs->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "\350\277\220\350\241\214\347\216\257\345\242\203", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "\345\275\223\345\211\215\347\250\213\345\272\217\347\211\210\346\234\254", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "\350\277\220\350\241\214\347\233\256\345\275\225", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "\346\223\215\344\275\234\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem1->child(3);
        ___qtreewidgetitem5->setText(0, QApplication::translate("MainWindow", "\345\217\257\347\224\250\345\206\205\345\255\230", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem1->child(4);
        ___qtreewidgetitem6->setText(0, QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\231\250\345\210\206\350\276\250\347\216\207", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem7 = treeWidget_logs->topLevelItem(1);
        ___qtreewidgetitem7->setText(0, QApplication::translate("MainWindow", "\350\267\257\345\276\204\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem7->child(0);
        ___qtreewidgetitem8->setText(0, QApplication::translate("MainWindow", "\350\276\223\345\205\245\345\233\276\345\203\217\350\267\257\345\276\204", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem7->child(1);
        ___qtreewidgetitem9->setText(0, QApplication::translate("MainWindow", "\345\267\245\344\275\234\347\233\256\345\275\225", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem7->child(2);
        ___qtreewidgetitem10->setText(0, QApplication::translate("MainWindow", "\350\276\223\345\207\272\347\233\256\345\275\225", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem11 = treeWidget_logs->topLevelItem(2);
        ___qtreewidgetitem11->setText(0, QApplication::translate("MainWindow", "\351\230\237\345\210\227\345\244\204\347\220\206", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem11->child(0);
        ___qtreewidgetitem12->setText(0, QApplication::translate("MainWindow", "\351\230\237\345\210\2271:", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem11->child(1);
        ___qtreewidgetitem13->setText(0, QApplication::translate("MainWindow", "\351\230\237\345\210\2272:", 0, QApplication::UnicodeUTF8));
        treeWidget_logs->setSortingEnabled(__sortingEnabled);

        label_logsOp->setText(QApplication::translate("MainWindow", "\346\227\245\345\277\227\346\223\215\344\275\234:", 0, QApplication::UnicodeUTF8));
        pushButton_saveLogs->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\227\245\345\277\227", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_logs), QApplication::translate("MainWindow", "\350\277\220\350\241\214\346\227\245\345\277\227", 0, QApplication::UnicodeUTF8));
        menu_file->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", 0, QApplication::UnicodeUTF8));
        menu_view->setTitle(QApplication::translate("MainWindow", "\346\237\245\347\234\213(&V)", 0, QApplication::UnicodeUTF8));
        menu_openDir->setTitle(QApplication::translate("MainWindow", "\346\211\223\345\274\200\347\233\256\345\275\225", 0, QApplication::UnicodeUTF8));
        menu_tool->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267(&T)", 0, QApplication::UnicodeUTF8));
        menu_option->setTitle(QApplication::translate("MainWindow", "\351\200\211\351\241\271(&O)", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\347\225\214\351\235\242\350\257\255\350\250\200", 0, QApplication::UnicodeUTF8));
        menu_help->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
