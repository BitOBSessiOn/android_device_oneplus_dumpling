#
# Copyright 2017 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# This contains the module build definitions for the hardware-specific
# components for this device.
#
# As much as possible, those components should be built unconditionally,
# with device-specific names to avoid collisions, to avoid device-specific
# bitrot and build breakages. Building a component unconditionally does
# *not* include it on all devices, so it is safe even with hardware-specific
# components.

BOARD_PATH := device/oneplus/dumpling

TARGET_OTA_ASSERT_DEVICE := OnePlus5T,dumpling,oneplus5t,op5t,A5010,OnePlus 5T

# Architecture
TARGET_ARCH := arm64
TARGET_ARCH_VARIANT := armv8-a
TARGET_CPU_ABI := arm64-v8a
TARGET_CPU_ABI2 :=
TARGET_CPU_VARIANT := generic
TARGET_2ND_ARCH := arm
TARGET_2ND_ARCH_VARIANT := armv7-a-neon
TARGET_2ND_CPU_ABI := armeabi-v7a
TARGET_2ND_CPU_ABI2 := armeabi
TARGET_2ND_CPU_VARIANT := cortex-a9

ENABLE_CPUSETS := true
ENABLE_SCHEDBOOST := true

# Bootloader
TARGET_BOOTLOADER_BOARD_NAME := msm8998
TARGET_NO_BOOTLOADER := true
TARGET_USES_UEFI := true

# Platform
TARGET_BOARD_PLATFORM := msm8998
TARGET_BOARD_PLATFORM_GPU := qcom-adreno540

# Kernel
BOARD_KERNEL_BASE := 0x00000000
BOARD_KERNEL_CMDLINE := androidboot.hardware=qcom user_debug=31 msm_rtb.filter=0x237
BOARD_KERNEL_CMDLINE += ehci-hcd.park=3 lpm_levels.sleep_disabled=1 sched_enable_hmp=1
BOARD_KERNEL_CMDLINE += sched_enable_power_aware=1 service_locator.enable=1 swiotlb=2048 androidboot.usbcontroller=a800000.dwc3
BOARD_KERNEL_CMDLINE += androidboot.selinux=permissive
BOARD_KERNEL_PAGESIZE := 4096
BOARD_KERNEL_TAGS_OFFSET := 0x01E00000
BOARD_RAMDISK_OFFSET := 0x02000000
TARGET_PREBUILT_KERNEL := $(BOARD_PATH)/prebuilt/Image.gz-dtb

# Partitions
BOARD_BOOTIMAGE_PARTITION_SIZE := 0x04000000
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 67108864
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 3221225472

BOARD_CACHEIMAGE_PARTITION_SIZE := 268435456
BOARD_CACHEIMAGE_FILE_SYSTEM_TYPE := ext4
BOARD_PERSISTIMAGE_PARTITION_SIZE := 33554432
BOARD_PERSISTIMAGE_FILE_SYSTEM_TYPE := ext4
BOARD_USERDATAIMAGE_PARTITION_SIZE := 32212254720
BOARD_USERDATAIMAGE_FILE_SYSTEM_TYPE := ext4
TARGET_USERIMAGES_USE_EXT4 := true
TARGET_USERIMAGES_USE_F2FS := true
BOARD_VENDORIMAGE_FILE_SYSTEM_TYPE := ext4
TARGET_COPY_OUT_VENDOR := vendor
BOARD_FLASH_BLOCK_SIZE := 131072

# Recovery
BOARD_HAS_LARGE_FILESYSTEM := true
TARGET_RECOVERY_PIXEL_FORMAT := "RGBX_8888"
TARGET_RECOVERY_QCOM_RTC_FIX := true
BOARD_SUPPRESS_SECURE_ERASE := true

# Crypto
TARGET_HW_DISK_ENCRYPTION = true

