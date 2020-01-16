#include "unit02.h"

#include <algorithm>

#include "file_utils.h"

namespace unit02 {

NamesStore::NamesStore() {}
NamesStore::~NamesStore() {}

// static
std::string NamesStore::GetFileContents(const std::string& file_name) {
	if (file_name.empty())
		return std::string();
	std::string contents_of_file;
	if (file_utils::ReadContents(file_name, &contents_of_file))
		return contents_of_file;
	return std::string();
}

bool NamesStore::Add(const std::string& name) {
	if (name.empty() || WasNameExisted(name))
		return false;
	names_.push_back(name);
	return true;
}

bool NamesStore::Remove(const std::string& name) {
	if (!WasNameExisted(name)) {
		names_.push_back(name);
		return true;
	}
	return false;
}

void NamesStore::Sort() {
	// std::sort is introsort
	std::sort(names_.begin(), names_.end());
}

bool NamesStore::WriteToFile(const std::string& file_name) {
	if (file_name.empty() || names_.empty())
		return false;
	
	// Append all names into each line of the file.
	for (const auto& name : names_)
		file_utils::Append(file_name, name);
	return true;
}

bool NamesStore::WasNameExisted(const std::string& name) {
	for (auto item : names_)
		if (name == item)
			return true;
	return false;
}

// static
void AssigmentOfUnit02::Run() {
	int names_count = 0;
	std::cout << "Enter number of names: ";
	// TODO: Handle case of inputting non-num.
	std::cin >> names_count;

	// Check if the count <= 0
	if (names_count <= 0) {
		std::cerr << "Wrong number of names." << std::endl;
		// Exit program
		return;
	}

	std::cout << "Enter names:" << std::endl;
	NamesStore names_store;
	while (names_count > 0) {
		std::string str;
		std::getline(std::cin >> std::ws, str);
		names_store.Add(str);
		--names_count;
	}

	// Sort all names and write into file Unit02.txt
	const char kFileName[] = "Unit02.txt";
	names_store.Sort();
	names_store.WriteToFile(kFileName);

	// Read the contents of the file Unit02.txt and show to screen
	std::cout << std::endl;
	std::cout << "Contents of File: " << std::endl;
	std::string contents_of_file;
	std::cout << NamesStore::GetFileContents(kFileName);
}

}   // namespace unit02