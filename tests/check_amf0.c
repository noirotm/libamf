#include <check.h>
#include <stdlib.h>
#include <string.h>
#include "amf0.h"

amf0_data * data;

void teardown(void) {
    amf0_data_free(data);
}

/**
    AMF number
*/
void setup_amf0_number(void) {
    data = amf0_number_new(0);
}

START_TEST(test_amf0_number_new) {
    fail_if(data == NULL,
        "data should not be NULL");

    fail_unless(amf0_data_get_type(data) == AMF0_TYPE_NUMBER,
        "invalid data type: expected %d, got %d", AMF0_TYPE_NUMBER, amf0_data_get_type(data));

    /* AMF number size == 1(header) + 8(data) -> 9 bytes */
    fail_unless(amf0_data_size(data) == 9,
        "invalid data size: expected 9, got %d", amf0_data_size(data));

    fail_unless(amf0_number_get_value(data) == 0,
        "invalid data value: expected 0, got %f", amf0_number_get_value(data));
}
END_TEST

START_TEST(test_amf0_number_set_value) {
    amf0_number_set_value(data, -512.78);

    fail_unless(amf0_number_get_value(data) == -512.78,
        "invalid data value: expected -512.78, got %f", amf0_number_get_value(data));
}
END_TEST

START_TEST(test_amf0_number_null) {
    fail_unless(amf0_number_get_value(NULL) == 0,
        "invalid data value: expected 0, got %f", amf0_number_get_value(NULL));

    /* just making sure we don't core dump */
    amf0_number_set_value(NULL, 12);
}
END_TEST

/**
    AMF boolean
*/
void setup_amf0_boolean(void) {
    data = amf0_boolean_new(1);
}

START_TEST(test_amf0_boolean_new) {
    fail_if(data == NULL,
        "data should not be NULL");

    fail_unless(amf0_data_get_type(data) == AMF0_TYPE_BOOLEAN,
        "invalid data type: expected %d, got %d", AMF0_TYPE_BOOLEAN, amf0_data_get_type(data));

    /* AMF boolean size == 1(header) + 1(data) -> 2 bytes */
    fail_unless(amf0_data_size(data) == 2,
        "invalid data size: expected 2, got %d", amf0_data_size(data));

    fail_unless(amf0_boolean_get_value(data) == 1,
        "invalid data value: expected 1, got %d", amf0_boolean_get_value(data));
}
END_TEST

START_TEST(test_amf0_boolean_set_value) {
    amf0_boolean_set_value(data, 0);
    fail_unless(amf0_boolean_get_value(data) == 0,
        "invalid data value: expected 0, got %d", amf0_boolean_get_value(data));
}
END_TEST

START_TEST(test_amf0_boolean_null) {
    fail_unless(amf0_boolean_get_value(NULL) == 0,
        "invalid data value: expected 0, got %d", amf0_boolean_get_value(data));

    /* just making sure we don't core dump */
    amf0_boolean_set_value(NULL, 12);
}
END_TEST

/**
    AMF string
*/
START_TEST(test_amf0_str) {
    char * str = "hello world";
    int length = strlen(str);
    data = amf0_str(str);

    fail_if(data == NULL,
        "data should not be NULL");

    fail_unless(amf0_data_get_type(data) == AMF0_TYPE_STRING,
        "invalid data type: expected %d, got %d", AMF0_TYPE_STRING, amf0_data_get_type(data));

    /* AMF string size == 1(header) + 2(string length) + length */
    fail_unless(amf0_data_size(data) == 3 + length,
        "invalid data size: expected %d, got %d", 3 + length, amf0_data_size(data));

    fail_unless(amf0_string_get_size(data) == length,
        "invalid string length: expected %d, got %f", length, amf0_string_get_size(data));

    fail_unless(strcmp(amf0_string_get_bytes(data), str) == 0,
        "invalid string contents");
}
END_TEST

START_TEST(test_amf0_str_null) {
    data = amf0_str(NULL);

    fail_unless(amf0_string_get_size(data) == 0,
        "invalid string length: expected 0, got %f", amf0_string_get_size(data));

    fail_unless(!strcmp(amf0_string_get_bytes(data), ""),
        "string data should be an empty string");

    amf0_data_free(data);
}
END_TEST

START_TEST(test_amf0_string_new) {
    char * str = "hello world";
    data = amf0_string_new(str, 5);

    fail_unless(amf0_string_get_size(data) == 5,
        "invalid string length: expected 5, got %f", amf0_string_get_size(data));

    fail_unless(strncmp(amf0_string_get_bytes(data), str, 5) == 0,
        "invalid string contents");

    amf0_data_free(data);
}
END_TEST

START_TEST(test_amf0_string_new_null) {
    data = amf0_string_new(NULL, 12);

    fail_unless(amf0_string_get_size(data) == 0,
        "invalid string length: expected 0, got %f", amf0_string_get_size(data));

    fail_unless(!strcmp(amf0_string_get_bytes(data),""),
        "string data should be an empty string");

    amf0_data_free(data);
}
END_TEST

START_TEST(test_amf0_string_null) {
    fail_unless(amf0_string_get_size(NULL) == 0,
        "invalid string length: expected 0, got %f", amf0_string_get_size(data));

    fail_unless(amf0_string_get_bytes(NULL) == NULL,
        "string data should be NULL");
}
END_TEST

/**
    AMF Types Suite
*/
Suite * amf0_suite(void) {
    Suite * s = suite_create("AMF0");

    /* AMF number test case */
    TCase * tc_number = tcase_create("AMF0 number");
    tcase_add_checked_fixture(tc_number, setup_amf0_number, teardown);
    tcase_add_test(tc_number, test_amf0_number_new);
    tcase_add_test(tc_number, test_amf0_number_set_value);
    tcase_add_test(tc_number, test_amf0_number_null);
    suite_add_tcase(s, tc_number);

    /* AMF boolean test case */
    TCase * tc_boolean = tcase_create("AMF0 boolean");
    tcase_add_checked_fixture(tc_boolean, setup_amf0_boolean, teardown);
    tcase_add_test(tc_boolean, test_amf0_boolean_new);
    tcase_add_test(tc_boolean, test_amf0_boolean_set_value);
    tcase_add_test(tc_boolean, test_amf0_boolean_null);
    suite_add_tcase(s, tc_boolean);

    /* AMF string test case */
    TCase * tc_string = tcase_create("AMF0 string");
    tcase_add_test(tc_string, test_amf0_str);
    tcase_add_test(tc_string, test_amf0_str_null);
    tcase_add_test(tc_string, test_amf0_string_new);
    tcase_add_test(tc_string, test_amf0_string_new_null);
    tcase_add_test(tc_string, test_amf0_string_null);
    suite_add_tcase(s, tc_string);

    return s;
}
