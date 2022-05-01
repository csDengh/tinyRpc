
aux_source_directory(. SRC_LISTS)

add_library(librpc ${SRC_LISTS})
target_link_libraries(librpc muduo_net muduo_base protobuf pthread zookeeper_mt)
