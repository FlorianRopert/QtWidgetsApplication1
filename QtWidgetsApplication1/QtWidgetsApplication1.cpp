#include "QtWidgetsApplication1.h"
#include <QSerialPortInfo>
#include <qserialport.h>
#include <QList>

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent),cam()
{
    ui.setupUi(this);
    ui.comboBoxListPort->clear();
    const QList<QSerialPortInfo> &infoport = cam.GetPort();
    for (int i = 0; i < infoport.size();i++) { // Permet d'ajouter les ports dans l'affiche ui
        ui.comboBoxListPort->addItem(infoport[i].portName(), QVariant(infoport[i].portName()));
    }
}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}


void QtWidgetsApplication1::OnButtonPortClicked()
{
    if (ui.comboBoxListPort->currentIndex() >= 0) {
        cam.ConnexionPort(ui.comboBoxListPort->currentText());
    }
}
void QtWidgetsApplication1::OnButtonRightClicked() {
    cam.sendRight();
}

void QtWidgetsApplication1::OnButtonLeftClicked() {
    cam.sendLeft();
}

void QtWidgetsApplication1::OnButtonTopClicked() {
    cam.sendUp();
}

void QtWidgetsApplication1::OnButtonBackClicked() {
    cam.sendDown();
}

void QtWidgetsApplication1::OnButtonCentrerClicked() {
    cam.sendCenter();
}

void QtWidgetsApplication1::OnButtonUpLeftClicked()
{
    cam.sendUpLeft();
}

void QtWidgetsApplication1::OnButtonUpRightClicked()
{
    cam.sendUpRight();
}

void QtWidgetsApplication1::OnButtonUpTopClicked()
{
    cam.sendUp();
}

void QtWidgetsApplication1::OnButtonUpBackClicked()
{
    cam.sendDown();
}

void QtWidgetsApplication1::OnButtonUpCheckupClicked()
{
    cam.sendLeft2();

    QTimer::singleShot(1500, this, [this]() {
        cam.sendRight2();
        });

    QTimer::singleShot(3000, this, [this]() {
        cam.sendCenter();
        });
}


