#pragma once
#pragma execution_character_set("utf-8")
#include<QtWidgets/QWidget>
#include<qboxlayout>
#include<qstringlist>
#include<qstring>
#include<qtreewidget>
#include"ConfigInformation.h"
#include"CFWidget.h"

class MenuTreeForm :public CFWidget
{
	Q_OBJECT
public:
	MenuTreeForm(CFWidget  *parent = Q_NULLPTR);
	~MenuTreeForm();
public:
	//���ļ����� �źŶ���
	signals:void pictureViewCliked();
	signals:void logViewCliked();
	signals:void violateInformationViewClicked();

			//�����á��� �źŶ���
	signals:void backGroundColorSetClicked();
	signals:void listFontSetCliked();
	signals:void listFontColorSetCliked();

			//"����"�� �źŶ���
	signals:void copyrightCliked();
	signals:void helpButtonCliked();
	signals:void aboutUSButtonClicked();

			//"����"�� �źŶ���
	signals:void closeSoftwareClicked();
	signals:void mixSoftwareClicked();
	signals:void screenStatusChangeClicked();

public slots:void createClickSignal(QTreeWidgetItem*, int);//��������ź�
public:
	void loadColorOrFont(ConfigInformation);

private:
	void createMenuTree();
private:
	QTreeWidget * functionTree;
	QVBoxLayout *vBoxLayout;
};
