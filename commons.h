#pragma once

#include <string>
#include <vector>
#include <QPixmap>

using namespace std;


// ���С��Ƶ���ڵĿ��
#define SMALL_VIDEO_WIDTH   300
#define SMALL_VIDEO_HEIGHT  225

#define CTRL_WIDGET_HEIGHT  82
#define CTRL_TOOLBUTTON_ICON_HEIGHT 40
#define CTRL_TOOLBUTTON_HEIGHT      70

#define SHARE_WINDOW_ITEM_WIDTH  200
#define SHARE_WINDOW_ITEM_HEIGHT 150

//�����ڵ���Ϣ
struct window_share_info
{
	enum WindowType
	{
		Screen,
		Window
	};

	void* hwnd;
	std::string name;
	WindowType windowType;
	QPixmap    pixmap;
};

using VecWindowShareInfo = vector<window_share_info>;

