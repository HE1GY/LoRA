

inc_dir = 'inc'
driver_inc = include_directories(
  inc_dir
)

src_dir = 'src'
driver_src = files(
  src_dir / 'stm32f4xx_hal.c',
  src_dir / 'stm32f4xx_hal_gpio.c',
  src_dir / 'stm32f4xx_hal_rcc.c',
  src_dir / 'stm32f4xx_hal_rcc_ex.c',
  src_dir / 'stm32f4xx_hal_cortex.c',
  src_dir / 'stm32f4xx_ll_utils.c',
  src_dir / 'stm32f4xx_ll_rcc.c',
  # add/remove as needed
)

driver_lib = static_library('hal',
  sources : driver_src,
  include_directories : driver_inc,
)

driver_dep = declare_dependency(
  link_with : driver_lib,
  include_directories : driver_inc,
)