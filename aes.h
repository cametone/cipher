#pragma once
#include <stdint.h>

void SubBytes(uint8_t *data);
void ShiftRows(uint8_t *data);
void MixColumns(uint8_t *data);
void invShiftRows(uint8_t *data);
void invSubBytes(uint8_t *data);
void invMixColumns(uint8_t *data);