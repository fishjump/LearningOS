# Learning OS
Write this OS for learning OS.

## TODO
- [x] bootloader
- [ ] system 
  - [ ] boot
    - [ ] BootInfo
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

2020/8/24:
  I need a class to put bootloader's information(e.g. graphic memory address, memory map, etc.). So, I add an namepsace boot under system.

2020/8/23:
  In order to support singleten pattern for class Screen, I need to support memory management first. Thus, I can call ```Screen::initScreen()```, and use ```Screen::getInstance()``` to get the only Screen object. Those above is beneficial for the consistency of screen data. 