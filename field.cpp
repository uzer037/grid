#include "field.h"

Field::Field(QWidget *parent) : QGraphicsView(parent)
{
    this->sz = new QSize(500,500);
    this->setMinimumHeight(this->sz->height());
    this->setMinimumWidth(this->sz->width());

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    gridPen = QPen(Qt::gray);
    gridFatPen = gridPen;
    gridFatPen.setColor(Qt::black);
    gridFatPen.setWidth(gridPen.width()+2);
    dotPen = QPen(Qt::darkRed);
    dotBrush = QBrush(Qt::darkRed);
    dotLinePen.setWidth(dotPen.width()+1);
    dotLinePen.setColor(Qt::red);



    scene = new QGraphicsScene();

    group_hline = new QGraphicsItemGroup();
    group_vline = new QGraphicsItemGroup();
    group_figure = new QGraphicsItemGroup();
    group_dlines = new QGraphicsItemGroup();
    group_cross = new QGraphicsItemGroup();
    group_coordLable = new QGraphicsItemGroup();

    newLine = new QGraphicsLineItem(0,0,0,0);

    scene->addItem(group_hline);
    scene->addItem(group_vline);
    scene->addItem(group_figure);
    scene->addItem(group_dlines);
    scene->addItem(group_cross);
    scene->addItem(group_coordLable);
    group_figure->setZValue(10);

    scene->addItem(newLine);

    this->setScene(scene);
}

Field::~Field()
{

}

void Field::resizeEvent(QResizeEvent* event)
{
    this->sz->rheight() = event->size().height();
    this->sz->rwidth() = event->size().width();
    QGraphicsView::resizeEvent(event);
    scene->setSceneRect(0,0,this->sz->height(),this->sz->width());
    this->setMinimumHeight(this->sz->height());
    this->setMinimumWidth(this->sz->width());

}

void Field::redrawGrid()
{
    for(auto i : group_hline->childItems())
    {
        scene->removeItem(i);
    }

    for(auto i : group_vline->childItems())
    {
        scene->removeItem(i);
    }

    int xds = (xshift - (int)xshift) * sizeFactor;
    int yds = (yshift - (int)yshift) * sizeFactor;

    for(int i = -gridSize.width(); i <= 2*gridSize.width(); i++)
    {
        if(i == (int)xshift)
        {
            group_hline->addToGroup(scene->addLine(i*sizeFactor + xds, -2*gridSize.width()*sizeFactor - yds, i*sizeFactor + xds, 2*gridSize.width()*sizeFactor - yds, gridFatPen));
            group_hline->childItems().last()->setZValue(2);
        }
        else
            group_hline->addToGroup(scene->addLine(i*sizeFactor + xds, -2*gridSize.width()*sizeFactor - yds, i*sizeFactor + xds, 2*gridSize.width()*sizeFactor - yds, gridPen));
    }

    for(int j = -gridSize.height(); j <= 2*gridSize.height(); j++)
    {
        if(mxGridSize.height()/2 - j == (int)yshift)
        {
            group_vline->addToGroup(scene->addLine(-2*gridSize.height()*sizeFactor + xds, j*sizeFactor - yds, 2*gridSize.height()*sizeFactor + xds, j*sizeFactor - yds, gridFatPen));
            group_vline->childItems().last()->setZValue(2);
        }
        else
            group_vline->addToGroup(scene->addLine(-2*gridSize.height()*sizeFactor + xds, j*sizeFactor - yds, 2*gridSize.height()*sizeFactor + xds, j*sizeFactor - yds, gridPen));
    }
}

