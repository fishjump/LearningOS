# Learning OS
Write this OS for learning OS.

## TODO
- [x] bootloader
- [ ] system 
  - [ ] io
    - [ ] Screen
      - [x] drawPixel
      - [x] drawChar
      - [ ] frame buffer
      - [ ] printk
      - [ ] change screen mode
    - [ ] Keyborad
  - [ ] memory
    - [ ] malloc
    - [ ] free
  - [x] media
    - [x] Color
    - [x] Font 

## Update Log

2020/8/23:
  In order to support singleten pattern for class Screen, I need to support memory management first. Thus, I can call ```Screen::initScreen()```, and use ```Screen::getInstance()``` to get the only Screen object. Those above is beneficial for the consistency of screen data. 