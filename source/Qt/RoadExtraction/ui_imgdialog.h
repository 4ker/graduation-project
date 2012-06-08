/********************************************************************************
** Form generated from reading UI file 'imgdialog.ui'
**
** Created: Tue May 8 17:53:58 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGDIALOG_H
#define UI_IMGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImgDialog
{
public:
    QAction *action_Open;
    QAction *action_save;
    QAction *action_fit;
    QAction *action_original;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_size;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_fit;
    QPushButton *pushButton_original;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_pixmap;

    void setupUi(QDialog *ImgDialog)
    {
        if (ImgDialog->objectName().isEmpty())
            ImgDialog->setObjectName(QString::fromUtf8("ImgDialog"));
        ImgDialog->resize(800, 600);
        ImgDialog->setMinimumSize(QSize(540, 400));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../RoadExtraction-build-desktop-Qt_4_8_0_for_Desktop_-_MSVC2010__Qt_SDK____/image/RoadExtraction.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ImgDialog->setWindowIcon(icon);
        action_Open = new QAction(ImgDialog);
        action_Open->setObjectName(QString::fromUtf8("action_Open"));
        action_save = new QAction(ImgDialog);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        action_fit = new QAction(ImgDialog);
        action_fit->setObjectName(QString::fromUtf8("action_fit"));
        action_original = new QAction(ImgDialog);
        action_original->setObjectName(QString::fromUtf8("action_original"));
        verticalLayout_2 = new QVBoxLayout(ImgDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_size = new QLabel(ImgDialog);
        label_size->setObjectName(QString::fromUtf8("label_size"));

        horizontalLayout_2->addWidget(label_size);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_fit = new QPushButton(ImgDialog);
        pushButton_fit->setObjectName(QString::fromUtf8("pushButton_fit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_fit->sizePolicy().hasHeightForWidth());
        pushButton_fit->setSizePolicy(sizePolicy);
        pushButton_fit->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(pushButton_fit);

        pushButton_original = new QPushButton(ImgDialog);
        pushButton_original->setObjectName(QString::fromUtf8("pushButton_original"));
        pushButton_original->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(pushButton_original);

        spinBox = new QSpinBox(ImgDialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(5);
        spinBox->setMaximum(200);
        spinBox->setSingleStep(5);
        spinBox->setValue(100);

        horizontalLayout_2->addWidget(spinBox);

        horizontalSlider = new QSlider(ImgDialog);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy1);
        horizontalSlider->setMinimum(5);
        horizontalSlider->setMaximum(200);
        horizontalSlider->setSingleStep(5);
        horizontalSlider->setValue(100);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider);


        verticalLayout->addLayout(horizontalLayout_2);

        scrollArea = new QScrollArea(ImgDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 778, 547));
        horizontalLayout_3 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_pixmap = new QLabel(scrollAreaWidgetContents);
        label_pixmap->setObjectName(QString::fromUtf8("label_pixmap"));
        label_pixmap->setContextMenuPolicy(Qt::CustomContextMenu);
        label_pixmap->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_pixmap);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ImgDialog);

        QMetaObject::connectSlotsByName(ImgDialog);
    } // setupUi

    void retranslateUi(QDialog *ImgDialog)
    {
        ImgDialog->setWindowTitle(QApplication::translate("ImgDialog", "\346\237\245\347\234\213\345\233\276\347\211\207", 0, QApplication::UnicodeUTF8));
        action_Open->setText(QApplication::translate("ImgDialog", "\346\211\223\345\274\200...", 0, QApplication::UnicodeUTF8));
        action_Open->setShortcut(QApplication::translate("ImgDialog", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        action_save->setText(QApplication::translate("ImgDialog", "\345\217\246\345\255\230\344\270\272...", 0, QApplication::UnicodeUTF8));
        action_save->setShortcut(QApplication::translate("ImgDialog", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        action_fit->setText(QApplication::translate("ImgDialog", "\351\200\202\345\220\210\347\252\227\345\217\243", 0, QApplication::UnicodeUTF8));
        action_original->setText(QApplication::translate("ImgDialog", "\345\256\236\351\231\205\345\244\247\345\260\217", 0, QApplication::UnicodeUTF8));
        label_size->setText(QString());
        pushButton_fit->setText(QApplication::translate("ImgDialog", "\351\200\202\345\220\210\347\252\227\345\217\243", 0, QApplication::UnicodeUTF8));
        pushButton_original->setText(QApplication::translate("ImgDialog", "\345\256\236\351\231\205\345\244\247\345\260\217", 0, QApplication::UnicodeUTF8));
        spinBox->setSuffix(QApplication::translate("ImgDialog", "%", 0, QApplication::UnicodeUTF8));
        label_pixmap->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImgDialog: public Ui_ImgDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGDIALOG_H
