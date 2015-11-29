#include <stdlib.h>
#include <check.h>

extern Suite * amf0_suite(void);

int main(void) {
    int number_failed;
    SRunner * sr = srunner_create(amf0_suite());
    
    /* srunner_set_log (sr, "check_amf.log"); */

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
