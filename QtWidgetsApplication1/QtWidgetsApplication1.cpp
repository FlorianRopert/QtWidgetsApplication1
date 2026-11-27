#include "QtWidgetsApplication1.h"
#include <QSerialPortInfo>
#include <QList>

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.comboBoxListPort->clear();

    const QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo& port : ports) {
        ui.comboBoxListPort->addItem(port.portName());
    }
}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}

void QtWidgetsApplication1::OnButtonPortClicked()
{
    if (ui.comboBoxListPort->currentIndex() >= 0) {
        port = new QSerialPort(ui.portComboBox());

    }
}
