aux_source_directory(. SRC_LISTS)
set(EXTRA_SRC ../operation.pb.cc)
add_executable(callee ${SRC_LISTS} ${EXTRA_SRC})
target_link_libraries(callee librpc protobuf)
