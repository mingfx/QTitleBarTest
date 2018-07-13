#pragma once
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTimer>

enum ButtonType
{
	MIN_BUTTON = 0,
	MIN_MAX_BUTTON,
	ONLY_CLOSE_BUTTON
};

class MyTitleBar :public QWidget
{
	Q_OBJECT
public:
	MyTitleBar(QWidget *parent);
	~MyTitleBar();
	void SetBackgroundColor(int r, int g, int b, bool isTransparent = false);
	void SetTitleIcon(QString filePath, QSize iconSize = QSize(25, 25));
	void SetTitleContent(QString titleContent, int titleFontSize = 9);
	void SetTitleWidth(int width);
	void SetButtonType(ButtonType buttonType);
	void SetTitleRoll();
	void SetWindowBorderWidth(int borderWidth);
	void SaveRestoreInfo(const QPoint point, const QSize size);
	void GetRestoreInfo(QPoint& point, QSize& size);
protected:
private:
	void PaintEvent(QPaintEvent *event);
	void MouseDoubleClickEvent(QMouseEvent *event);
	void MousePressEvent(QMouseEvent *event);
	void MouseMoveEvent(QMouseEvent *event);
	void MouseReleaseEvent(QMouseEvent *event);

	void InitControl();
	void InitConnections();
	void LoadStyleSheet(const QString &sheetName);
signals:
	void signalButtonMinClicked();
	void signalButtonMaxClicked();
	void signalButtonRestoreClicked();
	void signalButtonCloseClicked();
private slots:
void on_ButtonMin_clicked();
void on_ButtonMax_clicked();
void on_ButtonRestore_clicked();
void on_ButtonRelease_clicked();
void onRollTitle();
private:
	QLabel *m_pIcon;//标题栏图标
	QLabel *m_pTitleContent;//标题栏内容
	QPushButton *m_pButtonMin;
	QPushButton *m_pButtonMax;
	QPushButton *m_pButtonRestore;
	QPushButton *m_pButtonClose;
	//标题栏背景色
	int m_colorR;
	int m_colorG;
	int m_colorB;
	//最大化，最小化变量
	QPoint m_restorePos;
	QSize m_restoreSize;
	//移动窗口变量
	bool m_isPressed;
	QPoint m_startMovePos;
	//标题栏滚动
	QTimer m_TitleRollTimer;
	//标题栏内容
	QString m_TitleContent;
	//按钮类型
	ButtonType m_buttonType;
	//窗口边框宽度
	int m_windowBorderWidth;
	//标题栏是否透明
	bool m_isTransparent;

	const int button_height = 30;
	const int button_width = 30;
	const int title_height = 30;
};
