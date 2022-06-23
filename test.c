#include <stdio.h>
#include <stdint.h>
#include "aes.h"

#define NB 4
#define NBb 16

uint8_t key[NBb];
uint8_t data[NBb];
int i;

void Cipher(uint8_t *data);
void invCipher(uint8_t *data);

void show(uint8_t *data)
{
    for (i = 0; i < NBb; i++)
    {
        printf("%02X", data[i]);
    }
    puts("");
}

int main()
{

    // 鍵とデータ入力
    for (i = 0; i < NBb; i++)
    {
        data[i] = (uint8_t)(i);
        key[i] = (uint8_t)(i + 1);
    }

    // データの表示
    printf("データ：");
    show(data);

    // 鍵の表示(今回使ってません)
    printf("鍵：");
    show(key);

    // 暗号化
    Cipher(data);

    // 暗号化後のデータの表示
    printf("暗号化：");
    show(data);

    // 復号
    invCipher(data);

    // 復号後のデータの表示
    printf("復号：");
    show(data);

    return 0;
}

void Cipher(uint8_t *data)
{

    // AddRoundKey(data, key);

    for (i = 1; i < 10; i++)
    {
        SubBytes(data);
        ShiftRows(data);
        MixColumns(data);
        // AddRoundKey(data, key);
    }

    SubBytes(data);
    ShiftRows(data);
    // AddRoundKey(data, key);
}

void invCipher(uint8_t *data)
{

    // AddRoundKey(data, key);

    for (i = 1; i < 10; i++)
    {
        invShiftRows(data);
        invSubBytes(data);
        // AddRoundKey(data, key);
        invMixColumns(data);
    }

    invShiftRows(data);
    invSubBytes(data);
    // AddRoundKey(data, key);
}