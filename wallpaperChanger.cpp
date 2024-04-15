#include <bits/stdc++.h>
#include <Windows.h>
#include <winuser.h>
#include <conio.h>

using namespace std;

void changeWallpaper(const wchar_t *portrait, const wchar_t *landscape)
{
  // Initalizing devmode to detect the orientation of the laptop/tablet.
  DEVMODE devmode;
  ZeroMemory(&devmode, sizeof(DEVMODE));
  devmode.dmSize = sizeof(DEVMODE);

  int result;
  bool isLandscape = false;
  bool isPortrait = false; 
  while (true) {
      EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devmode); // Updates the current display settings.
      // Check the orientation of the display. 1 means its 90deg, 3 means its 270 deg, 0 means its 0deg and 2 means its 180 
      if (devmode.dmDisplayOrientation == 1 || devmode.dmDisplayOrientation == 3) {
        if (! isPortrait) {
          result = SystemParametersInfoW(SPI_SETDESKWALLPAPER, 2, (void *)portrait, SPIF_UPDATEINIFILE); // Sets the desktop wallpaper
          isPortrait = true;
          isLandscape = false;
        }
        
    } else {
        if (! isLandscape) {
        result = SystemParametersInfoW(SPI_SETDESKWALLPAPER, 2, (void *)landscape, SPIF_UPDATEINIFILE);
        isPortrait = false;
        isLandscape = true;
        }
      }
    }

    
}

int main() {
  // ImagePaths.
  const wchar_t *portrait = L"C:\\Users\\HP\\Pictures\\Wallpapers\\6.jpeg";
  const wchar_t *landscape = L"C:\\Users\\HP\\Pictures\\Wallpapers\\3.jpg";
  changeWallpaper(portrait, landscape) ;
  return 0;
}

