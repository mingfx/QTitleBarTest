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
	QLabel *m_pIcon;//������ͼ��
	QLabel *m_pTitleContent;//����������
	QPushButton *m_pButtonMin;
	QPushButton *m_pButtonMax;
	QPushButton *m_pButtonRestore;
	QPushButton *m_pButtonClose;
	//����������ɫ
	int m_colorR;
	int m_colorG;
	int m_colorB;
	//��󻯣���С������
	QPoint m_restorePos;
	QSize m_restoreSize;
	//�ƶ����ڱ���
	bool m_isPressed;
	QPoint m_startMovePos;
	//����������
	QTimer m_TitleRollTimer;
	//����������
	QString m_TitleContent;
	//��ť����
	ButtonType m_buttonType;
	//���ڱ߿���
	int m_windowBorderWidth;
	//�������Ƿ�͸��
	bool m_isTransparent;

	const int button_height = 30;
	const int button_width = 30;
	const int title_height = 30;
};
