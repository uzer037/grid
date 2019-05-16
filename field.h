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

struct gElem
{
    int type; //0 - dot, 1 - line
    QPointF p1;
    QPointF p2;
};

class Field : public QGraphicsView
{
    Q_OBJECT
public:
    Field(QWidget *parent = nullptr);
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
public slots:
    void load();
    void game();
public:
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
    void loadGameFile(QString gameFilename);

    QString filename;
    bool closedLoop = 1;
    bool showingCross = 0;
    bool showingLines = 0;
    QSize *sz;
    double sizeFactor = 20;
    double oldSizeFactor = 20;

    double xshift = 0, yshift = 0;
    double mxXshift = 50, mxYshift = 50;
    double oldxshift = 0, oldyshift = 0;

    void redrawGrid();
    void redrawDots();
    void recalcDots();
    void redrawCoord(int x, int y);
    void hideCoord();

    QVector <gElem> gameArr;
    bool gameMode = 0;

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
