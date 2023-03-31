# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040
VIA_ENABLE = yes

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

AUDIO_SUPPORTED = no        # Audio is not supported
RGB_MATRIX_SUPPORTED = no   # RGB matrix is supported and enabled by default
RGBLIGHT_SUPPORTED = no     # RGB underglow is supported, but not enabled by default
RGB_MATRIX_ENABLE = no      # Enable keyboard RGB matrix functionality

SERIAL_DRIVER = vendor

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_spi # Assembled version uses SPI.
CIRQUE_PINNACLE_TAP_ENABLE = yes
POINTING_DEVICE_GESTURES_SCROLL_ENABLE = yes

SPLIT_KEYBOARD = yes
LAYOUTS = split_3x5_2

# RP2040-specific options
PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS.

TAP_DANCE_ENABLE = no
CAPS_WORD_ENABLE = yes
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
COMBO_ENABLE = yes
MOUSEKEY_ENABLE = yes
