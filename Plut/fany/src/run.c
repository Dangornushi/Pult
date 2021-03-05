#include <stdio.h>
#include <string.h>
#include  "include/main.h"

int main( int argc, char *argv[] ){
    //ファイル構造体へのポインタを宣言
    FILE *fo;
    char str[1024];

	fo = fopen(argv[1], "r");

    if(fo==NULL){

        printf("Err: Can`t found file.\n");
        return -1;
    }
    while ( 1 ) {
        if ( fgets(str,1024,fo) != NULL ) {
            run(str);
        } else {
            break;
        }
    }
    //ファイルを閉じる
	fclose(fo);
    return 0;
}

void run (char str[]) {
    char *endstr;
    int len;
    if ( strncmp ( str, "call ", 4 ) == 0 ) {
        printf("%s", str);
    } else if ( endstr == 0 ) {
    }
    return;
}
