#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QColorDialog>
#include <QKeyEvent>
#include <cmath>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

public:
    Ui::MainWindow *ui;
    int x = 0, y = 0; // current position of cursor
    int xshift = 0, yshift = 0; // shift of main axis
    double sizeFactor = 20;
    QSize gridSize = QSize(25,25); //size of visible grid in cells (1 <= gridSize <= 50) (use ONLY SQUARE shape of grid (like 2x2 or 15x15))
    QSize mnGridSize =  QSize(2,2);
    QSize mxGridSize =  QSize(50,50);

public slots:
    void subwindowResized();
    void renameWindow(QString newName);

private slots:

    void mousePressEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void resizeEvent(QResizeEvent *e);


    void on_addDotBtn_clicked();
    void updateCoord(int x, int y);
    void updateLastCoord(int x, int y);
    QColor colorPick();
    void on_dotColorBtn_clicked();
    void on_gridColorBtn_clicked();
    void on_xSpin_valueChanged(int arg1);
    void on_ySpin_valueChanged(int arg1);
    void on_clearButton_clicked();
    void on_clearButton_2_clicked();
    void on_checkBox_stateChanged(int arg1);
    void on_verticalSlider_valueChanged(int value);
    void on_horizontalSlider_valueChanged(int value);
    void on_dotLineColorBtn_clicked();
    void on_gridMainColrBtn_clicked();
    void on_aim_Checkbox_stateChanged(int arg1);
    void on_openBtn_clicked();
    void on_saveBtn_clicked();
    void on_exitBtn_clicked();
    void on_infoBtn_clicked();
    void on_aim_Checkbox_3_stateChanged(int arg1);
    void on_xScroll_valueChanged(int value);
    void on_yScroll_valueChanged(int value);
};

#endif // MAINWINDOW_H
