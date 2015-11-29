#ifndef __AMF0_H__
#define __AMF0_H__

#include <stdio.h>
#include <time.h>

#include "amf.h"

/* AMF data types */
#define AMF0_TYPE_NUMBER                0x00
#define AMF0_TYPE_BOOLEAN               0x01
#define AMF0_TYPE_STRING                0x02
#define AMF0_TYPE_OBJECT                0x03
#define AMF0_TYPE_MOVIECLIP             0x04 /* reserved, not supported */
#define AMF0_TYPE_NULL                  0x05
#define AMF0_TYPE_UNDEFINED             0x06
#define AMF0_TYPE_REFERENCE             0x07
#define AMF0_TYPE_ECMA_ARRAY            0x08
#define AMF0_TYPE_OBJECT_END            0x09
#define AMF0_TYPE_STRICT_ARRAY          0x0A
#define AMF0_TYPE_DATE                  0x0B
#define AMF0_TYPE_LONG_STRING           0x0C
#define AMF0_TYPE_UNSUPPORTED           0x0D
#define AMF0_TYPE_RECORDSET             0x0E /* reserved, not supported */
#define AMF0_TYPE_XML_DOCUMENT          0x0F
#define AMF0_TYPE_TYPED_OBJECT          0x10

/* AMF error codes */
#define AMF0_ERROR_OK                   0x00
#define AMF0_ERROR_EOF                  0x01
#define AMF0_ERROR_UNKNOWN_TYPE         0x02
#define AMF0_ERROR_END_TAG              0x03
#define AMF0_ERROR_NULL_POINTER         0x04
#define AMF0_ERROR_MEMORY               0x05
#define AMF0_ERROR_UNSUPPORTED_TYPE     0x06

/* a node wraps AMF data in a list, used for iteration */
typedef struct amf0_node_t * p_amf0_node;

/* string type */
typedef struct amf0_string_t {
    uint16_t size;
    uint8_t * mbstr;
} amf0_string;

/* array type */
typedef struct amf0_list_t {
    uint32_t size;
    p_amf0_node first_element;
    p_amf0_node last_element;
} amf0_list;

/* date type */
typedef struct amf0_date_t {
    number64_t milliseconds;
    int16_t timezone;
} amf0_date;

/* XML string type */
typedef struct amf0_xmlstring_t {
    uint32_t size;
    uint8_t * mbstr;
} amf0_xmlstring;

/* class type */
typedef struct amf0_class_t {
    amf0_string name;
    amf0_list elements;
} amf0_class;

/* structure encapsulating the various AMF objects */
typedef struct amf0_data_t {
    uint8_t type;
    uint8_t error_code;
    union {
        number64_t number_data;
        uint8_t boolean_data;
        amf0_string string_data;
        amf0_list list_data;
        amf0_date date_data;
        amf0_xmlstring xmlstring_data;
        amf0_class class_data;
    };
} amf0_data;

/* node used in lists, relies on amf0_data */
typedef struct amf0_node_t {
    amf0_data * data;
    p_amf0_node prev;
    p_amf0_node next;
} amf0_node;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* read AMF data */
amf0_data * amf0_data_read(amf_read_proc_t read_proc, void * user_data);

/* write AMF data */
size_t amf0_data_write(const amf0_data * data, amf_write_proc_t write_proc, void * user_data);

/* generic functions */

/* allocate an AMF data object */
amf0_data * amf0_data_new(uint8_t type);
/* load AMF data from buffer */
amf0_data * amf0_data_buffer_read(uint8_t * buffer, size_t maxbytes);
/* load AMF data from stream */
amf0_data * amf0_data_file_read(FILE * stream);
/* AMF data size */
size_t      amf0_data_size(const amf0_data * data);
/* write encoded AMF data into a buffer */
size_t      amf0_data_buffer_write(const amf0_data * data, uint8_t * buffer, size_t maxbytes);
/* write encoded AMF data into a stream */
size_t      amf0_data_file_write(const amf0_data * data, FILE * stream);
/* get the type of AMF data */
uint8_t     amf0_data_get_type(const amf0_data * data);
/* get the error code of AMF data */
uint8_t     amf0_data_get_error(const amf0_data * data);
/* return a new copy of AMF data */
amf0_data * amf0_data_clone(const amf0_data * data);
/* release the memory of AMF data */
void        amf0_data_free(amf0_data * data);
/* dump AMF data into a stream as text */
void        amf0_data_dump(FILE * stream, const amf0_data * data, int indent_level);

