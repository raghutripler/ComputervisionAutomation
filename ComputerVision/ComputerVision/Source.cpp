
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <windows.h>
#include <gdiplus.h>
#include <memory>
#include <vector>
#include <string>
#include <sstream>
//#include <date.h>
#include <iostream>
#pragma comment (lib,"Gdiplus.lib")
using namespace std;
using namespace Gdiplus;

INPUT ip;
INPUT  shift;

void press(SHORT ch);
int Click(int x, int y);
int Takescreenshot();
bool ScreenCapture(int x, int y, int width, int height, char *filename);
string sendkeys(string stringvalue);
int ClickEnter();
int ClickMenu();
string FindObject(string  screenshot, string testimg);
string clickObject(string Object);
int CloseWindow();
int ClickTab();
int main() {
	Sleep(6000);
	clickObject("Template");

	//clickObject("eclipse");
	//Sleep(3000);
	//clickObject("Run");
	//Sleep(3000);

	//clickObject("OK");
	//Sleep(6000);
	//clickObject("RunProgram");
	//Sleep(5000);
	//CloseWindow();
	//Sleep(3000);
	//ClickEnter();
	//Sleep(3000);
	//ClickMenu();
	//sendkeys("Google chrome");
	//ClickEnter();
	//Sleep(4000);
	//sendkeys("http://citrixnasa.mgd.mrshmc.com/Citrix/XenApp/auth/login.aspx");
	//ClickEnter();
	//Sleep(3000);
	//sendkeys("vignesh-g");
	//ClickTab();
	//sendkeys("Cats@345");
	//ClickEnter();
	/*

	clickObject("citrix");
	Sleep(5000);
	clickObject("TestDropdown");
	Sleep(3000);
	clickObject("AllOption");
	Sleep(5000);
	clickObject("YearDropDown");
	Sleep(5000);
	clickObject("2014Option");
	Sleep(5000);
	clickObject("2014USFSQA");
	Sleep(5000);
	clickObject("SelectButton");
	Sleep(5000);
	clickObject("Tools");
	Sleep(5000);
	clickObject("DataDictionaryObjects");
	Sleep(6000);
	clickObject("AuditSummary");
	Sleep(5000);

	*/

	//using namespace date;
	//using namespace std::chrono;
	//std::cout << system_clock::now() << '\n';

	//clickObject("calculator");
	//Sleep(1500);
	//clickObject("0");
	//clickObject("1");
	//clickObject("2");
	//clickObject("3");
	//clickObject("4");
	//clickObject("5");
	//clickObject("6");
	//clickObject("7");
	//clickObject("8");
	//clickObject("9");
	//clickObject("0");
	//clickObject("1");
	//clickObject("0");
	//clickObject("1");
	//clickObject("2");
	//clickObject("3");
	//clickObject("4");
	//clickObject("dot");




	//CloseWindow();




	return 0;
}



int ClickEnter() {

	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	ip.ki.wVk = 0x0D;
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));

	return 0;
}

int ClickTab() {

	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	ip.ki.wVk = 0x09;
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));

	return 0;
}
int CloseWindow() {

	shift.type = INPUT_KEYBOARD;
	shift.ki.wScan = 0; // hardware scan code for key
	shift.ki.time = 0;
	shift.ki.dwExtraInfo = 0;

	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	shift.ki.wVk = 0x12;
	shift.ki.dwFlags = 0;
	SendInput(1, &shift, sizeof(INPUT));


	ip.ki.wVk = 0x73;
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));



	shift.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &shift, sizeof(INPUT));

	return 0;
}


string sendkeys(string stringvalue) {

	int j;
	Sleep(2000);
	// Set up a generic keyboard event.
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;
	//HOLD
	shift.type = INPUT_KEYBOARD;
	shift.ki.wScan = 0; // hardware scan code for key
	shift.ki.time = 0;
	shift.ki.dwExtraInfo = 0;

	//hyndavi test+
	string k = stringvalue;

	for (int i = 0; i <= (k.length() - 1); i++)
	{
		//SHORT ret = VkKeyScan(TCHAR(k[i]));
		WORD nVkCode = HIBYTE(VkKeyScanEx(k[i], GetKeyboardLayout(0)));
		//hyndavi test end 
		j = nVkCode;
		switch (j)
		{
		case 0:
			// Press the  key
			ip.ki.wVk = VkKeyScan(TCHAR(k[i]));
			ip.ki.dwFlags = 0; // 0 for key press
			SendInput(1, &ip, sizeof(INPUT));

			// Release the  key
			ip.ki.wVk = VkKeyScan(TCHAR(k[i]));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;

		case 1:
			shift.ki.wVk = VK_SHIFT;
			shift.ki.dwFlags = 0;
			SendInput(1, &shift, sizeof(INPUT));

			ip.ki.wVk = VkKeyScan(TCHAR(k[i]));
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));

			shift.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &shift, sizeof(INPUT));
			break;
		default:
			break;
		}
	}

	return "0";

}

string clickObject(string Object) {

	Takescreenshot();

	string objectCoordinates = FindObject("screen.jpg", Object + ".jpg");

	vector<string> strings;
	istringstream f(objectCoordinates);
	string s;
	while (getline(f, s, '*')) {
		cout << s << endl;
		strings.push_back(s);
	}

	int Xcoordinate = std::stoi(strings[0]);
	int Ycoordinate = std::stoi(strings[1]);

	Click(Xcoordinate, Ycoordinate);
	return "0";
}
int ClickMenu() {


	int driver = Click(32, 742);
	return 0;
}

