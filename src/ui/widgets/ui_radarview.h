/********************************************************************************
** Form generated from reading UI file 'radarview.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RADARVIEW_H
#define UI_RADARVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RadarView
{
public:

    void setupUi(QWidget *RadarView)
    {
        if (RadarView->objectName().isEmpty())
            RadarView->setObjectName("RadarView");
        RadarView->resize(388, 258);

        retranslateUi(RadarView);

        QMetaObject::connectSlotsByName(RadarView);
    } // setupUi

    void retranslateUi(QWidget *RadarView)
    {
        RadarView->setWindowTitle(QCoreApplication::translate("RadarView", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RadarView: public Ui_RadarView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RADARVIEW_H
