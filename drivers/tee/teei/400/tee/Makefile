# Copyright (c) 2015-2019, MICROTRUST Incorporated
# All Rights Reserved.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# version 2 as published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.

$(info "whf src=")

include $(srctree)/drivers/tee/gpapi/Makefile.impl.include

obj-y += tee.o
tee-objs += tee_core.o
tee-objs += tee_shm.o
tee-objs += tee_shm_pool.o
tee-objs += tee_client_api.o

ifeq ($(CONFIG_MICROTRUST_TEST_DRIVERS),y)
tee-objs += capi_proxy.o
endif

obj-y += soter/
