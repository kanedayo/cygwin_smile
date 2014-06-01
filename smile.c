#include <stdio.h>
#include <string.h>

void chop(char *st)
{
  char *p;
  p=st+strlen(st)-1;
  while( (*p=='\r') || (*p=='\n') ){
    *p='\0';
    p=st+strlen(st)-1;
  }
}
int main(int argc,char**argv)
{
  FILE *fi,*fo;
  char buf[256];
  char *st;

  if(argc==2) {
    fi=fopen(argv[1],"r");
    strcpy(buf,argv[1]);
    //strcpy(buf+strlen(buf)-4,".log"); // ".xxx"->".log"
    strcpy(buf+strlen(buf)-4,"_smile"); // ".xxx" -> "_smile.xxx"
    strcpy(buf+strlen(buf)  ,argv[1]+strlen(argv[1])-4);
    fo=fopen(buf,"w");

    while(st=fgets(buf,sizeof(buf),fi)){
      chop(st);
      fprintf(fo,"%s(^^)/~\n",st);
    }

    close(fi);
    close(fo);
    return 0;

  } else {
    printf("USAGE: %s filename",argv[0]);
    return 0;
  }
}
