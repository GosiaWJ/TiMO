#ifndef WYKRES_HH
#define WYKRES_HH
#include<qcustomplot.h>

#include <QWidget>
#include<QString>
#include<QVector>

/*!
 * \brief Widget sluzacy do rysowania wykresow na postawie danych wczytanych z wektorów.
 *
 * Dziedziczy po QCustomPlot
 */
class Wykres:public QCustomPlot
{
    Q_OBJECT
    QString *funkcja_celu;
    QCPColorMap *colorMap;
public:
    Wykres(QWidget *parent);

    void setFunction(const QString fun);
public slots:
    void plot(double *p_s, double *wynik, QVector<double> x_1, QVector<double> x_2);


};

#endif // WYKRES_HH
