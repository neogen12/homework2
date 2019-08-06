#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


auto split(const std::string &str, char d)
{
	std::vector<std::string> r;

	std::string::size_type start = 0;
	std::string::size_type stop = str.find_first_of(d);
	while (stop != std::string::npos)
	{
		r.push_back(str.substr(start, stop - start));

		start = stop + 1;
		stop = str.find_first_of(d, start);
	}

	r.push_back(str.substr(start));

	return r;
}


bool comp(const std::vector<std::string>& a, const std::vector<std::string>& b) {
	
	if (std::stoi(a.at(0)) > std::stoi(b.at(0)))
		return true;
	else if (std::stoi(a.at(0)) == std::stoi(b.at(0)))
	{
		if (std::stoi(a.at(1)) > std::stoi(b.at(1)))
			return true;
		else if (std::stoi(a.at(1)) == std::stoi(b.at(1)))
		{
			if (std::stoi(a.at(2)) > std::stoi(b.at(2)))
				return true;
			else if (std::stoi(a.at(2)) == std::stoi(b.at(2)))
			{
				if (std::stoi(a.at(3)) > std::stoi(b.at(3)))
					return true;
				return false;
			}
		}
	}
	return false;
}

void filter(const std::string& first, const std::vector<std::vector<std::string>>& ip_pool)
{
	for (const auto x : ip_pool)
	{
		if (x.at(0) == first)
			std::cout << x.at(0) << "." << x.at(1) << "." << x.at(2) << "." << x.at(3) << std::endl;
	}
}

void filter(const std::string& first, const std::string& second, const std::vector<std::vector<std::string>>& ip_pool)
{
	for (const auto x : ip_pool)
	{
		if (x.at(0) == first && x.at(1) == second)
			std::cout << x.at(0) << "." << x.at(1) << "." << x.at(2) << "." << x.at(3) << std::endl;
	}
}

void filter_any(const std::string& byte, const std::vector<std::vector<std::string>>& ip_pool)
{
	for (const auto x : ip_pool)
	{
		if (x.at(0) == byte || x.at(1) == byte || x.at(2) == byte || x.at(3) == byte)
			std::cout << x.at(0) << "." << x.at(1) << "." << x.at(2) << "." << x.at(3) << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	try
	{
		std::vector<std::vector<std::string>> ip_pool;

		for (std::string line; std::getline(std::cin, line);)
		{
			std::vector<std::string> v = split(line, '\t');
			ip_pool.push_back(split(v.at(0), '.'));
		}

		// TODO reverse lexicographically sort
		std::stable_sort(ip_pool.begin(), ip_pool.end(), comp);
		for (auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
		{
			for (auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
			{
				if (ip_part != ip->cbegin())
				{
					std::cout << ".";
				}
				std::cout << *ip_part;
			}
			std::cout << std::endl;
		}
		// TODO filter by first byte and output
		filter("1", ip_pool);

		// TODO filter by first and second bytes and output
		filter("46", "70", ip_pool);
		// ip = filter(46, 70)


		// TODO filter by any byte and output
		// ip = filter_any(46)
		filter_any("46", ip_pool);

	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}