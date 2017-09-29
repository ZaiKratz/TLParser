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

	bool Getjoin() const
	{
		 return this->join;
	}

	bool Getleave() const
	{
		 return this->leave;
	}

	bool Getinvite() const
	{
		 return this->invite;
	}

	bool Getban() const
	{
		 return this->ban;
	}

	bool Getunban() const
	{
		 return this->unban;
	}

	bool Getkick() const
	{
		 return this->kick;
	}

	bool Getunkick() const
	{
		 return this->unkick;
	}

	bool Getpromote() const
	{
		 return this->promote;
	}

	bool Getdemote() const
	{
		 return this->demote;
	}

	bool Getinfo() const
	{
		 return this->info;
	}

	bool Getsettings() const
	{
		 return this->settings;
	}

	bool Getpinned() const
	{
		 return this->pinned;
	}

	bool Getedit() const
	{
		 return this->edit;
	}

	bool GetDelete() const
	{
		 return this->Delete;
	}

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
