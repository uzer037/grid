#ifndef FIELD_H
#define FIELD_H

#include <QGraphicsView>
#include <QGraphicsItemGroup>
#include <QResizeEvent>
#include <QVector>
#include <cmath>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QApplication>

class Field : public QGraphicsView
{
    Q_OBJECT
public:
    Field(QWidget *parent = 0);
    ~Field();
    QGraphicsItem *getLastDot();

    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    QPointF last_mPos;

    void wheelEvent(QWheelEvent *e);

    void recalcSizeFac();

    double getSizeFactor();
    QString getFilename();
    void addDot(int x, int y);
    void addLine(int x1, int y1, int x2, int y2);
    void setSizeFactor(double sizeFactor);
    void setGridColor(QColor col);
    void setGridMainColor(QColor col);
    void setDotColor(QColor col);
    void setDotLineColor(QColor col);
    void clearDots();
    void showLines();
    void hideLines();
    void showCross(int x, int y);
    void hideCross();
    void redrawCross(int x, int y);
    int dotCount();
    void setShift(int x, int y);
    void undo();
    void save();
    void load();
    void exit();
    void nlinepos(int x1, int y1, int x2, int y2);

    QSize gridSize;
    QSize mnGridSize;
    QSize mxGridSize;
    bool showingCoord = 0;

    void resizeEvent(QResizeEvent* event);
signals:
    void resized();
    void renameRootWindow();

private:

    QPointF normalizeCoord(QPointF p);

    void loadFromFile();
    void saveToFile();
    QString filename;
    bool closedLoop = 1;
    bool showingCross = 0;
    bool showingLines = 0;
    QSize *sz;
    double sizeFactor = 20;
    double oldSizeFactor = 20;

    int xshift = 0, yshift = 0;
    int oldxshift = 0, oldyshift = 0;

    void redrawGrid();
    void redrawDots();
    void recalcDots();
    void redrawCoord(int x, int y);
    void hideCoord();

    QGraphicsScene *scene;
    QGraphicsItemGroup *group_hline;
    QGraphicsItemGroup *group_vline;
    QGraphicsItemGroup *group_figure;
    QGraphicsItemGroup *group_figure_tmp;
    QGraphicsItemGroup *group_dlines;
    QGraphicsItemGroup *group_cross;
    QGraphicsItemGroup *group_coordLable;
    //QGraphicsItemGroup *anchor;
    QGraphicsLineItem *newLine;
    QPen gridPen;
    QPen gridFatPen;
    QPen dotPen;
    QPen dotLinePen;
    QBrush dotBrush;
};

#endif // FIELD_H
