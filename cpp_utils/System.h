/*
 * System.h
 *
 *  Created on: May 27, 2017
 *      Author: kolban
 */

#ifndef COMPONENTS_CPP_UTILS_SYSTEM_H_
#define COMPONENTS_CPP_UTILS_SYSTEM_H_

#include <stdint.h>
#include <string>
#include <esp_system.h>

/**
 * @brief System wide functions.
 */
class System {
public:
	System();
	virtual ~System();
	static void getChipInfo(esp_chip_info_t *info);
	static std::string getIDFVersion();
    static size_t getFreeHeapSize();
    static size_t getMinimumFreeHeapSize();
    static size_t getFreeExternalHeapSize();
    static size_t getMinimumFreeExternalHeapSize();
    
	static void restart();
};

#endif /* COMPONENTS_CPP_UTILS_SYSTEM_H_ */
