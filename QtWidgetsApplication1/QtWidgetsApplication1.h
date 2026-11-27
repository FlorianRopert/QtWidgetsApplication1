#pragma once

#include <QtWidgets/QMainWindow>
#include <QTimer>
#include "ui_QtWidgetsApplication1.h"
#include "Camera.h"

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = nullptr);
    ~QtWidgetsApplication1();
    bool ConnexionPort(QString portName);
    Camera cam;

private:
    Ui::QtWidgetsApplication1Class ui;
    
    

public slots:
	void OnButtonPortClicked();
    void OnButtonLeftClicked();
    void OnButtonRightClicked();
    void OnButtonTopClicked();
    void OnButtonBackClicked();
    void OnButtonCentrerClicked();
    void OnButtonUpLeftClicked();
    void OnButtonUpRightClicked();
    void OnButtonUpTopClicked();
    void OnButtonUpBackClicked();
    void OnButtonUpCheckupClicked();
};

