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
