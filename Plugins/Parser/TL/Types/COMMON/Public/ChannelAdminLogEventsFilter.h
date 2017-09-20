#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminLogEventsFilter : public TLBaseObject
{
public:
	ChannelAdminLogEventsFilter();
	ChannelAdminLogEventsFilter(bool join, bool leave, bool invite, bool ban, bool unban, bool kick, bool unkick, bool promote, bool demote, bool info, bool settings, bool pinned, bool edit, bool Delete);

	~ChannelAdminLogEventsFilter();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool join;
	 bool leave;
	 bool invite;
	 bool ban;
	 bool unban;
	 bool kick;
	 bool unkick;
	 bool promote;
	 bool demote;
	 bool info;
	 bool settings;
	 bool pinned;
	 bool edit;
	 bool Delete;
};
} //end namespace block
