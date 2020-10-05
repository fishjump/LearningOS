# Learning OS
Write this OS for learning OS.

## Memory Map
Memory map 
|Adress start|Adress end|Description|
|------------|----------|-----------|
|0x0         |0xFFF     |EfiBootServicesCode|
|0x1000      |0x5FFFF   |EfiConventionalMemory|
|0x60000     |0x6FFFF   |Boot Info|
|0x70000     |0x9FFFF   |EfiConventionalMemory|
|0xA0000     |0xFFFFF   |Used by VGA|
|0x100000    |0x100FFF  |kernel header code|
|0x101000    |0x101FFF  |page directory entry|
|0x102000    |0x102FFF  |page table entry|
|0x103000    |0x103FFF  |page table entry|
|0x104000    |0x104FFF  |page table entry|
Get more paging information via: https://wiki.osdev.org/Paging

## x86_64 CPU address map strategy

64 bits address on paper, but only 48 bits are available.

### 1GB page

| Page Directory Index | Page Table Index   | Page Intern Offset  | Total Bits |
| -------------------- | ------------------ | ------------------- | ---------- |
| 9 bits (512 items)   | 9 bits (512 items) | 30 bits (1 GB Page) | 48 bits    |

### 2MB page

| Page Directory 1 Index | Page Directory 2 Index | Page Table Index   | Page Intern Offset  | Total Bits |
| ---------------------- | ---------------------- | ------------------ | ------------------- | ---------- |
| 9 bits (512 items)     | 9 bits (512 items)     | 9 bits (512 items) | 21 bits (2 MB Page) | 48 bits    |

### 4KB page

| Page Directory 1 Index | Page Directory 2 Index | Page Directory 3 Index | Page Table Index   | Page Intern Offset  | Total Bits |
| ---------------------- | ---------------------- | ---------------------- | ------------------ | ------------------- | ---------- |
| 9 bits (512 items)     | 9 bits (512 items)     | 9 bits (512 items)     | 9 bits (512 items) | 12 bits (4 KB Page) | 48 bits    |

## TODO
- [x] bootloader
- [ ] system 
  - [x] boot
    - [x] BootInfo
  - [ ] io
    - [ ] Screen
      - [x] drawPixel
      - [x] drawChar
      - [ ] frame buffer
      - [ ] print
      - [ ] change screen mode
    - [ ] Keyborad
  - [ ] memory
    - [ ] malloc
    - [ ] free
  - [x] media
    - [x] Color
    - [x] Font 

## Update Log
2020/10/5:
  Memory management almost done. Now it's quite simply, but let's do some other parts, and then go back to the memory management.

2020/10/4:
  Didn't update for a long time. I was so busy recently. Partially updated memory management and used sfinae to implement print now. 

2020/8/30:
  Update memory map.

2020/8/26:
  Implement BootInfo, now we can access data which comes from UEFI, and I use ```system::boot::bootInfo->graphicInfo``` to replace hard-coded screen parameters(memory, width, height, etc.)

2020/8/24:
  I need a class to put bootloader's information(e.g. graphic memory address, memory map, etc.). So, I add an namepsace boot under system.

2020/8/23:
  In order to support singleten pattern for class Screen, I need to support memory management first. Thus, I can call ```Screen::initScreen()```, and use ```Screen::getInstance()``` to get the only Screen object. Those above is beneficial for the consistency of screen data. 