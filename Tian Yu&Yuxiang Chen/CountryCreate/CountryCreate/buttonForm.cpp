#include "buttonForm.h"

ButtonForm::ButtonForm(CFWidget *parent):CFWidget(parent)
{
	QGroupBox *timeBox = new QGroupBox(this);
	QGroupBox *kindBox = new QGroupBox(this);
	QGroupBox *stasticstBox = new QGroupBox(this);
	timeBox->setStyleSheet("QGroupBox{font: 14pt \"����\";color: rgb(249,120,69);}");
	kindBox->setStyleSheet("QGroupBox{font: 14pt \"����\";color: rgb(249,120,69);}");
	stasticstBox->setStyleSheet("QGroupBox{font: 14pt \"����\";color: rgb(249,120,69);}");

	timeBox->setTitle("ѡ��ʱ��");
	kindBox->setTitle("ѡ��ֲ�");
	stasticstBox->setTitle("ѡ��ͳ�Ʒ�ʽ");

	todayChoosed = new QRadioButton("����");
	NowChoosed = new QRadioButton("����");
	NowChoosed->setChecked(true);

	speedChoosed = new QRadioButton("���ٷֲ�");
	roadChoosed = new QRadioButton("�����ֲ�");
	roadChoosed->setChecked(true);

	rectangleChoose = new QRadioButton("��״ͼ");
	circleChoose = new QRadioButton("��״ͼ");
	circleChoose->setChecked(true);

	QVBoxLayout *vbox1_ = new QVBoxLayout(this);
	QVBoxLayout *vbox2_ = new QVBoxLayout(this);
	QVBoxLayout *vbox3_ = new QVBoxLayout(this);
	vbox1_->addWidget(todayChoosed);
	vbox1_->addWidget(NowChoosed);
	vbox2_->addWidget(speedChoosed);
	vbox2_->addWidget(roadChoosed);
	vbox3_->addWidget(rectangleChoose);
	vbox3_->addWidget(circleChoose);

	timeBox->setLayout(vbox1_);
	kindBox->setLayout(vbox2_);
	stasticstBox->setLayout(vbox3_);

	QVBoxLayout *vbox = new QVBoxLayout(this);
	vbox->addWidget(timeBox);
	vbox->addWidget(kindBox);
	vbox->addWidget(stasticstBox);

	this->setLayout(vbox);
	connect(todayChoosed, SIGNAL(clicked(bool)), this, SLOT(setTimeModelChoose()));
	connect(NowChoosed, SIGNAL(clicked(bool)), this, SLOT(setTimeModelChoose()));
	connect(speedChoosed, SIGNAL(clicked(bool)), this, SLOT(setKindModelChoose()));
	connect(roadChoosed, SIGNAL(clicked(bool)), this, SLOT(setKindModelChoose()));
	connect(rectangleChoose, SIGNAL(clicked(bool)), this, SLOT(setStatisticstModelChoose()));
	connect(circleChoose, SIGNAL(clicked(bool)), this, SLOT(setStatisticstModelChoose()));
}

void ButtonForm::setTimeModelChoose()
{
	if (todayChoosed->isChecked())
	{
		timeModelChoose = 1;
	}
	if (NowChoosed->isChecked())
	{
		timeModelChoose = 2;
	}

}

void ButtonForm::setKindModelChoose()
{
	if (speedChoosed->isChecked())
	{
		kindModelChoose = 1;
	}
	if (roadChoosed->isChecked())
	{
		kindModelChoose = 2;
	}
}

void ButtonForm::setStatisticstModelChoose()
{

	if (rectangleChoose->isChecked())
	{
		statisticstChoose = 1;
	}
	if (circleChoose->isChecked())
	{
		statisticstChoose = 2;
	}
}