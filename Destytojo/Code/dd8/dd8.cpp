#include <windows.h>
#include <string.h>
#include <stdio.h>
#include "dd8.h"
// global objects

LRESULT CALLBACK WindowProc2345(HWND,UINT,WPARAM,LPARAM);
char szWinName[] = "MyWindow";

int WINAPI WinMain (HINSTANCE hThisInst,
                    HINSTANCE hPrevInst,
                        LPSTR lpszArgs,
                          int nWinMode)
{
   HWND hwnd;
   MSG msg;
   WNDCLASS wcl;
   HACCEL hAccel;
   
   // Windows class determination
   wcl.hInstance = hThisInst; // descriptor of application
   wcl.lpszClassName = szWinName; // name of windows class
   wcl.lpfnWndProc = WindowProc2345; // function of window
   wcl.style = 0; // default style
   wcl.hIcon = LoadIcon (NULL, IDI_APPLICATION); // standard icon
   wcl.hCursor = LoadCursor (NULL, IDC_ARROW); // standard cursor
   wcl.lpszMenuName="MYMENU_002"; // main menu

   //wcl.lpszMenuName=NULL; // no menu
   wcl.cbClsExtra= 0; // no additional
   wcl.cbWndExtra= 0; // information

   // to fill window by white color
   wcl.hbrBackground = (HBRUSH)GetStockObject (WHITE_BRUSH);
   //wcl.hbrBackground = (HBRUSH)GetStockObject (BLACK_BRUSH);
   
   // to register the window class
   if ( !RegisterClass (&wcl)) return 0;

   // to create window
   hwnd= CreateWindow (
                        szWinName, // class name
                        "MENU AND MANIPULATOR", // window header
                        WS_OVERLAPPEDWINDOW, // window style
                        CW_USEDEFAULT, // X-coordinate, from Windows
                        CW_USEDEFAULT, // Y-coordinate, from Windows
                        CW_USEDEFAULT, // width, from Windows
                        CW_USEDEFAULT, // high, from Windows
                        HWND_DESKTOP, // no additional window
                        (HMENU) NULL, // use class menu
                        hThisInst, // descriptor
                        NULL); // no additional arguments
   // to load accelerator
   hAccel = LoadAccelerators (hThisInst,"MYMENU_002");

   //to show window and redraw content
   ShowWindow (hwnd,nWinMode);
   UpdateWindow(hwnd);

   // cycle of annonses
   while ( GetMessage (&msg, NULL,0,0))
   {
      if (!TranslateAccelerator (hwnd,hAccel,&msg))
      {
          TranslateMessage (&msg); // to use keyboard
          DispatchMessage (&msg); // to return direction from Windows
      }
   };
   return msg.wParam;
}
// ====================================================================
LRESULT CALLBACK WindowProc2345 (HWND hwnd,
                                 UINT message,
                               WPARAM wParam,
                               LPARAM lParam)
{
   int response;
   switch (message)
   {
      case WM_COMMAND: //
      switch ( LOWORD (wParam))
      {
         case IDM_ALPHA:   MessageBox (hwnd, "Alpha",   "A",  MB_OK); break;
         case IDM_BETA:    MessageBox (hwnd, "Beta",    "B",  MB_OK); break;
         case IDM_GAMMA:   MessageBox (hwnd, "Gamma",   "G",  MB_OK); break;
         case IDM_EPSILON: MessageBox (hwnd, "Epsilon", "E",  MB_OK); break;
         case IDM_ZETA:    MessageBox (hwnd, "Zeta",    "Z",  MB_OK); break;
         case IDM_ETA:     MessageBox (hwnd, "Eta",     "E",  MB_OK); break;
         case IDM_THETA:   MessageBox (hwnd, "Theta",   "Th", MB_OK); break;
         case IDM_HELP:    MessageBox (hwnd, "No Help", "Help", MB_OK);break;
      };
      break;

      case WM_RBUTTONDOWN: // right button of mouse
          response = MessageBox (hwnd, "Select action:",
                               "Right button", MB_ABORTRETRYIGNORE);
      switch (response)
      {
          case IDABORT:  MessageBox (hwnd, "", "Abort",  MB_OK); break;
          case IDRETRY:  MessageBox (hwnd, "", "Retry",  MB_OK); break;
          case IDIGNORE: MessageBox (hwnd, "", "Ignore", MB_OK); break;
      };
      
      case WM_LBUTTONDOWN: // left button of mouse
          response = MessageBox (hwnd, "Continue ?",
                              "Left button", MB_ICONHAND | MB_YESNO);
      switch (response)
      {
          case IDYES: MessageBox (hwnd, "Press", "YES", MB_OK); break;
          case IDNO:  MessageBox (hwnd, "Press", "NO",  MB_OK); break;
      };
      
      case WM_DESTROY: // to end program
         PostQuitMessage (0); break;
      default:
            
      return DefWindowProc (hwnd, message, wParam, lParam);
   }
   return 0;
}
