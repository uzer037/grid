/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <field.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *root;
    QFrame *top_frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *openBtn;
    QPushButton *saveBtn;
    QPushButton *infoBtn;
    QPushButton *exitBtn;
    QSpacerItem *horizontalSpacer;
    QScrollBar *yScroll;
    QTabWidget *tabWidget;
    QWidget *tab;
    QSpinBox *ySpin;
    QSlider *verticalSlider;
    QLabel *hLable;
    QPushButton *addDotBtn;
    QLabel *vLable;
    QSpinBox *xSpin;
    QSlider *horizontalSlider;
    QPushButton *clearButton_2;
    QPushButton *clearButton;
    QLabel *CursorPos;
    QGroupBox *groupBox;
    QWidget *tab_2;
    QCheckBox *aim_Checkbox;
    QPushButton *gridColorBtn;
    QPushButton *gridMainColrBtn;
    QPushButton *dotColorBtn;
    QPushButton *dotLineColorBtn;
    QCheckBox *aim_Checkbox_3;
    QScrollBar *xScroll;
    Field *graphicsView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(750, 570);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(750, 570));
        MainWindow->setMaximumSize(QSize(750, 570));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(238, 238, 236, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(246, 246, 245, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(119, 119, 118, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(159, 159, 157, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush7(QColor(0, 0, 0, 128));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        MainWindow->setPalette(palette);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("applications-graphics");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(0, 0));
        centralWidget->setMaximumSize(QSize(10000, 10000));
        root = new QFrame(centralWidget);
        root->setObjectName(QString::fromUtf8("root"));
        root->setGeometry(QRect(0, 0, 751, 590));
        root->setMinimumSize(QSize(0, 0));
        root->setFrameShape(QFrame::NoFrame);
        root->setFrameShadow(QFrame::Plain);
        top_frame = new QFrame(root);
        top_frame->setObjectName(QString::fromUtf8("top_frame"));
        top_frame->setGeometry(QRect(0, 0, 751, 31));
        sizePolicy.setHeightForWidth(top_frame->sizePolicy().hasHeightForWidth());
        top_frame->setSizePolicy(sizePolicy);
        top_frame->setMinimumSize(QSize(361, 30));
        top_frame->setFrameShape(QFrame::StyledPanel);
        top_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(top_frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        openBtn = new QPushButton(top_frame);
        openBtn->setObjectName(QString::fromUtf8("openBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(openBtn->sizePolicy().hasHeightForWidth());
        openBtn->setSizePolicy(sizePolicy1);
        openBtn->setMinimumSize(QSize(0, 30));
        openBtn->setFlat(true);

        horizontalLayout->addWidget(openBtn);

        saveBtn = new QPushButton(top_frame);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));
        sizePolicy1.setHeightForWidth(saveBtn->sizePolicy().hasHeightForWidth());
        saveBtn->setSizePolicy(sizePolicy1);
        saveBtn->setMinimumSize(QSize(0, 30));
        saveBtn->setFlat(true);

        horizontalLayout->addWidget(saveBtn);

        infoBtn = new QPushButton(top_frame);
        infoBtn->setObjectName(QString::fromUtf8("infoBtn"));
        sizePolicy1.setHeightForWidth(infoBtn->sizePolicy().hasHeightForWidth());
        infoBtn->setSizePolicy(sizePolicy1);
        infoBtn->setMinimumSize(QSize(0, 30));
        infoBtn->setFlat(true);

        horizontalLayout->addWidget(infoBtn);

        exitBtn = new QPushButton(top_frame);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));
        sizePolicy1.setHeightForWidth(exitBtn->sizePolicy().hasHeightForWidth());
        exitBtn->setSizePolicy(sizePolicy1);
        exitBtn->setMinimumSize(QSize(0, 30));
        exitBtn->setFlat(true);

        horizontalLayout->addWidget(exitBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        yScroll = new QScrollBar(root);
        yScroll->setObjectName(QString::fromUtf8("yScroll"));
        yScroll->setEnabled(true);
        yScroll->setGeometry(QRect(500, 50, 16, 501));
        yScroll->setMinimum(0);
        yScroll->setMaximum(500);
        yScroll->setSingleStep(0);
        yScroll->setValue(250);
        yScroll->setOrientation(Qt::Vertical);
        yScroll->setInvertedAppearance(false);
        tabWidget = new QTabWidget(root);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(520, 50, 220, 500));
        tabWidget->setMinimumSize(QSize(220, 500));
        tabWidget->setMaximumSize(QSize(220, 340));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        ySpin = new QSpinBox(tab);
        ySpin->setObjectName(QString::fromUtf8("ySpin"));
        ySpin->setGeometry(QRect(130, 220, 71, 31));
        ySpin->setMaximum(25);
        verticalSlider = new QSlider(tab);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(10, 10, 21, 181));
        verticalSlider->setMinimum(-25);
        verticalSlider->setMaximum(25);
        verticalSlider->setSingleStep(1);
        verticalSlider->setPageStep(1);
        verticalSlider->setTracking(true);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setInvertedAppearance(false);
        verticalSlider->setInvertedControls(false);
        verticalSlider->setTickPosition(QSlider::TicksBelow);
        hLable = new QLabel(tab);
        hLable->setObjectName(QString::fromUtf8("hLable"));
        hLable->setGeometry(QRect(10, 220, 21, 31));
        QFont font;
        font.setPointSize(14);
        hLable->setFont(font);
        addDotBtn = new QPushButton(tab);
        addDotBtn->setObjectName(QString::fromUtf8("addDotBtn"));
        addDotBtn->setGeometry(QRect(60, 30, 121, 111));
        addDotBtn->setFont(font);
        addDotBtn->setAutoDefault(false);
        addDotBtn->setFlat(false);
        vLable = new QLabel(tab);
        vLable->setObjectName(QString::fromUtf8("vLable"));
        vLable->setGeometry(QRect(110, 220, 20, 31));
        vLable->setFont(font);
        xSpin = new QSpinBox(tab);
        xSpin->setObjectName(QString::fromUtf8("xSpin"));
        xSpin->setGeometry(QRect(30, 220, 71, 31));
        xSpin->setMaximum(25);
        horizontalSlider = new QSlider(tab);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(30, 190, 181, 21));
        horizontalSlider->setMinimum(-25);
        horizontalSlider->setMaximum(25);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setTracking(true);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedControls(true);
        horizontalSlider->setTickPosition(QSlider::TicksAbove);
        clearButton_2 = new QPushButton(tab);
        clearButton_2->setObjectName(QString::fromUtf8("clearButton_2"));
        clearButton_2->setGeometry(QRect(110, 260, 91, 31));
        clearButton = new QPushButton(tab);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(10, 260, 91, 31));
        CursorPos = new QLabel(tab);
        CursorPos->setObjectName(QString::fromUtf8("CursorPos"));
        CursorPos->setGeometry(QRect(60, 150, 121, 17));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 320, 221, 151));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        aim_Checkbox = new QCheckBox(tab_2);
        aim_Checkbox->setObjectName(QString::fromUtf8("aim_Checkbox"));
        aim_Checkbox->setGeometry(QRect(20, 220, 181, 41));
        aim_Checkbox->setFont(font);
        aim_Checkbox->setChecked(false);
        gridColorBtn = new QPushButton(tab_2);
        gridColorBtn->setObjectName(QString::fromUtf8("gridColorBtn"));
        gridColorBtn->setGeometry(QRect(20, 120, 181, 41));
        gridMainColrBtn = new QPushButton(tab_2);
        gridMainColrBtn->setObjectName(QString::fromUtf8("gridMainColrBtn"));
        gridMainColrBtn->setGeometry(QRect(20, 180, 181, 25));
        dotColorBtn = new QPushButton(tab_2);
        dotColorBtn->setObjectName(QString::fromUtf8("dotColorBtn"));
        dotColorBtn->setGeometry(QRect(20, 20, 181, 21));
        dotLineColorBtn = new QPushButton(tab_2);
        dotLineColorBtn->setObjectName(QString::fromUtf8("dotLineColorBtn"));
        dotLineColorBtn->setGeometry(QRect(20, 60, 181, 41));
        aim_Checkbox_3 = new QCheckBox(tab_2);
        aim_Checkbox_3->setObjectName(QString::fromUtf8("aim_Checkbox_3"));
        aim_Checkbox_3->setGeometry(QRect(20, 270, 181, 41));
        aim_Checkbox_3->setFont(font);
        aim_Checkbox_3->setChecked(false);
        tabWidget->addTab(tab_2, QString());
        xScroll = new QScrollBar(root);
        xScroll->setObjectName(QString::fromUtf8("xScroll"));
        xScroll->setEnabled(true);
        xScroll->setGeometry(QRect(0, 550, 501, 16));
        xScroll->setMinimum(0);
        xScroll->setMaximum(500);
        xScroll->setValue(250);
        xScroll->setOrientation(Qt::Horizontal);
        graphicsView = new Field(root);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 50, 500, 500));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(500, 500));
        graphicsView->setMaximumSize(QSize(500, 500));
        graphicsView->setSizeIncrement(QSize(0, 0));
        graphicsView->setBaseSize(QSize(0, 0));
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        graphicsView->setMouseTracking(true);
        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(saveBtn, infoBtn);
        QWidget::setTabOrder(infoBtn, exitBtn);
        QWidget::setTabOrder(exitBtn, verticalSlider);
        QWidget::setTabOrder(verticalSlider, addDotBtn);
        QWidget::setTabOrder(addDotBtn, horizontalSlider);
        QWidget::setTabOrder(horizontalSlider, ySpin);
        QWidget::setTabOrder(ySpin, xSpin);
        QWidget::setTabOrder(xSpin, clearButton);
        QWidget::setTabOrder(clearButton, aim_Checkbox);
        QWidget::setTabOrder(aim_Checkbox, gridColorBtn);
        QWidget::setTabOrder(gridColorBtn, gridMainColrBtn);
        QWidget::setTabOrder(gridMainColrBtn, dotColorBtn);
        QWidget::setTabOrder(dotColorBtn, dotLineColorBtn);
        QWidget::setTabOrder(dotLineColorBtn, aim_Checkbox_3);
        QWidget::setTabOrder(aim_Checkbox_3, clearButton_2);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        addDotBtn->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        openBtn->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        saveBtn->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        infoBtn->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
        exitBtn->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        hLable->setText(QApplication::translate("MainWindow", "X:", nullptr));
        addDotBtn->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214\n"
