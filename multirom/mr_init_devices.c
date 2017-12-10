#include <stdlib.h>

// These are paths to folders in /sys which contain "uevent" file
// need to init this device.
// MultiROM needs to init framebuffer, mmc blocks, input devices,
// some ADB-related stuff and USB drives, if OTG is supported
// You can use * at the end to init this folder and all its subfolders
const char *mr_init_devices[] =
{
    // FrameBuffers
    "/sys/class/graphics/fb0",

    // Storage devices
    "/sys/dev/block*",
    "/sys/module/ufshcd",
    "/sys/block/sda",
    "/sys/block/sde",
    "/sys/block/sdf",

    // Internal storage
    "/dev/block/bootdevice/by-name/*",
    "/sys/devices/soc/1da4000.ufshc",

    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:0/block/sda/sda3", // cache
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:0/block/sda/sda2", // persist
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:0/block/sda/sda1",  // ssd
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:0/block/sda/sda13", // userdata

    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:4/block/sde/sde19", // boot
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:4/block/sde/sde25", // keymaster
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:4/block/sde/sde26", // keymasterbak
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:4/block/sde/sde10", // modem
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:4/block/sde/sde21", // system
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:4/block/sde/sde1", // rpm
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:4/block/sde/sde2", // rpmbak

    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:5/block/sde/sdf1", // modemst1
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:5/block/sde/sdf2", // modemst2

    // Devices
    "/sys/bus*",
    "/sys/bus/mmc",
    "/sys/bus/mmc/drivers/mmcblk",
    "/sys/devices*",
    "/sys/devices/virtual/mem/null",
    "/sys/devices/virtual/misc/fuse",

    // Inputs
    "/sys/class/input/event*",
    "/sys/class/input/input*",
    "/sys/class/misc/uinput",
    "/sys/class/tty/ptmx",
    "/sys/devices/soc/soc:gpio_keys/input*",
    "/sys/devices/virtual/input*",
    "/sys/devices/virtual/misc/uinput",
    // Oneplus5T specific:
    "/sys/devices/soc/c179000.i2c/i2c-5/5-0020/input",
    "/sys/devices/soc/soc:gpio_keys/input",

/*
    c179000.i2c
    c17a000.i2c
    c1b5000.i2c
    c1b7000.i2c
*/

    // ADB
    "/sys/devices/virtual/tty/ptmx",
    "/sys/bus/usb",
    "/sys/bus/usb-serial",
    "/sys/class/android_usb/android0/f_adb",
    "/sys/class/misc/android_adb",
    "/sys/devices/virtual/misc/mtp_usb",

    // USB
    "/sys/bus/usb",
    "/sys/bus/platform/drivers/xhci-hcd*",
    "/sys/devices/soc/6a00000.ssusb/6a00000.dwc3",

    // Encryption
    "/sys/devices/virtual/icesdcc/icesdcc",
    "/sys/devices/virtual/misc/device-mapper",
    "/sys/devices/virtual/misc/ion",
    "/sys/devices/virtual/qseecom/qseecom",

    // Logging
    "/sys/devices/virtual/pmsg/pmsg0",
    "/sys/devices/virtual/mem/kmsg",

    NULL
};

