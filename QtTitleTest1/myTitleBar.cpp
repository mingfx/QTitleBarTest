#include "myTitleBar.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QFile>
#include <QMouseEvent>


MyTitleBar::MyTitleBar(QWidget *parent)
	: QWidget(parent)
	, m_colorR(153)
	, m_colorG(153)
	, m_colorB(153)
	, m_isPressed(false)
	, m_buttonType(MIN_MAX_BUTTON)
	, m_windowBorderWidth(0)
	, m_isTransparent(false)
{
	// ��ʼ��;
	InitControl();
	InitConnections();
	// ���ر�����ʽ MyTitle.css�ļ�;
	LoadStyleSheet("MyTitle");
}

MyTitleBar::~MyTitleBar()
{

}

void MyTitleBar::InitControl()
{
	m_pIcon = new QLabel;
	m_pTitleContent = new QLabel;

	m_pButtonClose = new QPushButton;
	m_pButtonMax = new QPushButton;
	m_pButtonMin = new QPushButton;
	m_pButtonRestore = new QPushButton;

	m_pButtonMax->setFixedSize(QSize(button_width, button_height));
	m_pButtonMin->setFixedSize(QSize(button_width, button_height));;
	m_pButtonRestore->setFixedSize(QSize(button_width, button_height));;
	m_pButtonClose->setFixedSize(QSize(button_width, button_height));;

	m_pTitleContent->setObjectName("TitleContent");
	m_pButtonMax->setObjectName("ButtonMax");
	m_pButtonMin->setObjectName("ButtonMin");
	m_pButtonRestore->setObjectName("ButtonRestore");
	m_pButtonClose->setObjectName("ButtonClose");

	m_pButtonMax->setToolTip(QStringLiteral("���"));
	m_pButtonMin->setToolTip(QStringLiteral("��С��"));
	m_pButtonRestore->setToolTip(QStringLiteral("��ԭ"));
	m_pButtonClose->setToolTip(QStringLiteral("�ر�"));

	QHBoxLayout *myLayout = new QHBoxLayout(this);
	myLayout->addWidget(m_pIcon);
	myLayout->addWidget(m_pTitleContent);

	myLayout->addWidget(m_pButtonMin);
	myLayout->addWidget(m_pButtonRestore);
	myLayout->addWidget(m_pButtonMax);
	myLayout->addWidget(m_pButtonClose);

	myLayout->setContentsMargins(5, 0, 0, 0);//���ܾ���
	myLayout->setSpacing(0);//���

	m_pTitleContent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	this->setFixedHeight(title_height);
	this->setWindowFlags(Qt::FramelessWindowHint);
}

//�źŲ۰�
void MyTitleBar::InitConnections()
{
	connect(m_pButtonMin, SIGNAL(clicked()), this, SLOT(on_ButtonMin_clicked()));
	connect(m_pButtonRestore, SIGNAL(clicked()), this, SLOT(on_ButtonRestore_clicked()));
	connect(m_pButtonMax, SIGNAL(clicked()), this, SLOT(on_ButtonMax_clicked()));
	connect(m_pButtonClose, SIGNAL(clicked()), this, SLOT(on_ButtonRelease_clicked()));
}

// ���ñ���������ɫ,��paintEvent�¼��н��л��Ʊ���������ɫ;
// �ڹ��캯���и���Ĭ��ֵ�������ⲿ������ɫֵ�ı����������ɫ;
void MyTitleBar::SetBackgroundColor(int r, int g, int b, bool isTransparent /* = false */)
{
	m_colorR = r;
	m_colorG = g;
	m_colorB = b;
	m_isTransparent = isTransparent;
	// ���»��ƣ�����paintEvent�¼���;
	update();
}

//���ñ�����ͼ��
void MyTitleBar::SetTitleIcon(QString filePath, QSize iconSize /* = QSize(25, 25) */)
{
	QPixmap titleIcon(filePath);
	m_pIcon->setPixmap(titleIcon.scaled(iconSize));
}

//���ñ�������
void MyTitleBar::SetTitleContent(QString titleContent, int titleFontSize /* = 9 */)
{

}