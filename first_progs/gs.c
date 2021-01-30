#include <stdio.h>
#include <windows.h>

void main()
{
	FILE* file = NULL;
	BITMAPFILEHEADER bfh;
	BITMAPINFOHEADER bih;
	RGBTRIPLE rt, bs[333960];
	
	int grey=0;
	
	fopen_s(&file, "C:/Users/Ingenerium/notepad/MonaLisa.bmp", "rb");
	
	fread(&bfh, sizeof(BITMAPFILEHEADER), 1, file);
	
	printf("%d \n", bfh.bfOffBits);
	
	fread(&bih, sizeof(BITMAPINFOHEADER), 1, file);
	
	fread(&bs, sizeof(RGBTRIPLE), 333960, file);
	
	printf("%d x %d\n", bih.biWidth, bih.biHeight);
	
	fclose(file);
	
	fopen_s(&file, "C:/Users/Ingenerium/notepad/test1.bmp", "wb");
	
	for(int i = 0; i < 333960; i++){
		grey = bs[i].rgbtBlue*7/100 + bs[i].rgbtGreen*7/10 + bs[i].rgbtRed/5;
		bs[i].rgbtBlue = grey;
		bs[i].rgbtGreen = grey;
		bs[i].rgbtRed = grey;
	}
	
	//for(int i = 0; i < 200; i++) {
	//
	//	for(int i = 0; i < 200; i++)
	//}
	
	fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, file);
	fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, file);
	fwrite(&bs, sizeof(RGBTRIPLE), 333960, file);
	fread(&rt, sizeof(RGBTRIPLE), 1, file);
	
//	printf("%d %d %d\n", rt.rgbtBlue, rt.rgbtGreen, rt.rgbtRed);
	fclose(file);
}