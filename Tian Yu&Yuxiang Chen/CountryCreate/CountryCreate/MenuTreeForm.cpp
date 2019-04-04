#include "MenuTreeForm.h"

MenuTreeForm::MenuTreeForm(CFWidget *parent): CFWidget(parent)
{
	createMenuTree();
	connect(functionTree, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(createClickSignal(QTreeWidgetItem *, int)));
}

void MenuTreeForm::createMenuTree()
{
	//ʵ������ֱ���ֺ���
	this->vBoxLayout = new QVBoxLayout(this);

	//����һ����
	this->functionTree = new QTreeWidget(this);
	this->functionTree->setColumnCount(1);
	this->functionTree->setHeaderLabel("����̨");
	this->functionTree->setHeaderHidden(true);
	//�洢��
	QTreeWidgetItem *fileView = new QTreeWidgetItem(functionTree, QStringList() << "�洢");
	QTreeWidgetItem *pictureView = new QTreeWidgetItem(fileView, QStringList() << "ץ��ͼƬ");
	QTreeWidgetItem *logView = new QTreeWidgetItem(fileView, QStringList() << "��־��Ϣ");
	QTreeWidgetItem *violateInformationView = new QTreeWidgetItem(fileView, QStringList() << "Υ����Ϣ");
	//����"�洢��"ͼ��
	fileView->setIcon(0, QIcon("./Icon/fileView.ico"));
	pictureView->setIcon(0, QIcon("./Icon/pictureView.ico"));
	logView->setIcon(0, QIcon("./Icon/logView.ico"));
	violateInformationView->setIcon(0, QIcon("./Icon/violateInformationView.ico"));

	//������
	QTreeWidgetItem *softwareSet = new QTreeWidgetItem(functionTree, QStringList() << "����");
	QTreeWidgetItem *backGroundColorSet = new QTreeWidgetItem(softwareSet, QStringList() << "������ɫ����");
	QTreeWidgetItem *listFontSet = new QTreeWidgetItem(softwareSet, QStringList() << "��������С����");
	QTreeWidgetItem *listFontColorSet = new QTreeWidgetItem(softwareSet, QStringList() << "���������ɫ����");
	//����"������"ͼ��
	softwareSet->setIcon(0, QIcon("./Icon/softwareSet.ico"));
	backGroundColorSet->setIcon(0, QIcon("./Icon/backGroundColorSet.ico"));
	listFontSet->setIcon(0, QIcon("./Icon/listFontSet.ico"));
	listFontColorSet->setIcon(0, QIcon("./Icon/listFontColorSet.ico"));

	//������
	QTreeWidgetItem *softwareHelp = new QTreeWidgetItem(functionTree, QStringList() << "����");
	QTreeWidgetItem *helpButton = new QTreeWidgetItem(softwareHelp, QStringList() << "�鿴����");
	QTreeWidgetItem *copyright = new QTreeWidgetItem(softwareHelp, QStringList() << "��Ȩ˵��");
	QTreeWidgetItem *aboutUSButton = new QTreeWidgetItem(softwareHelp, QStringList() << "��������");
	//����"������"ͼ��
	softwareHelp->setIcon(0, QIcon("./Icon/softwareHelp.ico"));
	helpButton->setIcon(0, QIcon("./Icon/helpButton.ico"));
	copyright->setIcon(0, QIcon("./Icon/copyright.ico"));
	aboutUSButton->setIcon(0, QIcon("./Icon/aboutUsButton.ico"));

	//������
	QTreeWidgetItem *softwareSwitch = new QTreeWidgetItem(functionTree, QStringList() << "����");
	QTreeWidgetItem *screenStatusChange = new QTreeWidgetItem(softwareSwitch, QStringList() << "ȫ��/�˳�ȫ��");
	QTreeWidgetItem *MixSoftware = new QTreeWidgetItem(softwareSwitch, QStringList() << "������С��");
	QTreeWidgetItem *closeSoftware = new QTreeWidgetItem(softwareSwitch, QStringList() << "�˳�����");
	//����"������"ͼ��
	softwareSwitch->setIcon(0, QIcon("./Icon/softwareSwitch.ico"));
	screenStatusChange->setIcon(0, QIcon("./Icon/screenStatusChange.ico"));
	MixSoftware->setIcon(0, QIcon("./Icon/MixSoftware.ico"));
	closeSoftware->setIcon(0, QIcon("./Icon/closeSoftware.ico"));

	functionTree->expandAll();
	vBoxLayout->addWidget(functionTree);
	this->setLayout(vBoxLayout);
}

void MenuTreeForm::createClickSignal(QTreeWidgetItem *item, int column)
{
	if (item->text(0) == "ץ��ͼƬ"&&item->parent()->text(0) == "�洢")
	{
		emit pictureViewCliked();
	}
	else if (item->text(0) == "��־��Ϣ"&&item->parent()->text(0) == "�洢")
	{
		emit logViewCliked();
	}
	else if (item->text(0) == "Υ����Ϣ"&&item->parent()->text(0) == "�洢")
	{
		emit violateInformationViewClicked();
	}
	else if (item->text(0) == "������ɫ����"&&item->parent()->text(0) == "����")
	{
		emit backGroundColorSetClicked();
	}

	else if (item->text(0) == "��������С����"&&item->parent()->text(0) == "����")
	{
		emit listFontSetCliked();
	}
	else if (item->text(0) == "���������ɫ����"&&item->parent()->text(0) == "����")
	{
		emit listFontColorSetCliked();
	}
	else if (item->text(0) == "�鿴����"&&item->parent()->text(0) == "����")
	{
		emit helpButtonCliked();
	}
	else if (item->text(0) == "��Ȩ˵��"&&item->parent()->text(0) == "����")
	{
		emit copyrightCliked();
	}
	else if (item->text(0) == "��������"&&item->parent()->text(0) == "����")
	{
		emit aboutUSButtonClicked();
	}
	else if (item->text(0) == "ȫ��/�˳�ȫ��"&&item->parent()->text(0) == "����")
	{
		emit screenStatusChangeClicked();
	}
	else if (item->text(0) == "������С��"&&item->parent()->text(0) == "����")
	{
		emit mixSoftwareClicked();
	}
	else if (item->text(0) == "�˳�����"&&item->parent()->text(0) == "����")
	{
		emit closeSoftwareClicked();
	}
}

void MenuTreeForm::loadColorOrFont(ConfigInformation config)
{
	this->setAttribute(Qt::WA_StyledBackground,true);
	this->setStyleSheet(QString("background-color: rgb(%1,%2, %3);color:rgb(%4,%5,%6);font: %7pt \"%8\";").arg(config.getBackgroundRedValue()).arg(config.getBackgroundGreenValue()).arg(config.getBackgroundBlueValue()).arg(config.getFontRedValue()).arg(config.getFontGreenValue()).arg(config.getFontBlueValue()).arg(config.getFontSize()).arg(config.getFontKind()));
}

MenuTreeForm::~MenuTreeForm()
{
	delete this->functionTree;
}