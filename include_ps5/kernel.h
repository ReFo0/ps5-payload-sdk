/* Copyright (C) 2023 John Törnblom

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 3, or (at your option) any
later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING. If not, see
<http://www.gnu.org/licenses/>.  */

#ifndef PS5SDK_KERNEL_H
#define PS5SDK_KERNEL_H

#include <sys/types.h>

// Absolute kernel pointers
extern const intptr_t KERNEL_ADDRESS_DATA_BASE;
extern const intptr_t KERNEL_ADDRESS_ALLPROC;
extern const intptr_t KERNEL_ADDRESS_PRISON0;
extern const intptr_t KERNEL_ADDRESS_ROOTVNODE;
extern const intptr_t KERNEL_ADDRESS_SECURITY_FLAGS;
extern const intptr_t KERNEL_ADDRESS_UTOKEN_FLAGS;
extern const intptr_t KERNEL_ADDRESS_QA_FLAGS;
extern const intptr_t KERNEL_ADDRESS_TARGETID;

// Proc field offsets
extern const off_t KERNEL_OFFSET_PROC_P_UCRED;
extern const off_t KERNEL_OFFSET_PROC_P_FD;
extern const off_t KERNEL_OFFSET_PROC_P_PID;

// Ucred field offsets
extern const off_t KERNEL_OFFSET_UCRED_CR_UID;
extern const off_t KERNEL_OFFSET_UCRED_CR_RUID;
extern const off_t KERNEL_OFFSET_UCRED_CR_SVUID;
extern const off_t KERNEL_OFFSET_UCRED_CR_RGID;
extern const off_t KERNEL_OFFSET_UCRED_CR_SCEAUTHID;
extern const off_t KERNEL_OFFSET_UCRED_CR_SCECAPS;
extern const off_t KERNEL_OFFSET_UCRED_CR_SCEATTRS;

//Filedesc field offsets
extern const off_t KERNEL_OFFSET_FILEDESC_FD_RDIR;
extern const off_t KERNEL_OFFSET_FILEDESC_FD_JDIR;


uint32_t kernel_get_fw_version(void);

int32_t  kernel_copyin(const void *udaddr, intptr_t kaddr, size_t len);
int32_t  kernel_copyout(const intptr_t kaddr, void *udaddr, size_t  len);

intptr_t kernel_get_proc(pid_t pid);
intptr_t kernel_get_proc_ucred(pid_t pid);
intptr_t kernel_get_proc_filedesc(pid_t pid);

intptr_t kernel_dynlib_resolve(pid_t pid, uint32_t handle, const char *nid);
intptr_t kernel_dynlib_entry_addr(pid_t pid, uint32_t handle);

uint64_t kernel_get_ucred_authid(pid_t pid);
int32_t  kernel_set_ucred_authid(pid_t pid, uint64_t authid);

int32_t kernel_get_ucred_caps(pid_t pid, uint8_t caps[16]);
int32_t kernel_set_ucred_caps(pid_t pid, uint8_t caps[16]);

uint64_t kernel_get_ucred_attrs(pid_t pid);
int32_t  kernel_set_ucred_attrs(pid_t pid, uint64_t attr);

int32_t kernel_get_qaflags(uint8_t qaflags[16]);
int32_t kernel_set_qaflags(uint8_t qaflags[16]);

intptr_t kernel_get_root_vnode(void);

intptr_t kernel_get_proc_rootdir(pid_t pid);
int32_t  kernel_set_proc_rootdir(pid_t pid, intptr_t vnode);

intptr_t kernel_get_proc_jaildir(pid_t pid);
int32_t  kernel_set_proc_jaildir(pid_t pid, intptr_t vnode);

int32_t kernel_set_ucred_uid(pid_t pid, uid_t uid);
int32_t kernel_set_ucred_ruid(pid_t pid, uid_t ruid);
int32_t kernel_set_ucred_svuid(pid_t pid, uid_t svuid);

int32_t kernel_set_ucred_rgid(pid_t pid, gid_t rgid);
int32_t kernel_set_ucred_svgid(pid_t pid, gid_t svgid);


#endif // PS5SDK_KERNEL_H
