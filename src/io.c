#include <stdio.h>
#include <string.h>

#include "io.h"

/* callback function to mimic fread using a memory buffer */
size_t buffer_read(void * out_buffer, size_t size, void * user_data) {
    buffer_context * ctxt = (buffer_context *)user_data;
    if (ctxt->current_address >= ctxt->start_address &&
        ctxt->current_address + size <= ctxt->start_address + ctxt->buffer_size) {

        memcpy(out_buffer, ctxt->current_address, size);
        ctxt->current_address += size;
        return size;
    }
    else {
        return 0;
    }
}

/* callback function to mimic fwrite using a memory buffer */
size_t buffer_write(const void * in_buffer, size_t size, void * user_data) {
    buffer_context * ctxt = (buffer_context *)user_data;
    if (ctxt->current_address >= ctxt->start_address &&
        ctxt->current_address + size <= ctxt->start_address + ctxt->buffer_size) {

        memcpy(ctxt->current_address, in_buffer, size);
        ctxt->current_address += size;
        return size;
    }
    else {
        return 0;
    }
}

/* callback function to read data from a file stream */
size_t file_read(void * out_buffer, size_t size, void * user_data) {
    return fread(out_buffer, sizeof(uint8_t), size, (FILE *)user_data);
}

/* callback function to write data to a file stream */
size_t file_write(const void * in_buffer, size_t size, void * user_data) {
    return fwrite(in_buffer, sizeof(uint8_t), size, (FILE *)user_data);
}

/* read a big-endian 64-bit floating point value */
size_t read_number64_be(amf_read_proc_t read_proc, void * user_data, number64_t * val) {
    char data[8];
    size_t size = read_proc(data, sizeof(data), user_data);

    if (size == sizeof(data)) {
        uint64_t v;
        v =   ((uint64_t)data[7] << 0)
            | ((uint64_t)data[6] << 8)
            | ((uint64_t)data[5] << 16)
            | ((uint64_t)data[4] << 24)
            | ((uint64_t)data[3] << 32)
            | ((uint64_t)data[2] << 40)
            | ((uint64_t)data[1] << 48)
            | ((uint64_t)data[0] << 56);
        *val = (number64_t)v;
    }

    return size;
}

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