/* number functions */
amf0_data * amf0_number_new(number64_t value);
number64_t  amf0_number_get_value(const amf0_data * data);
void        amf0_number_set_value(amf0_data * data, number64_t value);

/* boolean functions */
amf0_data * amf0_boolean_new(uint8_t value);
uint8_t     amf0_boolean_get_value(const amf0_data * data);
void        amf0_boolean_set_value(amf0_data * data, uint8_t value);

/* string functions */
amf0_data * amf0_string_new(uint8_t * str, uint16_t size);
amf0_data * amf0_str(const char * str);
uint16_t    amf0_string_get_size(const amf0_data * data);
uint8_t *   amf0_string_get_bytes(const amf0_data * data);

/* object functions */
amf0_data * amf0_object_new(void);
uint32_t    amf0_object_size(amf0_data * data);
amf0_data * amf0_object_add(amf0_data * data, const char * name, amf0_data * element);
amf0_data * amf0_object_get(const amf0_data * data, const char * name);
amf0_data * amf0_object_set(amf0_data * data, const char * name, amf0_data * element);
amf0_data * amf0_object_delete(amf0_data * data, const char * name);
amf0_node * amf0_object_first(const amf0_data * data);
amf0_node * amf0_object_last(const amf0_data * data);
amf0_node * amf0_object_next(const amf0_node * node);
amf0_node * amf0_object_prev(const amf0_node * node);
amf0_data * amf0_object_get_name(const amf0_node * node);
amf0_data * amf0_object_get_data(const amf0_node * node);

/* null functions */
#define amf0_null_new() amf0_data_new(AMF0_TYPE_NULL)

/* undefined functions */
#define amf0_undefined_new() amf0_data_new(AMF0_TYPE_UNDEFINED)

/* associative array functions */
amf0_data * amf0_associative_array_new(void);
#define amf0_associative_array_size(d)       amf0_object_size(d)
#define amf0_associative_array_add(d, n, e)  amf0_object_add(d, n, e)
#define amf0_associative_array_get(d, n)     amf0_object_get(d, n)
#define amf0_associative_array_set(d, n, e)  amf0_object_set(d, n, e)
#define amf0_associative_array_delete(d, n)  amf0_object_delete(d, n)
#define amf0_associative_array_first(d)      amf0_object_first(d)
#define amf0_associative_array_last(d)       amf0_object_last(d)
#define amf0_associative_array_next(n)       amf0_object_next(n)
#define amf0_associative_array_prev(n)       amf0_object_prev(n)
#define amf0_associative_array_get_name(n)   amf0_object_get_name(n)
#define amf0_associative_array_get_data(n)   amf0_object_get_data(n)

/* array functions */
amf0_data * amf0_array_new(void);
uint32_t   amf0_array_size(const amf0_data * data);
amf0_data * amf0_array_push(amf0_data * data, amf0_data * element);
amf0_data * amf0_array_pop(amf0_data * data);
amf0_node * amf0_array_first(const amf0_data * data);
amf0_node * amf0_array_last(const amf0_data * data);
amf0_node * amf0_array_next(const amf0_node * node);
amf0_node * amf0_array_prev(const amf0_node * node);
amf0_data * amf0_array_get(const amf0_node * node);
amf0_data * amf0_array_get_at(const amf0_data * data, uint32_t n);
amf0_data * amf0_array_delete(amf0_data * data, amf0_node * node);
amf0_data * amf0_array_insert_before(amf0_data * data, amf0_node * node, amf0_data * element);
amf0_data * amf0_array_insert_after(amf0_data * data, amf0_node * node, amf0_data * element);

/* date functions */
amf0_data * amf0_date_new(number64_t milliseconds, int16_t timezone);
number64_t amf0_date_get_milliseconds(const amf0_data * data);
int16_t    amf0_date_get_timezone(const amf0_data * data);
time_t     amf0_date_to_time_t(const amf0_data * data);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __AMF0_H__ */
