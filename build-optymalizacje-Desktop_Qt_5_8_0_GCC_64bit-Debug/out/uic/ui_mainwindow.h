/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "wykres.hh"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *funkcja_celu_label;
    QComboBox *funkcja_celu_box;
    QHBoxLayout *horizontalLayout_9;
    QLabel *ilosc_zmiennych_label;
    QSpinBox *ilosc_zmiennych_spinbox;
    QSpacerItem *verticalSpacer_2;
    QLabel *ograniczenia_label;
    QHBoxLayout *horizontalLayout_8;
    QListWidget *lista_ograniczen;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *ograniczenie;
    QPushButton *dodaj_ograniczenie;
    QPushButton *usun_ograniczenie;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *epsilon0_label;
    QSpinBox *epsilon0_spinbox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *epsilon1_label;
    QSpinBox *epsilon1_spinbox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *epsilon2_label;
    QSpinBox *epsilon2_spinbox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *l_label;
    QLineEdit *l_edit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *punkt_startowy_label;
    QLineEdit *x_10;
    QLineEdit *x_20;
    QLineEdit *x_30;
    QLineEdit *x_40;
    QLineEdit *x_50;
    QPushButton *oblicz;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    Wykres *wykres;
    QListWidget *wyniki;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(924, 639);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_10 = new QHBoxLayout(centralWidget);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        funkcja_celu_label = new QLabel(centralWidget);
        funkcja_celu_label->setObjectName(QStringLiteral("funkcja_celu_label"));

        horizontalLayout->addWidget(funkcja_celu_label);

        funkcja_celu_box = new QComboBox(centralWidget);
        funkcja_celu_box->setObjectName(QStringLiteral("funkcja_celu_box"));
        funkcja_celu_box->setEditable(true);

        horizontalLayout->addWidget(funkcja_celu_box);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        ilosc_zmiennych_label = new QLabel(centralWidget);
        ilosc_zmiennych_label->setObjectName(QStringLiteral("ilosc_zmiennych_label"));

        horizontalLayout_9->addWidget(ilosc_zmiennych_label);

        ilosc_zmiennych_spinbox = new QSpinBox(centralWidget);
        ilosc_zmiennych_spinbox->setObjectName(QStringLiteral("ilosc_zmiennych_spinbox"));
        ilosc_zmiennych_spinbox->setMinimum(1);
        ilosc_zmiennych_spinbox->setMaximum(5);

        horizontalLayout_9->addWidget(ilosc_zmiennych_spinbox);


        verticalLayout_3->addLayout(horizontalLayout_9);

        verticalSpacer_2 = new QSpacerItem(18, 18, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer_2);

        ograniczenia_label = new QLabel(centralWidget);
        ograniczenia_label->setObjectName(QStringLiteral("ograniczenia_label"));

        verticalLayout_3->addWidget(ograniczenia_label);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        lista_ograniczen = new QListWidget(centralWidget);
        lista_ograniczen->setObjectName(QStringLiteral("lista_ograniczen"));

        horizontalLayout_8->addWidget(lista_ograniczen);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_8->addWidget(label);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ograniczenie = new QLineEdit(centralWidget);
        ograniczenie->setObjectName(QStringLiteral("ograniczenie"));

        horizontalLayout_2->addWidget(ograniczenie);

        dodaj_ograniczenie = new QPushButton(centralWidget);
        dodaj_ograniczenie->setObjectName(QStringLiteral("dodaj_ograniczenie"));

        horizontalLayout_2->addWidget(dodaj_ograniczenie);

        usun_ograniczenie = new QPushButton(centralWidget);
        usun_ograniczenie->setObjectName(QStringLiteral("usun_ograniczenie"));

        horizontalLayout_2->addWidget(usun_ograniczenie);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(391, 13, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        epsilon0_label = new QLabel(centralWidget);
        epsilon0_label->setObjectName(QStringLiteral("epsilon0_label"));

        horizontalLayout_3->addWidget(epsilon0_label);

        epsilon0_spinbox = new QSpinBox(centralWidget);
        epsilon0_spinbox->setObjectName(QStringLiteral("epsilon0_spinbox"));
        epsilon0_spinbox->setMinimum(-12);
        epsilon0_spinbox->setMaximum(-3);

        horizontalLayout_3->addWidget(epsilon0_spinbox);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        epsilon1_label = new QLabel(centralWidget);
        epsilon1_label->setObjectName(QStringLiteral("epsilon1_label"));

        horizontalLayout_4->addWidget(epsilon1_label);

        epsilon1_spinbox = new QSpinBox(centralWidget);
        epsilon1_spinbox->setObjectName(QStringLiteral("epsilon1_spinbox"));
        epsilon1_spinbox->setMinimum(-12);
        epsilon1_spinbox->setMaximum(-3);

        horizontalLayout_4->addWidget(epsilon1_spinbox);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        epsilon2_label = new QLabel(centralWidget);
        epsilon2_label->setObjectName(QStringLiteral("epsilon2_label"));

        horizontalLayout_5->addWidget(epsilon2_label);

        epsilon2_spinbox = new QSpinBox(centralWidget);
        epsilon2_spinbox->setObjectName(QStringLiteral("epsilon2_spinbox"));
        epsilon2_spinbox->setMinimum(-12);
        epsilon2_spinbox->setMaximum(-3);

        horizontalLayout_5->addWidget(epsilon2_spinbox);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        l_label = new QLabel(centralWidget);
        l_label->setObjectName(QStringLiteral("l_label"));

        horizontalLayout_6->addWidget(l_label);

        l_edit = new QLineEdit(centralWidget);
        l_edit->setObjectName(QStringLiteral("l_edit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(l_edit->sizePolicy().hasHeightForWidth());
        l_edit->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(l_edit);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        punkt_startowy_label = new QLabel(centralWidget);
        punkt_startowy_label->setObjectName(QStringLiteral("punkt_startowy_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(punkt_startowy_label->sizePolicy().hasHeightForWidth());
        punkt_startowy_label->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(punkt_startowy_label);

        x_10 = new QLineEdit(centralWidget);
        x_10->setObjectName(QStringLiteral("x_10"));
        x_10->setEnabled(true);
        sizePolicy1.setHeightForWidth(x_10->sizePolicy().hasHeightForWidth());
        x_10->setSizePolicy(sizePolicy1);
        x_10->setMaximumSize(QSize(35, 25));

        horizontalLayout_7->addWidget(x_10);

        x_20 = new QLineEdit(centralWidget);
        x_20->setObjectName(QStringLiteral("x_20"));
        sizePolicy1.setHeightForWidth(x_20->sizePolicy().hasHeightForWidth());
        x_20->setSizePolicy(sizePolicy1);
        x_20->setMaximumSize(QSize(35, 25));

        horizontalLayout_7->addWidget(x_20);

        x_30 = new QLineEdit(centralWidget);
        x_30->setObjectName(QStringLiteral("x_30"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(x_30->sizePolicy().hasHeightForWidth());
        x_30->setSizePolicy(sizePolicy2);
        x_30->setMaximumSize(QSize(35, 25));

        horizontalLayout_7->addWidget(x_30);

        x_40 = new QLineEdit(centralWidget);
        x_40->setObjectName(QStringLiteral("x_40"));
        sizePolicy1.setHeightForWidth(x_40->sizePolicy().hasHeightForWidth());
        x_40->setSizePolicy(sizePolicy1);
        x_40->setMaximumSize(QSize(35, 25));

        horizontalLayout_7->addWidget(x_40);

        x_50 = new QLineEdit(centralWidget);
        x_50->setObjectName(QStringLiteral("x_50"));
        sizePolicy1.setHeightForWidth(x_50->sizePolicy().hasHeightForWidth());
        x_50->setSizePolicy(sizePolicy1);
        x_50->setMaximumSize(QSize(35, 25));

        horizontalLayout_7->addWidget(x_50);


        verticalLayout_3->addLayout(horizontalLayout_7);

        oblicz = new QPushButton(centralWidget);
        oblicz->setObjectName(QStringLiteral("oblicz"));

        verticalLayout_3->addWidget(oblicz);


        horizontalLayout_10->addLayout(verticalLayout_3);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        wykres = new Wykres(centralWidget);
        wykres->setObjectName(QStringLiteral("wykres"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(wykres->sizePolicy().hasHeightForWidth());
        wykres->setSizePolicy(sizePolicy3);
        wykres->setMinimumSize(QSize(350, 350));

        verticalLayout->addWidget(wykres);

        wyniki = new QListWidget(centralWidget);
        wyniki->setObjectName(QStringLiteral("wyniki"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(wyniki->sizePolicy().hasHeightForWidth());
        wyniki->setSizePolicy(sizePolicy4);
        wyniki->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(wyniki);


        horizontalLayout_10->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 924, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        funkcja_celu_label->setText(QApplication::translate("MainWindow", "Funkcja celu", Q_NULLPTR));
        ilosc_zmiennych_label->setText(QApplication::translate("MainWindow", "Ilo\305\233\304\207 zmiennych", Q_NULLPTR));
        ograniczenia_label->setText(QApplication::translate("MainWindow", "Ograniczenia:", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<=0", Q_NULLPTR));
        dodaj_ograniczenie->setText(QApplication::translate("MainWindow", "Dodaj", Q_NULLPTR));
        usun_ograniczenie->setText(QApplication::translate("MainWindow", "Usu\305\204", Q_NULLPTR));
        epsilon0_label->setText(QApplication::translate("MainWindow", "Episilon0 = 10^", Q_NULLPTR));
        epsilon1_label->setText(QApplication::translate("MainWindow", "Epsilon1 = 10^", Q_NULLPTR));
        epsilon2_label->setText(QApplication::translate("MainWindow", "Epsilon2= 10^", Q_NULLPTR));
        l_label->setText(QApplication::translate("MainWindow", "Max. ilo\305\233\304\207 iteracji", Q_NULLPTR));
        l_edit->setPlaceholderText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        punkt_startowy_label->setText(QApplication::translate("MainWindow", "Punkt startowy", Q_NULLPTR));
        x_10->setPlaceholderText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        x_20->setPlaceholderText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        x_30->setPlaceholderText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        x_40->setPlaceholderText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        x_50->setPlaceholderText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        oblicz->setText(QApplication::translate("MainWindow", "Oblicz", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
