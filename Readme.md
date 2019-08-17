# Systray Experiments

## Description

This project is about creating a systray icon. It is a C++ program which uses GTK3+ to create and interact with a System Tray icon.
The menu entries simply call GTK callback functions which can then do any task which may include changing the icon which is demonstrated with the "Low, Medium and High Security" buttons. (Not that any functionality has been associated with this when you try it out.)

Screenshot of the AppIndicator (blue):

![Screenshot](https://richardeigenmann.github.io/Systray/Screenshot_Systray.png)

The menu expaned when right-clicked:

![Screenshot](https://richardeigenmann.github.io/Systray/Screenshot_Menu_Open.png)

The changed icon of the AppIndicator (shield):

![Screenshot](https://richardeigenmann.github.io/Systray/Screenshot_Icon_Changed.png)

## See also

* https://wiki.ubuntu.com/DesktopExperienceTeam/ApplicationIndicators
* Use gtk3-icon-browser to see the installed icons

## Prerequisites to build on openSUSE Linux

```bash
sudo zypper in gtk3-devel libappindicator3-devel
```

## Build and run

```bash
git clone https://github.com/richardeigenmann/Systray.git
cd Systray
mkdir -p build
cd build
cmake ..
# or cmake -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_CC_COMPILER=/usr/bin/clang ..
# or cmake -DCMAKE_CXX_COMPILER=/usr/bin/g++-6 -DCMAKE_CC_COMPILER=/usr/bin/gcc ..
make
./systrayApp
```