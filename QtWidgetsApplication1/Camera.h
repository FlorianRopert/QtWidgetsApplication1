#pragma once
#include <QString>
#include <QSerialPortInfo>
#include <qserialport.h>
#include <QList>


class Camera
{
public:
    Camera();
    ~Camera();
    bool ConnexionPort(QString portName);
    void onSendDataPort();
    void sendLeft();
    void sendRight();
    void sendUp();
    void sendDown();
    void sendUpLeft();
    void sendUpRight();
    void sendDownLeft();
    void sendDownRight();
    void sendStop();
    const QList<QSerialPortInfo> &GetPort() const noexcept;
private:
    void sendFrame(const QByteArray &frame);
    QSerialPort* port; // creer un port 
    QList<QSerialPortInfo> availablePorts;
};

