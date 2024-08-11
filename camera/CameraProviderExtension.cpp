#include <fstream>
#include <iostream>
#include <string>
#include <cstdint>

bool supportsTorchStrengthControlExt() {
    return true;
}

int32_t getTorchDefaultStrengthLevelExt() {
    return 80;
}

int32_t getTorchMaxStrengthLevelExt() {
    std::ifstream file0("/sys/devices/platform/soc/c440000.qcom,spmi/spmi-0/spmi0-02/c440000.qcom,spmi:qcom,pm8350c@2:qcom,flash_led@ee00/leds/led:torch_0/max_brightness");
    int32_t max_brightness0 = 0;

    if (file0.is_open()) {
        file0 >> max_brightness0;
        file0.close();
    } else {
        std::cerr << "Error: Unable to open max_brightness file" << std::endl;
    }

    return max_brightness0 * 0.9;
}

int32_t getTorchStrengthLevelExt() {
    std::ifstream file0("/sys/devices/platform/soc/c440000.qcom,spmi/spmi-0/spmi0-02/c440000.qcom,spmi:qcom,pm8350c@2:qcom,flash_led@ee00/leds/led:torch_0/brightness");
    int32_t brightness0 = 0;

    if (file0.is_open()) {
        file0 >> brightness0;
        file0.close();
    } else {
        std::cerr << "Error: Unable to open brightness file" << std::endl;
    }

    return brightness0;
}

void setTorchStrengthLevelExt(int32_t torchStrength) {
    std::ofstream file0("/sys/devices/platform/soc/c440000.qcom,spmi/spmi-0/spmi0-02/c440000.qcom,spmi:qcom,pm8350c@2:qcom,flash_led@ee00/leds/led:torch_0/brightness");

    if (file0.is_open()) {
        file0 << torchStrength;
        file0.close();
    } else {
        std::cerr << "Error: Unable to open brightness file for writing" << std::endl;
    }
}