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
    cam.onSendDataPort();
}

void QtWidgetsApplication1::OnButtonLeftClicked() {

}

void QtWidgetsApplication1::OnButtonTopClicked() {

}

void QtWidgetsApplication1::OnButtonBackClicked() {

}