"\320\242\320\276\321\207\320\272\321\203", nullptr));
        vLable->setText(QApplication::translate("MainWindow", "Y:", nullptr));
        clearButton_2->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        clearButton->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        CursorPos->setText(QApplication::translate("MainWindow", "\320\242\320\276\321\207\320\272\320\270 \320\275\320\265 \320\267\320\260\320\264\320\260\320\275\321\213", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\241\320\273\320\265\320\264\321\203\321\211\320\260\321\217 \321\202\320\276\321\207\320\272\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213", nullptr));
        aim_Checkbox->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\320\275\320\276\320\265\n"
"\320\277\320\265\321\200\320\265\320\272\321\200\320\265\321\201\321\202\320\270\320\265", nullptr));
        gridColorBtn->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\320\275\320\276\320\271\n"
"\320\241\320\265\321\202\320\272\320\270", nullptr));
        gridMainColrBtn->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\223\320\273\320\260\320\262\320\275\320\276\320\271 \320\236\321\201\320\270", nullptr));
        dotColorBtn->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\242\320\276\321\207\320\272\320\270", nullptr));
        dotLineColorBtn->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\241\320\276\320\265\320\264\320\270\320\275\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205\n"
"\320\233\320\270\320\275\320\270\320\271", nullptr));
        aim_Checkbox_3->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\260\321\202\321\214\n"
"\320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
