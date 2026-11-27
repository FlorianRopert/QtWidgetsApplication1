#include "Camera.h"


Camera::Camera()
    : port(nullptr),
      availablePorts(QSerialPortInfo::availablePorts())
{
}


Camera::~Camera() {
    delete port;
}
const QList<QSerialPortInfo> &Camera::GetPort() const noexcept {
    return availablePorts;
}
bool Camera::ConnexionPort(QString portName) {
    if (port != nullptr) {
        port->close();
        delete port;
    }
    port = new QSerialPort();
    port->setPortName(portName);
    port->setBaudRate(9600);
    port->setDataBits(QSerialPort::DataBits::Data8);
    port->setParity(QSerialPort::Parity::NoParity);
    port->setStopBits(QSerialPort::StopBits::OneStop);
    if (port->open(QIODevice::ReadWrite)) {
        port->blockSignals(true);
        return true;
    }
    else {
        return false;
    }
}
void Camera::onSendDataPort() {
    if (port != nullptr && port->isOpen()) {
        port->write("test");
    }
}
