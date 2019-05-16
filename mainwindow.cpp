#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsView"
#include "QMessageBox"

int rounded(int n, int to)
{
    return round(1.0*n/to)*to;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Координатная Плоскость");
    connect(ui->graphicsView,SIGNAL(resized()), this, SLOT(subwindowResized()));

    openMenu = new QMenu("Открыть для...");
    QAction* openAsDraw = new QAction("Построение");
    QAction* openAsEdit = new QAction("Редактирование");
    connect(openAsEdit, SIGNAL(triggered()), ui->graphicsView, SLOT(load()));
    connect(openAsEdit, SIGNAL(triggered()), ui->graphicsView, SLOT(game()));
    openMenu->addAction(openAsDraw);
    openMenu->addAction(openAsEdit);
    ui->openBtn->setMenu(openMenu);


    connect(this, SIGNAL(ui->graphicsView->renameRootWindow()), SLOT(this->renameWindow("Координатная плоскость - " + ui->graphicsView->getFilename()))); //updating header name
    ui->graphicsView->setShift(0,0);
    ui->graphicsView->gridSize = this->gridSize;
    ui->graphicsView->mnGridSize = this->mnGridSize;
    ui->graphicsView->mxGridSize = this->mxGridSize;
    ui->graphicsView->recalcSizeFac();

    ui->xScroll->setValue(ui->xScroll->maximum()/2);
    ui->yScroll->setValue(ui->yScroll->maximum()/2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// // // // // // // // // // // // //
// //                            // //
// //  UI - SLIDERS & BUTTONS    // //
// //                            // //
// // // // // // // // // // // // //

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    this->x = ui->horizontalSlider->value()*sizeFactor;
    this->updateCoord(ui->horizontalSlider->value(),ui->verticalSlider->value());
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    this->y = ui->verticalSlider->value()*sizeFactor;
    this->updateCoord(ui->horizontalSlider->value(),ui->verticalSlider->value());
}

void MainWindow::on_xSpin_valueChanged(int arg1) // horiz (X) textbox
{
    this->x = ui->xSpin->value()*sizeFactor;
    this->updateCoord(ui->xSpin->value(),ui->ySpin->value());
}

void MainWindow::on_ySpin_valueChanged(int arg1) // vertic (Y) textbox
{
    this->y = ui->ySpin->value()*sizeFactor;
    this->updateCoord(ui->xSpin->value(),ui->ySpin->value());
}


void MainWindow::on_addDotBtn_clicked()
{
    ui->graphicsView->addDot(round((x)/sizeFactor)*sizeFactor,round((gridSize.height()*sizeFactor - y)/sizeFactor)*sizeFactor);
    this->updateLastCoord(x/sizeFactor,y/sizeFactor);
}



void MainWindow::updateCoord(int x, int y)
{
    ui->horizontalSlider->setValue(x);
    ui->verticalSlider->setValue(y);

    ui->xSpin->setValue(x);
    ui->ySpin->setValue(y);

    ui->graphicsView->redrawCross(x, gridSize.height() - y);
}

void MainWindow::updateLastCoord(int x, int y)
{
    ui->CursorPos->setText("Последняя точка:\nX=" + QString::number(x) + ", Y=" + QString::number(y));
}

// // // // // // // // // // // // //
// //                            // //
// //     UI - MOUSE EVENTS      // //
// //                            // //
// // // // // // // // // // // // //

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    int offx = ui->graphicsView->pos().x(); // offset from top left corner
    int offy = ui->graphicsView->pos().y(); //
    QPointF lpos = e->localPos();
    if(e->button() == Qt::LeftButton && lpos.x() > offx && lpos.x() <= gridSize.height()*sizeFactor + offx && lpos.y() > offy && lpos.y() <= gridSize.width()*sizeFactor + offy) //if clicked on field obj
    {
        this->x = round((lpos.x())/sizeFactor-offx/sizeFactor)*sizeFactor;
        this->y = gridSize.height() -  round((lpos.y()-offy)/sizeFactor)*sizeFactor;
        ui->graphicsView->addDot(round((lpos.x()-offx)/sizeFactor)*sizeFactor,round((lpos.y()-offy)/sizeFactor)*sizeFactor);

    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->modifiers() & Qt::Modifier::CTRL)
    {
        if(e->key() == Qt::Key_Z)
            ui->graphicsView->undo();

        if(e->key() == Qt::Key_S)
            ui->graphicsView->save();

        if(e->key() == Qt::Key_O)
            ui->graphicsView->load();

        if(e->key() == Qt::Key_N)
        {
            if(QMessageBox::Yes == QMessageBox(QMessageBox::Information, "Внимание!!!", "Вы хотите очистить поле?", QMessageBox::Yes|QMessageBox::No).exec())
            {
                ui->graphicsView->clearDots();
                ui->CursorPos->setText("Точки не заданы");
            }
        }
    }
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
    double reszFac = e->size().height()/e->oldSize().height();
    QResizeEvent ne = *e;
    ne.size().scaled(ui->graphicsView->size().width()*reszFac,ui->graphicsView->size().height()*reszFac, Qt::KeepAspectRatio);
    ne.size().scaled(std::min(ne.size().width()/reszFac, ne.size().height()/reszFac), std::min(ne.size().width()/reszFac, ne.size().height()/reszFac), Qt::KeepAspectRatio);
    ui->root->resize(e->size());
    ui->top_frame->resize(e->size().width(),ui->top_frame->height());
    //ui->graphicsView->resizeEvent(&ne);
}

