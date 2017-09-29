#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChatPhoto.h"
#include "../../../Types/Common/Public/InputChannel.h"

//begin namespace block
namespace COMMON
{
class Chat : public TLBaseObject
{
public:
	Chat();
	Chat(bool creator, bool kicked, bool left, bool admins_enabled, bool admin, bool deactivated, int32 id, FString title, COMMON::ChatPhoto* photo, int32 participants_count, FDateTime date, int32 version, COMMON::InputChannel* migrated_to);

	~Chat();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getcreator() const
	{
		 return this->creator;
	}

	bool Getkicked() const
	{
		 return this->kicked;
	}

	bool Getleft() const
	{
		 return this->left;
	}

	bool GetAdminsEnabled() const
	{
		 return this->admins_enabled;
	}

	bool Getadmin() const
	{
		 return this->admin;
	}

	bool Getdeactivated() const
	{
		 return this->deactivated;
	}

	int32 Getid() const
	{
		 return this->id;
	}

	FString Gettitle() const
	{
		 return this->title;
	}

	COMMON::ChatPhoto*  Getphoto() const
	{
		 return this->photo;
	}

	int32 GetParticipantsCount() const
	{
		 return this->participants_count;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

	int32 Getversion() const
	{
		 return this->version;
	}

	COMMON::InputChannel*  GetMigratedTo() const
	{
		 return this->migrated_to;
	}

private:
	bool creator;
	 bool kicked;
	 bool left;
	 bool admins_enabled;
	 bool admin;
	 bool deactivated;
	 int32 id;
	 FString title;
	 COMMON::ChatPhoto* photo;
	 int32 participants_count;
	 FDateTime date;
	 int32 version;
	 COMMON::InputChannel* migrated_to;
};
} //end namespace block
