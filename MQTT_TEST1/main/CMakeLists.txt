idf_component_register(SRCS "main.c"
                    INCLUDE_DIRS ".")

idf_component_register(SRCS "protocol_examples_common.h"
                    INCLUDE_DIRS "${IDF_PATH}/examples/common_components/protocol_examples_common/include")
