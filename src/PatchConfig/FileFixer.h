#ifndef PAL3PATCHCONFIG_FILEFIXER
#define PAL3PATCHCONFIG_FILEFIXER

class FileFixer : public RepairCommitter {
protected:
	std::vector<FileRW *> fp;
protected:
	FileFixer(BufferReader &r);
	~FileFixer();
};

class FileRawFixer : private FileFixer {
private:
	std::vector<const void *> data;
	std::vector<bool> bad;
public:
	FileRawFixer(BufferReader &r);
	int repair(ProgressObject *progress);
	bool commit();
};

class FileXorFixer : private FileFixer {
private:
	size_t blksize;
	const void *xorsum;
	SHA1Hash checksum;
	XorRepair *xr;
public:
	FileXorFixer(BufferReader &r);
	~FileXorFixer();
	int repair(ProgressObject *progress);
	bool commit();
};

#endif
