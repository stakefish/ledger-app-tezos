#pragma once

#include "os.h"
#include <stdbool.h>
#include <stdint.h>

#include "apdu.h"

#define MAX_BIP32_PATH 10

typedef struct {
    cx_curve_t curve;
    int highest_level;
    uint8_t path_length;
    uint32_t bip32_path[MAX_BIP32_PATH];
} nvram_data;
extern WIDE nvram_data N_data_real;
#define N_data (*(WIDE nvram_data*)PIC(&N_data_real))

void authorize_baking(cx_curve_t curve, void *data, int datalen, uint32_t *bip32_path, uint8_t pathLength);
void write_highest_level(int level);
void check_baking_authorized(cx_curve_t curve, void *data, int datalen, uint32_t *bip32_path,
                             uint8_t path_length);
bool is_path_authorized(cx_curve_t curve, uint32_t *bip32_path, uint8_t path_length);
void update_high_water_mark(void *data, int datalen);
bool is_level_authorized(int level);

#define INS_RESET 0x06
unsigned int handle_apdu_reset(uint8_t instruction);
