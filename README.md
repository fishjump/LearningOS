# Learning OS
Write this OS for learning OS.

## TODO
- [x] bootloader
- [ ] screen
  - [x] method drawPixel
  - [x] method drawChar
  - [x] class Color  
  - [ ] frame buffer
  - [ ] printk
  - [ ] change screen mode
- [ ] keyborad
- [ ] memory
  - [ ] malloc
  - [ ] free

## Update Log

2020/8/23:
  In order to support singleten pattern for class Screen, I need to support memory management first. Thus, I can call ```Screen::initScreen()```, and use ```Screen::getInstance()``` to get the only Screen object. Those above is beneficial for the consistency of screen data. 