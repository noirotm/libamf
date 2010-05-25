#include "amf0.h"

int main() {
    amf0_data * test;

    test = amf0_object_new();
    amf0_object_add(test, "toto", amf0_str("une chaine de caracteres"));
    amf0_object_add(test, "test_bool", amf0_boolean_new(1));

    amf0_data_dump(stdout, test, 0);

    amf0_data_free(test);
}