void Field::redrawDots()
{
    group_figure_tmp = new QGraphicsItemGroup();
    scene->addItem(group_figure_tmp);
    for(auto i : group_figure->childItems())
    {
        QGraphicsEllipseItem* dot = dynamic_cast<QGraphicsEllipseItem *>(i);
        QGraphicsLineItem* line = dynamic_cast<QGraphicsLineItem *>(i);
        if(dot)
        {
            group_figure_tmp->addToGroup(scene->addEllipse(-5, -5, 10, 10, dotPen, dotBrush));
        }
        if(line)
        {
            group_figure_tmp->addToGroup(scene->addLine(0, 0, line->line().x2(), line->line().y2(), dotLinePen));
        }

        group_figure_tmp->childItems().last()->setPos(i->pos() + QPointF(xshift - oldxshift,yshift - oldyshift));
        scene->removeItem(i);
    }
    scene->addItem(group_figure);
    for(auto i : group_figure_tmp->childItems())
    {
        QGraphicsEllipseItem* dot = dynamic_cast<QGraphicsEllipseItem *>(i);
        QGraphicsLineItem* line = dynamic_cast<QGraphicsLineItem *>(i);
        if(dot)
        {
            group_figure->addToGroup(scene->addEllipse(-5, -5, 10, 10, dotPen, dotBrush));
        }
        if(line)
        {
            group_figure->addToGroup(scene->addLine(0, 0, line->line().x2(), line->line().y2(), dotLinePen));
        }
        group_figure->childItems().last()->setPos(i->pos() + QPointF(xshift - oldxshift,yshift - oldyshift));
        scene->removeItem(i);
    }
    oldxshift = xshift;
    oldyshift = yshift;
}

void Field::redrawCoord(int x, int y)
{
    for(int i = 0; i < group_coordLable->childItems().size(); i++)
        scene->removeItem(group_coordLable->childItems()[i]);
    group_coordLable->addToGroup(scene->addText("X:" + QString::number(round(x/sizeFactor - xshift)) + " Y:" + QString::number(round((mxGridSize.height()*sizeFactor/2 - y)/sizeFactor - yshift))));
    while(x >= sz->width() - 70)    x--;
    while(y >= sz->height() - 25)    y--;
    while(x <= 0)    x++;
    while(y <= 0)    y++;
    group_coordLable->childItems()[0]->setPos(x,y);
}

void Field::hideCoord()
{
    for(int i = 0; i < group_coordLable->childItems().size(); i++)
        scene->removeItem(group_coordLable->childItems()[i]);
}

void Field::nlinepos(int x1, int y1, int x2, int y2)
{
    scene->removeItem(newLine);
    newLine = scene->addLine(x1,y1,x2,y2,dotLinePen);
}

void Field::addDot(int x, int y)
{
    bool make = true;
    for(auto i : group_figure->childItems())
    {
        QGraphicsEllipseItem* dot = dynamic_cast<QGraphicsEllipseItem *>(i);
        QGraphicsLineItem* line = dynamic_cast<QGraphicsLineItem *>(i);
        if(dot && i == scene->itemAt(x,y,this->transform())) make = false;
        if(line && i == scene->itemAt(x,y,this->transform())) qDebug()<<"foundLine!!!!";
    }
    if(make)
    {
        group_figure->addToGroup(scene->addEllipse(-5, -5, 10, 10, dotPen, dotBrush));
        group_figure->childItems().last()->setPos(x,y);
        if(showingLines && group_figure->childItems().size() > 1)
        {
            if(group_figure->childItems().size() > 3 && closedLoop) scene->removeItem(group_dlines->childItems().last());
            group_dlines->addToGroup(scene->addLine(group_figure->childItems().at(group_figure->childItems().size() - 2) ->x(),
                                                    group_figure->childItems().at(group_figure->childItems().size() - 2)->y(),x,y, dotLinePen));

            if(group_figure->childItems().size() > 2 && closedLoop) group_dlines->addToGroup(scene->addLine(group_figure->childItems().at(0) ->x(),
                                                    group_figure->childItems().at(0)->y(),
                                                    group_figure->childItems().at(group_figure->childItems().size()-1)->x(),
                                                    (group_figure->childItems().at(group_figure->childItems().size()-1)->y()), dotLinePen));
        }
    }
    else
    {
        qDebug() << "Dot at: x=" << x << " y=" << y << "already exist!";
    }
}

