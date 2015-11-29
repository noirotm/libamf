#ifndef __IO_H__
#define __IO_H__

#include "amf.h"

/* structure used to mimic a stream with a memory buffer */
typedef struct buffer_context_t {
    uint8_t * start_address;
    uint8_t * current_address;
    size_t buffer_size;
} buffer_context;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* callback function to mimic fread using a memory buffer */
size_t buffer_read(void * out_buffer, size_t size, void * user_data);

/* callback function to mimic fwrite using a memory buffer */
size_t buffer_write(const void * in_buffer, size_t size, void * user_data);

/* callback function to read data from a file stream */
size_t file_read(void * out_buffer, size_t size, void * user_data);

/* callback function to write data to a file stream */
size_t file_write(const void * in_buffer, size_t size, void * user_data);

/** IO helper functions */

/* read a big-endian 64-bit floating point value */
size_t read_number64_be(amf_read_proc_t read_proc, void * user_data, number64_t * val);

/* read a big-endian unsigned 32-bit integer */
size_t read_uint32_be(amf_read_proc_t read_proc, void * user_data, uint32_t * val);

/* read a big-endian unsigned 16-bit integer */
size_t read_uint16_be(amf_read_proc_t read_proc, void * user_data, uint16_t * val);

/* read a big-endian signed 16-bit integer */
size_t read_int16_be(amf_read_proc_t read_proc, void * user_data, int16_t * val);

/* write a big-endian 64-bit floating point value */
size_t write_number64_be(amf_write_proc_t write_proc, void * user_data, number64_t val);

/* write a big-endian unsigned 32-bit integer */
size_t write_uint32_be(amf_write_proc_t write_proc, void * user_data, uint32_t val);

/* write a big-endian unsigned 16-bit integer */
size_t write_uint16_be(amf_write_proc_t write_proc, void * user_data, uint16_t val);

/* write a big-endian signed 16-bit integer */
size_t write_int16_be(amf_write_proc_t write_proc, void * user_data, int16_t val);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __IO_H__ */
