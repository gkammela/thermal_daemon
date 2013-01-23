/*
 * thd_cdev_pstates.h: thermal cooling class interface
 *	using T states.
 * Copyright (C) 2012 Intel Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 *
 * Author Name <Srinivas.Pandruvada@linux.intel.com>
 *
 */
#ifndef THD_CDEV_PSTATE_MSR_H_
#define THD_CDEV_PSTATE_MSR_H_

#include "thd_cdev.h"
#include "thd_msr.h"

class cthd_cdev_pstate_msr : public cthd_cdev
{
private:
	int 				p_state_index;
	cthd_msr			msr;
	int cpu_start_index;
	int cpu_end_index;
	std::string			last_governor;
	int	highest_freq_state;
	int lowest_freq_state;
	int control_begin();
	int control_end();

public:
	cthd_cdev_pstate_msr(unsigned int _index) : cthd_cdev(_index, "/sys/devices/system/cpu/"), p_state_index(0) {}
	int init();
	void set_curr_state(int state);
	int get_max_state();
	int update();
};

#endif /* THD_CDEV_TSTATES_H_ */
