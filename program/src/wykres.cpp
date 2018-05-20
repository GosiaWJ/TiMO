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
    this->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom); // this will also allow rescaling the color scale by dragging/zooming
    this->axisRect()->setupFullAxesBox(true);
    this->xAxis->setLabel("x1");
    this->yAxis->setLabel("x2");

    colorMap = new QCPColorMap(this->xAxis, this->yAxis);
    constrainsMap=new QCPColorMap(this->xAxis, this->yAxis);
    QCPColorGradient Gradient1;
    Gradient1.clearColorStops();
    Gradient1.setColorStopAt(1, QColor(0,0,0,60));
    Gradient1.setColorStopAt(0, QColor(0,0,0,00));
    Gradient1.setLevelCount(2);
    constrainsMap->setGradient(Gradient1);

    colorScale = new QCPColorScale(this);
    if(this->plotLayout()->hasElement(0,1)) this->plotLayout()->remove(this->plotLayout()->element(0,1));
    this->plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect
    colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
    colorMap->setColorScale(colorScale); // associate the color map with the color scale
    colorScale->axis()->setLabel("Wartosc funkcji");
    colorMap->setGradient(QCPColorGradient::gpJet);
    colorMap->colorScale()->setRangeZoom(true);


    QCPMarginGroup *marginGroup = new QCPMarginGroup(this);
    this->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);

   this->addGraph(this->xAxis, this->yAxis);
   this->graph(0)->setPen(QPen(QColor(255, 100, 0)));
   this->graph(0)->setBrush(QBrush(QPixmap("./balboa.jpg"))); // fill with texture of specified image
   this->graph(0)->setLineStyle(QCPGraph::lsLine);
   this->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));

  // this->rescaleAxes();
}
/*!
 * \brief Wykres::plot - rysuje dane na wykresie
 * \param qv_x - wektor czasu
 * \param qv_enc -wektor danych z enkodera
 */

void Wykres::plot( QVector<double> x_1, QVector<double> x_2 ,double x_l, double x_p, double y_d, double y_g)
{

    Parser parser;
    // configure axis rect:


   /* double x_l=x_1.first();
    double x_p=x_1.first();
    double y_d=x_2.first();
    double y_g=x_2.first();

    for(int i=0;i<x_1.size();i++) x_l=min(x_l,x_1.at(i));
    for(int i=0;i<x_1.size();i++) x_p=max(x_p,x_1.at(i));
    for(int i=0;i<x_2.size();i++) y_d=min(y_d,x_2.at(i));
    for(int i=0;i<x_2.size();i++) y_g=max(y_g,x_2.at(i));
    double roznica1=abs(x_p-x_l);
    x_l=x_l-0.15*roznica1;
    x_p=x_p+0.15*roznica1;
    double roznica2=abs(y_g-y_d);
    y_d=y_d-0.15*roznica2;
    y_g=y_g+0.15*roznica2;*/
    this->xAxis->setRange(x_l, x_p);
    this->yAxis->setRange(y_d,y_g);

   // cout<<x_l<<" "<<x_p<<" "<<y_d<<" "<<y_g<<endl;
    // set up the QCPColorMap:
    if(colorMap->data()->isEmpty()) colorMap->data()->clear();

    int nx = 300;
    int ny = 300;
    colorMap->data()->setSize(nx, ny); // we want the color map to have nx * ny data points
    colorMap->data()->setRange(QCPRange(x_l,x_p), QCPRange(y_d,y_g)); // and span the coordinate range -4..4 in both key (x) and value (y) dimensions

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
    colorMap->data()->recalculateDataBounds();
    colorMap->rescaleDataRange();

if(ilosc_ograniczen>0){

    constrainsMap->data()->setSize(nx, ny); // we want the color map to have nx * ny data points
    constrainsMap->data()->setRange(QCPRange(x_l,x_p), QCPRange(y_d,y_g));

    for (int xIndex=0; xIndex<nx; ++xIndex)
    {
      for (int yIndex=0; yIndex<ny; ++yIndex)
      {
        int ogr=0;
        for(int i=0;i<ilosc_ograniczen;i++) {
            parser.SetExpr(ograniczenia[i].toStdString());
            double wartosc=parser.Eval();
            if(wartosc<=0) ogr+=1;
        }
        constrainsMap->data()->cellToCoord(xIndex, yIndex, &x, &y);
        if(ogr==ilosc_ograniczen) z=0;
        else z=1;
        constrainsMap->data()->setCell(xIndex, yIndex, z);
      }
    }
    constrainsMap->rescaleDataRange();
}


    //plotting points

    this->graph(0)->setData(x_1,x_2,true);

    this->xAxis->setRange(x_l,x_p);
    this->yAxis->setRange(y_d,y_g);

    this->replot();
    this->update();

}
void Wykres::setFunction(const QString fun)
{
    funkcja_celu=new QString(fun);

}
void Wykres::setConstr(QString *Constr_tab, int ilosc)
{
    ilosc_ograniczen=ilosc;
    ograniczenia=new QString[ilosc];
    for(int i=0;i<ilosc;i++){
    ograniczenia[i]=QString(Constr_tab[i]);
    }
}
