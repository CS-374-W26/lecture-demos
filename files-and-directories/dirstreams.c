#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int main() {
	DIR* dir_stream = opendir(".");

	struct dirent* current_entry = NULL;
	while(current_entry = readdir(dir_stream)) {
		struct stat entry_info = {0};
		lstat(current_entry->d_name, &entry_info);
		printf(
			"Size of %s is %ld\n",
			current_entry->d_name,
			entry_info.st_size
		);
	}

	closedir(dir_stream);
	
	mode_t old_umask = umask(0000);
	mkdir("new_cool_directory", 0777);
	umask(old_umask);
	// chmod("new_cool_directory", 0777);
}
