/*
 *	Copyright © 2012-2016 Naim A.
 *
 *	This file is part of UDPT.
 *
 *		UDPT is free software: you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as published by
 *		the Free Software Foundation, either version 3 of the License, or
 *		(at your option) any later version.
 *
 *		UDPT is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *		GNU General Public License for more details.
 *
 *		You should have received a copy of the GNU General Public License
 *		along with UDPT.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "logging.h"
#include <fstream>
#include <ostream>
#include <string>

using namespace std;

namespace UDPT {

	Logger::Logger(const boost::program_options::variables_map& s)
		: m_logfile (std::cout)
	{
		const std::string& filename = s["logging.filename"].as<std::string>();
		const std::string& level = s["logging.level"].as<std::string>();

		closeStreamOnDestroy = false;

		if (level == "debug" || level == "d")
			this->loglevel = LL_DEBUG;
		else if (level == "warning" || level == "w")
			this->loglevel = LL_WARNING;
		else if (level == "info" || level == "i")
			this->loglevel = LL_INFO;
		else
			this->loglevel = LL_ERROR;
	}

	Logger::~Logger()
	{
	}

	void Logger::log(enum LogLevel lvl, string msg)
	{
		const char letters[] = "EWID";
		if (lvl <= this->loglevel)
		{
			m_logfile << time (NULL) << ": ("
					<< ((char)letters[lvl]) << "): "
					<< msg << "\n";
		}
	}
};