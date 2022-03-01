add_library(data_structures
        vector/vector.c
        matrix/matrix.c
        string/string_.c
        string/test_string.c
        )

target_link_libraries(data_structures algorithms)