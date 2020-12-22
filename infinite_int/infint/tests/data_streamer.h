#ifndef DATA_STREAMER_H
#define DATA_STREAMER_H

#define MAX_STREAMS_NUM 10

#define STREAM_MEM_POS__START   0
#define STREAM_MEM_POS__CURRENT 1
#define STREAM_MEM_POS__END     2

#define STREAM_WR_MODE__INSERT  0
#define STREAM_WR_MODE__REPLACE 1

int rd(void* ptr, unsigned int len, unsigned int id);
int wr(void* ptr, unsigned int len, int mode, unsigned int id);
int rm(int len, int id);
int pos(int pos, int shift, unsigned int id);
unsigned int crt(void);
int del(int id);

#endif//DATA_STREAMER_H
