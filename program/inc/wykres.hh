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
    QCPColorMap *constrainsMap;
    QCPColorScale *colorScale;
    QString *ograniczenia;
    int ilosc_ograniczen=0;


public:
    Wykres(QWidget *parent);

    void setFunction(const QString fun);
    void setConstr(QString *Constr_tab, int ilosc);
public slots:
    void plot( QVector<double> x_1, QVector<double> x_2 ,double x_l, double x_p, double y_d, double y_g);


};

#endif // WYKRES_HH
