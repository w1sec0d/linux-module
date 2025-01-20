obj-m += simple.o

all:
    # Ensure this line starts with a tab
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules CC=x86_64-linux-gnu-gcc-13

clean:
    # Ensure this line starts with a tab
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean