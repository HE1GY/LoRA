# Public includes (kernel headers)
freertos_inc = include_directories(
 'include',
 'portable/GCC/ARM_CM4F'
)

# Core kernel sources
freertos_sources = files(
 'tasks.c',
 'queue.c',
 'list.c',
 'timers.c',
 'stream_buffer.c',
)

# Port layer (Cortex-M4F + GCC)
freertos_port_sources = files(
 'portable/MemMang/heap_4.c',      # or heap_1.c/heap_2.c/heap_5.c
 'portable/GCC/ARM_CM4F/port.c'
)

freertos_lib = static_library('freertos',
  sources : freertos_sources + freertos_port_sources,
  include_directories : freertos_inc,
)

freertos_dep = declare_dependency(
  link_with : freertos_lib,
  include_directories : freertos_inc,
)
