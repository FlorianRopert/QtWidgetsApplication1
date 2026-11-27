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
    const QList<QSerialPortInfo> &GetPort() const noexcept;
private:
    QSerialPort* port; // creer un port 
    QList<QSerialPortInfo> availablePorts;
};

