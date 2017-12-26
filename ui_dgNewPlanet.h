/********************************************************************************
** Form generated from reading UI file 'dgNewPlanet.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DGNEWPLANET_H
#define UI_DGNEWPLANET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dgDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLineEdit *edPlanetName;
    QLabel *lbName;
    QLineEdit *edWeight;
    QLabel *lbWeigtht;
    QLineEdit *edSize;
    QLabel *lbSize;
    QLineEdit *edColor;
    QLabel *lbColor;
    QLineEdit *edRadius;
    QLabel *lbRadius;
    QLineEdit *edOmega;
    QLabel *lbOmega;
    QLineEdit *edAlph;
    QLabel *lbAlpha;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dgDialog)
    {
        if (dgDialog->objectName().isEmpty())
            dgDialog->setObjectName(QStringLiteral("dgDialog"));
        dgDialog->resize(320, 232);
        verticalLayout = new QVBoxLayout(dgDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        edPlanetName = new QLineEdit(dgDialog);
        edPlanetName->setObjectName(QStringLiteral("edPlanetName"));

        formLayout->setWidget(0, QFormLayout::LabelRole, edPlanetName);

        lbName = new QLabel(dgDialog);
        lbName->setObjectName(QStringLiteral("lbName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lbName);

        edWeight = new QLineEdit(dgDialog);
        edWeight->setObjectName(QStringLiteral("edWeight"));

        formLayout->setWidget(1, QFormLayout::LabelRole, edWeight);

        lbWeigtht = new QLabel(dgDialog);
        lbWeigtht->setObjectName(QStringLiteral("lbWeigtht"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lbWeigtht);

        edSize = new QLineEdit(dgDialog);
        edSize->setObjectName(QStringLiteral("edSize"));

        formLayout->setWidget(2, QFormLayout::LabelRole, edSize);

        lbSize = new QLabel(dgDialog);
        lbSize->setObjectName(QStringLiteral("lbSize"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lbSize);

        edColor = new QLineEdit(dgDialog);
        edColor->setObjectName(QStringLiteral("edColor"));

        formLayout->setWidget(3, QFormLayout::LabelRole, edColor);

        lbColor = new QLabel(dgDialog);
        lbColor->setObjectName(QStringLiteral("lbColor"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lbColor);

        edRadius = new QLineEdit(dgDialog);
        edRadius->setObjectName(QStringLiteral("edRadius"));

        formLayout->setWidget(4, QFormLayout::LabelRole, edRadius);

        lbRadius = new QLabel(dgDialog);
        lbRadius->setObjectName(QStringLiteral("lbRadius"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lbRadius);

        edOmega = new QLineEdit(dgDialog);
        edOmega->setObjectName(QStringLiteral("edOmega"));

        formLayout->setWidget(5, QFormLayout::LabelRole, edOmega);

        lbOmega = new QLabel(dgDialog);
        lbOmega->setObjectName(QStringLiteral("lbOmega"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lbOmega);

        edAlph = new QLineEdit(dgDialog);
        edAlph->setObjectName(QStringLiteral("edAlph"));

        formLayout->setWidget(6, QFormLayout::LabelRole, edAlph);

        lbAlpha = new QLabel(dgDialog);
        lbAlpha->setObjectName(QStringLiteral("lbAlpha"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lbAlpha);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(dgDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dgDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), dgDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dgDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(dgDialog);
    } // setupUi

    void retranslateUi(QDialog *dgDialog)
    {
        dgDialog->setWindowTitle(QApplication::translate("dgDialog", "Dialog", 0));
        lbName->setText(QApplication::translate("dgDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\273\320\260", 0));
        lbWeigtht->setText(QApplication::translate("dgDialog", "\320\222\320\265\321\201 \321\202\320\265\320\273\320\260", 0));
        lbSize->setText(QApplication::translate("dgDialog", "\320\240\320\260\320\267\320\274\320\265\321\200 \321\202\320\265\320\273\320\260", 0));
        lbColor->setText(QApplication::translate("dgDialog", "\320\246\320\262\320\265\321\202 \321\202\320\265\320\273\320\260 (RGB hex)", 0));
        lbRadius->setText(QApplication::translate("dgDialog", "\320\240\320\260\320\264\320\270\321\203\321\201 \320\276\321\200\320\261\320\270\321\202\321\213", 0));
        lbOmega->setText(QApplication::translate("dgDialog", "\320\243\320\263\320\273\320\276\320\262\320\260\321\217 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214", 0));
        lbAlpha->setText(QApplication::translate("dgDialog", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\271 \321\203\320\263\320\276\320\273", 0));
    } // retranslateUi

};

namespace Ui {
    class dgDialog: public Ui_dgDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DGNEWPLANET_H
