#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 *  文字列を連結する
 * 
 *  引数で受け取る文字列は「配列型」を期待
 *  逆にポインタ型で定義するとエラーが発生するので注意
 */
char* str_concat(char *str1, const char *str2) {

    // str1の最初のアドレスを保持しておく
    char *top = str1;

    // 文字列終端までポインタを進める
    while (*(str1++) != '\0');

    // `\0`分を消すため、ポインタをひとつ戻す（連結のため）
    str1 -= 1;

    // 終端直前から、str2の文字を追加していく
    do {
        *(str1++) = *str2;
    } while (*(str2++) != '\0');

    return str1;
}

/**
 *  mallocを使ってヒープに領域を確保するパターン
 */
char* str_concat2(const char *str1, const char *str2, char **result) {

    // 連結後の文字列分の領域を確保する（+1は終端文字（\0）分）
    size_t size = sizeof(char) * (strlen(str1) + strlen(str2) + 1);
    char *work = (char*)malloc(size);
    if (work == NULL) {
        printf("Cannot allocate memory.\n");
        return NULL;
    }

    // 確保した領域の最初のアドレスを保持しておく
    char *top = work;

    // str1をコピー
    strcpy(work, str1);

    // 追加した文字数分、ポインタを進める
    work += strlen(str1);

    // str2をコピー
    strcpy(work, str2);

    // 確保した先頭アドレスを結果に格納
    *result = top;

    return top;
}

/**
 *  文字列を置換する
 *
 *  @param src 評価する文字列
 *  @param target  置き換え対象となる文字列
 *  @param replace 置き換える文字列
 *  @param result  置換後の文字列を返すポインタ
 */
void str_replace(const char *src, const char *target, const char *replace, char **result) {

    char *temp = (char*)malloc(sizeof(char) * 1000);
    if (temp == NULL) {
        printf("Cannot allocate memory.\n");
        return;
    }

    char *top = temp;

    // 操作できるようにコピーする
    char *work = (char*)malloc(sizeof(char) * strlen(src));
    strcpy(work, src);

    char *p;
    while ((p = strstr(work, target)) != NULL) {
        // 検知した位置に文字列終端文字を挿入
        *p = '\0';

        // 検知した位置＋対象文字数分の位置にポインタを移動
        p += strlen(target);

        // 該当文字列以降をいったんtempに退避
        strcpy(temp, p);

        // 前半文字列と置き換え文字列を連結する
        str_concat(work, replace);
        str_concat(work, temp);
    }

    free(temp);

    *result = work;
}


int main() {
    char src[100] = "1. this is a test.";
    char *replace = "t";
    char *target  = "|";
    char *result;

    str_replace(src, replace, target, &result);
    printf("%s\n", result); // => "1. |his is a |es|."

    free(result);

    return 0;
}