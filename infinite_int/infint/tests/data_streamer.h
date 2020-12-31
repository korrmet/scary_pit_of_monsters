#ifndef DATA_STREAMER_H
#define DATA_STREAMER_H

#define MAX_STREAMS_NUM 10

#define STREAM_MEM_POS__START   0
#define STREAM_MEM_POS__CURRENT 1
#define STREAM_MEM_POS__END     2

#define STREAM_WR_MODE__INSERT  0
#define STREAM_WR_MODE__REPLACE 1

/** \brief  read from data stream
 *  \param  ptr pointer to data buffer which be used to read
 *  \param  len length of data will be readen
 *  \param  id  id of data stream
 *  \return num of actually readen bytes or error sequence
 *  \retval -1  error occured
 *  \retval >=0 num of actually readen bytes */
int rd(void* ptr, unsigned int len, unsigned int id);

/** \brief  write to data stream
 *  \param  ptr pointer to data must be written in stream
 *  \param  len number of bytes which must be written in stream
 *  \param  mode mode of write. can be STREAM_WR_MODE__INSERT or 
 *               STREAM_WR_MODE__REPLACE
 *  \param  id  identifier of data stream */
int wr(void* ptr, unsigned int len, int mode, unsigned int id);
int rm(int len, int id);
int pos(int pos, int shift, unsigned int id);
unsigned int crt(void);
int del(int id);

#endif//DATA_STREAMER_H
