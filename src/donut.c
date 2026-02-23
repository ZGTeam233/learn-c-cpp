// 经典 ASCII 甜甜圈的 C 语言实现，最初由 Andy Sloane 于 2011 年创建。
// A C implementation of the classic ASCII donut, originally created by Andy Sloane in 2011.
//
// 这个程序使用了简单的数学函数来计算甜甜圈的形状，并通过 ASCII 字符在终端上显示出来。
// The program uses simple mathematical functions to calculate the shape of the donut and displays it in the terminal
// using ASCII characters.
//
// 这里为源码，在这里仅为学习参考引用，我也并非原作者，原帖地址：https://www.a1k0n.net/2011/07/20/donut-math.html
// The source code is provided here for learning reference, and I am not the original author. The original post can
// be found at: https://www.a1k0n.net/2011/07/20/donut-math.html
//
//              k;double sin()
//          ,cos();main(){float A=
//        0,B=0,i,j,z[1760];char b[
//      1760];printf("\x1b[2J");for(;;
//   ){memset(b,32,1760);memset(z,0,7040)
//   ;for(j=0;6.28>j;j+=0.07)for(i=0;6.28
//  >i;i+=0.02){float c=sin(i),d=cos(j),e=
//  sin(A),f=sin(j),g=cos(A),h=d+2,D=1/(c*
//  h*e+f*g+5),l=cos      (i),m=cos(B),n=s\
// in(B),t=c*h*g-f*        e;int x=40+30*D*
// (l*h*m-t*n),y=            12+15*D*(l*h*n
// +t*m),o=x+80*y,          N=8*((f*e-c*d*g
//  )*m-c*d*e-f*g-l        *d*n);if(22>y&&
//  y>0&&x>0&&80>x&&D>z[o]){z[o]=D;;;b[o]=
//  ".,-~:;=!*#$@"[N>0?N:0];}}/*#****!!-*/
//   printf("\x1b[H");for(k=0;1761>k;k++)
//    putchar(k%80?b[k]:10);A+=0.04;B+=
//      0.02;}}/*****####*******!!=;:~
//        ~::==!!!**********!!!==::-
//          .,~~;;;========;;;:~-.
//              ..,--------,*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int k;
double sin(), cos();

int main() {
    float A = 0, B = 0, i, j, z[1760];
    char b[1760];
    
    printf("\x1b[2J");  // 清屏
    
    for (;;) {
        memset(b, 32, 1760);  // 用空格填充
        memset(z, 0, 7040);   // 深度缓冲清零
        
        for (j = 0; j < 6.28; j += 0.07) {          // theta
            for (i = 0; i < 6.28; i += 0.02) {      // phi
                float c = sin(i);
                float d = cos(j);
                float e = sin(A);
                float f = sin(j);
                float g = cos(A);
                float h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = cos(i);
                float m = cos(B);
                float n = sin(B);
                float t = c * h * g - f * e;
                
                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                
                if (y > 0 && y < 22 && x > 0 && x < 80 && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        
        printf("\x1b[H");  // 光标回到左上角
        for (k = 0; k < 1761; k++) {
            putchar(k % 80 ? b[k] : 10);  // 每80个字符换行
        }
        
        A += 0.04;
        B += 0.02;
    }
    
    return 0;
}