void Field::addLine(int x1, int y1, int x2, int y2)
{
    bool make = true;
    for(auto i : group_dlines->childItems())
    {
        if(i == scene->itemAt(x1,y1,this->transform())) make = false;
    }
    if(make)
    {
        group_figure->addToGroup(scene->addLine(0, 0, x2-x1, y2-y1, dotLinePen));
        group_figure->childItems().last()->setPos(x1,y1);
    }
    else
    {
        qDebug() << "Dot at: x=" << x1 << " y=" << y1 << "already exist!";
    }
}

void Field::setSizeFactor(double sizeFactor)
{
    this->sizeFactor = sizeFactor;
}

void Field::setGridColor(QColor col)
{
    gridPen.setColor(col);
    redrawGrid();
}

void Field::setGridMainColor(QColor col)
{
    gridFatPen.setColor(col);
    redrawGrid();
}

void Field::setDotColor(QColor col)
{
    dotBrush.setColor(col);
    dotPen.setColor(col);

    redrawDots();
}

void Field::setDotLineColor(QColor col)
{
    dotLinePen.setColor(col);
    redrawDots();
}

void Field::clearDots()
{
    for(auto i : group_figure->childItems())
    {
        scene->removeItem(i);
    }
    if(showingLines)
    {
        hideLines();
        showLines();
    }
}

void Field::showLines()
{
    showingLines = true;
    for(int i = 1; i < group_figure->childItems().size(); i++)
    {
        group_dlines->addToGroup(scene->addLine(group_figure->childItems().at(i-1) ->x(),group_figure->childItems().at(i-1)->y(),group_figure->childItems().at(i)->x(),(group_figure->childItems().at(i)->y()), dotLinePen));
    }
    if(group_figure->childItems().size() > 2 && closedLoop) group_dlines->addToGroup(scene->addLine(group_figure->childItems().at(0) ->x(),
                                            group_figure->childItems().at(0)->y(),
                                            group_figure->childItems().at(group_figure->childItems().size()-1)->x(),
                                            (group_figure->childItems().at(group_figure->childItems().size()-1)->y()), dotLinePen));
}

void Field::hideLines()
{
    showingLines = false;
    for(auto i : group_dlines->childItems())
    {
        scene->removeItem(i);
    }
}

void Field::showCross(int x, int y)
{
    showingCross = 1;
    redrawCross(x, y);
}

void Field::hideCross()
{
    showingCross = 0;
    redrawCross(0, 0);
    hideCoord();
}

void Field::redrawCross(int x, int y)
{
    if(group_cross->childItems().size() >= 1)
    {
        for(auto i : group_cross->childItems())
        {
            scene->removeItem(i);
        }
    }
    if(showingCross)
    {
        group_cross->addToGroup(scene->addLine(x*sizeFactor, 0, x*sizeFactor, 40*sizeFactor, gridFatPen));
        group_cross->addToGroup(scene->addLine(0,y*sizeFactor, 40*sizeFactor, y*sizeFactor, gridFatPen));
    }
}

int Field::dotCount()
{
    return group_figure->childItems().size();
}

QGraphicsItem* Field::getLastDot()
{
    return group_figure->childItems().last();
}

void Field::setShift(int x, int y)
{
    xshift = x;
    yshift = y;
}

void Field::undo()
{
    int n = this->group_figure->childItems().size();
    if(n > 0)
    {
        if(n >= 3)
        {
            QGraphicsLineItem* tmp_line = dynamic_cast<QGraphicsLineItem *>(this->group_figure->childItems().at(n-3));
            if(tmp_line)
            {
                scene->removeItem(this->group_figure->childItems().at(n-3));
                scene->removeItem(this->group_figure->childItems().at(n-3));
            }
            scene->removeItem(this->group_figure->childItems().last());
        }
        else
            scene->removeItem(this->group_figure->childItems().last());
    }
    if(showingLines)
    {
        hideLines();
        showLines();
    }
}

void Field::load()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Открыть чертеж (редактирование)"), QDir::homePath(), tr("Файл Чертежа (*.cbf)"));
    if(fileName == "")
    {
        QMessageBox::warning(this, tr("Внимание!"),
                                       tr("Файл не выбран!"),
                                       QMessageBox::Ok);
    }
    else
    {
        this->clearDots();
        filename = fileName;
        loadFromFile();
        renameRootWindow();
    }
}

