# -------------------------------
# Common compiler & linker flags
# -------------------------------
common_flags = [
  '-mcpu=cortex-m4',
  '-mthumb',
  '-mfpu=fpv4-sp-d16',
  '-mfloat-abi=hard',
  '-ffreestanding',
]

ld_flags = [
  '-Wl,-Map=output.map',
]

# Apply globally
add_project_arguments(common_flags, language: ['c', 'cpp'])
add_project_arguments(['-fno-exceptions', '-fno-rtti'], language: 'cpp')
add_project_link_arguments(common_flags + ld_flags, language: ['c', 'cpp'])

# MCU macro (could be option-driven)
add_project_arguments('-DSTM32F411xE', language: ['c', 'cpp'])