void MainWindow::subwindowResized()
{
    ui->xScroll->setMaximum((50 - ui->graphicsView->size().width() / ui->graphicsView->getSizeFactor())*10);
    ui->yScroll->setMaximum((50 - ui->graphicsView->size().height() / ui->graphicsView->getSizeFactor())*10);
}

void MainWindow::renameWindow(QString newName)
{
    this->setWindowTitle(newName);
}


// // // // // // // // // // // // //
// //                            // //
// //        UI - COLORS         // //
// //                            // //
// // // // // // // // // // // // //

QColor MainWindow::colorPick()
{
    QColorDialog pick;
    return pick.getColor();
}

void MainWindow::on_dotColorBtn_clicked()
{
    ui->graphicsView->setDotColor(this->colorPick());
}


void MainWindow::on_gridColorBtn_clicked()
{
    ui->graphicsView->setGridColor(this->colorPick());
}

void MainWindow::on_dotLineColorBtn_clicked()
{
    ui->graphicsView->setDotLineColor(this->colorPick());
}

void MainWindow::on_gridMainColrBtn_clicked()
{
    ui->graphicsView->setGridMainColor(this->colorPick());
}

// // // // // // // // // // // // //
// //                            // //
// //     UI - CLEAR & UNDO      // //
// //                            // //
// // // // // // // // // // // // //

void MainWindow::on_clearButton_clicked()
{
    if(QMessageBox::Yes == QMessageBox(QMessageBox::Information, "Внимание!!!", "Вы хотите очистить поле?", QMessageBox::No|QMessageBox::Yes).exec())
    {
        ui->graphicsView->clearDots();
        ui->CursorPos->setText("Точки не заданы");
    }
}

void MainWindow::on_clearButton_2_clicked() //undo
{
    int offx = ui->graphicsView->pos().x(); // offset from top left corner
    int offy = ui->graphicsView->pos().y(); //
    if(ui->graphicsView->dotCount() >= 1)
    {
        ui->graphicsView->undo();
        if(ui->graphicsView->dotCount() >= 1)
        {
            QPointF pos = QPointF((ui->graphicsView->getLastDot()->pos().x())/sizeFactor,(ui->graphicsView->getLastDot()->pos().y())/sizeFactor);
            qDebug() << pos;
            this->updateCoord(pos.x(),gridSize.height() - pos.y());
        }
        else
        {
            ui->CursorPos->setText("Точки не заданы");
        }
    }

}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == Qt::CheckState::Checked)
    {
        ui->graphicsView->showLines();
    }
    if(arg1 == Qt::CheckState::Unchecked)
    {
        ui->graphicsView->hideLines();
    }
}

void MainWindow::on_aim_Checkbox_stateChanged(int arg1)
{
    if(arg1 == Qt::CheckState::Checked)
    {
        ui->graphicsView->showCross(x/sizeFactor, gridSize.height() - y/sizeFactor);
    }
    if(arg1 == Qt::CheckState::Unchecked)
    {
        ui->graphicsView->hideCross();
    }
}

void MainWindow::on_openBtn_clicked()
{
    ui->graphicsView->load();
}

void MainWindow::on_saveBtn_clicked()
{
    ui->graphicsView->save();
}

void MainWindow::on_exitBtn_clicked()
{
    ui->graphicsView->exit();
}

void MainWindow::on_infoBtn_clicked()
{
    QMessageBox::information(this, tr("Помощь"),
                                   tr(" Чтобы установить точку воспользуйтесь левой кнопкой мыши либо ползунками/полями ввода (в этом случае точка устанавливается соответсвующей кнопкой).\n\n"
                                      " Чтобы начертить линию воспользуйтесь правой кнопкой мыши (нажать и удерживать).\n\n"
                                      " Для сохранения/загрузки чертежа используются соответствующие кнопки\n\n"
                                      " Для изменения цветов и изменения дополнительных параметров используется вкладка \"настройки\"."),
                                   QMessageBox::Ok);
}

void MainWindow::on_aim_Checkbox_3_stateChanged(int arg1)
{
    if(arg1 == Qt::CheckState::Checked)
    {
        ui->graphicsView->showingCoord = 1;
    }
    if(arg1 == Qt::CheckState::Unchecked)
    {
        ui->graphicsView->showingCoord = 0;
    }
}

void MainWindow::on_xScroll_valueChanged(int value)
{
    xshift = gridSize.width()-value/10;
    ui->graphicsView->setShift(xshift,yshift);
    ui->graphicsView->recalcSizeFac();
}

void MainWindow::on_yScroll_valueChanged(int value)
{
    yshift = value/10-1;
    ui->graphicsView->setShift(xshift,yshift);
    ui->graphicsView->recalcSizeFac();
}
