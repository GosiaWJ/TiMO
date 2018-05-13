#include "wykres.hh"
#include<iostream>
#include <muParser.h>
#include<QVector>
using namespace mu;
using namespace std;
/*!
 * \brief Wykres::Wykres - konstruktor klasy wykres
 * \param parent
 */

Wykres::Wykres(QWidget *parent): QCustomPlot(parent)
{
   colorMap = new QCPColorMap(this->xAxis, this->yAxis);
    this->addGraph(this->xAxis, this->yAxis);
   this->graph(0)->setPen(QPen(QColor(255, 100, 0)));
   this->graph(0)->setBrush(QBrush(QPixmap("./balboa.jpg"))); // fill with texture of specified image
   this->graph(0)->setLineStyle(QCPGraph::lsLine);
   this->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));


}
/*!
 * \brief Wykres::plot - rysuje dane na wykresie
 * \param qv_x - wektor czasu
 * \param qv_enc -wektor danych z enkodera
 */

void Wykres::plot(double *p_s, double *wynik, QVector<double> x_1, QVector<double> x_2 )
{
    Parser parser;
    // configure axis rect:
    this->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom); // this will also allow rescaling the color scale by dragging/zooming
    this->axisRect()->setupFullAxesBox(true);
    this->xAxis->setLabel("x1");
    this->yAxis->setLabel("x2");
    double x_l, x_p, y_d, y_g;
    x_l=min(x_1.first(),x_1.at(x_1.size()-1))-0.15*abs(x_1.first()-x_1.at(x_1.size()-1));
    x_p= max(x_1.first(),x_1.at(x_1.size()-1))+0.15*abs(x_1.first()-x_1.at(x_1.size()-1));
    y_d=min(x_2.first(),x_2.at(x_2.size()-1))-0.15*abs(x_2.first()-x_2.at(x_2.size()-1));
    y_g= max(x_2.first(),x_2.at(x_2.size()-1))+0.15*abs(x_2.first()-x_2.at(x_2.size()-1));
    this->xAxis->setRange(x_l, x_p);
    this->yAxis->setRange(y_d,y_g);

    cout<<x_l<<" "<<x_p<<" "<<y_d<<" "<<y_g<<endl;
    // set up the QCPColorMap:
    int nx = 200;
    int ny = 200;
    colorMap->data()->setSize(nx, ny); // we want the color map to have nx * ny data points
    colorMap->data()->setRange(QCPRange(x_l, x_p), QCPRange(y_d, y_g)); // and span the coordinate range -4..4 in both key (x) and value (y) dimensions
    // now we assign some data, by accessing the QCPColorMapData instance of the color map:
    double x, y, z;
    parser.DefineVar("x1", &x);
    parser.DefineVar("x2", &y);
    parser.SetExpr(funkcja_celu->toStdString());
    for (int xIndex=0; xIndex<nx; ++xIndex)
    {
      for (int yIndex=0; yIndex<ny; ++yIndex)
      {
        colorMap->data()->cellToCoord(xIndex, yIndex, &x, &y);
        z = parser.Eval(); // the B field strength of dipole radiation (modulo physical constants)
        colorMap->data()->setCell(xIndex, yIndex, z);
      }
    }

    // add a color scale:
    QCPColorScale *colorScale = new QCPColorScale(this);
    if(this->plotLayout()->hasElement(0,1)) this->plotLayout()->remove(this->plotLayout()->element(0,1));
    this->plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect
    colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
    colorMap->setColorScale(colorScale); // associate the color map with the color scale
    colorScale->axis()->setLabel("Wartosc funkcji");

    // set the color gradient of the color map to one of the presets:
    colorMap->setGradient(QCPColorGradient::gpPolar);
    // we could have also created a QCPColorGradient instance and added own colors to
    // the gradient, see the documentation of QCPColorGradient for what's possible.

    // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:
    colorMap->rescaleDataRange();

    // make sure the axis rect and color scale synchronize their bottom and top margins (so they line up):
    QCPMarginGroup *marginGroup = new QCPMarginGroup(this);
    this->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
   // this->rescaleAxes();

   /* for (int i=0; i<x_2.size(); i++) {
    cout<<"wy_x"<<i<<"="<<x_1.at(i)<<" "<<x_2.at(i)<<" "<<endl;
    }
    cout<<endl;*/
    //plotting points

    this->graph(0)->clearData();
    this->graph(0)->addData(x_1,x_2);

    this->replot();
    this->update();

}
void Wykres::setFunction(const QString fun)
{
    funkcja_celu=new QString(fun);

}
