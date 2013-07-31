/* License: WTFPL (http://www.wtfpl.net/) */

#pragma once

#ifndef __IFA_H_INCLUDED__
#define __IFA_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

const char*
network_address_r(const char* if_name, char* buf, size_t buf_sz);

const char*
network_address(const char* if_name);

#ifdef __cplusplus
} // extern "C"
#endif  /* __cplusplus */

#endif  /* __IFA_H_INCLUDED__ */
