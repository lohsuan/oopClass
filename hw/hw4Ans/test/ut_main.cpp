#include <gtest/gtest.h>

#include "ut_html.h"
#include "ut_text.h"
#include "ut_image.h"

int main( int argc , char **argv ){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS( ) ;
}
