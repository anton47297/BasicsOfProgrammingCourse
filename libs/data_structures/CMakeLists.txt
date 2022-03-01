add_library(data_structures
        vector/vector.c
        matrix/matrix.c
        string/string_.c
        string/test_string.c
        )

add_subdirectory(string)
target_link_libraries(data_structures algorithms)