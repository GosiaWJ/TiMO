#ifndef WYKRES_HH
#define WYKRES_HH
#include<qcustomplot.h>

#include <QWidget>

/*!
 * \brief Widget sluzacy do rysowania wykresow na postawie danych wczytanych z wektorów.
 *
 * Dziedziczy po QCustomPlot
 */
class Wykres:public QCustomPlot
{
    Q_OBJECT
public:
    Wykres(QWidget *parent);

public slots:
    void plot(QVector<double> qv_x, QVector<double> qv_enc);


};

#endif // WYKRES_HH
