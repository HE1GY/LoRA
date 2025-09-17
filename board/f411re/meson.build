board_src = files(
  'startup_stm32f411xe.s',
)

board_linker = meson.current_source_dir() / 'STM32F411RETX_FLASH.ld'

board_lib = static_library('board',
  board_src,
  include_directories: include_directories('.'),
)


