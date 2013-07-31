
#pragma once

#ifndef __IFA_HPP_INCLUDED__
#define __IFA_HPP_INCLUDED__

#include <stdexcept>
#include <string>

#include <ifa.h>

namespace network {

inline bool
get_address(const std::string& if_name, std::string& ans)
{
    char buf[64];

    if (network_address_r(if_name.c_str(), buf, sizeof(buf)) != 0) {
        ans = buf;
        return true;
    }
    return false;
}

inline std::string
address(const std::string& if_name)
{
    std::string ans;

    if (!get_address(if_name, ans)) {
        throw std::runtime_error("Couldn't get address of '" + if_name + "' interface");
    }
    return ans;
}

} // namespace network

#endif  // __IFA_HPP_INCLUDED__
