int in_area(int i, int j, int top, int left, int bottom, int right)
{
    return left <= i && i <= right && top <= j && j <= bottom;
}

void draw_color(int *addr, int color)
{
    *((char *)addr + 0) = (char)(color >> 0);
    *((char *)addr + 1) = (char)(color >> 8);
    *((char *)addr + 2) = (char)(color >> 16);
}

void kernel_main(void)
{
    // 1360 * 768
    // so, red : x:[595, 674] y:[299, 378]  green:  x:[685, 764] y:[299, 378]
    //     blue: x:[595, 674] y:[389, 468]  yellow: x:[685, 764] y:[389, 468]
    int *addr = (int *)0xffff800080000000;
    int ms_red = 0xff4325;
    int ms_blue = 0x06a4eb;
    int ms_green = 0x77b921;
    int ms_yellow = 0xf8b619;

    int i, j;
    for (int i = 0; i < 680; i++)
    {
        for (int j = 0; j < 1360; j++)
        {
            if (in_area(i, j, 595, 299, 674, 378))
            {
                draw_color(addr, ms_red);
            }
            else if (in_area(i, j, 685, 299, 764, 378))
            {
                draw_color(addr, ms_green);
            }
            else if (in_area(i, j, 595, 389, 674, 468))
            {
                draw_color(addr, ms_blue);
            }
            else if (in_area(i, j, 685, 389, 764, 468))
            {
                draw_color(addr, ms_yellow);
            }
            else
            {
                draw_color(addr, 0x000000);
            }

            addr++;
        }
    }
    while (1)
    {
    }
}
