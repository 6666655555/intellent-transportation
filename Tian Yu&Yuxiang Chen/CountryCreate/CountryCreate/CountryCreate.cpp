#include "CountryCreate.h"

CountryCreate::CountryCreate(CFWidget *parent):CFWidget(parent)
{
	setDefaultConfig();
	getDefaultForm();
	connectSignalAndSlot();
}

void CountryCreate::getDefaultForm()
{
	menuTreeForm = new MenuTreeForm();
	errorListForm = new QTextEdit();
	errorListForm->setToolTip("������־");
	errorListForm->setReadOnly(true);
	videoPlayForm = new VideoPlayForm();
	listForm = new ListForm();
	statisticstForm = new StatisticstForm();

	QVBoxLayout *vboxLeft = new QVBoxLayout();
	vboxLeft->addWidget(menuTreeForm);
	vboxLeft->addWidget(errorListForm);
	QVBoxLayout *vboxRight = new QVBoxLayout();
	vboxRight->addWidget(listForm);
	vboxRight->addWidget(statisticstForm);
	QHBoxLayout *hboxMain = new QHBoxLayout();
	hboxMain->addLayout(vboxLeft, 1);
	hboxMain->addWidget(videoPlayForm, 6);
	hboxMain->addLayout(vboxRight, 2);

	this->setLayout(hboxMain);

	ConfigInformation Config;
	Config.getConfigFileInformation();
	this->loadColorOrFont(Config);
}


void CountryCreate::setDefaultConfig()
{
	this->setWindowState(Qt::WindowMaximized);
	this->setWindowFlags(Qt::Window);//���ر߿�
	this->setWindowTitle("���ٹ�·���ϵͳ");
	this->setWindowIcon(QIcon("./Icon/software.ico"));
	this->showFullScreen();
	this->installEventFilter(this);
}

void CountryCreate::connectSignalAndSlot()
{
	//�󶨿�����
	connect(menuTreeForm, SIGNAL(closeSoftwareClicked()), this, SLOT(closeSoftware()));
	connect(menuTreeForm, SIGNAL(mixSoftwareClicked()), this, SLOT(mixSoftware()));
	connect(menuTreeForm, SIGNAL(screenStatusChangeClicked()), this, SLOT(screenStatusChange()));
	connect(menuTreeForm, SIGNAL(copyrightCliked()), this, SLOT(copyright()));
	connect(menuTreeForm, SIGNAL(aboutUSButtonClicked()), this, SLOT(aboutUSButton()));
	connect(menuTreeForm, SIGNAL(helpButtonCliked()), this, SLOT(helpButton()));
	connect(menuTreeForm, SIGNAL(listFontColorSetCliked()), this, SLOT(listFontColorSet()));
	connect(menuTreeForm, SIGNAL(listFontSetCliked()), this, SLOT(listFontSet()));
	connect(menuTreeForm, SIGNAL(backGroundColorSetClicked()), this, SLOT(backGroundColorSet()));
	connect(menuTreeForm, SIGNAL(violateInformationViewClicked()), this, SLOT(violateInformationView()));
	connect(menuTreeForm, SIGNAL(logViewCliked()), this, SLOT(logView()));
	connect(menuTreeForm, SIGNAL(pictureViewCliked()), this, SLOT(pictureView()));
}

void CountryCreate::pictureView()
{

}

void CountryCreate::logView()
{

}

void CountryCreate::violateInformationView()
{
	
}  



void CountryCreate::copyright()
{
	if (_copyright == NULL)
	{
		_copyright = new MyDialog(QString("��Ȩ˵��"), QString("./picture/copyright.png"), NULL);
		connect(_copyright, SIGNAL(close()), this, SLOT(delete_copyright()));
	}
	else
	{
		_copyright->show();
	}
}

void CountryCreate::helpButton()
{
	if (_help == NULL)
	{
		_help = new MyDialog(QString("����"), QString("./picture/help.png"), NULL);
		connect(_help, SIGNAL(close()), this, SLOT(delete_help()));
	}
	else
	{
		_help->show();
	}
}

void CountryCreate::aboutUSButton()
{
	if (_aboutUs == NULL)
	{
		_aboutUs = new MyDialog(QString("��������"), QString("./picture/aboutUs.png"), NULL);
		connect(_aboutUs, SIGNAL(close()), this, SLOT(delete_aboutUs()));
	}
	else
	{
		_aboutUs->show();
	}
}

