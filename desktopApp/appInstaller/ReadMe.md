# Creating an installer

## Automatically creating the installer

Running bash or bat files to create the installer
### Linux

todo: Create a bash script which 
1. Wipes the data directory
2. builds the desktop desktopApp in release mode to a binary
3. Copies the desktop release  binary to the data folder
4. Gets all application dependencies and copies them to the data directory
5. Builds the installer application
6. Optionally deploys the binary
### Windows

todo: Create a bat script which 
1. Wipes the data directory
2. builds the desktop desktopApp in release mode to a binary
3. Copies the desktop release  binary to the data folder
4. Gets all application dependencies and copies them to the data directory
   by running the `windeployqt.exe` on the `cpuBroadcast.exe` desktop binary
5. Builds the installer application
6. Optionally deploys the binary

## Manually creating the installer



### Linux installer

What is needed to create a linux installer to 
be used to deploy your desktopApp to linux users.

1. In terminal cd into root folder of the repository and clean data folder
    ```shell
    cd /home/gudjon/repos/personal/cpuBroadcast
    ```
2. Build release version of the desktop desktopApp in Qt creator.
    ```shell
    ~/Qt/Tools/QtCreator/bin/qtcreator desktopApp/cpuBroadcast &
    ```
3. Clean the data directory and copy the linux release version of the desktop desktopApp to the directory installer data directory
    ```shell
    rm -rf desktopApp/appInstaller/packageDir/packages/com.guttih.cpubroadcast/data/*
    mkdir -p desktopApp/appInstaller/packageDir/packages/com.guttih.cpubroadcast/data
    cp desktopApp/build-cpuBroadcast-Desktop_Qt_6_2_4_GCC_64bit-Release/cpuBroadcast desktopApp/appInstaller/packageDir/packages/com.guttih.cpubroadcast/data
    ```
5. Build binary with linux package dependencies
```shell
#todo:get https://github.com/probonopd/linuxdeployqt working, 
# and probably need also https://github.com/OlivierLDff/QtLinuxCMake
#Tried copying these files to workstation but it did not work, try something else
cd desktopApp/appInstaller/packageDir/packages/com.guttih.cpubroadcast/data
cp /media/sf_gudjon/Qt/6.4.2/gcc_64/lib/libQt6Widgets.so.6 .
cp /media/sf_gudjon/Qt/6.4.2/gcc_64/lib/libQt6Gui.so.6 .
cp /media/sf_gudjon/Qt/6.4.2/gcc_64/lib/libQt6Core.so.6 .
cp /media/sf_gudjon/Qt/6.4.2/gcc_64/lib/libQt6DBus.so.6 .
cp /media/sf_gudjon/Qt/6.4.2/gcc_64/lib/libicui18n.so.56 . 
cp /media/sf_gudjon/Qt/6.4.2/gcc_64/lib/libicuuc.so.56 .
cp /media/sf_gudjon/Qt/6.4.2/gcc_64/lib/libicudata.so.56 .



```

6. Build the installer
    ```shell
    ~/Qt/Tools/QtInstallerFramework/4.5/bin/binarycreator -c desktopApp/appInstaller/packageDir/config/config.xml -p desktopApp/appInstaller/packageDir/packages desktopApp/appInstaller/cpuBroadcastInstaller.run

    ```

### Windows installer

What is needed to create a windows installer to 
be used to deploy your desktopApp to windows users.

1. Open cmd and cd into root folder of the repository
```cmd
set WORK_DIR="C:\Users\gutti\source\repos\cpuBroadcast"
set PACK_DIR="%WORK_DIR%\desktopApp\appInstaller\packageDir"
```
2. Open *Qt Creator*
```cmd
C:\forrit\Qt\Tools\QtCreator\bin\qtcreator.exe "%WORK_DIR%\desktopApp\cpuBroadcast"
```
3. Build release version of the desktop desktopApp in Qt creator.
4. Clean the data directory
```cmd
rmdir /s /q "%PACK_DIR%\packages\com.guttih.cpubroadcast\data"
mkdir "%PACK_DIR%\packages\com.guttih.cpubroadcast\data"
del "%WORK_DIR%\desktopApp\appInstaller\cpuBroadcastInstaller.exe"
```
5. Copy the windows release version of the desktop desktopApp to the directory installer data directory
```cmd
copy "%WORK_DIR%\desktopApp\build-cpuBroadcast-Desktop_Qt_6_4_2_MinGW_64_bit-Release\cpuBroadcast.exe" "%PACK_DIR%\packages\com.guttih.cpubroadcast\data"
```
6. Build binary with windows dependencies
```cmd
C:\forrit\Qt\6.4.2\mingw_64\bin\qtenv2.bat
cd "%PACK_DIR%\packages\com.guttih.cpubroadcast\data"
windeployqt.exe cpuBroadcast.exe
```
7. Build the installer
```cmd
cd "%PACK_DIR%"
C:\forrit\Qt\Tools\QtInstallerFramework\4.5\bin\binarycreator.exe -c config\config.xml -p packages "..\cpuBroadcastInstaller.exe"
```
7. Run and test the installer
```cmd
"%WORK_DIR%\desktopApp\appInstaller\cpuBroadcastInstaller.exe"
```