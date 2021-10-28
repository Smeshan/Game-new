#ifndef MGRBASE_H
#define MGRBASE_H
/* C system icnludes */

/* C++ system icnludes */

/* Third-party icnludes */

/* Own icnludes */

/* Forward Declaration */
enum {
	DRAW_MGR_INDX,
	RSRC_MGR_INDX,
	MEDIA_MGR_INDX,
	MANAGERS_COUNT
};

class MgrBase
{
public:
	virtual ~MgrBase() = default;

	MgrBase() = default;

	MgrBase(const MgrBase& other) = delete;
	MgrBase(MgrBase&& other) = delete;

	MgrBase& operator=(const MgrBase& other) = delete;
	MgrBase& operator=(MgrBase&& other) = delete;

	//forbid the copy and move constructors
	//forbid the copy and move assignment operators

	virtual void deinit() = 0;
	virtual void process() = 0;

};
#endif