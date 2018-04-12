#include "wykres.hh"
#include<iostream>
using namespace std;
/*!
 * \brief Wykres::Wykres - konstruktor klasy wykres
 * \param parent
 */

Wykres::Wykres(QWidget *parent): QCustomPlot(parent)
{
    this->addGraph();
    this->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    this->graph(0)->setLineStyle(QCPGraph::lsNone);
    this->graph(0)->keyAxis()->setLabel("time [s]");
    this->graph(0)->valueAxis()->setLabel("velocity [%]");
}
/*!
 * \brief Wykres::plot - rysuje dane na wykresie
 * \param qv_x - wektor czasu
 * \param qv_enc -wektor danych z enkodera
 */

void Wykres::plot(QVector<double> qv_x, QVector<double> qv_enc)
{
    this->graph(0)->setData(qv_x,qv_enc);
    this->graph(0)->rescaleAxes(true);
    this->replot();
    this->update();

}