/*


# ls /dev/block/bootdevice/by-name/ -l
# ls /dev/block/platform/soc/1da4000.ufshc/by-name -l

lrwxrwxrwx 1 root root 16 1970-01-01 02:20 LOGO -> /dev/block/sde18
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 abl -> /dev/block/sde16
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 ablbak -> /dev/block/sde17
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 apdp -> /dev/block/sde31
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 bluetooth -> /dev/block/sde24
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 boot -> /dev/block/sde19
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 boot_aging -> /dev/block/sde20
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 cache -> /dev/block/sda3
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 cdt -> /dev/block/sdd2
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 cmnlib -> /dev/block/sde27
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 cmnlib64 -> /dev/block/sde29
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 cmnlib64bak -> /dev/block/sde30
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 cmnlibbak -> /dev/block/sde28
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 config -> /dev/block/sda12
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 ddr -> /dev/block/sdd3
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 devcfg -> /dev/block/sde39
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 devinfo -> /dev/block/sde23
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 dip -> /dev/block/sde14
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 dpo -> /dev/block/sde33
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 dsp -> /dev/block/sde11
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 frp -> /dev/block/sda6
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 fsc -> /dev/block/sdf4
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 fsg -> /dev/block/sdf3
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 fw_4g9n4 -> /dev/block/sde45
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 fw_4j1ed -> /dev/block/sde43
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 fw_4t0n8 -> /dev/block/sde46
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 fw_8v1ee -> /dev/block/sde44
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 hyp -> /dev/block/sde5
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 hypbak -> /dev/block/sde6
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 keymaster -> /dev/block/sde25
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 keymasterbak -> /dev/block/sde26
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 keystore -> /dev/block/sda5
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 limits -> /dev/block/sde35
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 logdump -> /dev/block/sde40
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 logfs -> /dev/block/sde37
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 md5 -> /dev/block/sdf5
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 mdtp -> /dev/block/sde15
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 mdtpsecapp -> /dev/block/sde12
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 mdtpsecappbak -> /dev/block/sde13
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 minidump -> /dev/block/sde47
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 misc -> /dev/block/sda4
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 modem -> /dev/block/sde10
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 modemst1 -> /dev/block/sdf1
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 modemst2 -> /dev/block/sdf2
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 msadp -> /dev/block/sde32
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 oem_dycnvbk -> /dev/block/sda7
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 oem_stanvbk -> /dev/block/sda8
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 param -> /dev/block/sda9
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 persist -> /dev/block/sda2
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 pmic -> /dev/block/sde8
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 pmicbak -> /dev/block/sde9
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 recovery -> /dev/block/sde22
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 reserve -> /dev/block/sdd1
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 reserve1 -> /dev/block/sda10
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 reserve2 -> /dev/block/sda11
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 rpm -> /dev/block/sde1
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 rpmbak -> /dev/block/sde2
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 sec -> /dev/block/sde7
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 splash -> /dev/block/sde34
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 ssd -> /dev/block/sda1
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 sti -> /dev/block/sde38
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 storsec -> /dev/block/sde41
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 storsecbak -> /dev/block/sde42
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 system -> /dev/block/sde21
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 toolsfv -> /dev/block/sde36
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 tz -> /dev/block/sde3
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 tzbak -> /dev/block/sde4
lrwxrwxrwx 1 root root 16 1970-01-01 02:20 userdata -> /dev/block/sda13
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 xbl -> /dev/block/sdb1
lrwxrwxrwx 1 root root 15 1970-01-01 02:20 xblbak -> /dev/block/sdc1


# mount

rootfs on / type rootfs (ro,seclabel,size=3849108k,nr_inodes=962277)
tmpfs on /dev type tmpfs (rw,seclabel,nosuid,relatime,size=3936168k,nr_inodes=984042,mode=755)
devpts on /dev/pts type devpts (rw,seclabel,relatime,mode=600)
proc on /proc type proc (rw,relatime,gid=3009,hidepid=2)
sysfs on /sys type sysfs (rw,seclabel,relatime)
selinuxfs on /sys/fs/selinux type selinuxfs (rw,relatime)
debugfs on /sys/kernel/debug type debugfs (rw,seclabel,relatime)
none on /acct type cgroup (rw,relatime,cpuacct)
none on /dev/stune type cgroup (rw,relatime,schedtune)
tmpfs on /mnt type tmpfs (rw,seclabel,relatime,size=3936168k,nr_inodes=984042,mode=755,gid=1000)
none on /config type configfs (rw,relatime)
none on /dev/cpuctl type cgroup (rw,relatime,cpu)
none on /dev/cpuset type cgroup (rw,relatime,cpuset,noprefix,release_agent=/sbin/cpuset_release_agent)
pstore on /sys/fs/pstore type pstore (rw,seclabel,relatime)
none on /sys/fs/cgroup type tmpfs (rw,seclabel,relatime,size=3936168k,nr_inodes=984042,mode=750,gid=1000)
none on /sys/fs/cgroup type tmpfs (rw,seclabel,relatime,size=3936168k,nr_inodes=984042,mode=750,gid=1000)
none on /sys/fs/cgroup/freezer type cgroup (rw,relatime,freezer)
/dev/block/sde21 on /system type ext4 (ro,seclabel,relatime,discard,errors=panic,data=ordered)
/dev/block/sda13 on /data type ext4 (rw,seclabel,nosuid,nodev,relatime,discard,noauto_da_alloc,errors=panic,data=ordered)
/dev/block/sde10 on /firmware type vfat (ro,context=u:object_r:firmware_file:s0,relatime,uid=1000,gid=1000,fmask=0337,dmask=0227,codepage=437,iocharset=iso8859-1,shortname=lower,errors=remount-ro)
/dev/block/sde24 on /bt_firmware type vfat (ro,context=u:object_r:bt_firmware_file:s0,relatime,uid=1002,gid=3002,fmask=0337,dmask=0227,codepage=437,iocharset=iso8859-1,shortname=lower,errors=remount-ro)
/dev/block/sda3 on /cache type ext4 (rw,seclabel,nosuid,nodev,relatime,data=ordered)
/dev/block/sda2 on /persist type ext4 (rw,seclabel,nosuid,nodev,relatime,data=ordered)
/dev/block/sde11 on /dsp type ext4 (ro,seclabel,nosuid,nodev,relatime,data=ordered)
tracefs on /sys/kernel/debug/tracing type tracefs (rw,seclabel,relatime)
tmpfs on /storage type tmpfs (rw,seclabel,relatime,size=3936168k,nr_inodes=984042,mode=755,gid=1000)
tmpfs on /sbin type tmpfs (rw,seclabel,relatime,size=3936168k,nr_inodes=984042)
/dev/block/sde21 on /sbin/.core/mirror/system type ext4 (ro,seclabel,relatime,discard,errors=panic,data=ordered)
/dev/block/sda13 on /sbin/.core/mirror/bin type ext4 (rw,seclabel,nosuid,nodev,relatime,discard,noauto_da_alloc,errors=panic,data=ordered)
/dev/block/loop0 on /sbin/.core/img type ext4 (rw,seclabel,relatime,data=ordered)
adb on /dev/usb-ffs/adb type functionfs (rw,relatime)
/data/media on /mnt/runtime/default/emulated type sdcardfs (rw,nosuid,nodev,noexec,noatime,low_uid=1023,low_gid=1023,gid=1015,multi_user,mask=0006,reserved=100MB)
/data/media on /storage/emulated type sdcardfs (rw,nosuid,nodev,noexec,noatime,low_uid=1023,low_gid=1023,gid=1015,multi_user,mask=0006,reserved=100MB)
/data/media on /mnt/runtime/read/emulated type sdcardfs (rw,nosuid,nodev,noexec,noatime,low_uid=1023,low_gid=1023,gid=9997,multi_user,mask=0027,reserved=100MB)
/data/media on /mnt/runtime/write/emulated type sdcardfs (rw,nosuid,nodev,noexec,noatime,low_uid=1023,low_gid=1023,gid=9997,multi_user,mask=0007,reserved=100MB)


*/
