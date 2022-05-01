aux_source_directory(. SRC_LISTS)
set(EXTRA_SRC ../operation.pb.cc)
add_executable(caller ${SRC_LISTS} ${EXTRA_SRC})
target_link_libraries(caller librpc protobuf)
