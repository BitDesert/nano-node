#pragma once

#include <nano/lib/alarm.hpp>
#include <nano/lib/work.hpp>
#include <nano/secure/common.hpp>
#include <nano/secure/utility.hpp>

#include <boost/asio/io_context.hpp>

namespace nano
{
/**
 * Resources that can be shared across node instances
 * *These are mostly useful in a testing context where more than one node may be running in a process
 * Sharing resources like worker threads removes the need for duplicating these resources
*/
class environment
{
public:
	environment (boost::filesystem::path const & = nano::working_path ());
	boost::filesystem::path path;
	boost::asio::io_context ctx;
	nano::alarm alarm;
	std::unique_ptr<nano::work_pool> work_impl;
	nano::work_pool & work;
	nano::environment_constants constants;
};
}
