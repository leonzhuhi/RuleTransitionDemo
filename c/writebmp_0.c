#include <stdio.h>

#define WIDTH 640
#define HEIGHT 480

unsigned char bmp_header[] = {
	0x42, 0x4D, 0x38, 0x10, 0x0E, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,  
	0x00, 0x00, (WIDTH & 0xff), (WIDTH & 0xff00) >> 8, (WIDTH & 0xff0000) >> 16, (WIDTH & 0xff000000) >> 24, (HEIGHT & 0xff), (HEIGHT & 0xff00) >> 8,
	(HEIGHT & 0xff0000) >> 16, (HEIGHT & 0xff000000) >> 24, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,  
	0x00, 0x00, 0x02, 0x10, 0x0E, 0x00, 0x12, 0x0B, 
	0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x00, 0x00,  
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

int main()
{
	FILE *fp = NULL;
	int x, y;
	unsigned char pixel[3] = {0};
	
	printf("write bmp start\n");
	if(NULL == (fp = fopen("writebmp_out.bmp", "wb+")))
	{
		printf("open file error\n");
		return 0;
	}
	fwrite(bmp_header, sizeof(bmp_header), 1, fp);
	for(y = 0; y < HEIGHT; y++)
	{
		for(x = 0; x < WIDTH; x++)
		{
			pixel[0] = (y > HEIGHT/2) ? 0xff : 0x00;
			pixel[1] = 0x00;
			pixel[2] = 0x00;
			fwrite(pixel, 3, 1, fp);
		}
	}
	fclose(fp);
	printf("write bmp end\n");
	return 0;
}