void CountryCreate::closeSoftware()
{
	this->close();
}

void CountryCreate::mixSoftware()
{
	this->showMinimized();
}

//
void CountryCreate::screenStatusChange()
{
	if (this->isFullScreen())
	{
		this->showNormal();
	}
	else
	{
		this->showFullScreen();
	}
}

//������ɫ����
void CountryCreate::backGroundColorSet()
{
	ConfigInformation Config;
	Config.getConfigFileInformation();
	QColor newBackgroundColor = QColorDialog::getColor(QColor(Config.getBackgroundRedValue(), Config.getBackgroundGreenValue(), Config.getBackgroundBlueValue()), this, "ѡ����򱳾�ɫ");

	if (!newBackgroundColor.isValid())
	{
		return;
	}
	Config.setBackgroundColor(newBackgroundColor);
	//����������Ϣ
	this->loadColorOrFont(Config);
	//������������
	configEdit(Config);//��¼������Ϣ
}

//��������
void CountryCreate::listFontSet()
{
	ConfigInformation Config;
	Config.getConfigFileInformation();
	bool chooseSuccessful = false;
	QFont newFont = QFontDialog::getFont(&chooseSuccessful, QFont(QString("%1 [%2]").arg(Config.getFontKind()).arg(Config.getFontType()), Config.getFontSize()), this, "ѡ������");
	if (chooseSuccessful == false)
	{
		return;
	}
	Config.setFont(newFont.toString());
	//����������Ϣ
	this->loadColorOrFont(Config);
	//������������
	configEdit(Config);//��¼������Ϣ
}

//������ɫ����
void CountryCreate::listFontColorSet()
{
	ConfigInformation Config;
	Config.getConfigFileInformation();
	QColor newFontColor = QColorDialog::getColor(QColor(Config.getFontRedValue(), Config.getFontGreenValue(), Config.getFontBlueValue()), this, "ѡ��������ɫ");
	if (!newFontColor.isValid())
	{
		return;
	}
	Config.setFontColor(newFontColor);
	//����������Ϣ
	this->loadColorOrFont(Config);
	//������������
	configEdit(Config);//��¼������Ϣ
}

//��¼������Ϣ
void CountryCreate::configEdit(ConfigInformation configInformation)
{
	QFile configFile("config");
	if (configFile.open(QFile::WriteOnly | QIODevice::Text))
	{
		QTextStream fileIO(&configFile);
		fileIO << configInformation.getBackgroundRedValue() << endl << configInformation.getBackgroundGreenValue() << endl << configInformation.getBackgroundBlueValue() << endl;//д�뱳��ɫ
		fileIO << configInformation.getFontRedValue() << endl << configInformation.getFontGreenValue() << endl << configInformation.getFontBlueValue() <<endl;//д������ɫ
		fileIO << configInformation.getFontKind() <<endl;
		fileIO << configInformation.getFontType() << endl;
		fileIO << configInformation.getFontSize() << endl;
	}
	else
	{
		QMessageBox::information(NULL, "����", "������Ϣд��ʱ����", QMessageBox::Close);
	}
}

void CountryCreate::closeDone()
{
	delete_aboutUs();
	delete_help();
	delete_copyright();
}

void CountryCreate::delete_aboutUs()
{
	if (this->_aboutUs != NULL)
	{
		disconnect(_aboutUs, SIGNAL(close()), this, SLOT(delete_aboutUs()));
		_aboutUs->close();
		delete _aboutUs;
		this->_aboutUs = NULL;
	}
}

void CountryCreate::delete_help()
{
	if (this->_help != NULL)
	{
		disconnect(_help, SIGNAL(close()), this, SLOT(delete_aboutUs()));
		_help->close();
		delete _help;
		this->_help = NULL;
	}
}

void CountryCreate::delete_copyright()
{
	if (this->_copyright != NULL)
	{
		disconnect(_copyright, SIGNAL(close()), this, SLOT(delete_aboutUs()));
		_copyright->close();
		delete _copyright;
		this->_copyright = NULL;

	}
}

bool CountryCreate::eventFilter(QObject *obj, QEvent *ev)
{
	if (obj == this)
	{
		if (ev->type() == QEvent::Close)
		{
			closeDone();
			return true;
		}
		return false;
	}
	return CountryCreate::eventFilter(obj, ev);
}
