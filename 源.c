#include<stdio.h>
#include<Windows.h>
#include <string.h>


//����ȫ�ֱ���
int client_hwnd;
int error;

void SimulateClickInBackground(HWND hwnd, int x, int y);



BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    

    char windowTitle[256];  // �洢���ڱ���
    
    // ��ȡ���ڱ���
    if (GetWindowTextA(hwnd, windowTitle, sizeof(windowTitle))) {
        // ��ӡ���ھ���ʹ��ڱ���
      //  printf("%s\n",windowTitle);
        if (strcmp(windowTitle, "��ʾ") == 0) {//��ȡ���󴰿�

            printf("\n��⵽����Ͽ�,�����رմ��󴰿�");
            Sleep(2000);
            PostMessage(hwnd, WM_CLOSE, 0, 0);
            error = 1;
            
        }
        if (strcmp(windowTitle, "У԰�ͻ���")==0) {//��ȡ������
            
            printf("\n�����---------");
            Sleep(2000);
            client_hwnd = hwnd;


           

        }
    }

    return TRUE;  // ���� TRUE ����ö����һ������
}

void SimulateClickInBackground(HWND hwnd, int x, int y) {
    // �� x �� y ����ת��Ϊ lParam ��ʽ����16λ�洢x����16λ�洢y��
    LPARAM lParam = MAKELPARAM(x, y);

    // ����������������Ϣ����̨����
    PostMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, lParam);

    // �����������ɿ���Ϣ����̨����
    PostMessage(hwnd, WM_LBUTTONUP, 0, lParam);
}



int main() {
	
    MessageBoxW(NULL, L"��ӭʹ���������Զ���¼���֣�", L"����ѧԺ", MB_OK);
	printf("������ʼ��⣬�����ر�����");
    Sleep(1000);
    printf("\n-----------------------------------------------------------%%%%%%100%%%%%");
    Sleep(1000);
    printf("\nһ�ּ�⿪ʼ");
   while(1){

       
        EnumWindows(EnumWindowsProc, 0);
        if (error == 1) {
            printf("\nǿ�ƶϿ���������...");
            Sleep(2000);
            SimulateClickInBackground(client_hwnd, 200, 462);//�Ͽ�
            printf("\n���ڵ�½��");

            Sleep(2000);
            SimulateClickInBackground(client_hwnd, 203, 406);//��¼
            error = 0;

        }


        SimulateClickInBackground(client_hwnd, 203, 406);//������¼ ��ֹ������ݿ����޷���¼

        Sleep(5000);

    }


	//��ʼ��������Ƿ����쳣����



}
