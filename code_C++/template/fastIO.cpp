// {{{ quick input & output init() before use and flush in the end
const int InputBufferSize = 67108864 << 1;//输入缓冲区大小
const int OutputBufferSize = 67108864 << 1;//输出缓冲区大小
 
namespace input
{
    char buffer[InputBufferSize],*s,*eof;
    inline void init()
    {
        s=buffer;
        eof=s+fread(buffer,1,InputBufferSize,stdin);
    }
    inline void read(int &x) {
        x=0;
        while(!isdigit(*s)) ++s;
        while(isdigit(*s)) x=x*10+*s++-'0';
    }
}

namespace output
{
    char buffer[OutputBufferSize];
    char *s=buffer;
    inline void flush() {
        fwrite(buffer,1,s-buffer,stdout);
        s=buffer;
        fflush(stdout);
    }
    inline void print(const char ch) {
        if(s-buffer>OutputBufferSize-2)flush();
        *s++=ch;
    }
    inline void print(int x)
    {
        char buf[25]= {0},*p=buf;
        if(x==0)print('0');
        while(x)*(++p)=x%10,x/=10;
        while(p!=buf)print(char(*(p--)+'0'));
    }
}
using namespace input;
using namespace output;
//}}}
