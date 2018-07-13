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
	// 初始化;
	InitControl();
	InitConnections();
	// 加载本地样式 MyTitle.css文件;
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

	m_pButtonMax->setToolTip(QStringLiteral("最大化"));
	m_pButtonMin->setToolTip(QStringLiteral("最小化"));
	m_pButtonRestore->setToolTip(QStringLiteral("还原"));
	m_pButtonClose->setToolTip(QStringLiteral("关闭"));

	QHBoxLayout *myLayout = new QHBoxLayout(this);
	myLayout->addWidget(m_pIcon);
	myLayout->addWidget(m_pTitleContent);

	myLayout->addWidget(m_pButtonMin);
	myLayout->addWidget(m_pButtonRestore);
	myLayout->addWidget(m_pButtonMax);
	myLayout->addWidget(m_pButtonClose);

	myLayout->setContentsMargins(5, 0, 0, 0);//四周距离
	myLayout->setSpacing(0);//间隔

	m_pTitleContent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	this->setFixedHeight(title_height);
	this->setWindowFlags(Qt::FramelessWindowHint);
}

//信号槽绑定
void MyTitleBar::InitConnections()
{
	connect(m_pButtonMin, SIGNAL(clicked()), this, SLOT(on_ButtonMin_clicked()));
	connect(m_pButtonRestore, SIGNAL(clicked()), this, SLOT(on_ButtonRestore_clicked()));
	connect(m_pButtonMax, SIGNAL(clicked()), this, SLOT(on_ButtonMax_clicked()));
	connect(m_pButtonClose, SIGNAL(clicked()), this, SLOT(on_ButtonRelease_clicked()));
}

// 设置标题栏背景色,在paintEvent事件中进行绘制标题栏背景色;
// 在构造函数中给了默认值，可以外部设置颜色值改变标题栏背景色;
void MyTitleBar::SetBackgroundColor(int r, int g, int b, bool isTransparent /* = false */)
{
	m_colorR = r;
	m_colorG = g;
	m_colorB = b;
	m_isTransparent = isTransparent;
	// 重新绘制（调用paintEvent事件）;
	update();
}

//设置标题栏图标
void MyTitleBar::SetTitleIcon(QString filePath, QSize iconSize /* = QSize(25, 25) */)
{
	QPixmap titleIcon(filePath);
	m_pIcon->setPixmap(titleIcon.scaled(iconSize));
}

//设置标题内容
void MyTitleBar::SetTitleContent(QString titleContent, int titleFontSize /* = 9 */)
{

}