string FindObject(string  screenshot, string testimg) {

	int x = 0;
	int y = 0;
	int Xcoordinates = 0;
	int Ycoordinates = 0;
	cv::Mat ref = cv::imread(screenshot);
	cv::Mat tpl = cv::imread(testimg);
	if (ref.empty() || tpl.empty())
		return "-1";

	cv::Mat gref, gtpl;
	cv::cvtColor(ref, gref, CV_BGR2GRAY);
	cv::cvtColor(tpl, gtpl, CV_BGR2GRAY);

	cv::Mat res(ref.rows - tpl.rows + 1, ref.cols - tpl.cols + 1, CV_32FC1);
	cv::matchTemplate(gref, gtpl, res, CV_TM_CCOEFF_NORMED);
	cv::threshold(res, res, 0.8, 1., CV_THRESH_TOZERO);

	while (true)
	{
		double minval, maxval, threshold = 0.8;
		cv::Point minloc, maxloc;

		cv::minMaxLoc(res, &minval, &maxval, &minloc, &maxloc);

		if (maxval >= threshold)
		{
			cv::rectangle(
				ref,
				maxloc,
				cv::Point(maxloc.x + tpl.cols, maxloc.y + tpl.rows),
				CV_RGB(0, 255, 0), 2
			);
			cout << "Max +tpl-->X  : " << maxloc.x + tpl.cols << endl;
			cout << "Max +tpl-->y : " << maxloc.y + tpl.rows << endl;
			cout << " Max-->X: " << maxloc.x << endl;
			cout << "Max-->y : " << maxloc.y << endl;
			cout << "tpl-->X  : " << tpl.cols << endl;
			cout << "tpl-->y : " << tpl.rows << endl;

			Xcoordinates = (maxloc.x + tpl.cols + maxloc.x) / 2;
			Ycoordinates = (maxloc.y + tpl.rows + maxloc.y) / 2;
			cout << "***************Xcoordinates************" << Xcoordinates << endl;
			cout << "***************Ycoordinates************" << Ycoordinates << endl;


			cv::floodFill(res, maxloc, cv::Scalar(0),
				0, cv::Scalar(.1), cv::Scalar(1.));
		}
		else
			break;
	}

	int a = Xcoordinates;
	stringstream ss;
	ss << a;
	string Xco = ss.str();

	int b = Ycoordinates;
	stringstream kk;
	kk << b;
	string Yco = kk.str();


	string coordinates = Xco + "*" + Yco;

	cv::imshow("reference", ref);

	//cv::imwrite("rgb.jpg", ref);

	cv::waitKey();

	return coordinates;
}



int Click(int x, int y)
{


	double fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;
	double fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;
	double fx = x*(65535.0f / fScreenWidth);
	double fy = y*(65535.0f / fScreenHeight);
	INPUT  Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
	Input.mi.dx = fx;
	Input.mi.dy = fy;
	::SendInput(1, &Input, sizeof(INPUT));


	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	::SendInput(1, &Input, sizeof(INPUT));
	// left up
	::ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	::SendInput(1, &Input, sizeof(INPUT));


	return 0;
}





int Takescreenshot() {



	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	int x1 = 0;
	int y1 = 0;
	int x2 = GetSystemMetrics(SM_CXSCREEN);
	int y2 = GetSystemMetrics(SM_CYSCREEN);
	ScreenCapture(x1, y1, x2 - x1, y2 - y1, "screen.jpg");
	//Shutdown GDI+
	GdiplusShutdown(gdiplusToken);


	return 0;
}




int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT num = 0; // number of image encoders
	UINT size = 0; // size of the image encoder array in bytes
	ImageCodecInfo* pImageCodecInfo = NULL;
	GetImageEncodersSize(&num, &size);
	if (size == 0)
	{
		return -1; // Failure
	}
	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if (pImageCodecInfo == NULL)
	{
		return -1; // Failure
	}
	GetImageEncoders(num, size, pImageCodecInfo);
	for (UINT j = 0; j < num; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j; // Success
		}
	}
	free(pImageCodecInfo);
	return -1; // Failure
}
void BitmapToJpg(HBITMAP hbmpImage, int width, int height)
{
	Bitmap *p_bmp = Bitmap::FromHBITMAP(hbmpImage, NULL);
	//Bitmap *p_bmp = new Bitmap(width, height, PixelFormat32bppARGB);
	CLSID pngClsid;
	int result = GetEncoderClsid(L"image/jpeg", &pngClsid);
	if (result != -1)
		std::cout << "Encoder succeeded" << std::endl;
	else
		std::cout << "Encoder failed" << std::endl;
	p_bmp->Save(L"screen.jpg", &pngClsid, NULL);
	delete p_bmp;
}
bool ScreenCapture(int x, int y, int width, int height, char *filename)
{
	HDC hDc = CreateCompatibleDC(0);
	HBITMAP hBmp = CreateCompatibleBitmap(GetDC(0), width, height);
	SelectObject(hDc, hBmp);
	BitBlt(hDc, 0, 0, width, height, GetDC(0), x, y, SRCCOPY);
	BitmapToJpg(hBmp, width, height);
	DeleteObject(hBmp);
	return true;
}
