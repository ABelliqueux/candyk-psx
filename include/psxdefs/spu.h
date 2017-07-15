#define SPU_CHANNEL_COUNT 24

#define SPU_CNT_MASTER_ENABLE 0x8000
#define SPU_CNT_MASTER_UNMUTE 0x4000
#define SPU_CNT_NOISE_SHIFT(n) (((n)&0xF)<<10)
#define SPU_CNT_NOISE_STEP(n) (((n)&0x3)<<8)
#define SPU_CNT_REVERB_ENABLE 0x0080
#define SPU_CNT_IRQ9_ENABLE 0x0040
#define SPU_CNT_TRANSFER_MODE(n) (((n)&0x3)<<4)
#define SPU_CNT_TRANSFER_MODE_MASK (((0x3)&0x3)<<4)
#define SPU_CNT_EXTERNAL_REVERB 0x0008
#define SPU_CNT_CDROM_REVERB 0x0004
#define SPU_CNT_EXTERNAL_ENABLE 0x0002
#define SPU_CNT_CDROM_ENABLE 0x0001

#define SPU_STAT_TRANSFER_MODE(n) (((n)&0x3)<<4)
#define SPU_STAT_TRANSFER_MODE_MASK (((0x3)&0x3)<<4)
#define SPU_STAT_EXTERNAL_REVERB 0x0008
#define SPU_STAT_CDROM_REVERB 0x0004
#define SPU_STAT_EXTERNAL_ENABLE 0x0002
#define SPU_STAT_CDROM_ENABLE 0x0001

#define SPU_TRANSFER_MODE_STOP 0x0
#define SPU_TRANSFER_MODE_FIFO_WRITE 0x1
#define SPU_TRANSFER_MODE_DMA_WRITE 0x2
#define SPU_TRANSFER_MODE_DMA_READ 0x3

