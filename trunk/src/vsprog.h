/***************************************************************************
 *   Copyright (C) 2009 by Simon Qian <SimonQian@SimonQian.com>            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef __VSPROG_H_INCLUDED__
#define __VSPROG_H_INCLUDED__

#define CHIP_ID						(1 << 0)
#define BOOTLOADER					(1 << 1)
#define APPLICATION					(1 << 2)
#define EEPROM						(1 << 3)
#define OTP_ROM						(1 << 4)
#define FUSE						(1 << 5)
#define LOCK						(1 << 6)
#define USER_SIG					(1 << 7)
#define CHECKSUM					(1 << 8)
#define ALL							(1 << 31)
#define TARGET_AREA_MASK			(BOOTLOADER | APPLICATION | EEPROM \
									 | OTP_ROM | FUSE | LOCK | USER_SIG \
									 | CHECKSUM | ALL)
#define NUM_OF_TARGET_AREA			9

typedef struct
{
	uint32 erase_operations;
	uint32 write_operations;
	uint32 read_operations;
	uint32 verify_operations;
	uint32 checksum_operations;
}operation_t;

extern uint8 gui_mode;

#endif /* __VSPROG_H_INCLUDED__ */

