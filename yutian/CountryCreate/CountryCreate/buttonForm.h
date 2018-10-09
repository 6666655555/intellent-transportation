#pragma once
#pragma execution_character_set("utf-8")
#include<QtWidgets/QWidget>
#include<qradiobutton>
#include<qboxlayout>
#include<qgroupbox>
#include"CFWidget.h"

class ButtonForm:public CFWidget
{
	Q_OBJECT
public:
	ButtonForm(CFWidget *parent = Q_NULLPTR);
public slots:void setTimeModelChoose();
public slots:void setKindModelChoose();
public slots:void setStatisticstModelChoose();

public:

	int timeModelChoose = 2;//signal==1: ��ʷ  ;  signal==2: ��ǰ;
	int kindModelChoose = 2;//signal==1: ���ٷֲ�  ;  signal==2: �����ֲ�
	int statisticstChoose = 2;//signal==1: ��״ͼ  ;  signal==2: ��״ͼ

	QRadioButton * todayChoosed;
	QRadioButton *NowChoosed;
	QRadioButton *speedChoosed;
	QRadioButton *roadChoosed;
	QRadioButton *circleChoose;
	QRadioButton *rectangleChoose;
};

