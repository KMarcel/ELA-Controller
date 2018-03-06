/**
 * @file NexTion_Marcel.h
 *
 * The definition. 
 *
 * @author Wu Pengfei (email:<pengfei.wu@itead.cc>)
 * @date 2015/8/13
 *
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */
 
#ifndef __NEXTOUCH_H__
#define __NEXTOUCH_H__

#include <Arduino.h>
class NexTion{
public:
	NexTion(int PgID, String ComID); // String ID
	void SendText(String Command);
	void SendNummer(uint32_t Command);
	uint32_t Button(void);
private:
	bool write_Nextion(String Command);
	int PgID;
	String ComID;
};

#endif