/* License: WTFPL (http://www.wtfpl.net/) */

#include <sys/types.h>
#include <sys/socket.h>

#include <arpa/inet.h>
#include <ifaddrs.h>

#include <string.h>

#include "ifa.h"

const char*
network_address_r(const char* iface, char* buf, size_t buf_sz)
{
    const char* ans = NULL;
    struct ifaddrs* ifas;

    if (getifaddrs(&ifas) == 0) {
        struct ifaddrs* ifa;
        void* addr;

        for (ifa = ifas; ifa != NULL; ifa = ifa->ifa_next) {
            if (strcmp(ifa->ifa_name, iface) == 0) {
                if (ifa->ifa_addr->sa_family == AF_INET) {
                    addr = &((struct sockaddr_in*)ifa->ifa_addr)->sin_addr;
                    break;
                } else if (ifa->ifa_addr->sa_family == AF_INET6) {
                    addr = &((struct sockaddr_in6*)ifa->ifa_addr)->sin6_addr;
                    break;
                }
            }
        }

        if (ifa != NULL) {
            ans = inet_ntop(ifa->ifa_addr->sa_family, addr, buf, buf_sz);
        }

        freeifaddrs(ifas);
    }

    return ans;
}

const char*
network_address(const char* iface)
{
    static char buf[INET6_ADDRSTRLEN + 1];
    return network_address_r(iface, buf, sizeof(buf));
}