void Field::game()
{
    loadGameFile(QFileDialog::getOpenFileName(this, tr("Открыть чертеж"), QDir::homePath(), tr("Файл Чертежа (*.cbf)")));
}

void Field::exit()
{
    if(this->dotCount() >= 1)
    {
        int ask = QMessageBox::warning(this, tr("Внимание!"),
                                               tr("Изменения не сохранены.\nСохранить?"),
                                               QMessageBox::Yes | QMessageBox::No);
        if(ask == QMessageBox::No)
        {
            QApplication::quit();
        }
        if(ask == QMessageBox::Yes)
        {
            this->save();
        }
    }
    else
    {
        QApplication::quit();
    }
}

void Field::loadFromFile()
{

    QFile file(filename);
    qDebug() << file;
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        QTextStream fin(&file);
        int tmp;
        fin >> tmp;
        gridSize.setHeight(tmp);
        fin >> tmp;
        gridSize.setWidth(tmp);
        recalcSizeFac();

        fin >> tmp; //n of dots
        qDebug() << tmp;
        for(int i = 0; i < tmp; i++)
        {
            int x, y, type;
            fin >> type >> x >> y;
            if(type == 0)
                addDot((x+xshift)*sizeFactor, this->sz->height() - (y+yshift)*sizeFactor);
            if(type == 1)
            {
                int x2, y2;
                fin >> x2 >> y2;
                addLine((x+xshift)*sizeFactor, this->sz->height() - (y+yshift)*sizeFactor, (x2+xshift)*sizeFactor, sz->height() - (y2+yshift)*sizeFactor);
            }
        }
    }
    file.close();
}

void Field::loadGameFile(QString gameFilename)
{

    QFile file(gameFilename);
    qDebug() << file << " -game";
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        QTextStream fin(&file);
        int tmp;
        fin >> tmp;
        gridSize.setHeight(tmp);
        fin >> tmp;
        gridSize.setWidth(tmp);
        recalcSizeFac();

        fin >> tmp; //n of dots
        qDebug() << tmp;
        for(int i = 0; i < tmp; i++)
        {
            int x, y, type;
            fin >> type >> x >> y;
            if(type == 0)

            if(type == 1)
            {
                int x2, y2;
                fin >> x2 >> y2;
                addLine((x+xshift)*sizeFactor, this->sz->height() - (y+yshift)*sizeFactor, (x2+xshift)*sizeFactor, sz->height() - (y2+yshift)*sizeFactor);
            }
        }
    }
    file.close();
}

void Field::saveToFile()
{

    QFile file(filename);
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream fout(&file);
        fout << gridSize.height() << " " << gridSize.width() << endl;
        fout << dotCount() << endl;
        for(auto i : group_figure->childItems())
        {
            QGraphicsEllipseItem* dot = dynamic_cast<QGraphicsEllipseItem *>(i);
            QGraphicsLineItem* line = dynamic_cast<QGraphicsLineItem *>(i);
            if(dot)
            {
                fout << "0 " << round(dot->pos().rx()/sizeFactor - xshift) << " " << round((mxGridSize.height()*sizeFactor/2 - dot->pos().y())/sizeFactor - yshift) << endl;
            }
            if(line)
            {
                fout << "1 " << round(line->pos().rx()/sizeFactor - xshift) << " " << round((mxGridSize.height()*sizeFactor/2 - line->pos().y())/sizeFactor - yshift);
                fout << " " << round((round(line->pos().rx() - xshift*sizeFactor)+line->line().p2().x())/sizeFactor) << " " << round((round((mxGridSize.height()*sizeFactor/2 - line->pos().y()) - yshift*sizeFactor) - line->line().p2().y())/sizeFactor) << endl;
            }
        }
    }
    file.close();
}

void Field::save()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Сохранить чертеж"), QDir::homePath(), tr("Файл Чертежа (*.cbf)"));
    if(fileName == "")
    {
        QMessageBox::warning(this, tr("Внимание!"),
                                       tr("Файл не выбран!"),
                                       QMessageBox::Ok);
    }
    else
    {
        filename = fileName;
        if(filename.right(4) != ".cbf")
        {
            filename += ".cbf";
        }
        saveToFile();
        renameRootWindow();
    }
}

