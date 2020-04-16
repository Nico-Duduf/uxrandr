# uxrandr
Another UI for xrandr focused on color management

uxrandr is a very easy way to change gamma settings of your displays on linux.

Here is an example with three different displays:  
![Screenshot](https://github.com/Nico-Duduf/uxrandr/raw/master/uxrander-screenshot.png)

It uses xrandr, and the change is software, not hardware. That means it will work with all screen models, but at the cost of a (very little) quality loss.

## Plans

Next versions should include:

- Remember settings between sessions
- Presets (global and for each display)
- White balance
- Color space (full or TV/limited)
- More references to adjust settings (images and gradients)

## Install

Binaries are available in the [releases](https://github.com/Nico-Duduf/uxrandr/releases) section, or on [rainboxlab](https://rainboxlab.org)

Debian/Ubuntu: download and install the .deb file.

All distributions: an appImage is available.  
Note: uxrandr AppImage needs xrandr to be available, but it should be the case with most distributions as its part of X11. If not, it should be available in the package repository of your distribution.

## Compile

The easiest way is to download and install [Qt](https://www.qt.io/) and compile from Qt Designer. There are no dependencies to compile using Qt, but you'll need [xrandr](https://www.x.org/wiki/Projects/XRandR/) to use uxrandr.
