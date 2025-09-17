project('LoRa', 'c', 'cpp',
  version: '0.1.0',
  default_options: [
    'cpp_std=c++17',
    'warning_level=3',   # replaces -Wall
    'optimization=0'     # replaces -O0
  ])

# Common flags for both C and C++
common_flags = [
  '-mcpu=cortex-m4',
  '-mthumb',
  '-mfpu=fpv4-sp-d16',
  '-mfloat-abi=hard',
  '-ffreestanding',
]

add_project_arguments(common_flags, language: ['c', 'cpp'])
add_project_arguments(['-fno-exceptions', '-fno-rtti'], language: 'cpp')
add_project_link_arguments(common_flags, language: ['c', 'cpp'])

add_project_arguments(
  '-DSTM32F411xE',
  language: ['c', 'cpp']
)

#if get_option('mcu') == 'f411re'
  subdir('board/f411re/')
#elif get_option('mcu') == 'f446re'
  #subdir('board/f446re')
#endif

inc = include_directories(
  'src',
  'STM32Cube_FW_F4_V1.28.3/Drivers/CMSIS/Device/ST/STM32F4xx/Include',
  'STM32Cube_FW_F4_V1.28.3/Drivers/CMSIS/Include',
  'STM32Cube_FW_F4_V1.28.3/Drivers/STM32F4xx_HAL_Driver/Inc',
  'board/f411re',
  'inc',
)

src = files(
  'src/main.cpp',
  'src/syscalls.c',
  'src/system_stm32f4xx.c',
  'src/stm32f4xx_it.c',
)


hal_dir = 'STM32Cube_FW_F4_V1.28.3/Drivers/STM32F4xx_HAL_Driver/Src'
hal_src = files(
  hal_dir / 'stm32f4xx_hal.c',
  hal_dir / 'stm32f4xx_hal_gpio.c',
  hal_dir / 'stm32f4xx_hal_rcc.c',
  hal_dir / 'stm32f4xx_hal_rcc_ex.c',
  hal_dir / 'stm32f4xx_hal_cortex.c',
  hal_dir / 'stm32f4xx_ll_utils.c',
  hal_dir / 'stm32f4xx_ll_rcc.c',
  # add/remove as needed
)


elf = executable('firmware.elf',
  src + hal_src,
  include_directories: inc,
  link_with : board_lib,
  link_args : ['-T', board_linker],
  install : false
)

# Generate .bin for flashing
objcopy = find_program('arm-none-eabi-objcopy')
custom_target('firmware.bin',
  input : elf,
  output : 'firmware.bin',
  command : [objcopy, '-O', 'binary', '@INPUT@', '@OUTPUT@']
)

