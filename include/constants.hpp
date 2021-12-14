#pragma once
/*  In order to not share my WiFi network SSID and password,
    i've placed them in separate header which will not be added to repository.

    The header content should look like this:

    #pragma once

    namespace Constants {
    constexpr char const* WIFI_SSID{"WIFI SSID"};
    constexpr char const* WIFI_PASSWORD{"WIFI PASSWORD"};
    }

*/
#include "private_network_constants.hpp"
#include "website_constants.hpp"

namespace Constants {
constexpr char const* DNS_DOMAIN_NAME{"starplatinum"};

constexpr int LED_PIN{};

constexpr unsigned long SERIAL_BAUDRATE{74880};
}  // namespace Constants