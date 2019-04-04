#include "VideoPlayForm.h"

VideoPlayForm::VideoPlayForm(CFWidget *parent): CFWidget(parent)
{
	timeLabel = new QLabel();
	videoLabel = new QLabel();
	informationLabel = new QLabel();

	//���������Ű�
	timeLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	informationLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	videoLabel->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
	videoLabel->setScaledContents(true);

	//���沼��
	QHBoxLayout *hbox = new QHBoxLayout();
	hbox->addWidget(timeLabel);
	hbox->addWidget(informationLabel);
	QVBoxLayout *vbox = new QVBoxLayout();
	vbox->addWidget(videoLabel);
	vbox->addLayout(hbox);
	vbox->setStretchFactor(videoLabel, 1);
	vbox->setStretchFactor(hbox, 0);
	this->setLayout(vbox);

	//���ÿؼ�����ɫ��
	this->setStyleSheet("VideoPlayForm{background-color: rgb(0, 0, 0);}");
	timeLabel->setStyleSheet("QLabel{font: 12pt \"����\";color: rgb(57, 173, 0);}");
	informationLabel->setStyleSheet("QLabel{font: 10pt \"����\";color: rgb(57, 173, 0);}");

	//������������
	timeLabel->setText("ʱ�䣺xxxx��xx��xx�� xx:xx:xx");
	informationLabel->setText("ƽ�����٣�xxx.xxkm/s  ƽ��ʶ�𾫶ȣ�xx.xx%");

	QPixmap pixmap("./picture/11.jpg");
	videoLabel->setPixmap(pixmap.scaled(800, 600, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
	
}


