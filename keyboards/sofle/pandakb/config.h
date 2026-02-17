#pragma once

// USB detection
#define USB_VBUS_PIN 19

// Split handedness
#define	SPLIT_HAND_PIN_LOW_IS_LEFT
#define SPLIT_HAND_PIN GP4

// Serial communication - half-duplex on PIO0
#define USE_SERIAL
#define SERIAL_PIO_USE_PIO0
#define SOFT_SERIAL_PIN GP1
// #define SERIAL_USART_TX_PIN GP1
//#undef SOFT_SERIAL_PIN


#ifdef OLED_ENABLE
    #define I2C_DRIVER I2CD1
    #define I2C1_SDA_PIN GP2
    #define I2C1_SCL_PIN GP3

    #define OLED_DISPLAY_128X32
    #define OLED_BRIGHTNESS 180
    #define OLED_TIMEOUT 10000

    // #define WPM_ESTIMATED_WORD_SIZE 5
    #define SPLIT_LAYER_STATE_ENABLE
    #define SPLIT_LED_STATE_ENABLE
    #define SPLIT_MODS_ENABLE
    #define SPLIT_WPM_ENABLE
    #define SPLIT_OLED_ENABLE
#endif

#ifdef RGB_MATRIX_ENABLE
    #define WS2812_DI_PIN GP0
    #define WS2812_PIO_USE_PIO1
    #define SPLIT_TRANSPORT_MIRROR
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_MATRIX_KEYPRESSES
#endif
