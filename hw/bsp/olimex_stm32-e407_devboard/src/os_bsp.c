/**
 * Copyright (c) 2015 Runtime Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * XXXX for now have this here.
 */
#include <util/flash_map.h>

static struct flash_area bsp_flash_areas[] = {
    [FLASH_AREA_BOOTLOADER] = {
        .fa_flash_id = 0,	/* internal flash */
        .fa_off = 0x08000000,	/* beginning */
        .fa_size = (32 * 1024)
    },
    /* 2 * 16K and 1*64K sectors here */
    [FLASH_AREA_IMAGE_0] = {
        .fa_flash_id = 0,
        .fa_off = 0x08020000,
        .fa_size = (384 * 1024)
    },
    [FLASH_AREA_IMAGE_1] = {
        .fa_flash_id = 0,
        .fa_off = 0x08080000,
        .fa_size = (384 * 1024)
    },
    [FLASH_AREA_IMAGE_SCRATCH] = {
        .fa_flash_id = 0,
        .fa_off = 0x080e0000,
        .fa_size = (128 * 1024)
    },
    [FLASH_AREA_NFFS] = {
        .fa_flash_id = 0,
        .fa_off = 0x08008000,
        .fa_size = (32 * 1024)
    }
};

void *_sbrk(int incr);
void _close(int fd);

void
os_bsp_init(void)
{
    /*
     * XXX this reference is here to keep this function in.
     */
    _sbrk(0);
    _close(0);
    flash_area_init(bsp_flash_areas,
                    sizeof(bsp_flash_areas) / sizeof(bsp_flash_areas[0]));
}