int rclkx = 0;
int rclky = 0;
bool lineFlag = 0;

int f_rounded(int n, int to)
{
    return round(1.0*n/to)*to;
}



void Field::mouseMoveEvent(QMouseEvent *e)
{

    if(showingCoord)
        redrawCoord(e->localPos().x(),e->localPos().y());
    else
    {
        hideCoord();
    }


    if(lineFlag)
    {
        QPointF lpos = e->localPos(); //
        int x = f_rounded(lpos.x(),sizeFactor);
        int y = f_rounded(lpos.y(),sizeFactor);

        if(x <= gridSize.width()*sizeFactor && x >=0 && y <= gridSize.height()*sizeFactor && y >=0)
        {
            this->nlinepos(rclkx,rclky,f_rounded(lpos.x(),sizeFactor),f_rounded(lpos.y(),sizeFactor));
            this->redrawCross(x/sizeFactor, y/sizeFactor);
        }
    }

   if(e->buttons() & Qt::RightButton)
   {
        if(e->pos() != last_mPos)
        {
            QPointF dir = QPointF(e->pos().x() - last_mPos.x(), e->pos().y() - last_mPos.y());
            if(dir.x() + gridSize.width()/sizeFactor > gridSize.width()/sizeFactor)
                xshift += gridSize.width()/sizeFactor/5;
            else
            {
                if(-dir.x() - gridSize.width()/sizeFactor > gridSize.width()/sizeFactor)
                    xshift -= gridSize.width()/sizeFactor/5;
            }

            if(dir.y() + gridSize.height()/sizeFactor > gridSize.height()/sizeFactor)
                yshift -= gridSize.height()/sizeFactor/5;
            else
            {
                if(-dir.y() - gridSize.height()/sizeFactor > gridSize.height()/sizeFactor)
                    yshift += gridSize.height()/sizeFactor/5;
            }
            if(xshift > mxXshift) xshift = mxXshift;
            if(xshift < -mxXshift) xshift = -mxXshift;

            if(xshift > mxYshift) xshift = mxYshift;
            if(xshift < -mxYshift) xshift = -mxYshift;
            qDebug() << "pos: " << xshift << " | " << yshift;
            recalcSizeFac();
            last_mPos = e->pos();
        }
   }
}

void Field::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::RightButton)
    {
        last_mPos = e->pos();
    }
    int x;
    int y;
    QPointF lpos = e->localPos();
    if(e->button() == Qt::LeftButton)
    {
        x = f_rounded(lpos.x(),sizeFactor);
        y = f_rounded(lpos.y(),sizeFactor);

        this->redrawCross(x/sizeFactor + xshift, y/sizeFactor + yshift);
        lineFlag = 0;
    }




    if(!lineFlag)
    {
        if(e->button() == Qt::LeftButton)
        {
            rclkx = f_rounded(lpos.x(),sizeFactor);
            rclky = f_rounded(lpos.y(),sizeFactor);
            lineFlag = 1;
        }
    }
    else
    {
        this->nlinepos(rclkx,rclky,f_rounded(lpos.x(),sizeFactor),f_rounded(lpos.y(),sizeFactor));
    }
}

void Field::mouseReleaseEvent(QMouseEvent *e)
{
   if(e->button() == Qt::LeftButton)
   {
    if(lineFlag)
    {
        lineFlag = 0;
        if(newLine)
        {
            QPointF p1 = newLine->line().p1();
            QPointF p2 = newLine->line().p2();


            qDebug() << p1 << " " << p2;
            if(abs(p1.x() - p2.x()) > 0.35 || abs(p1.y() - p2.y()) > 0.35)
            {
                qDebug() << abs(p1.x() - p2.y()) << " " << abs(p1.y() - p2.y());
            addLine(p1.x(),p1.y(),p2.x(),p2.y());

            addDot(p1.x(),p1.y());
            addDot(p2.x(),p2.y());
            }
            else
            {
                addDot(p1.x(),p1.y());
            }
        }
        else
        {
            this->addDot(f_rounded(rclkx,sizeFactor),f_rounded(rclky,sizeFactor));
        }
    }

    if(newLine)
    {
        scene->removeItem(newLine);
        newLine = nullptr;
    }
   }
}



