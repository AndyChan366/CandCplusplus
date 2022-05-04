#include <stdio.h>
#include <stdarg.h>
void printint(int dec){
    if(0 == dec){
        return;
    }
    printint(dec / 10);
    putchar(dec % 10 + '0');
}
void printstr(char *str){
    while(*str){
        putchar(*str);
        str++;
    }
}
void printfloat(float flt){
    int tempint = (int)flt;
    int tempflt = (int)(100000 *(flt - tempint));
    if(tempflt % 10 > 5){
        tempflt = tempflt /10 + 1;
    }
    else{
        tempflt = tempflt / 10;
    }
    printint(tempint);
    putchar('.');
    printint(tempflt);
}
void myprintf(const char *format,...){
    va_list ap;
    va_start(ap,format);
    while(*format){
		if(*format != '%'){
			putchar(*format);
			format++;
		}
		else{
			format++;
			switch(*format){
				case 'c':{
				char val_ch = va_arg(ap,int);
				putchar(val_ch);
				format++;
				break;
				}
				case 'd':{
					int val_int = va_arg(ap,int);
					printint(val_int);
					format++;
					break;
				}
				case 's':{
					char * val_str = va_arg(ap,char *);
					printstr(val_str);
					format++;
					break;
				}
				case 'f':{
					float val_flt = va_arg(ap,double);
					printfloat(val_flt);
					format++;
					break;
				}
				default :{
					putchar(*format);
					format++;
				}
			}
		}
    }
    va_end(ap); 
}
int main(){
	myprintf("%s\n%d\n%c\n%f\n","string",12345,'c',123.45);
}