# TWRP specific build flags
TW_THEME := portrait_hdpi
TW_SCREEN_BLANK_ON_BOOT := true
TW_INCLUDE_CRYPTO := true
BOARD_HAS_NO_REAL_SDCARD := true
RECOVERY_SDCARD_ON_DATA := true
TW_INCLUDE_NTFS_3G := true
TW_INPUT_BLACKLIST := "hbtp_vm"
TW_BRIGHTNESS_PATH := "/sys/class/leds/lcd-backlight/brightness"
TW_MAX_BRIGHTNESS := 255
TW_DEFAULT_BRIGHTNESS := 100
TW_MTP_DEVICE := "/dev/mtp_usb"
TW_NO_USB_STORAGE := true
TW_EXCLUDE_DEFAULT_USB_INIT := true
TW_EXCLUDE_SUPERSU := true
TW_EXTRA_LANGUAGES := true
TW_IGNORE_MISC_WIPE_DATA := true

BOARD_SUPPRESS_EMMC_WIPE := true
BOARD_SUPPRESS_SECURE_ERASE := true
TW_NO_LEGACY_PROPS := 1

# MR config. MultiROM also uses parts of TWRP config
TARGET_RECOVERY_IS_MULTIROM := true

MR_NO_KEXEC := 2
# possible options:
#       1 true allowed      # NO_KEXEC_DISABLED =  0x00,   // no-kexec is disabled (ie it is built, but needs to be manually enabled)
#       2 enabled           # NO_KEXEC_ALLOWED  =  0x01,   // "Use no-kexec only when needed"
#       3 ui_confirm        # NO_KEXEC_CONFIRM  =  0x02,   // "..... but also ask for confirmation"
#       4 ui_choice         # NO_KEXEC_CHOICE   =  0x04,   // "Ask whether to kexec or use no-kexec"
#       5 forced            # NO_KEXEC_FORCED   =  0x08,   // "Always force using no-kexec workaround"
# any other setting won't build it at all

MR_DPI := xhdpi
MR_DPI_FONT := 340
MR_USE_MROM_FSTAB := true
MR_FSTAB := $(BOARD_PATH)/multirom/mrom.fstab
MR_INPUT_TYPE := type_b
MR_INIT_DEVICES := $(BOARD_PATH)/multirom/mr_init_devices.c

#MR_KEXEC_MEM_MIN := 0x00200000
MR_KEXEC_MEM_MIN := 0xAC000000
MR_KEXEC_DTB := true
MR_DEVICE_HOOKS := $(BOARD_PATH)/multirom/mr_hooks.c
MR_DEVICE_HOOKS_VER := 6
MR_DEVICE_VARIANTS := dumpling, oneplus5t, OnePlus5T, A5010

# Encryption support
#MR_ENCRYPTION := true
#MR_ENCRYPTION_SETUP_SCRIPT := $(BOARD_PATH)/multirom/mr_cp_crypto.sh
#MR_ENCRYPTION_FAKE_PROPERTIES := true
#MR_ENCRYPTION_FAKE_PROPERTIES_EXTRAS := $(BOARD_PATH)/multirom/mr_fake_properties.c

# Bootmenu
DEVICE_RESOLUTION := 1080x1920
MR_PIXEL_FORMAT := "RGBA_8888"
MR_UNIFIED_TABS := true
MR_USE_DEBUGFS_MOUNT := true
RECOVERY_GRAPHICS_USE_LINELENGTH := true
MR_DEV_BLOCK_BOOTDEVICE := true

#Force populating /dev/block/platform/soc/1da4000.ufshc/by-name/
#from the emmc
MR_POPULATE_BY_NAME_PATH := "/dev/block/platform/soc/1da4000.ufshc/by-name/"
#MR_DEVICE_BOOTDEVICE := /dev/block/platform/soc/1da4000.ufshc

# Versioning
TW_DEVICE_VERSION := 1

include $(BOARD_PATH)/multirom/version/MR_REC_VERSION.mk

ifeq ($(MR_REC_VERSION),)
MR_REC_VERSION := $(shell date -u +%Y%m%d)-01
endif

BOARD_MKBOOTIMG_ARGS += --board mrom$(MR_REC_VERSION)