void Field::wheelEvent(QWheelEvent *e)
{
//    if(e->delta() < 0 && gridSize.height() < 50)
//    {
//        gridSize.setHeight(gridSize.height()+1);
//        gridSize.setWidth(gridSize.width()+1);
//    }
//    if(e->delta() > 0 && gridSize.height() > 1)
//    {
//        gridSize.setHeight(gridSize.height()-1);
//        gridSize.setWidth(gridSize.width()-1);
//    }
//    recalcSizeFac();
}

void Field::recalcSizeFac()
{
    this->oldSizeFactor = this->sizeFactor;
    this->sizeFactor = round(1.0 * sz->height()/ gridSize.height());

    qDebug() << gridSize << " " << xshift << yshift;
    resized();
    redrawGrid();
    recalcDots();
    redrawDots();
    redrawGrid();

}

double Field::getSizeFactor()
{
    return sizeFactor;
}

QString Field::getFilename()
{
    return filename;
}

void Field::recalcDots()
{
    group_figure_tmp = new QGraphicsItemGroup();
    scene->addItem(group_figure_tmp);
    for(auto i : group_figure->childItems())
    {
        QGraphicsEllipseItem* dot = dynamic_cast<QGraphicsEllipseItem *>(i);
        QGraphicsLineItem* line = dynamic_cast<QGraphicsLineItem *>(i);
        qDebug() << i->pos();
        double x1, y1;
        if(dot)
        {
            x1 = round((1.0*dot->pos().x() / oldSizeFactor) - oldxshift) * sizeFactor;
            y1 = round((1.0*dot->pos().y() / oldSizeFactor) + oldyshift) * sizeFactor;
            //qDebug() << dot->pos().y() << " " << round(1.0*dot->pos().y() / oldSizeFactor * sizeFactor);
            group_figure_tmp->addToGroup(scene->addEllipse(-5, -5, 5+sizeFactor/4, 5+sizeFactor/4, dotPen, dotBrush));
            group_figure_tmp->childItems().last()->setPos(x1 + xshift*sizeFactor, y1 - yshift*sizeFactor);
        }
        if(line)
        {
            double x2, y2;
            x1 = round((1.0*line->pos().x() / oldSizeFactor) - oldxshift) * sizeFactor;
            y1 = round((1.0*line->pos().y() / oldSizeFactor) + oldyshift) * sizeFactor;
            x2 = round(1.0*line->line().p2().x() / oldSizeFactor * sizeFactor);
            y2 = round(1.0*line->line().p2().y() / oldSizeFactor * sizeFactor);
            group_figure_tmp->addToGroup(scene->addLine(0, 0, x2, y2, dotLinePen));
            group_figure_tmp->childItems().last()->setPos(x1 + xshift*sizeFactor, y1 - yshift*sizeFactor);
            qDebug() << i << " | " << x1 << " " << y1 << ", " << x2 << " " << y2;
        }

        scene->removeItem(i);
    }

    group_figure = new QGraphicsItemGroup();
    scene->addItem(group_figure);

    scene->addItem(group_figure);
    for(auto i : group_figure_tmp->childItems())
    {
        QGraphicsEllipseItem* dot = dynamic_cast<QGraphicsEllipseItem *>(i);
        QGraphicsLineItem* line = dynamic_cast<QGraphicsLineItem *>(i);
        if(dot)
        {
            group_figure->addToGroup(scene->addEllipse(-5, -5, 10, 10, dotPen, dotBrush));
        }
        if(line)
        {
            group_figure->addToGroup(scene->addLine(0, 0, line->line().x2(), line->line().y2(), dotLinePen));
        }
        group_figure->childItems().last()->setPos(i->pos());
        scene->removeItem(i);
    }
    oldxshift = xshift;
    oldyshift = yshift;
}
