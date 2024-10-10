#include<stdio.h>
#include<Windows.h>
#include <string.h>


//定义全局变量
int client_hwnd;
int error;

void SimulateClickInBackground(HWND hwnd, int x, int y);



BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    

    char windowTitle[256];  // 存储窗口标题
    
    // 获取窗口标题
    if (GetWindowTextA(hwnd, windowTitle, sizeof(windowTitle))) {
        // 打印窗口句柄和窗口标题
      //  printf("%s\n",windowTitle);
        if (strcmp(windowTitle, "提示") == 0) {//获取错误窗口

            printf("\n检测到天翼断开,即将关闭错误窗口");
            Sleep(2000);
            PostMessage(hwnd, WM_CLOSE, 0, 0);
            error = 1;
            
        }
        if (strcmp(windowTitle, "校园客户端")==0) {//获取主窗口
            
            printf("\n检测中---------");
            Sleep(2000);
            client_hwnd = hwnd;


           

        }
    }

    return TRUE;  // 返回 TRUE 继续枚举下一个窗口
}

void SimulateClickInBackground(HWND hwnd, int x, int y) {
    // 将 x 和 y 坐标转换为 lParam 格式（低16位存储x，高16位存储y）
    LPARAM lParam = MAKELPARAM(x, y);

    // 发送鼠标左键按下消息到后台窗口
    PostMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, lParam);

    // 发送鼠标左键松开消息到后台窗口
    PostMessage(hwnd, WM_LBUTTONUP, 0, lParam);
}



int main() {
	
    MessageBoxW(NULL, L"欢迎使用天翼云自动登录助手！", L"惠州学院", MB_OK);
	printf("即将开始检测，请隐藏本程序");
    Sleep(1000);
    printf("\n-----------------------------------------------------------%%%%%%100%%%%%");
    Sleep(1000);
    printf("\n一轮检测开始");
   while(1){

       
        EnumWindows(EnumWindowsProc, 0);
        if (error == 1) {
            printf("\n强制断开防卡死中...");
            Sleep(2000);
            SimulateClickInBackground(client_hwnd, 200, 462);//断开
            printf("\n正在登陆中");

            Sleep(2000);
            SimulateClickInBackground(client_hwnd, 203, 406);//登录
            error = 0;

        }


        SimulateClickInBackground(client_hwnd, 203, 406);//持续登录 防止程序短暂卡死无法登录

        Sleep(5000);

    }


	//开始遍历检测是否有异常窗口



}
