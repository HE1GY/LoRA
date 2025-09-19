
inc_dir = 'inc'
src_dir = 'src/'
src = files(
  src_dir + 'main.cpp',
  src_dir + 'system_stm32f4xx.c',
  src_dir + 'stm32f4xx_it.c',
  src_dir + 'syscalls.c',
)

elf = executable('firmware.elf',
  sources : src,
  include_directories : include_directories(inc_dir),
  dependencies : [board_dep, driver_dep, freertos_dep],
  link_args : ['-T', board_linker],   # from board/<mcu>/meson.build
  install : false
)

# Generate .bin for flashing
objcopy = find_program('arm-none-eabi-objcopy')
custom_target('firmware.bin',
  input : elf,
  output : 'firmware.bin',
  command : [objcopy, '-O', 'binary', '@INPUT@', '@OUTPUT@']
)
