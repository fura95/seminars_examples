#рср мхвецн хмрепеямнцн, лнфере хдрх дюкэье

#include p7 library if P7_LOGGER = true
if (P7_LOGGER)
   target_link_libraries(eigen_lib INTERFACE P7)
   target_link_libraries(additional_libs INTERFACE P7)
endif()
