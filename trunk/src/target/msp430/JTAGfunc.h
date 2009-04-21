// This file is rewritten from the same file in slaa149f

#ifndef __JTAGFUNC_H_INCLUDED__
#define __JTAGFUNC_H_INCLUDED__

// Controlling the Memory Address Bus(MAB)
#define IR_ADDR_16BIT					0xC1
#define IR_ADDR_CAPTURE					0x21
// Controlling the Memory Data Bus(MDB)
#define IR_DATA_TO_ADDR					0xA1
#define IR_DATA_16BIT					0x82
#define IR_DATA_QUICK					0xC2
#define IR_BYPASS						0xFF
// Controlling the CPU
#define IR_CNTRL_SIG_16BIT				0xC8
#define IR_CNTRL_SIG_CAPTURE			0x28
#define IR_CNTRL_SIG_RELEASE			0xA8
// Memory Verification Cia Pseudo Signature Analysis(PSA)
#define IR_DATA_PSA						0x22
#define IR_SHIFT_OUT_PSA				0x62
// JTAG Access Security Fuse Programming
#define IR_PREPARE_BLOW					0x44
#define IR_EX_BLOW						0x24

#define MSP430_JTAG_ID					0x89





#define msp430_jtag_init()									msp430jtagsbw_init()
#define msp430_jtag_fini()									msp430jtagsbw_fini()
#define msp430_jtag_config(has_test)						msp430jtagsbw_config(has_test)
#define msp430_jtag_clr_tclk()								msp430jtagsbw_tclk(0)
#define msp430_jtag_set_tclk()								msp430jtagsbw_tclk(1)
#define msp430_jtag_ir_w(i)									{ ir = i; msp430jtagsbw_ir((uint8*)&ir, 0); }
#define msp430_jtag_ir_rw(i, ptr)							{ *(uint8*)(ptr) = i; msp430jtagsbw_ir((uint8*)(ptr), 1); }
#define msp430_jtag_dr16_w(d)								{ dr = d; msp430jtagsbw_dr((uint32*)&dr, 16, 0); }
#define msp430_jtag_dr16_rw(d, ptr)							{ *(uint32*)(ptr) = d; msp430jtagsbw_dr((uint32*)(ptr), 16, 1); }
#define msp430_jtag_dr20_w(d)								{ dr = d; msp430jtagsbw_dr((uint32*)&dr, 20, 0); } while(0)
#define msp430_jtag_dr20_rw(d, ptr)							{ *(uint32*)(ptr) = d; msp430jtagsbw_dr((uint32*)(ptr), 20, 1); }
#define msp430_jtag_dr_poll(dr, mask, value, len, cnt, t)	msp430jtagsbw_poll((dr), (mask), (value), (len), (cnt), (t))
#define msp430_jtag_dr16_poll(dr, mask, value, cnt, t)		msp430jtagsbw_poll((dr), (mask), (value), 16, (cnt), (t))
#define msp430_jtag_reset()									msp430jtagsbw_reset()

#define delay_ms(ms)										prog->delayms((ms) | 0x8000)
#define delay_us(us)										prog->delayus((us) & 0x7FFF)
#define commit()											prog->peripheral_commit()


typedef uint16 word;
#define IR_Shift(i)											msp430_jtag_ir_w(i)
#define DR_Shift16(d)										msp430_jtag_dr16_w(d)
#define DR_Shift20(d)										msp430_jtag_dr20_w(d)
#define ClrTCLK()											msp430_jtag_clr_tclk()
#define SetTCLK()											msp430_jtag_set_tclk()
#define ResetTAP()											msp430_jtag_reset()

#define DR_Shift16_Read(d, ptr)								msp430_jtag_dr16_rw((d), (ptr))
#define IR_Shift_Read(i, ptr)								msp430_jtag_ir_rw((i), (ptr))
#define DR_Shift0()											{ dr = 1; msp430jtagsbw_dr((uint32*)&dr, 1, 0); }
#define TCLKstrobes(cnt)									msp430jtagsbw_tclk_strobe(cnt)



void ReadMem(word Format, word Addr, word *ptr);
void ExecutePOR(void);
void EraseFLASH(word EraseMode, word EraseAddr);
void ReleaseDevice(word Addr);
word EraseCheck(word StartAddr, word Length, word *CRC);
void WriteFLASH(word StartAddr, word Length, word *DataArray);
word VerifyMem(word StartAddr, word Length, word *DataArray, word *CRC);

#endif /* __JTAGFUNC_H_INCLUDED__ */

