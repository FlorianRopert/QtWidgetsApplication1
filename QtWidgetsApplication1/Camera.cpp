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
    sendRight();
}

void Camera::sendFrame(const QByteArray &frame)
{
    if (port != nullptr && port->isOpen()) {
        port->write(frame);
        port->flush();
    }
}

void Camera::sendLeft()
{
    sendFrame(QByteArray::fromHex("81 01 06 01 10 10 01 03 FF"));
}

void Camera::sendRight()
{
    sendFrame(QByteArray::fromHex("81 01 06 01 10 10 02 03 FF"));
}

void Camera::sendUp()
{
    sendFrame(QByteArray::fromHex("81 01 06 01 10 10 03 01 FF"));
}

void Camera::sendDown()
{
    sendFrame(QByteArray::fromHex("81 01 06 01 10 10 03 02 FF"));
}

void Camera::sendUpLeft()
{
    sendFrame(QByteArray::fromHex("81 01 06 01 10 10 01 01 FF"));
}

void Camera::sendUpRight()
{
    sendFrame(QByteArray::fromHex("81 01 06 01 10 10 02 01 FF"));
}

void Camera::sendDownLeft()
{
    sendFrame(QByteArray::fromHex("81 01 06 01 10 10 01 02 FF"));
}

void Camera::sendDownRight()
{
    sendFrame(QByteArray::fromHex("81 01 06 01 10 10 02 02 FF"));
}

void Camera::sendStop()
{
    sendFrame(QByteArray::fromHex("81 01 06 01 10 10 03 03 FF"));
}
